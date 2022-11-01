<template>
  <h1 class="h1"> Carrito</h1>
  <div class="menu">
    <div class="carrito">
      <Block class="block" placeholder="Email">
        <div class="producto">
          <img src="../assets/img/lysol.webp" class="foto">
          <p class="articulo"> Pack Lysol toallits desinfectantes citrus de 35 pzas </p>
          <p class="precio"> $9.99 </p>
        </div>
        <div class="producto">
          <img src="../assets/img/lysol.webp" class="foto">
          <p class="articulo"> Producto 2 </p>
          <p class="precio"> $9.99 </p>
        </div>
        <div class="producto">
          <img src="../assets/img/lysol.webp" class="foto">
          <p class="articulo"> Producto 3 </p>
          <p class="precio"> $9.99 </p>
        </div>
      </Block>
    </div>
  <div class="checkout">
    <p class="h2"> Checkout </p>
    <p class="articulo"> Total: </p>
    <p class="precio-final"> $30.00 </p>
    <button class="boton"> Comprar </button>
  </div>
  </div>
</template>

<script>
  import { db } from '../firebase'
  import { getDocs, collection } from 'firebase/firestore'

  export default {
      name: "login"
  }
</script>

<style scoped>
  .menu {
        display: flex;
        flex-direction: row;
        justify-content: center;
        align-items: center;
    }
  .carrito {
      display: flex;
      flex-direction: column;
      padding: 10px;
      justify-content: center;
      align-items: center;
  }
  h1 {
      font-weight: 500px;
      text-align: center;
      margin-top: 20px;
  }
  .block {
      display: flex;
      flex-direction: column;
      width: 800px;
      padding: 50px;
      background-color: #fafafa;
      margin-top: 30px;
      border-radius: 10px;
      box-shadow: rgba(50, 50, 93, 0.25) 0px 2px 5px -1px, rgba(0, 0, 0, 0.3) 0px 1px 3px -1px;
  }
  .producto {
    display: flex;
    flex-direction: row;
    background-color: white;
    padding-bottom: 10px;
    border-radius: 10px;
    margin-bottom: 10px;
  }
  .foto {
      width: 150px;
      height: 150px;
      border-radius: 5px;
      padding-top: 20px;
  }
  .articulo {
      width: 400px;
      height: 150px;
      padding-top: 70px;
      font-family: 'Helvetica';
      font-weight: 500;
      font-size: 20px;
      line-height: 20px;
      letter-spacing: -0.015em;
      color: #1E1E1E;
  }
  .precio {
      width: 8px;
      height: 50px;
      padding-top: 70px;
      padding-left: 40px;
      font-family: 'Helvetica';
      font-weight: 800;
      font-size: 20px;
      line-height: 20px;
      letter-spacing: -0.015em;
      color: #1E1E1E;
  }
  .checkout {
      display: flex;
      flex-direction: column;
      width: 300px;
      height: 400px;
      padding: 10px;
      background-color: #cccccc;
      border-radius: 10px;
      box-shadow: rgba(50, 50, 93, 0.25) 0px 2px 5px -1px, rgba(0, 0, 0, 0.3) 0px 1px 3px -1px;
  }
  .boton {
      width: 250px;
      color: white;
      background-color: #2d69ca;
      border-radius: 5px;
      font-size: 25px;
      border: none;
      font-family: sans-serif;
  }
  .h2 {
      color: #1E1E1E;
      align-items: center;
      justify-content: center;
  }
  .precio-final {
      font-family: 'Helvetica';
      font-weight: 800;
      font-size: 20px;
      line-height: 20px;
      letter-spacing: -0.015em;
      color: #1E1E1E;
  }
</style>
