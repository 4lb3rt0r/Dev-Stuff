<template>
        <div class="container">
            <div class="row mx-1 justify-content-center">
                <div class="col px-1 mb-3" v-for="product in products" :key="product.id">
                    <div class="card" style="width: 14rem;">
                        <img :src=product.urlImg class="card-img-top" alt="...">
                        <div class="card-body">
                            <h5 class="card-title">{{product.nombre}}</h5>
                            <p class="card-text">Precio: $ {{product.precio}}</p>
                            <button href="#" class="btn btn-primary">Añadir al carrito</button>
                        </div>
                    </div>
                </div>
            </div>
        </div>
</template>

<script>
    import { db, auth } from '../firebase';
    import { getDocs, collection } from 'firebase/firestore';
    import { onAuthStateChanged } from "firebase/auth";

    export default {
        name: "Products",
        components: {},
        data() {
            return {
                products: [],
                product: {
                    nombre: '',
                    precio: '',
                    urlImg: '',
                    uid: ''
                }
            }
        },
        methods: {
            async fetchProducts() {
                let querySnapshot  = await getDocs(collection(db, "products"));
                querySnapshot.forEach((doc) => {
                    let product = doc.data();
                    product.id = doc.id;
                    this.products.push(product);
                    // console.log(product);
                });
            }
        },
        mounted() {
            this.fetchProducts();
        },
    };
</script>

<style>
</style>