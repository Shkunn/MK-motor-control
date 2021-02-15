<template>
  <div id="about">
    <div class="map__head">
      <img alt="Vue logo" class="logo" src="@/assets/logo.png">
      <h1 class="map__title">4th floor navigation</h1>
    </div>
    <div class="navigations">
     <div id="FOODLAB" v-on:click="showModal('foodlab')" class="navigation"></div>
     <div id="ROBOT" v-on:click="showModal('robot')" class="navigation navigation-robot"></div>
   </div>
   <div class="modal-keypoint" v-if="show">
     <span v-on:click="hideModal()" class="modal__close">x</span>
     <div class="modal__title">
       {{ modal.title }}
     </div>
     <div class="modal__description">
       {{ modal.description }}
     </div>
     <div class="" v-if="modal.id == 'robot'">
       ROBOT SLKNJZKFHBZHDIOJKZBHDUOAZK
     </div>
     <button type="button" name="button" class="modal__button" v-on:click="navigation(modal.id)" v-if="modal.id != 'robot'">Go To</button>
   </div>
  </div>
</template>
<script>
const Http = new XMLHttpRequest();
const SERVER = "127.0.0.1:5000"

export default {
  name: "Map",
  data: () => ({
    show: false,
    modal: {
      id: '',
      title: '',
      description: ''
    }
  }),
  methods: {
    showModal: function (coordinates) {
      if (coordinates == 'foodlab') {
        this.modal.id = 'foodlab'
        this.modal.title = 'Food Tech Lab'
        this.modal.description = 'Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.'
        this.show = true
      } else if (coordinates == 'robot') {
        this.modal.id = 'robot'
        this.modal.title = 'Mon robot'
        this.modal.description = 'Mon robot'
        this.show = true
      }
    },
    hideModal: function() {
      this.show = false
    },
    navigation: function (coordinates) {
      // alert(coordinates)
      const url = "http:" + SERVER + "/navigation/" + coordinates;
      Http.open("GET", url);
      Http.send();
      this.$router.push('/info')
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
.modal__button {
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

.navigations {
  position: relative;
  width: 385px;
  height: 500px;
  background-image: url('../assets/4map-bg.jpeg');
  background-size: contain;
  background-repeat: no-repeat;
  background-position: center;
  margin-right: auto;
  margin-left: auto;
}

.navigation {
  position: absolute;
  display: block;
  top: 210px;
  left: 50px;
  width: 30px;
  height: 30px;
  background-image: url('../assets/food.png');
  cursor: pointer;
  background-size: contain;
  background-repeat: no-repeat;
  background-position: center;
}

.navigation-robot {
  top: 310px;
  left: 50px;
  width: 30px;
  height: 30px;
  background-image: url('../assets/robot.svg');
}
</style>
