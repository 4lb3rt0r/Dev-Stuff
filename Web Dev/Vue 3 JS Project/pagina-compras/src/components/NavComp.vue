<template>
    <nav class="navbar navbar-expand-lg">
        <div class="container-fluid m-1">
            <RouterLink to="/" class="navbar-brand">
                <img class="logo" src="@/assets/img/logo.svg" alt="Walmart">
            </RouterLink>
            <div class="row">
                <div class="col">
                    <RouterLink to="/" class="nav-link active" aria-current="page" >
                        <span class="material-icons">
                            home
                        </span>
                    </RouterLink>
                </div>
                <div class="col">
                    <RouterLink to="/shopping-cart" class="nav-link">
                        <span class="material-icons">
                            shopping_cart
                        </span>
                    </RouterLink>
                </div>
                <div class="col">
                    <div class="nav-item dropdown">
                        <a class="nav-link dropdown-toggle" href="#" role="button" data-bs-toggle="dropdown" aria-expanded="false">
                            <span class="material-icons">
                                person
                            </span>
                        </a>
                        <ul class="dropdown-menu dropdown-menu-end justify-content-center">
                            <RouterLink to="/login" class="nav-link">
                                <li><a class="dropdown-item text-danger fw-semibold" href="#" @click="signout">
                                    <img src="@/assets/img/log-out.svg" className="img-thumbail mx-1" alt="..."/>
                                    Cerrar Sesión
                                </a></li>
                            </RouterLink>
                        </ul>
                    </div>
                    <RouterLink to="/login" class="nav-link">

                    </RouterLink>
                </div>
            </div>
        </div>
    </nav>
</template>

<script>

    import { getAuth, signOut } from "firebase/auth";

    export default {
        name: "NavComp",

        methods: {
            signout () {
                const auth = getAuth();
                signOut(auth).then(() => {
                    alert('¡Sesión cerrada! Inicia sesión.');
                }).catch((error) => {
                    console.log("error al cerrar sesión")
                });
            }
        }
    }
</script>

<style scoped>
    .material-icons {
        color: white;
        background-color: rgba(218, 218, 218, 0.158);
        padding: 0.3em;
        border-radius: 50%;
        margin: 0.1em;
    }

    .img-thumbail {
        width: 15%;
    }
</style>