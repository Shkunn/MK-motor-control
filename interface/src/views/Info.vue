<template>
  <div id="info">
    <div class="cells">
      <div class="cell">
        Stat
      </div>
      <div class="cell">
        <DviclittleMap />
      </div>
      <div class="cell cell-ctas">
        <button v-on:click="manual()" class="info__cta-manual">MANUAL MODE</button>
        <button v-on:click="stop('stop')" class="info__cta-stop">STOP</button>
      </div>      
      <div class="cell">
        CAMERA VIEW
      </div>
    </div>
    <div class="modal-keypoint" v-if="show">
      <div class="controls">
        <div id="UP" v-on:mousedown="control('up')" v-on:mouseup="control('close')" class="control"></div>
        <div id="LEFT" v-on:mousedown="control('left')" v-on:mouseup="control('close')" class="control"></div>
        <div id="RIGHT" v-on:mousedown="control('right')" v-on:mouseup="control('close')" class="control"></div>
        <div id="DOWN" v-on:mousedown="control('down')" v-on:mouseup="control('close')" class="control"></div>
      </div>
      <span v-on:click="hideModal()" class="modal__close">x</span>
      <div class="modal__title">
       {{ modal.title }}
      </div>
      <div class="modal__description">
        {{ modal.description }}
      </div>
      <!-- <button type="button" name="button" class="modal__button" v-on:click="navigation(modal.id)" v-if="modal.id != 'robot'">Go To</button> -->
    </div>
    <div class="button-return">
     <button type="button" name="return_button" class="modal__return_button" v-on:click="return_button()">Return</button>
   </div>
  </div>
</template>
<script>

export default {
  name: "Info",
  data: () => ({
    show: false,
    modal: {
      title: '',
      description: '',
    }
  }),
  methods: {
    return_button: function () {
      // alert(coordinates)
      this.$router.push('/navigation')
      this.$route.params.pathMatch
    },
    manual: function () {
      this.showReturn = false
      this.modal.title = 'MANUAL INTERFACE'
      this.modal.description = 'Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.'
      this.show = true
      // this.$router.push('/manual')
      // this.$route.params.pathMatch
    },
    stop: function (coordinates) {
      this.$axios.get('http://localhost:5000/navigation/' + coordinates, {headers: {'Access-Control-Allow-Origin': '*'}})
      .then(resp => {
          console.log(resp.data);
      }).catch(function (error) {
        console.log(error)
      })
    },
    hideModal: function() {
      this.show = false
      this.showReturn = true;
    },
    control: function(direction) {
    this.$axios.get('http://localhost:5000/control/' + direction, {headers: {'Access-Control-Allow-Origin': '*'}})
      .then(resp => {
          console.log(resp.data);
      }).catch(function (error) {
        console.log(error)
      })
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

.cell-ctas {
  display: flex;
  justify-content: center;
  align-items: center;
  flex-wrap: wrap;
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

.modal-keypoint {
  z-index: 1000;
  position: absolute;
  top: 20px;
  bottom: 20px;
  left: 20px;
  right: 20px;
  width: auto;
  height: auto;
  background-color: rgba(0,0,0,0.9);
  color: white;
}

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

.info__cta-manual {
  display: block;
  margin: 0.5em 0;
  padding: 3em 2em;
  background: #fff;
  border: 10px solid #f07b4b;
  border-radius: 20px;
  color: #f07b4b;
  font-family: "Quicksand", sans-serif;
  font-size: 20px;
  font-weight: 700;
  letter-spacing: 0.02em;
  line-height: 1;
  text-decoration: none;
  text-transform: uppercase;
  cursor: pointer;
  flex-basis: 100%;
  margin-left: 200px;
  margin-right: 200px;
}

.info__cta-stop {
  display: block;
  margin: 0.5em 0;
  padding: 3em 2em;
  background: #fff;
  border: 10px solid red;
  border-radius: 20px;
  color: red;
  font-family: "Quicksand", sans-serif;
  font-size: 20px;
  font-weight: 700;
  letter-spacing: 0.02em;
  line-height: 1;
  text-decoration: none;
  text-transform: uppercase;
  cursor: pointer;
  flex-basis: 100%;
  margin-left: 200px;
  margin-right: 200px;
}

.control {
  position: absolute;
  display: block;
  width: 100px;
  height: 100px;
  background-image: url('../assets/arrow.svg');
  cursor: pointer;
}

@media screen and (max-width: 640px) {
  .control {
    width: 50px;
    height: 50px;
  }
}

#LEFT{
  top: 500px;
  transform: rotate(180deg);
  margin-left: 700px;
}

#RIGHT {
  top: 500px;
  margin-left: 900px;
}

#UP {
  display: block;
  top: 400px;
  margin-left: 800px;
  transform: rotate(-90deg);
}

#DOWN {
  transform: rotate(90deg);
  top: 600px;
  margin-left: 800px;
}

</style>
