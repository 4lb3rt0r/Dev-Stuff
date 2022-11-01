<template>
    <div class="container p-5 login align-items-center">
        <h1 class="h1 p-4 text-center">Regístrate</h1>
        <form @submit.prevent="register( this.name, this.lastName, this.email, this.password, this.repassword )">
            <div className="row mb-3">
                <div className="col-6">
                    <div className="form-floating">
                        <input v-model="name" id="nombre" type="text" className="form-control" name="firstname" placeholder="Escriba su nombre(s)" required="true"/>
                        <label className="form-label text-form">Nombre(s)</label>
                        <div className="invalid-feedback">Campo vacío</div>
                        <div className="valid-feedback">Válido</div>
                    </div>
                </div>
                <div className="col-6">
                    <div className="form-floating">
                        <input v-model="lastName" id="apellidoPaterno" type="text" className="form-control" name="lastname" placeholder="Escriba su apellido parterno" required="true"/>
                        <label className="form-label text-form" >Apellido</label>
                        <div className="invalid-feedback">Campo vacío</div>
                        <div className="valid-feedback">Válido</div>
                    </div>
                </div>
            </div>
            <div class="form-floating mb-3">
                <input v-model="email" type="email" class="form-control" placeholder="Escriba su correo electrónico" required="true"/>
                <label class="form-label text-form">Correo electrónico</label>
            </div>
            <div class="form-floating mb-3">
                <input v-model="password" type="password" class="form-control" placeholder="Escriba su contraseña" required="true"/>
                <label class="form-label text-form">Contraseña</label>
            </div>
            <div class="form-floating mb-3">
                <input v-model="repassword" type="password" class="form-control" placeholder="Confirme su contraseña" required="true"/>
                <label class="form-label text-form">Confirmar contraseña</label>
            </div>
            <button type="submit" class="btn btn-primary btn-lg w-100 mb-2 text-form">Regístrate Aquí</button>
            <div className="my-3 text-center">
                <span className="text-form fs-6">¿Ya tienes cuenta? <a href="/login">Inicia sesión</a> </span>
            </div>
        </form>
    </div>
</template>

<script>

    import { getAuth, createUserWithEmailAndPassword } from "firebase/auth";
    import { doc, setDoc } from "firebase/firestore";
    import { db } from '@/firebase.js'

    export default {
        name: "LoginView",
        data() {
            return {
                name: '',
                lastName: '',
                email: '',
                list: [],
                password: '',
                repassword: '',
                errorMessage: ''
            }
        },
        methods: {
            register(name, lastName, email, password, repassword) {
                if (password !== repassword) {
                    alert("Las constraseñas no coinciden :/");
                }
                else {
                    const auth = getAuth();
                    createUserWithEmailAndPassword(auth, email, password)
                    .then((userCredential) => {
                        const user = userCredential.user;
                        this.addData(name, lastName, user.uid);
                        alert('¡Registrado!');
                        this.$router.push('/login')
                    })
                    .catch((error) => {
                        const errorCode = error.code;
                        this.errorMessage = error.message;
                        alert(this.errorMessage);
                        // ..
                    });
                }
            },
            async addData(name, lastName, uid) {
                const docRef = await setDoc(doc(db, "users", uid), {
                    nombre: name,
                    apellido: lastName,
                    lista: []
                })
                .then(() => {
                    console.log("Documento añadido");
                })
                .catch(function(error) {
                    console.error("Error al añadir el documento: ", error);
                });
            }
        }
    }
</script>
  
<style scoped>

    h1 {
        font-weight: 500px;
    }
    .login {
        margin-top: 85px;
    }
    .form-control {
        opacity: '0.5';
    }
</style>