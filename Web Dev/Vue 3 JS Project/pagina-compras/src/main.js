import { createApp } from 'vue'
import App from './App.vue'
import router from './router'

import './assets/main.css'
import '@/assets/bootstrap.min.css'
import '@/assets/bootstrap.bundle.min.js'
import 'material-icons/iconfont/material-icons.css'
import '@/assets/custom_styles.css'

const app = createApp(App)

app.use(router)

app.mount('#app')
