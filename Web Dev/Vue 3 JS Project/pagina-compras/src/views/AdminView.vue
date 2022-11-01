<template>
    <div>
        <div class = "container">
            <div class = "row">
                <h2 class="px-5 py-4" style="text-align:center"> Productos </h2>
                <div class="d-grid gap-2 d-md-flex justify-content-md-end">
                        <a  class = "btn btn-success" href="/add-item"> Añadir producto nuevo </a>
                </div>
                <div class="col-md-6 offset-md-3">
                    <ul class="list-group">
                    <li v-for="product in products" :key = "product.id"
                    class="list-group-item d-flex justify-content-between align-items-center">
                        {{product.nombre}}
                        <span class="badge badge-primary badge-pill">
                            <router-link 
                            :to="{path: `/products/${product.id}` }"
                            class = "btn btn-primary"
                            > Editar </router-link
                            >
                            <a href="#" class = "btn btn-danger" @click="deleteItem(product.id)"> Eliminar </a>
                        </span>
                    </li>
                    </ul>
                </div>
            </div>
        </div>
    </div>
</template>

<script>
import productsCollection from '../firebase';
import {getDocs, doc, deleteDoc} from 'firebase/firestore';
export default {
    data() {
        return {
            products: [],
            selectedDoc: null,
        }
    },
    methods:{
        async fetchProducts(){
            let productsSnapShot = await getDocs(productsCollection);
            let products = [];
            products = productsSnapShot.forEach(doc => {
                let product = doc.data();
                    product.id = doc.id;
                    this.products.push(product);
                    console.log(product);
            })
        },
        async deleteItem(id){
            let productRef = doc(productsCollection, id);
            await deleteDoc(productRef);
            alert('El producto ha sido eliminado correctamente');
            this.$router.go();

        }
    },
    created() {
        this.fetchProducts();
    },
}
</script>