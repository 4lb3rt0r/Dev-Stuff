import React, { useState, useContext, useEffect } from 'react';
import Dropdown from 'react-bootstrap/Dropdown';
import { Alert, Modal, Button} from 'react-bootstrap';
import ButtonGroup from 'react-bootstrap/ButtonGroup';
import { db } from '../../../firebase-config'
import { collection, getDocs, doc, updateDoc } from 'firebase/firestore';
import { signOut  } from 'firebase/auth';
import { auth } from "../../../firebase-config";
import { useNavigate } from 'react-router-dom';
import { AuthContext } from "../../../context/AuthContext";
import Chart from 'chart.js/auto';
import { Bar, Line } from 'react-chartjs-2';

// Importación de imágenes jpg, png y svg
import { FontAwesomeIcon } from "@fortawesome/react-fontawesome"
import { faMagnifyingGlass } from '@fortawesome/free-solid-svg-icons';
// Importación de estilos
import './Page2.css'

function Page2(){

    const patientUID = localStorage.getItem('patient');

    // Datos de Registro de Presión
    let fyh = [];
    let pD = [];
    let pS = [];
    let pulsos = [];
    let mEmocional = [];
    let hEjercicio;
    let comentarios;

    // Datos de Registro de Salud
    let fecha;
    let indicaciones;
    let cantMed = [];
    let fechaLimMed = [];
    let frecMed = [];
    let nombreMed = [];

    // Datos de Cuestionario Semanal
    let medAlimentacion  = [];
    let medEjercicio = [];
    let medEmocional = [];
    let fechaCuestionario;

    const [error, setError] = useState("");
    const [loading, setLoading] = useState(false);

    const [nombreMedi, setNMedi] = useState("");
    const [cantMedi, setCantMedi] = useState("");
    const [cFrec, setCFrec] = useState("");
    const [cLim, setCLim] = useState("");
    const [indic, setIndic] = useState("");
    
    const [show, setShow] = useState(false);

    const [modalState, setModalState] = useState( "modal-one" | "modal-salud" | "modal-two" | "modal-three" | "close")

    const handleShowModalOne = () => {
        setModalState("modal-one")
    }

    const handleShowModalSalud = () => {
        setModalState("modal-salud")
    }

    const handleShowModalTwo = () => {
        setModalState("modal-two")
    }

    const handleShowModalThree = () => {
        setModalState("modal-three")
    }

    const handleClose = () => {
        setModalState("close")
    }

    // const handleClosed = () => setShow(false);
    const handleShow = () => setShow(true);

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
    const [rS, setRS] = useState([]);
    const rSRef = collection(db, 'RegistroSalud');
    const [cS, setCS] = useState([]);
    const cSRef = collection(db, 'CuestionarioSemanal');

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

                const dataCS = await getDocs(cSRef);
                setCS(dataCS.docs.map((doc) => ({...doc.data(), id: doc.id})));
            }
            catch (err) {
                console.log(err);
            }
        };
        getUsers()
    }, []);

    const refreshPatients = () => {
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

                const dataCS = await getDocs(cSRef);
                setCS(dataCS.docs.map((doc) => ({...doc.data(), id: doc.id})));
            }
            catch (err) {
                console.log(err);
            }
        };
        getUsers()
    }

    const addHealthRegister = async (e) => {
        e.preventDefault();

        const date = new Date();

        let day = date.getDate();
        let month = date.getMonth() + 1;
        let year = date.getFullYear();

        let currentDate = `${day}-${month}-${year}`;

        try {
            setError("");
            setLoading(true);

            cantMed.push(cantMedi);
            fechaLimMed.push(cLim);
            frecMed.push(cFrec);
            nombreMed.push(nombreMedi);
            indicaciones = indic;
            await updateDoc(doc(db, "RegistroSalud", patientUID), { cantidadMedicamentos: cantMed, fecha: currentDate, fechaLimiteMedicamentos: fechaLimMed, frecuenciaMedicamentos: frecMed, indicaciones: indicaciones, nombreMedicamentos: nombreMed, uidMedico: userUID, uidPaciente: patientUID});
            console.log("Éxito");
            setModalState("close");
        }
        catch {
            setError("Error al crear la cuenta")
        }
        refreshPatients()
    };

    function removeDuplicates(arr) {
        return [...new Set(arr)];
    }

    function doExcercise (hEjercicio) {
        var hEj = "";
        if (hEjercicio) {
            return hEj = "Sí"
        }
        else {
            return hEj = "No"
        }
    }

    function imgStatus(mEmocional) {
        var mEmo = "";
        if (mEmocional >= 6.66) {
            return mEmo = "./images/cara-feliz.png"
        }
        else if (mEmocional >= 3.33 && mEmocional < 6.66) {
            return mEmo = "./images/cara-seria.png"
        }
        else if (mEmocional < 3.33) {
            return mEmo = "./images/cara-mala.png"
        }
        else {
            return mEmo = "./images/cara-gris.png"
        }
    }

    function verify7(arr) {
        var arrLast7 = [];
        var i = arr.length - 1;
        var count = 0;
        if (arr.length > 7) {
            while (i > 0 && count < 7) {
                arrLast7.unshift(arr[i]);
                i--;
                count++;
            }
        }
        else {
            arrLast7 = arr;
        }
        return arrLast7;
    }

    {rP.map((rPresion) => {
        if (rPresion.uidPaciente === patientUID) {
            fyh.push(rPresion.fechayHoraToma);
            // fyh = removeDuplicates(fyh);
            pD.push(rPresion.presionDiastolica);
            // pD = removeDuplicates(pD);
            pS.push(rPresion.presionSistolica);
            // pS = removeDuplicates(pS);
            pulsos.push(rPresion.pulso);
            // pulsos = removeDuplicates(pulsos);
            mEmocional.push(rPresion.medidorEmocional);
            // mEmocional = removeDuplicates(mEmocional);
            comentarios = rPresion.comentarios;
            hEjercicio = rPresion.hicisteEjercicio;
        }
    })}

    fyh = verify7(fyh);
    pD = verify7(pD);
    pS = verify7(pS);
    pulsos = verify7(pulsos);

    {rS.map((rSalud) => {
        if (userUID === rSalud.uidMedico && patientUID === rSalud.uidPaciente) {
            fecha = rSalud.fecha;
            indicaciones = rSalud.indicaciones;
            cantMed = rSalud.cantidadMedicamentos;
            // cantMed = removeDuplicates(cantMed);
            fechaLimMed = rSalud.fechaLimiteMedicamentos;
            // fechaLimMed = removeDuplicates(fechaLimMed);
            frecMed = rSalud.frecuenciaMedicamentos;
            // frecMed = removeDuplicates(frecMed);
            nombreMed = rSalud.nombreMedicamentos;
            // nombreMed = removeDuplicates(nombreMed);
        }
    })}

    let indices = [];
    for (let i = 0; i < cantMed.length; i++) {
        indices[i] = i;
    }

    {cS.map((cSemanal) => {
        if (cSemanal.uidPaciente === patientUID) {
            medAlimentacion.push(cSemanal.medidorAlimentacion);
            // medAlimentacion = removeDuplicates(medAlimentacion);
            medEjercicio.push(cSemanal.medidorEjercicio);
            // medEjercicio = removeDuplicates(medEjercicio);
            medEmocional.push(cSemanal.medidorEmocional);
            // medEmocional = removeDuplicates(medEmocional);
            fechaCuestionario = cSemanal.fechaCuestionario;
        }
    })}

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

    return (
    <div>
        <nav className="navbar-brand p-3">
            <div className="container-fluid">
                <div className="row-4 d-flex justify-content-center align-items-center">
                    <div className="col">
                        <i id="bell" className="btn effect-btn float-start">
                            <img href="" src="./images/bell.png" width="40" alt="bell"/>
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

        <div className="container-fluid p-3">
            <div className="row row-cols-1">
                <div className="col">
                    <a href="/" id="bell" className="btn float-end effect-btn">
                        <img href="/#" src="./images/cross-btn.png" width="85" alt=""/>
                    </a>
                </div>
            </div>
        </div>

        {patients.map((patient) => {
            if (patientUID === patient.uid) {
                hEjercicio = doExcercise (hEjercicio);
                if (patient.urlImg === undefined || "") {
                    patient.urlImg = "./images/profile-pic.png";
                }
                return (
                    <div className="container-fluid mt-2 mb-3 rounded shadow" style={{backgroundColor: '#EBECEF', width: '90%'}}>
                        <div className="row align-items-stretch justify-content-center">
                                <img src={patient.urlImg} className="img-thumbail rounded-circle p-1 profile-pic" id="profile-pic" alt="#"/>
                        </div>
                        <div className="row align-items-stretch justify-content-center">
                            <div className="col-8 c-name rounded-2 align-self-center px-4 " style={{backgroundColor: '#869FF2'}}>
                                <h2 className="text-light fw-bold text-center" style={{fontWeight: '750px', fontSize: '65px'}}>{patient.nombrePila} {patient.apellidoPaterno} {patient.apellidoMaterno}</h2>
                            </div>
                        </div>
                        <div className="row row-cols-1 row-cols-md-3 g-4 mt-4">
                            <div className="col">
                                <div className="card effect">
                                    <h1 className="card-title text-center rounded-top fs-1 fw-bolder p-2">Datos Generales</h1>
                                    <div className="card-body">
                                        <p className="card-text text-center">
                                            <span className="fs-4 fw-bold">Fecha de Nacimiento: <span className="fs-4 fw-normal">{patient.fechaNacimiento}</span></span>
                                            <br></br>
                                            <span className="fs-4 fw-bold">Peso: <span className="fs-4 fw-normal">{patient.peso} Kg</span></span>
                                            <br></br>
                                            <span className="fs-4 fw-bold">Altura: <span className="fs-4 fw-normal">{patient.altura} cm</span></span>
                                        </p>
                                        <div className="d-grid gap-2">
                                            <Button className="btn fst-italic btn-lg" variant="outline-primary" dafs-4ta-bs-toggle="modal" data-bs-target="#exampleModal" type="button" onClick={handleShowModalOne}>Más Información...</Button>
            
                                            <Modal centered show={modalState === "modal-one"} onHide={handleClose} size="lg" id="#exampleModal">
                                                <Modal.Header closeButton>
                                                    <Modal.Title className="modal-title fs-1 fw-bold" style={{color: "#7A28FF"}}>Datos del Paciente</Modal.Title>
                                                </Modal.Header>
                                                <Modal.Body className="modal-body text-center">
                                                        <span className="fs-3 fw-bold">Fecha de Nacimiento: <span className="fw-normal">{patient.fechaNacimiento}</span></span>
                                                        <br></br>
                                                        <span className="fs-3 fw-bold">Peso: <span className="fw-normal">{patient.peso} Kg</span></span>
                                                        <br></br>
                                                        <span className="fs-3 fw-bold">Altura: <span className="fw-normal">{patient.altura} cm</span></span>
                                                        <br></br>
                                                        <span className="fs-3 fw-bold">Indicaciones del Médico:  <span className="fw-normal">{indicaciones}</span></span>
                                                        <br></br>
                                                        <span className="fs-3 fw-bold">Medicamentos:</span>
                                                        <br></br>
                                                        <span className="fs-5 fw-bold fst-italic">Actualizado el: <span className="fw-semibold" style={{color: "#7A28FF"}}>{fecha}</span></span>
                                                        <br></br>
                                                        {
                                                            indices.map( i => 
                                                                <div>
                                                                    <span className="fs-4 fw-bold" style={{color: "#556FCC"}}>Medicamento {i + 1}: <span className="fw-bold text-dark">{nombreMed[i]}</span></span>
                                                                    <br></br>
                                                                    <span className="fs-5 fw-bold">Dosis de Consumo: <span className="fw-semibold" style={{color: "#7A28FF"}}>{cantMed[i]}</span></span>
                                                                    <br></br>
                                                                    <span className="fs-5 fw-bold">Frecuencia: <span className="fw-semibold" style={{color: "#7A28FF"}}>{frecMed[i]}</span></span>
                                                                    <br></br>
                                                                    <span className="fs-5 fw-bold">Consumir hasta: <span className="fw-semibold" style={{color: "#7A28FF"}}>{fechaLimMed[i]}</span></span>
                                                                    <br></br>
                                                                    <span className="fw-semibold" style={{color: "#7A28FF"}}>-----------------------------------------------------</span>
                                                                </div>
                                                            )
                                                        }
                                                        
                                                </Modal.Body>
                                                <Modal.Footer>
                                                    <Button variant="primary" onClick={handleClose}>Listo</Button>
                                                </Modal.Footer>
                                            </Modal>

                                            <Button className="btn fst-italic btn-lg" variant="outline-info" dafs-4ta-bs-toggle="modal" data-bs-target="#exampleModal" type="button" onClick={handleShowModalSalud}>Añadir Nuevo Registro de Salud</Button>
            
                                            <Modal centered show={modalState === "modal-salud"} onHide={handleClose} size="lg" id="#exampleModal">
                                                <Modal.Header closeButton>
                                                    <Modal.Title className="modal-title fs-1 fw-bold" style={{color: "#7A28FF"}}>Añadir Registro de Salud</Modal.Title>
                                                </Modal.Header>
                                                <form onSubmit={addHealthRegister}>
                                                    <Modal.Body className="modal-body text-center">
                                                    <div>
                                                        {error && <Alert variant="danger" className="fw-bold text-danger">{error}</Alert>}
                                                    </div>
                                                            <div className="form-group">
                                                                <div className="row align-items-center justify-content-center m-1">
                                                                    <div className="col-6">
                                                                        <div className="form-floating mb-1">
                                                                            <input id="nombre" type="text" className="form-control" placeholder="Escriba su nombre(s)" required onChange={e=>setNMedi(e.target.value)} />
                                                                            <label className="form-label text-form" style={{opacity: '0.5'}}>Nombre del medicamento</label>
                                                                            <div className="invalid-feedback">Campo vacío</div>
                                                                            <div className="valid-feedback">Válido</div>
                                                                        </div>
                                                                    </div>
                                                                    <div className="col-6">
                                                                        <div className="form-floating mb-1">
                                                                            <input id="nombre" type="text" className="form-control" placeholder="Escriba su nombre(s)" required onChange={e=>setCantMedi(e.target.value)} />
                                                                            <label className="form-label text-form" style={{opacity: '0.5'}}>Cantidad... (Ejem: 15ml)</label>
                                                                            <div className="invalid-feedback">Campo vacío</div>
                                                                            <div className="valid-feedback">Válido</div>
                                                                        </div>
                                                                    </div>
                                                                </div>
                                                                <div className="row align-items-center justify-content-center m-1">
                                                                    <div className="col-6">
                                                                        <div className="form-floating mb-1">
                                                                            <input id="nombre" type="text" className="form-control" placeholder="Escriba su nombre(s)" required onChange={e=>setCFrec(e.target.value)} />
                                                                            <label className="form-label text-form" style={{opacity: '0.5'}}>Consumir cada... (Ejem: "2 días")</label>
                                                                            <div className="invalid-feedback">Campo vacío</div>
                                                                            <div className="valid-feedback">Válido</div>
                                                                        </div>
                                                                    </div>
                                                                    <div className="col-6">
                                                                        <div className="form-floating mb-1">
                                                                            <input id="nombre" type="text" className="form-control" placeholder="Escriba su nombre(s)" required onChange={e=>setCLim(e.target.value)} />
                                                                            <label className="form-label text-form" style={{opacity: '0.5'}}>Consumir hasta... (Ejem: 15 de Octubre)</label>
                                                                            <div className="invalid-feedback">Campo vacío</div>
                                                                            <div className="valid-feedback">Válido</div>
                                                                        </div>
                                                                    </div>
                                                                </div>
                                                                <div className="row align-items-center justify-content-center m-1">
                                                                <div className="col">
                                                                    <div className="form-floating mb-1">
                                                                        <input id="nombre" type="text" className="form-control" placeholder="Escriba su nombre(s)" required onChange={e=>setIndic(e.target.value)} />
                                                                        <label className="form-label text-form" style={{opacity: '0.5'}}>Indicaciones a seguir...</label>
                                                                        <div className="invalid-feedback">Campo vacío</div>
                                                                        <div className="valid-feedback">Válido</div>
                                                                    </div>
                                                                </div>
                                                                </div>
                                                            </div>
                                                    </Modal.Body>
                                                    <Modal.Footer>
                                                        <button type="submit" className="btn btn-primary">Enviar</button>
                                                    </Modal.Footer>
                                                </form>
                                            </Modal>
                                        </div>
                                    </div>
                                    <div className="card-footer">
                                        <small className="text-muted">Último cambio el {fyh[fyh.length - 1]}</small>
                                    </div>
                                </div>
                            </div>
                            <div className="col">
                                <div className="card effect">
                                    <h1 className="card-title text-center rounded-top fs-1 fw-bolder p-2">Datos de Presión Arterial</h1>
                                    <div className="card-body">
                                        <div className="row align-items-stretch justify-content-center mb-4">
                                            <Line data={{
                                                labels: fyh,
                                                datasets: [
                                                {
                                                    label: 'Presión Diastólica',
                                                    data: pD,
                                                    backgroundColor: [
                                                    'rgba(255, 99, 132, 0.2)'
                                                    ],
                                                    borderColor: [
                                                        'rgb(255, 99, 132)'
                                                    ],
                                                    borderWidth: 1
                                                },
                                                {
                                                    label: 'Presión Sistólica',
                                                    data: pS,
                                                    backgroundColor: [
                                                    'rgba(54, 162, 235, 0.2)'
                                                    ],
                                                    borderColor: [
                                                    'rgb(54, 162, 235)'
                                                    ],
                                                    borderWidth: 1
                                                },
                                                {
                                                    label: 'Pulsos',
                                                    data: pulsos,
                                                    backgroundColor: [
                                                    'rgba(75, 192, 192, 0.2)'
                                                    ],
                                                    borderColor: [
                                                    'rgb(75, 192, 192)'
                                                    ],
                                                    borderWidth: 1
                                                }
                                            ]
                                            }} />
                                        </div>
                                        <div className="row align-items-stretch justify-content-center">
                                            <img src={imgStatus(mEmocional[mEmocional.length - 1])} alt="" className="w-50 img-fluid mb-3"/>
                                        </div>
                                        <div className="d-grid gap-2 mt-3">
                                            <Button className="btn fst-italic btn-lg" variant="outline-primary" data-bs-toggle="modal" data-bs-target="#dataModal" type="button" onClick={handleShowModalTwo}>Más Información...</Button>
            
                                            <Modal centered show={modalState === "modal-two"} onHide={handleClose} size="lg">
                                                <Modal.Header closeButton>
                                                    <Modal.Title className="modal-title fs-1 fw-bold" style={{color: "#7A28FF"}}>Datos de Presión Arterial y Pulso</Modal.Title>
                                                </Modal.Header>
                                                <Modal.Body className="modal-body text-center">
                                                <div className="row align-items-stretch justify-content-center">
                                                    <Line data={{
                                                        labels: fyh,
                                                        datasets: [
                                                        {
                                                            label: 'Presión Diastólica',
                                                            data: pD,
                                                            backgroundColor: [
                                                            'rgba(255, 99, 132, 0.2)'
                                                            ],
                                                            borderColor: [
                                                                'rgb(255, 99, 132)'
                                                            ],
                                                            borderWidth: 1
                                                        },
                                                        {
                                                            label: 'Presión Sistólica',
                                                            data: pS,
                                                            backgroundColor: [
                                                            'rgba(54, 162, 235, 0.2)'
                                                            ],
                                                            borderColor: [
                                                            'rgb(54, 162, 235)'
                                                            ],
                                                            borderWidth: 1
                                                        },
                                                        {
                                                            label: 'Pulsos',
                                                            data: pulsos,
                                                            backgroundColor: [
                                                            'rgba(75, 192, 192, 0.2)'
                                                            ],
                                                            borderColor: [
                                                            'rgb(75, 192, 192)'
                                                            ],
                                                            borderWidth: 1
                                                        }
                                                    ]
                                                    }} />
                                                </div>
                                                <div className="mt-2">
                                                    <span className="fs-5 fw-bold text-start">Medidor emocional actual de presión arterial:</span>
                                                    <br></br>
                                                    <img src={imgStatus(mEmocional[mEmocional.length - 1])} alt="" className="img-fluid m-3" style={{width: "185px"}}/>
                                                    <br></br>
                                                    <span className="fs-5 fw-bold text-start">Realizó ejercicio durante la última toma: <span className="fw-normal">{hEjercicio}</span></span>
                                                    <br></br>
                                                    <span className="fs-5 fw-bold text-start">Comentarios del paciente: <span className="fw-normal">{comentarios}</span></span>
                                                </div>

                                                </Modal.Body>
                                                <Modal.Footer>
                                                    <Button variant="primary" onClick={handleClose}>Listo</Button>
                                                </Modal.Footer>
                                            </Modal>
                                        </div>
                                    </div>
                                    <div className="card-footer">
                                        <small className="text-muted">Último cambio el {fyh[fyh.length - 1]}</small>
                                    </div>
                                </div>
                            </div>
                            <div className="col">
                                <div className="card effect">
                                    <h1 className="card-title text-center rounded-top fs-1 fw-bolder p-2">Datos Semanales</h1>
                                    <div className="card-body">
                                        <div className="row align-items-stretch justify-content-center mb-4">
                                            <Bar data={{
                                                    labels: ['Medidor Alimentacion', 'Medidor Ejercicio', 'Medidor Emocional'],
                                                    datasets: [
                                                    {
                                                        label: 'Medidores de Salud',
                                                        data: [medAlimentacion[medAlimentacion.length - 1], medEjercicio[medEjercicio.length - 1], medEmocional[medEmocional.length - 1]],
                                                        backgroundColor: [
                                                        'rgba(75, 192, 192, 0.2)',
                                                        'rgba(54, 162, 235, 0.2)',
                                                        'rgba(153, 102, 255, 0.2)'
                                                        ],
                                                        borderColor: [
                                                            'rgba(75, 192, 192, 0.2)',
                                                            'rgba(54, 162, 235, 0.2)',
                                                            'rgba(153, 102, 255, 0.2)'
                                                        ],
                                                        borderWidth: 1
                                                    }
                                                    ]
                                                }} />
                                        </div>
                                        <div className="row align-items-stretch justify-content-center">
                                            <img src={imgStatus(medEmocional[medEmocional.length - 1])} alt="" className="w-50 img-fluid mb-3"/>
                                        </div>
                                        <div className="d-grid gap-2 mt-3">
                                            <Button className="btn fst-italic btn-lg" variant="outline-primary" data-bs-toggle="modal" data-bs-target="#dataModal" type="button" onClick={handleShowModalThree}>Más Información...</Button>
            
                                            <Modal centered show={modalState === "modal-three"} onHide={handleClose} size="lg">
                                                <Modal.Header closeButton>
                                                    <Modal.Title className="modal-title fs-1 fw-bold" style={{color: "#7A28FF"}}>Datos de Encuesta Semanal</Modal.Title>
                                                </Modal.Header>
                                                <div className="text-center">
                                                    <span className="fs-5 fw-bold">Mediciones de encuesta semanal actuales:</span>
                                                </div>
                                                <Modal.Body className="modal-body text-center">
                                                <div className="row align-items-stretch justify-content-center">
                                                    <Bar data={{
                                                        labels: ['Medidor Alimentacion', 'Medidor Ejercicio', 'Medidor Emocional'],
                                                        datasets: [
                                                        {
                                                            label: 'Medidores de Salud',
                                                            data: [medAlimentacion[medAlimentacion.length - 1], medEjercicio[medEjercicio.length - 1], medEmocional[medEmocional.length - 1]],
                                                            backgroundColor: [
                                                            'rgba(75, 192, 192, 0.2)',
                                                            'rgba(54, 162, 235, 0.2)',
                                                            'rgba(153, 102, 255, 0.2)'
                                                            ],
                                                            borderColor: [
                                                                'rgba(75, 192, 192, 0.2)',
                                                                'rgba(54, 162, 235, 0.2)',
                                                                'rgba(153, 102, 255, 0.2)'
                                                            ],
                                                            borderWidth: 1
                                                        }
                                                        ]
                                                    }} />
                                                </div>
                                                <div className="mt-2">
                                                    <span className="fs-5 fw-bold text-start">Medidor emocional de encuesta semanal actual:</span>
                                                    <br></br>
                                                    <img src={imgStatus(medEmocional[medEmocional.length - 1])} alt="" className="img-fluid m-3" style={{width: "185px"}}/>
                                                </div>
                                                </Modal.Body>
                                                <Modal.Footer>
                                                    <Button variant="primary" onClick={handleClose}>Listo</Button>
                                                </Modal.Footer>
                                            </Modal>
                                        </div>
                                    </div>
                                    <div className="card-footer">
                                        <small className="text-muted">Último cambio el {fechaCuestionario}</small>
                                    </div>
                                </div>
                            </div>
                        </div>
                    </div>
                )
            }
        })}
    </div>
    )
}

export default Page2