import { reactive, effect, ref, computed } from "./reactivity.js";

const product = reactive({
  price: 10,
  count: 2
})

const age = ref(10)

effect(() => {
  const total = product.price * product.count
  console.log('total', total)
})

effect(() => {
  console.log('age：', age.value)
})

const total = computed(() => {
  return product.price * product.count
})
console.log('computed total', total.value)

setTimeout(() => {
  product.count = 5
  age.value = 18
  console.log('computed total', total.value)
}, 1000)