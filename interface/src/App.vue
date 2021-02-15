<template>
  <div id="app">
    <div class="home__head">
      <img alt="Vue logo" class="logo" src="./assets/logo.png">
      <h1 class="title">DEVO</h1>
    </div>
    <p class="para">
      The DVIC is a transdisciplinary laboratory where numerous projects are being carried out. We will guide you through these ! Please follow me
    </p>

    <div class="home__modules">
      <a class="home__module" href="/test">
        4th floor navigation
      </a>
      <a class="home__module" href="#">
        Mapping
      </a>
      <a class="home__module" target="_blank" href="https://dvic.devinci.fr/resource/startup/devo-group-robotic/">
        Details
      </a>
    </div>
  </div>
</template>

<script>
export default {
  name: 'App'
}
</script>

<style>
body {
  font-family: 'Poppins', sans-serif;
  background-color: #030326;
  color: black;
}

#app {
  font-family: Avenir, Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  text-align: center;
  color: #2c3e50;
  margin-top: 60px;
}

.home__head {
  display: flex;
  justify-content: center;
  align-items: center;
}

.logo {
  width: 150px;
  height: 150px;
  display: block;
}

@media screen and (max-width: 640px) {
  .logo {
    width: 100px;
  }
}

.title {
  font-size: 5em;
  color: #f07b4b;
}

@media screen and (max-width: 640px) {
  .title {
    font-size: 1.5em;
  }
}

.para {
  margin-top: 10px;
  margin-left: auto;
  margin-right: auto;
  font-size: 1.6em;
  width: 700px;
  color: white;
}

.home__modules {
  display: grid;
  grid-template-columns: repeat(3, 1fr);
  grid-gap: 30px;
  margin-top: 50px;
  margin-left: 200px;
  margin-right: 200px;
}

.home__module {
  display: flex;
  justify-content: center;
  align-items: center;
  flex-basis: 33%;
  height: 220px;
  background-color: gray;
  border-radius: 5px;
  font-size: 1.8em;
  color: white;
  text-decoration: none;
}
</style>
