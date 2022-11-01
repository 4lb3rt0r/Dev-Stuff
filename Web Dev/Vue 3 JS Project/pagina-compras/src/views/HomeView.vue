<template>
  <div class="home">
    <Carousel/>

    <h1 class="px-5 py-4">Para tu despensa</h1>

    <Products/>
  </div> 
</template>


<script>
import Carousel from '../components/Carousel.vue'
import Products from '../components/Products.vue'

//@ is an alias to /src

export default {
  name: 'HomeView',
  components: { 
    Carousel,
    Products
  }
}
</script>