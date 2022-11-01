<script setup>
import { RouterLink, RouterView } from 'vue-router'
</script>

<template>
  <NavComp/>
  <header>
    <div class="wrapper">
    </div>
  </header>

  <RouterView />
</template>

<script>
import NavComp from "../src/components/NavComp.vue"
export default {
  name: "App",
  components: {
    NavComp
  }
}
</script>

<style>

</style>
