<template>
    <div>
        <div class = "container">
            <div class = "row">
                <div class="col-md-6 offset-md 3">
                    <h2>Editar el producto</h2>
                    <form @submit.prevent="updateItem">
                    <div class="form-group">
                        <input 
                        type="text" 
                        class="form-control" 
                        placeholder="Nombre"
                        v-model = "productInfo.nombre">
                    </div>
                    <div class="form-group">
                        <input 
                        type="number" 
                        step="any"
                        class="form-control" 
                        placeholder="Precio"
                        v-model = "productInfo.precio">
                    </div>
                    <div class="form-group">
                        <input 
                        type="url" 
                        class="form-control" 
                        placeholder="Url de la imagen"
                        v-model="productInfo.urlImg">
                    </div>
                    <button class="btn btn-primary"> Actualizar Objeto </button>
                    </form>
                </div>
            </div>
        </div>
    </div>
</template>

<script>
import productsCollection from '../firebase';
import {getDoc, doc, setDoc} from 'firebase/firestore'
export default {
    data() {
        return {
            selectedProduct: {},
            id: null,
            docRef: null,
            productInfo:{
                nombre: null,
                precio: null,
                uid: null,
                urlImg: null,
            }
        }
    },

    methods:{
        async getProduct(){
            let productRef = doc(productsCollection, this.id);
            this.docRef = productRef;
            let product = await getDoc(this.docRef);
            let productData = product.data();
            this.productInfo.nombre = productData.nombre;
            this.productInfo.precio = productData.precio;
            this.productInfo.uid = this.id;
            this.productInfo.urlImg = productData.urlImg;
        },
        async updateItem(){
            await setDoc(this.docRef, this.productInfo);
            alert(
                `El producto con el ID ${this.id} ha sido actualizado` 
            );
            this.$router.push("/admin");
        }
    },

    created(){
        let id = this.$route.params.id;
        this.id = id;
        this.getProduct();
    }
}

</script>

<style>

</style>