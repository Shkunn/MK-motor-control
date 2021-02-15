<template>
  <div id="about">
    <div class="map__head">
      <img alt="Vue logo" class="logo" src="@/assets/logo.png">
      <h1 class="map__title">4th floor navigation</h1>
    </div>
    <DvicMap />
   <div class="button-return">
     <button type="button" name="return_button" class="modal__return_button" v-on:click="return_button()" v-if="showReturn">Return</button>
   </div>
  </div>
</template>
<script>
export default {
  name: "Map",
  data: () => ({
    showReturn: true,
  }),
  methods: {
    return_button: function () {
      // alert(coordinates)
      this.$router.push('/')
      this.$route.params.pathMatch
    }
  }
}
</script>
<style scoped>
.modal__close {
  position: absolute;
  right: 20px;
  font-size: 3em;
}
.modal__title {
  margin-top: 100px;
  font-size: 5em;
  font-weight: bold;
}
.modal__description {
  margin-top: 50px;
  margin-left: 100px;
  margin-right: 100px;
}
.modal-keypoint {
  z-index: 1000;
  position: absolute;
  top: 20px;
  bottom: 20px;
  left: 20px;
  right: 20px;
  width: auto;
  height: auto;
  background-color: rgba(0,0,0,0.8);
  color: white;
}
.button-return {
  z-index: 1000;
  position: absolute;
  top: 50px;
  bottom: 20px;
  right: 100px;
  width: auto;
  height: auto;
  background-color: rgba(0,0,0,0);
}
.modal__button {
  margin-top: 50px;
}
.modal__return_button{
  margin-top: 50px;
}
.map__head {
  display: flex;
  justify-content: center;
  align-items: center;
}
.map__title {
  font-size: 5em;
  color: #f07b4b;
}

@media screen and (max-width: 640px) {
  .title {
    font-size: 1.5em;
  }
}

</style>
