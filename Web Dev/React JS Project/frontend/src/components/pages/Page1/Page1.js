import React, { useState, useContext, useEffect } from 'react';
import Dropdown from 'react-bootstrap/Dropdown';
import ButtonGroup from 'react-bootstrap/ButtonGroup';
import { db } from '../../../firebase-config'
import { collection, getDocs } from 'firebase/firestore';
import { signOut  } from 'firebase/auth'
import { auth } from "../../../firebase-config"
import { useNavigate } from 'react-router-dom'
import { AuthContext } from "../../../context/AuthContext"
import { Alert } from 'react-bootstrap';

// Importación de imágenes jpg, png y svg
import { FontAwesomeIcon } from "@fortawesome/react-fontawesome"
import { faMagnifyingGlass } from '@fortawesome/free-solid-svg-icons';
// Importación de estilos
import './Page1.css'

function Page1(){

    const {currentUser} = useContext(AuthContext)
    const userUID = currentUser.uid;
    let arrPatientUID = [];

    // Datos de Registro de Presión
    let mEmocional;

    const [patients, setUsers] = useState([]);
    const pacientCollectionRef = collection(db, "Paciente");
    const [doctors, setDoctors] = useState([]);
    const medicoCollectionRef = collection(db, "Medico");
    const [rP, setRP] = useState([]);
    const rPRef = collection(db, 'RegistroPresion');
    const [rS, setRS] = useState([]);
    const rSRef = collection(db, 'RegistroSalud');

    const [filteredData, setFilteredData] = useState([]);

    useEffect(() => {
        const getUsers = async () => {
            try {
                const dataP = await getDocs(pacientCollectionRef);
                setUsers(dataP.docs.map((doc) => ({...doc.data(), id: doc.id})));

                const dataD = await getDocs(medicoCollectionRef);
                setDoctors(dataD.docs.map((doc) => ({...doc.data(), id: doc.id})));

                const dataRP = await getDocs(rPRef);
                setRP(dataRP.docs.map((doc) => ({...doc.data(), id: doc.id})));

                const dataRS = await getDocs(rSRef);
                setRS(dataRS.docs.map((doc) => ({...doc.data(), id: doc.id})));
            }
            catch (err) {
                console.log(err);
            }
        };
        getUsers()
    },[]);

    const navigate = useNavigate();
    const {dispatch} = useContext(AuthContext);

    const handleClick = event => {
        const patientUID = event.currentTarget.id;
        localStorage.setItem('patient', patientUID);
    };

    const handleLogOut = (e) => {
        e.preventDefault();

        localStorage.setItem('patient', null);
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

    function getIndicaciones(uidPaciente) {
        let indicaciones;
        {rS.map((rSalud) => {
            if (rSalud.uidPaciente === uidPaciente) {
                indicaciones = rSalud.indicaciones;
                console.log(indicaciones)
            }
        })}
        if (indicaciones === undefined) {
            return "Por el momento no hay indicaciones."
        }
        return indicaciones;
    }

    function removeDuplicates(arr) {
        return [...new Set(arr)];
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
                        <div className="search form">
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

        <div className="container-fluid mb-4" style={{maxWidth: '1290px'}}>
            <div className="row d-flex justify-content-center align-items-center">
                <div className="col">
                    <h1 className="fw-bold p-title" style={{fontSize: '6vw'}}>Pacientes</h1>
                </div>
                <div className="col">
                    <a id="bell" className="btn float-end effect-btn" href="/page3">
                        <img src="./images/plus-btn.png" width="85" alt="plus"/>
                    </a>
                </div>
            </div>
        </div>
        <div className="container-fluid">
            {patients.map((patient) => {
                for (let i = 0; i < patient.uidMedicos.length; i++) {
                    if (userUID === patient.uidMedicos[i]) {
                        arrPatientUID.push(patient.uid);
                        if (patient.urlImg === undefined || "") {
                            patient.urlImg = "./images/profile-pic.png";
                        }
                        return (
                            <div onClick={handleClick} id={patient.uid} className="row d-flex align-items-center justify-content-center px-5 mb-4">
                                <a className="card effect shadow" href="/page2" style={{textDecoration: 'none', maxWidth: '1250px'}}>
                                    <div className="row align-items-center justify-content-center">
                                        <div className="col-md-3">
                                            <img src={patient.urlImg} className="img-thumbail rounded-circle p-5 profile-pic"/>
                                        </div>
                                        <div className="col col-md py-4">
                                            <div className="row d-flex justify-content-center align-items-center px-1 py-3">
                                                <div className="col-9 rounded-2 align-self-start p-3" style={{backgroundColor: '#869FF2'}}>
                                                    <h2 className="text-light fw-bold text-center" style={{fontWeight: '750px', fontSize: '45px'}}>{patient.nombrePila} {patient.apellidoPaterno} {patient.apellidoMaterno}</h2>
                                                </div>
                                                <div className="col">
                                                        <img src={imgStatus(patient.uid)} alt="" className="img-fluid float-end" style={{width: '200px'}}/>
                                                </div>
                                            </div>
                                            <div className="d-flex row p-1 d-flex justify-content-center text-dark">
                                                <div id="c-datos" className="col-4 p-2 px-4">
                                                        <span className="fs-5 fw-bold m-1">Fecha de Nacimiento: <span className="fw-normal">{patient.fechaNacimiento}</span></span>
                                                        <br></br>
                                                        <span className="fs-5 fw-bold">Peso: <span className="fw-normal">{patient.peso} Kg</span></span>
                                                </div>
                                                <div id="c-datos" className="col p-2 px-4 offset-1">
                                                    <span className="fs-5 fw-bold m-1">Indicaciones: <span className="fw-normal">{getIndicaciones(patient.uid)}</span></span>
                                                </div>
                                            </div>
                                        </div>
                                    </div>
                                </a>
                            </div>
                        )
                    }
                }
                // if (count === 0) {
                //     return (
                //     <div className="container-fluid">
                //         <div className="row align-items-center justify-content-center">
                //             <div className="col" style={{maxWidth: '1290px'}}>
                //                 <Alert variant="warning" className="fw-bold text-warning m-2 p-4 text-center" style={{fontSize: '45px'}}>
                //                     <img src="./images/warning.png" className="img-thumbail" width="75px" alt="#"/>
                //                     ¡Ups! Parece que no has añadido pacientes a tu lista :/
                //                 </Alert>
                //             </div>
                //         </div>
                //     </div>
                //     )
                // }
            })}
        </div>
    </div>
    )
}

export default Page1