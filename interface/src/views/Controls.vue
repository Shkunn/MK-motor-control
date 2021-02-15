<template>
  <div id="info">
    <div class="cells">
      <div class="cell">
        Stat
      </div>
      <div class="cell">
        MAP
      </div>
      <div class="cell">
        <button v-on:click="manual()" class="info__cta-manual">MANUAL MODE</button>
        <button v-on:click="stop()" class="info__cta-stop">STOP</button>
      </div>
      <div class="cell">
        CAMERA VIEW
      </div>
    </div>
    <div class="button-return">
     <button type="button" name="return_button" class="modal__return_button" v-on:click="return_button()">Return</button>
   </div>
  </div>
</template>
<script>
const Http = new XMLHttpRequest();
const SERVER = "127.0.0.1:5000"

export default {
  name: "Info",
  data: () => ({

  }),
  methods: {
    return_button: function () {
      // alert(coordinates)
      this.$router.push('/navigation')
      this.$route.params.pathMatch
    },
    manual: function () {
      this.$router.push('/manual')
      this.$route.params.pathMatch
    },
    stop: function (coordinates) {
      const url = "http:" + SERVER + "/navigation/" + coordinates;
      Http.open("GET", url);
      Http.send();
      //this.$router.push('/info')
      //this.$route.params.pathMatch
    }
  }
}

</script>
<style scoped>
#info {
  color: white;
}

.cells {
  display: grid;
  grid-template-columns: repeat(2, 1fr);
  grid-gap: 0;
}

.cell {
  height: 50vh;
}

.button-return {
  z-index: 1000;
  position: absolute;
  top: 50px;
  bottom: 20px;
  right: 100px;
  width: auto;
  height: auto;
}

.modal__return_button {
  background-color: orange;
}

.info__cta-manual {
  background-color: purple;
}

.info__cta-stop {
  background-color: red;
  margin-left: 30px;
}
</style>
