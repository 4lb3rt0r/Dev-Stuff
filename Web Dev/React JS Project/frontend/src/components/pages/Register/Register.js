import React, { useState } from 'react';
import { doc, setDoc } from "firebase/firestore";
import { auth, db } from "../../../firebase-config"
import { createUserWithEmailAndPassword } from "firebase/auth";
import { Alert, Modal, Button} from 'react-bootstrap';
import { useNavigate } from 'react-router-dom'

// Importación de imágenes jpg, png y svg

// Importación de estilos
import './Register.css'

function Register () {

    const [error, setError] = useState("");
    const [loading, setLoading] = useState(false);
    const [show, setShow] = useState(false);

    const [nombre, setNombre] = useState("");
    const [aPaterno, setAPaterno] = useState("");
    const [aMaterno, setAMaterno] = useState("");
    const [email, setEmail] = useState("");
    const [especialidad, setEspecialidad] = useState("");
    const [cedulaProfesional, setCedulaProfesional] = useState("");
    const [password, setPassword] = useState("");
    const [cPassword, setCPassword] = useState("");

    const navigate = useNavigate();

    const handleClose = () => {
        setShow(false)
        navigate("/login")
    };

    const createUser = async (e) => {
        e.preventDefault();

        if (password !== cPassword) {
            return setError("Las contraseñas no coinciden")
        }

        try {
            setError("")
            setLoading(true)
            const res = await createUserWithEmailAndPassword(auth, email, password);
            await setDoc(doc(db, "Medico", res.user.uid), { nombrePila: nombre, apellidoPaterno: aPaterno, apellidoMaterno: aMaterno, titulo: especialidad, cedulaProfesional: cedulaProfesional, uid: res.user.uid});
            setShow(true);
        }
        catch {
            
            setError("Error al crear la cuenta")
        }
        setLoading(false)
    };

    return (
    <div className="container w-80 bg-primary mt-4 mb-3 rounded shadow">
        <div className="row align-items-stretch">
            <div className="col rounded-start p-5 pt-3 pb-3" style={{backgroundColor: '#C6D0F2'}}>
                <div className="text-center mb-4">
                    <h3 className="page-title">Bienvenido a</h3>
                    <h1 className="page-title">Salud - OS</h1>
                    <h2 className="page-title">¡Te Saluda!</h2>
                </div>
                <div>
                    {error && <Alert variant="danger" className="fw-bold text-danger">{error}</Alert>}
                </div>
                <form onSubmit={createUser}>
                    <div className="form-group">
                        <div className="row">
                            <div className="col-6">
                                <div className="form-floating mb-1">
                                    <input id="nombre" type="text" className="form-control" name="firstname" placeholder="Escriba su nombre(s)" required onChange={e=>setNombre(e.target.value)}/>
                                    <label className="form-label text-form" style={{opacity: '0.5'}}>Nombre(s)</label>
                                    <div className="invalid-feedback">Campo vacío</div>
                                    <div className="valid-feedback">Válido</div>
                                </div>
                            </div>
                            <div className="col-6">
                                <div className="form-floating mb-2">
                                    <input id="apellidoPaterno" type="text" className="form-control" name="lastname" placeholder="Escriba su apellido parterno" required onChange={e=>setAPaterno(e.target.value)}/>
                                    <label className="form-label text-form" style={{opacity: '0.5'}}>Apellido Paterno</label>
                                    <div className="invalid-feedback">Campo vacío</div>
                                    <div className="valid-feedback">Válido</div>
                                </div>
                            </div>
                        </div>
                        <div className="row">
                            <div className="col-6">
                                <div className="form-floating mb-3">
                                    <input id="apellidoMaterno" type="text" className="form-control" name="lastname" placeholder="Escriba su apellido materno" required onChange={e=>setAMaterno(e.target.value)}/>
                                    <label className="form-label text-form" style={{opacity: '0.5'}}>Apellido Materno</label>
                                    <div className="invalid-feedback">Campo vacío</div>
                                    <div className="valid-feedback">Válido</div>
                                </div>
                            </div>
                        </div>
                    </div>
                    <div className="form-floating mb-2">
                        <input id="correo" type="email" className="form-control" placeholder="Escriba su correo electrónico" required onChange={e=>setEmail(e.target.value)}/>
                        <label className="form-label text-form" style={{opacity: '0.5'}}>Correo Electrónico</label>
                        <div className="invalid-feedback">Correo inválido</div>
                        <div className="valid-feedback">Correo válido</div>
                    </div>
                    <div className="row">
                        <div className="col-6">
                            <div className="form-floating mb-3">
                                <input id="especialidad" type="text" className="form-control" placeholder="Escriba su cédula profesional" required onChange={e=>setEspecialidad(e.target.value)}/>
                                <label className="form-label text-form" style={{opacity: '0.5'}}>Especialidad</label>
                                <div className="invalid-feedback">Campo vacío</div>
                                <div className="valid-feedback">Válido</div>
                            </div>
                        </div>
                        <div className="col-6">
                            <div className="form-floating mb-3">
                                <input id="cedulaProfesional" type="password" className="form-control" placeholder="Escriba su cédula profesional" required onChange={e=>setCedulaProfesional(e.target.value)}/>
                                <label className="form-label text-form" style={{opacity: '0.5'}}>Cédula Profesional</label>
                                <div className="invalid-feedback">Campo vacío</div>
                                <div className="valid-feedback">Válido</div>
                            </div>
                        </div>
                    </div>
                    <div className="form-floating">
                        <input type="password" className="form-control" placeholder="Escriba su contraseña" required onChange={e=>setPassword(e.target.value)}/>
                        <label className="form-label text-form" style={{opacity: '0.5'}}>Contraseña</label>
                        <div className="invalid-feedback">Contraseña Inválida</div>
                        <div className="valid-feedback">Contraseña válida</div>
                    </div>
                    <div className="col-auto mb-1">
                        <span id="passwordHelpInLine" className="form-text">Debe ser entre 6 a 20 caracteres</span>
                    </div>
                    <div className="form-floating mb-3">
                        <input type="password" className="form-control" placeholder="Escriba nuevamente su contraseña" required onChange={e=>setCPassword(e.target.value)}/>
                        <label className="form-label text-form" style={{opacity: '0.5'}}>Confirmar Contraseña</label>
                        <div className="invalid-feedback">Contraseña Inválida</div>
                        <div className="valid-feedback">Contraseña válida</div>
                    </div>
                    <button disabled={loading} type="submit" className="btn btn-primary btn-lg w-100 text-form mb-2">Registrarte</button>
                    <span className="text-form fs-6">¿Ya tienes cuenta? <a href="/login">Inicia sesión</a> </span>
                </form>
            </div>

            <div className="col bg d-none d-lg-block col-md-5 col-lg-5 col-xl-6 rounded-end">

            </div>
        </div>
        <Modal centered backdrop="static" show={show}>
            <Modal.Header>
                <Modal.Title className="modal-title">
                    <span className="fs-2 fw-bold text-success">Cuenta creada con éxito</span>
                </Modal.Title>
            </Modal.Header>
            <Modal.Body className="modal-body text-center m-3">
                <img className="p-0 effect-btn" href="" src="./images/user-check.png" width="250" alt="bell"/>
            </Modal.Body>
            <Modal.Footer>
                <Button variant="outline-success" onClick={handleClose}>Aceptar</Button>
            </Modal.Footer>
        </Modal>
    </div>
    )
}

export default Register