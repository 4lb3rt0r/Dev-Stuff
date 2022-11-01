<template>
    <div class="container p-5 login align-items-center">
        <h1 class="h1 p-4 text-center">Iniciar Sesión</h1>
        <form @submit.prevent="login( this.email, this.password )">
            <div class="form-floating mb-3">
                <input v-model="email" type="email" class="form-control" placeholder="Escriba su correo electrónico" required="true"/>
                <label class="form-label text-form">Correo Electrónico</label>
            </div>
            <div class="form-floating mb-3">
                <input v-model="password" type="password" class="form-control" placeholder="Escriba su contraseña" required="true"/>
                <label class="form-label text-form">Contraseña</label>
            </div>
            <button type="submit" class="btn btn-primary btn-lg w-100 mb-2 text-form">Iniciar Sesión</button>
            <div className="my-3 text-center">
                <span className="text-form">¿No tienes cuenta? <a href="/register">Regístrate aquí</a> </span>
            </div>
        </form>
    </div>
</template>

<script>

    import { getAuth, signInWithEmailAndPassword } from "firebase/auth";

    export default {
        name: "LoginView",
        data() {
            return {
                email: '',
                password: '',
                errorMessage: ''
            }
        },
        methods: {
            login( email, password ) {
                const auth = getAuth();
                signInWithEmailAndPassword(auth, email, password)
                .then((userCredential) => {
                    alert('¡Sesión iniciada!');
                    // Signed in
                    const user = userCredential.user;
                    this.$router.push('/') 
                    // ...
                    // console.log(user.uid);

                })
                .catch((error) => {
                    const errorCode = error.code;
                    this.errorMessage = error.message;
                    alert(this.errorMessage);
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
</style>