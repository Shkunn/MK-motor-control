<template>
  <div class="map">
    <div class="navigations">
     <div id="FOODLAB" v-on:click="showModal('foodlab')" class="navigation"></div>
     <div id="ELECTRONICLAB" v-on:click="showModal('electroniclab')" class="elec_navigation"></div>
     <div id="4DSPACE" v-on:click="showModal('4Dspace')" class="fourdspace_navigation"></div>
     <div id="CLASSROOM" v-on:click="showModal('classsroom')" class="classroom_navigation"></div>
     <div id="BIOLIVINGLAB" v-on:click="showModal('biolivinglab')" class="biolivinglab_navigation"></div>
     <div id="WATERBOTTLE" v-on:click="showModal('waterbottle')" class="water_navigation"></div>
     <div id="ROBOT" v-on:click="showModal('robot')" class="navigation navigation_robot"></div>
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
       MK2-R is the 4 wheels and robust version and of MK2. It will guide you through the different labs of the DVIC. Please follow him.
     </div>
     <button type="button" name="button" class="modal__button" v-on:click="navigation(modal.id)" v-if="modal.id != 'robot'">Go To</button>
   </div>
  </div>
</template>

<script>
export default {
  name: 'Map',
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
      this.showReturn = false
      if (coordinates == 'foodlab') {
        this.modal.id = 'foodlab'
        this.modal.title = 'Food Tech Lab'
        this.modal.description = 'Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.'
        this.show = true
      } else if (coordinates == 'robot') {
        this.modal.id = 'robot'
        this.modal.title = 'MK2-R'
        this.modal.description = ''
        this.show = true
      } else if (coordinates == 'electroniclab') {
        this.modal.id = 'electroniclab'
        this.modal.title = 'Electronic Lab'
        this.modal.description = 'Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.'
        this.show = true
      } else if (coordinates == '4Dspace') {
        this.modal.id = '4Dspace'
        this.modal.title = '4D space'
        this.modal.description = 'Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.'
        this.show = true
      } else if (coordinates == 'classsroom') {
        this.modal.id = 'classroom'
        this.modal.title = 'Classroom'
        this.modal.description = 'Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.'
        this.show = true
      } else if (coordinates == 'biolivinglab') {
        this.modal.id = 'biolivinglab'
        this.modal.title = 'Bio Living Lab'
        this.modal.description = 'Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.'
        this.show = true
      } else if (coordinates == 'waterbottle') {
        this.modal.id = 'waterbottle'
        this.modal.title = 'Water Bottle'
        this.modal.description = 'Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.'
        this.show = true
      }      
    },
    hideModal: function() {
      this.show = false
      this.showReturn = true;
    },
    // navigation: function (coordinates) {
    //   alert(coordinates)
    //   this.$http.get("http://localhost:5000/navigation/" + coordinates, {headers: {'Access-Control-Allow-Origin': '*'}})
    //   .then(function (response) {
    //       console.log(response)
    //       this.$router.push('/info')
    //   this.$route.params.pathMatch
    //   })
    //   .catch(function (error) {
    //   // handle error
    //   console.log(error);
    //   })
    // }
    navigation: function (coordinates) {
      console.log(coordinates)
      this.$router.push('/info')
      this.$route.params.pathMatch
    }
  }
}
</script>

<!-- Add "scoped" attribute to limit CSS to this component only -->
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
  left: 60px;
  width: 30px;
  height: 30px;
  background-image: url('../assets/food.png');
  cursor: pointer;
  background-size: contain;
  background-repeat: no-repeat;
  background-position: center;
}

.elec_navigation {
  position: absolute;
  display: block;
  top: 350px;
  left: 60px;
  width: 30px;
  height: 30px;
  background-image: url('../assets/elec.svg');
  cursor: pointer;
  background-size: contain;
  background-repeat: no-repeat;
  background-position: center;
}

.fourdspace_navigation {
  position: absolute;
  display: block;
  top: 420px;
  left: 60px;
  width: 30px;
  height: 30px;
  background-image: url('../assets/4Dspace.svg');
  cursor: pointer;
  background-size: contain;
  background-repeat: no-repeat;
  background-position: center;
}

.classroom_navigation {
  position: absolute;
  display: block;
  top: 280px;
  left: 110px;
  width: 30px;
  height: 30px;
  background-image: url('../assets/classroom.svg');
  cursor: pointer;
  background-size: contain;
  background-repeat: no-repeat;
  background-position: center;
}

.biolivinglab_navigation {
  position: absolute;
  display: block;
  top: 310px;
  right: 105px;
  width: 30px;
  height: 30px;
  background-image: url('../assets/lab.svg');
  cursor: pointer;
  background-size: contain;
  background-repeat: no-repeat;
  background-position: center;
}

.water_navigation {
  position: absolute;
  display: block;
  top: 360px;
  right: 40px;
  width: 30px;
  height: 30px;
  background-image: url('../assets/waterbottle.svg');
  cursor: pointer;
  background-size: contain;
  background-repeat: no-repeat;
  background-position: center;
}

.navigation_robot {
  top: 60px;
  left: 190px;
  width: 30px;
  height: 30px;
  background-image: url('../assets/robot.svg');
}
</style>
