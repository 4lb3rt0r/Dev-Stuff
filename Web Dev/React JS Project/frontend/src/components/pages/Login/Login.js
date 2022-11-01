import React, { useState, useContext } from 'react';
import { signInWithEmailAndPassword  } from 'firebase/auth'
import { auth } from "../../../firebase-config"
import { useNavigate } from 'react-router-dom'
import { AuthContext } from "../../../context/AuthContext"
import { Alert } from 'react-bootstrap';

// Importación de imágenes jpg, png y svg

// Importación de estilos
import './Login.css'

function Login() {

    const [error, setError] = useState("");
    const [email, setEmail] = useState("");
    const [password, setPassword] = useState("");

    const navigate = useNavigate()

    const {dispatch} = useContext(AuthContext)

    const handleLogin = (e) => {
        e.preventDefault();

        signInWithEmailAndPassword(auth, email, password)
        .then((userCredential) => {
            // Signed in
            const user = userCredential.user;
            dispatch({type: "LOGIN", payload:user})
            navigate("/")
        })
        .catch((error) => {
            setError("El correo o contraseña no coinciden")
        });
    }

    return (
    <div className="container w-80 bg-primary mt-4 mb-3 rounded shadow">
        <div className="row align-items-stretch">
            <div className="col rounded-start p-5 pb-3" style={{backgroundColor: '#C6D0F2'}}>
                <div className="text-center mb-5">
                    <h3 className="page-title1">Bienvenido a</h3>
                    <h1 className="page-title2">Salud - OS</h1>
                    <h2 className="page-title3">¡Te Saluda!</h2>
                </div>

                {error && <Alert variant="danger" className="fw-bold text-danger">{error}</Alert>}

                <form onSubmit={handleLogin}>
                    <div className="form-floating mb-3">
                        <input type="email" onChange={e=>setEmail(e.target.value)}  className="form-control" placeholder="Escriba su correo electrónico" required/>
                        <label className="form-label text-form" style={{opacity: '0.5'}}>Correo Electrónico</label>
                    </div>
                    <div className="form-floating mb-0">
                        <input type="password" onChange={e=>setPassword(e.target.value)} className="form-control" placeholder="Escriba su contraseña" required/>
                        <label className="form-label text-form" style={{opacity: '0.5'}}>Contraseña</label>
                    </div>
                    <div className="form-check form-check form-check-inline my-2">
                        <input type="checkbox" id="email" className="form-check-input"/>
                        <label className="form-check-label text-form">Recuérdame</label>
                    </div>
                    <div className="my-3">
                        <span><a className="text-form" href="/#">¿Olvidaste tu contraseña?</a></span>
                    </div>
                    <button type="submit" className="btn btn-primary btn-lg w-100 mb-2 text-form">Iniciar Sesión</button>
                    <div className="my-1">
                        <span className="text-form">¿No tienes cuenta? <a href="/register">Regístrate aquí</a> </span>
                    </div>
                </form>
                
            </div>

            <div className="col bg d-none d-lg-block col-md-5 col-lg-5 col-xl-6 rounded-end">

            </div>

        </div>
    </div>
    /* <script>
        const form = document.querySelector("form")

        form.addEventListener('submit', e => {
            if (!form.checkValidity()) {
                e.preventDefault()
            }

            form.classNameNameList.add('was-validated')
        })
    </script> */
    )
}

export default Login