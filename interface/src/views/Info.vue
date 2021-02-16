<template>
  <div id="info">
    <div class="cells">
      <div class="cell">
        Stat
      </div>
      <div class="cell">
        <DvicMap />
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
  justify-items: center;
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
  background-color: white;
}

.info__cta-manual {
  display: inline-block;
  margin: 0.5em 0;
  padding: 1em 2em;
  background: #fff;
  border: 2px solid orange;
  border-radius: 3px;
  color: orange;
  font-family: "Quicksand", sans-serif;
  font-size: 1em;
  font-weight: 700;
  letter-spacing: 0.02em;
  line-height: 1;
  text-decoration: none;
  text-transform: uppercase;
  cursor: pointer;
  transition: 0.3s;
}

.info__cta-stop {
  /* color: red !important;
  text-transform: uppercase;
  position: relative;
  top: 300px;
  right: 100px;
  background: #ffffff;
  padding: 100px;
  border: 7px solid red !important;
  border-radius: 10px;
  display: inline-block;
  transition: all 0.3s ease 0s; */
  display: inline-block;
  margin: 0.5em 0;
  padding: 1em 2em;
  background: #fff;
  border: 2px solid tomato;
  border-radius: 3px;
  color: tomato;
  font-family: "Quicksand", sans-serif;
  font-size: 1em;
  font-weight: 700;
  letter-spacing: 0.02em;
  line-height: 1;
  text-decoration: none;
  text-transform: uppercase;
  cursor: pointer;
  transition: 0.3s;
}
</style>
