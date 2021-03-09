import Vue from 'vue'
import axios from 'axios'
import VueRouter from 'vue-router'
import Home from '../views/Home.vue'

Vue.component("DviclittleMap", () => import("../components/littleMap.vue"));
Vue.component("DvicMap", () => import("../components/Map.vue"));
Vue.component("DvicCameraFront", () => import("../components/CameraFront.vue"));

Vue.prototype.$http = axios
Vue.use(VueRouter)

const routes = [
  {
    path: '/',
    name: 'Home',
    component: Home
  },
  {
    path: '/navigation',
    name: 'Navigation',
    // route level code-splitting
    // this generates a separate chunk (about.[hash].js) for this route
    // which is lazy-loaded when the route is visited.
    component: () => import(/* webpackChunkName: "about" */ '../views/Navigation.vue')
  },
  {
    path: '/info',
    name: 'Info',
    component: () => import(/* webpackChunkName: "about" */ '../views/Info.vue')
  },
  {
    path: '/controls',
    name: 'Controls',
    component: () => import(/* webpackChunkName: "about" */ '../views/Controls.vue')
  }
]

const router = new VueRouter({
  mode: 'history',
  base: process.env.BASE_URL,
  routes
})

export default router
