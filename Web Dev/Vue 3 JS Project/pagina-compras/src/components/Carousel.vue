<template>

    <div id="carouselExampleCaptions" class="carousel slide mt-4" data-bs-ride="false">
    <div class="carousel-indicators">
        <button type="button" data-bs-target="#carouselExampleCaptions" data-bs-slide-to="0" class="active" aria-current="true" aria-label="Slide 1"></button>
        <button type="button" data-bs-target="#carouselExampleCaptions" data-bs-slide-to="1" aria-label="Slide 2"></button>
        <button type="button" data-bs-target="#carouselExampleCaptions" data-bs-slide-to="2" aria-label="Slide 3"></button>
    </div>
    <div class="carousel-inner">
        <div class="carousel-item active">
        <img src="@/assets/img/slide01.svg" class="d-block w-100" alt="...">
        <div class="carousel-caption d-none d-md-block">
            <h5>Aprovecha los precios bajos</h5>
            <p>Válido para pedido y entrega del 16 al 31 de octubre de 2022</p>
        </div>
        </div>
        <div class="carousel-item">
        <img src="@/assets/img/slide02.svg" class="d-block w-100" alt="...">
        <div class="carousel-caption d-none d-md-block text-dark fw-bold">
            <h5>Nuevo mezcal artesanal añejo</h5>
            <p>EVITA EL EXCESO</p>
        </div>
        </div>
        <div class="carousel-item">
        <img src="@/assets/img/slide03.svg" class="d-block w-100" alt="...">
        <div class="carousel-caption d-none d-md-block">
            <h5>Bonificación de $100*</h5>
            <p>Para tu siguiente súper</p>
        </div>
        </div>
    </div>
    <button class="carousel-control-prev" type="button" data-bs-target="#carouselExampleCaptions" data-bs-slide="prev">
        <span class="carousel-control-prev-icon" aria-hidden="true"></span>
        <span class="visually-hidden">Previous</span>
    </button>
    <button class="carousel-control-next" type="button" data-bs-target="#carouselExampleCaptions" data-bs-slide="next">
        <span class="carousel-control-next-icon" aria-hidden="true"></span>
        <span class="visually-hidden">Next</span>
    </button>
    </div>
</template>

<script>
    export default {
        name: "Carousel"
    }
</script>

<style scoped>
</style>