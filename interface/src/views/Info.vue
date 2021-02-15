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
        CTA
      </div>
      <div class="cell">
        CAMERA VIEW
      </div>
    </div>
  </div>
</template>
<script>
export default {
  name: "Info",
  data: () => ({

  }),
  methods: {
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
</style>
