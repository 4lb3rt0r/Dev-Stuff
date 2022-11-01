import React, { useContext, useState, useEffect, useRef } from 'react';
import Dropdown from 'react-bootstrap/Dropdown';
import ButtonGroup from 'react-bootstrap/ButtonGroup';
import { db } from '../../../firebase-config'
import { collection, getDocs, doc, updateDoc } from 'firebase/firestore';
import { signOut  } from 'firebase/auth'
import { auth } from "../../../firebase-config"
import { useNavigate } from 'react-router-dom'
import { AuthContext } from "../../../context/AuthContext"
import { Alert, Modal, Button } from 'react-bootstrap';
import md5 from 'md5';
import Snackbar from '../../Snackbar';

// Importación de imágenes jpg, png y svg
import { FontAwesomeIcon } from "@fortawesome/react-fontawesome"
import { faMagnifyingGlass } from '@fortawesome/free-solid-svg-icons';
// Importación de estilos
import './Page3.css'

function Page3 () {

    let mEmocional;

    const snackbarRef = useRef(null)
    const snackbarRef2 = useRef(null)
    const snackbarRef3 = useRef(null)
    const snackbarRef4 = useRef(null)

    const [token, setToken] = useState("");
    const [tokenState, setTokenState] = useState({tokenInput: ''});

    const [show, setShow] = useState(false);

    const navigate = useNavigate()
    const {dispatch} = useContext(AuthContext)

    const {currentUser} = useContext(AuthContext)
    const userUID = currentUser.uid;

    const [patients, setUsers] = useState([]);
    const pacientCollectionRef = collection(db, "Paciente");
    const [doctors, setDoctors] = useState([]);
    const medicoCollectionRef = collection(db, "Medico");
    const [rP, setRP] = useState([]);
    const rPRef = collection(db, 'RegistroPresion');

    const handleClose = () => {
        setShow(false)
    };

    const handleOpen = event => {
        setShow(true)
        const patientUID = event.currentTarget.id;
        localStorage.setItem('patient', patientUID);
    };

    useEffect(() => {
        const getUsers = async () => {
            try {
                const dataP = await getDocs(pacientCollectionRef);
                setUsers(dataP.docs.map((doc) => ({...doc.data(), id: doc.id})));

                const dataD = await getDocs(medicoCollectionRef);
                setDoctors(dataD.docs.map((doc) => ({...doc.data(), id: doc.id})));

                const dataRP = await getDocs(rPRef);
                setRP(dataRP.docs.map((doc) => ({...doc.data(), id: doc.id})));
            }
            catch (err) {
                console.log(err);
            }
        };
        getUsers()
    },[]);

    const refreshPatients = () => {
        const getUsers = async () => {
            try {
                const dataP = await getDocs(pacientCollectionRef);
                setUsers(dataP.docs.map((doc) => ({...doc.data(), id: doc.id})));

                const dataD = await getDocs(medicoCollectionRef);
                setDoctors(dataD.docs.map((doc) => ({...doc.data(), id: doc.id})));

                const dataRP = await getDocs(rPRef);
                setRP(dataRP.docs.map((doc) => ({...doc.data(), id: doc.id})));
            }
            catch (err) {
                console.log(err);
            }
        };
        getUsers()
    }

    const handleClick = event => {
        const patientUID = event.currentTarget.id;
        localStorage.setItem('patient', patientUID);
    };

    const handleLogOut = (e) => {
        e.preventDefault();

        signOut(auth)
        .then(() => {
            // Sign-out successful.
            dispatch({type: "LOGOUT"})
            navigate("/login")
        })
        .catch((error) => {
            console.log("Error");
        });
    }

    function imgStatus(uidPaciente) {
        mEmocional = -1;
        {rP.map((rPresion) => {
            if (rPresion.uidPaciente === uidPaciente) {
                mEmocional = rPresion.medidorEmocional;
                // console.log(mEmocional);
                // mEmocional = removeDuplicates(mEmocional);
            }
        })}
        var mEmo = "";
        console.log(mEmocional);
        if (mEmocional >= 6.66) {
            return mEmo = "./images/cara-feliz.png"
        }
        else if (mEmocional >= 3.33 && mEmocional < 6.66) {
            return mEmo = "./images/cara-seria.png"
        }
        else if (mEmocional < 3.33 && mEmocional >= 0) {
            return mEmo = "./images/cara-mala.png"
        }
        else {
            return mEmo = "./images/cara-gris.png"
        }
        
    }

    const addPatient = async (e) => {
        e.preventDefault();

        var encrypted = md5(token);
        let listPatientUID = [];
        let patientUID;
        let listMedicoUID = [];

        console.log(encrypted);

        try{
            {patients.map((patient) => {
                if (patient.token === encrypted) {
                    {doctors.map((doctor) => {
                        if (userUID === doctor.uid) {
                            listPatientUID = doctor.uidPacientes;
                        }
                    })}
                    listMedicoUID = patient.uidMedicos;
                    listPatientUID.push(patient.uid);
                    patientUID = patient.uid;
                    console.log(patientUID)
                }
            })}
            console.log(listPatientUID);
            listMedicoUID.push(userUID);
            await updateDoc(doc(db, "Medico", userUID), { uidPacientes: listPatientUID });
            await updateDoc(doc(db, "Paciente", patientUID), { uidMedicos: listMedicoUID });
            console.log("Éxito");
            snackbarRef.current.show();
        }
        catch {
            console.log("Error");
            snackbarRef2.current.show();
        }
        refreshPatients()
    }

    const deletePatient = async (e) => {
        e.preventDefault();

        let listPatientUID = [];
        let patientUID = localStorage.getItem('patient');
        let listMedicoUID = [];

        try{
            {patients.map((patient) => {
                if (patient.uid === patientUID) {
                    {doctors.map((doctor) => {
                        if (userUID === doctor.uid) {
                            listPatientUID = doctor.uidPacientes;
                        }
                    })}
                    listMedicoUID = patient.uidMedicos;
                }
            })}

            console.log(listPatientUID);
            console.log(listMedicoUID);

            for (let i = 0; i < listPatientUID.length; i++) {
                if (listPatientUID[i] === patientUID) {
                    listPatientUID.splice(i, 1);
                }
            }
            for (let i = 0; i < listMedicoUID.length; i++) {
                if (listMedicoUID[i] === userUID) {
                    listMedicoUID.splice(i, 1);
                }
            }

            console.log(listPatientUID);
            console.log(listMedicoUID);
            
            await updateDoc(doc(db, "Medico", userUID), { uidPacientes: listPatientUID });
            await updateDoc(doc(db, "Paciente", patientUID), { uidMedicos: listMedicoUID });
            console.log("Éxito");
            snackbarRef3.current.show();
            // setShow(false);
        }
        catch {
            console.log("Error");
            snackbarRef4.current.show();
        }
        refreshPatients()
    }

    return (
        <div>
            <nav className="navbar-brand p-3">
                <div className="container-fluid">
                    <div className="row-4 d-flex justify-content-center align-items-center">
                        <div className="col">
                            <i id="bell" className="btn effect-btn float-start">
                                <img src="./images/bell.png" width="40" alt="bell"/>
                            </i>
                        </div>
                        <div className="col-6 align-items-center">
                            <div className="form">
                                <FontAwesomeIcon icon={faMagnifyingGlass} id="search-icon" className="fa fa-search btn p-0 effect-btn"></FontAwesomeIcon>
                                <input type="search" className="form-control form-input fs-5 fw-lighter" placeholder="Buscar pacientes..."/>
                            </div>
                        </div>
                        <div className="col">
                            <span className="float-end text-light fs-4">
                                <div className="row align-items-center justify-content-center">
                                <Dropdown as={ButtonGroup}>
                                    <Dropdown.Toggle className="dropdown-name">
                                    <img src="./images/profile-pic.png" className="img-thumbail rounded-circle mx-3" width="40px" alt="#"/>
                                        {doctors.map((doctor) => {
                                            if (userUID === doctor.uid) {
                                                
                                                return (
                                                    <span className="fw-semibold d-none d-lg-inline">{doctor.nombrePila} {doctor.apellidoPaterno} {doctor.apellidoMaterno}</span>
                                                )
                                            }
                                        })}
                                    </Dropdown.Toggle>

                                    <Dropdown.Menu align="end">
                                        <Dropdown.Item onClick={handleLogOut} className="text-danger">
                                        <img src="./images/log-out.png" className="img-thumbail mx-2 text-danger" width="20px" alt="#"/>
                                        <span className="fw-semibold">Cerrar Sesión</span>
                                        </Dropdown.Item>
                                    </Dropdown.Menu>
                                </Dropdown>
                                </div>
                            </span>
                        </div>
                    </div>
                </div>
            </nav>

            <div className="container-fluid mb-4" style={{maxWidth: '1350px'}}>
                <div className="row d-flex justify-content-center align-items-center">
                    <div className="col-6">
                        <h1 id="p-title" className="fw-bold mx-2">Agregar o quitar pacientes</h1>
                    </div>
                    <div className="col">
                        <a href="/" id="bell" className="btn float-end effect-btn">
                            <img href="/#" src="./images/cross-btn.png" width="85" alt="cross"/>
                        </a>
                    </div>
                </div>
            </div>

            <div className="container">
                <div className="row mb-5 justify-content-center">
                    <form className="row justify-content-center" onSubmit={addPatient}>
                        <div className="col-6">
                            <label htmlFor="text" className="visually-hidden">Token</label>
                            <input type="text" className="form-control form-control-lg fs-3 fw-lighter" id="token-input" placeholder="Ingrese el token proporcionado por el paciente" aria-label=".form-control-lg example" onChange={ (e) =>setToken(e.target.value)}/>
                        </div>
                        <div className="col-auto">
                            <button onClick={() => setTokenState({tokenInput: ''})} type="submit" id="bell" className="btn float-end effect-btn">
                                <img src="./images/plus-btn.png" width="85" alt="plus"/>
                            </button>
                            <Snackbar  ref={snackbarRef} message="El Paciente ha sido agregado" type= "success"/>
                            <Snackbar  ref={snackbarRef2} message="Token Invalido" type= "fail"/>
                        </div>
                    </form>
                </div>

                {patients.map((patient) => {
                    for (let i = 0; i < patient.uidMedicos.length; i++) {
                        if (userUID === patient.uidMedicos[i]) {
                            if (patient.urlImg === undefined || "") {
                                patient.urlImg = "./images/profile-pic.png";
                            }
                            return (
                                <div className="row justify-content-center align-items-center">
                                    <div className="col-10">
                                        <div className="row align-items-center justify-content-center mb-4">
                                            <a onClick={handleClick} id={patient.uid} className="card effect shadow" href="/page2" style={{textDecoration: 'none', maxWidth: '1400px'}}>
                                                <div className="row align-items-center justify-content-center">
                                                    <div className="col-md-3">
                                                        <img src={patient.urlImg} className="img-thumbail rounded-circle p-5 profile-pic" alt=""/>
                                                    </div>
                                                    <div className="col col-md py-4">
                                                        <div className="row justify-content-center align-items-center px-1 py-3">
                                                            <div className="col-9 rounded-2 align-self-start p-3" style={{backgroundColor: '#869FF2'}}>
                                                                <h2 className="text-light fw-bold text-center" style={{fontWeight: '750px', fontSize: '40px'}}>{patient.nombrePila} {patient.apellidoPaterno} {patient.apellidoMaterno}</h2>
                                                            </div>
                                                            <div className="col">
                                                                <img src={imgStatus(patient.uid)} alt="" className="img-fluid float-end" style={{width: '150px'}}/>
                                                            </div>
                                                        </div>
                                                        <div className="d-flex row p-1 d-flex justify-content-center text-dark">
                                                            <div id="c-datos" className="col-5 p-3 px-4">
                                                                    <span className="fs-6 fw-bold">Fecha de Nacimiento: <span className="fs-6 fw-normal">{patient.fechaNacimiento}</span></span>
                                                                    <br></br>
                                                                    <span className="fs-6 fw-bold">Peso: <span className="fw-normal">{patient.peso} Kg</span></span>
                                                            </div>
                                                            <div id="c-datos" className="col p-3 px-4 offset-1">
                                                                <span className="fs-6   fw-bold">Órdenes médicas: <span className="fs-6 fw-normal">Texto breve de las indicaciones proporcionadas por el médico</span></span>
                                                            </div>
                                                        </div>
                                                    </div>
                                                </div>
                                            </a>
                                        </div>
                                    </div>
                                    <div className="col">
                                        <button onClick={handleOpen} id={patient.uid} className="btn float-end effect-btn">
                                            <img href="#" src="./images/minus-btn.png" width="85" alt="minus"/>
                                        </button>
                                    </div>
                                </div>
                            )
                        }
                    }
                    // if (count === 0) {
                    //     return (
                    //         <div className="container-fluid">
                    //             <div className="row align-items-center justify-content-center">
                    //                 <div className="col" style={{maxWidth: '1290px'}}>
                    //                     <Alert variant="warning" className="fw-bold text-warning m-2 p-4 text-center" style={{fontSize: '45px'}}>
                    //                         <img src="./images/warning.png" className="img-thumbail" width="75px" alt="#"/>
                    //                         ¡Ups! Parece que no has añadido pacientes a tu lista :/
                    //                     </Alert>
                    //                 </div>
                    //             </div>
                    //         </div>
                    //     )
                    // }
                })}
            <Modal centered backdrop="static" show={show} onHide={handleClose}>
                <Modal.Header closeButton>
                    <Modal.Title className="modal-title">
                        <span className="fs-2 fw-bold text-danger">¿Desea eliminar a este paciente de su lista?</span>
                    </Modal.Title>
                </Modal.Header>
                <Modal.Body className="modal-body text-start m-3">
                    <div className="row justify-content-center align-items-center">
                        <div className="col-3">
                            <img className="p-0 effect-btn w-100" href="" src="./images/user-minus.png"  alt="bell"/>
                        </div>
                        <div className="col">
                            <span className="fs-5 fw-bold text-danger">Eliminar al paciente significa desvincularlos a ambos como paciente y médico.</span>
                        </div>
                    </div>
                </Modal.Body>
                <Modal.Footer>
                    <Button variant="outline-danger" onClick={deletePatient}>Eliminar</Button>
                    <Snackbar  ref={snackbarRef3} message="Se Elimino al Paciente Correctamente" type= "success"/>
                    <Snackbar  ref={snackbarRef4} message="Error al eliminar Paciente" type= "fail"/>
                </Modal.Footer>
            </Modal>
            </div>
        </div>
    )
}

export default Page3