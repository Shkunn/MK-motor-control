<template>
  <div id="info">
    <div class="cells">
      <div class="cell">
        <h1>STATISTICS</h1>
        <div class="svg-item">
          <svg width="100%" height="100%" viewBox="0 0 40 40" class="donut">
            <circle class="donut-hole" cx="20" cy="20" r="15.91549430918954" fill="#fff"></circle>
            <circle class="donut-ring" cx="20" cy="20" r="15.91549430918954" fill="transparent" stroke-width="3.5"></circle>
            <circle class="donut-segment donut-segment-2" cx="20" cy="20" r="15.91549430918954" fill="transparent" stroke-width="3.5" stroke-dasharray="80 20" stroke-dashoffset="25"></circle>
            <g class="donut-text donut-text-1">
              <text y="50%" transform="translate(0, 2)">
                <tspan x="50%" text-anchor="middle" class="donut-percent">80%</tspan>   
              </text>
              <text y="60%" transform="translate(0, 2)">
                <tspan x="50%" text-anchor="middle" class="donut-data">BATTERY</tspan>   
              </text>
            </g>
          </svg>
        </div>
        <div class="meter-viz">
          <svg width="100%" height="100%" viewBox="0 0 40 40" class="donut">
            <circle class="donut-hole" cx="20" cy="20" r="15.91549430918954" fill="#fff"></circle>
            <circle class="donut-ring" cx="20" cy="20" r="15.91549430918954" fill="transparent" stroke-width="3.5"></circle>
            <g class="donut-text donut-text-1">
              <text y="50%" transform="translate(0, 2)">
                <tspan x="50%" text-anchor="middle" class="donut-percent">35</tspan>   
              </text>
              <text y="60%" transform="translate(0, 2)">
                <tspan x="50%" text-anchor="middle" class="donut-data">METERS</tspan>   
              </text>
            </g>
          </svg>
        </div>
      </div>
      <div class="cell">
        <DviclittleMap />
      </div>
      <div class="cell cell-ctas">
        <button v-on:click="manual('stop')" class="info__cta-manual">MANUAL MODE</button>
        <button v-on:click="stop('stop')" class="info__cta-stop">STOP</button>
      </div>      
      <div class="cell camera-view">
        <h1>CAMERA VIEW</h1>
      </div>
    </div>
    <div class="modal-keypoint" v-if="show">

      <span v-on:click="hideModal()" class="modal__close">x</span>
      <div class="modal__title">
       {{ modal.title }}
      </div>
      <div class="modal__description">
        {{ modal.description }}
      </div>
      <div class="controls">
        <div id="FORWARD" v-on:mousedown="control('forward')" v-on:mouseup="control('stop')" class="control"></div>
        <div id="LEFT" v-on:mousedown="control('left')" v-on:mouseup="control('stop')" class="control"></div>
        <div id="RIGHT" v-on:mousedown="control('right')" v-on:mouseup="control('stop')" class="control"></div>
        <div id="BACKWARD" v-on:mousedown="control('backward')" v-on:mouseup="control('stop')" class="control"></div>
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
    manual: function (command) {
      this.showReturn = false
      this.modal.title = 'MANUAL INTERFACE'
      this.modal.description = 'Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.'
      this.show = true
      // this.$router.push('/manual')
      // this.$route.params.pathMatch
      this.$axios.get('http://localhost:5000/navigation/' + command, {headers: {'Access-Control-Allow-Origin': '*'}})
      .then(resp => {
          console.log(resp.data);
      }).catch(function (error) {
        console.log(error)
      })
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
  border-radius: 10px;
}

.cell {
  height: 50vh;
  justify-items: center;
  border: 2px solid #fff;
  padding: 20px;
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
  margin: 0em 0;
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
    width: 100px;
    height: 100px;
  }
}

.controls {
  display: block;
  top: 50px;
  width: 500px;
  height: 500px;
  position: relative;
  margin-left: auto;
  margin-right: auto;
}

#LEFT{
  top: 40%;
  left: 10%;
  transform: rotate(180deg);
}

#RIGHT {
  top: 40%;
  right: 10%;
}

#FORWARD {
  display: block;
  top: 10%;
  left: 40%;
  transform: rotate(-90deg);
}

#BACKWARD {
  transform: rotate(90deg);
  left: 40%;
  bottom: 10%;
}

.svg-item {
    width: 100%;
    font-size: 16px;
    margin: 0 auto;
    margin-right: 400px;
    animation: donutfade 1s;
}

.meter-viz {
  width: 100%;
  font-size: 16px;
  margin: 0 auto;
  margin-right: 400px;
  animation: donutfade 1s;
}

@keyframes donutfade {
  /* this applies to the whole svg item wrapper */
    0% {
        opacity: .2;
    }
    100% {
        opacity: 1;
    }
}

@media (min-width: 992px) {
    .svg-item {
        width: 80%;
    }
}

.donut-ring {
    stroke: #EBEBEB;
}

.donut-segment {
    transform-origin: center;
    stroke: #f0784b;
}

.donut-segment-2 {
    stroke: #418820;
    animation: donut1 3s;
}


.segment-1{fill:#ccc;}
.segment-2{fill:#418820;}

.donut-percent {
    animation: donutfadelong 1s;
}

@keyframes donutfadelong {
    0% {
        opacity: 0;
    }
    100% {
        opacity: 1;
    }
}

@keyframes donut1 {
    0% {
        stroke-dasharray: 0, 100;
    }
    100% {
        stroke-dasharray: 69, 31;
    }
}

.donut-text {
  font-family: Arial, Helvetica, sans-serif;
  fill: #418820;
}
.donut-text-1 {
  fill: #418820;
}


.donut-label {
  font-size: 0.28em;
  font-weight: 700;
  line-height: 1;
  fill: #000;
  transform: translateY(0.25em);
}

.donut-percent {
  font-size: 0.5em;
  line-height: 1;
  transform: translateY(0.5em);
  font-weight: bold;
}

.donut-data {
  font-size: 0.2em;
  line-height: 1;
  transform: translateY(0.5em);
  text-align: center;
  text-anchor: middle;
  color:#666;
  fill: #666;
  animation: donutfadelong 1s;
}


/* ---------- */
/* just for this presentation */
html { text-align:center; }
.svg-item {
  max-width:20%;
  display:inline-block;
}

html { text-align:center; }
.meter-viz {
  max-width:20%;
  display:inline-block;
}


</style>
