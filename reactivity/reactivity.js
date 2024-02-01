let activeEffect = null
const targetMap = new WeakMap()

const track = (target, key) => {
    if (activeEffect) {
        let depsMap = targetMap.get(target)
        if (!depsMap) {
            targetMap.set(target, depsMap = (new Map()))
        }
        let deps = depsMap.get(key)
        if (!deps) {
            depsMap.set(key, (deps = new Set()))
        }
        deps.add(activeEffect)
    }

}

const trigger = (target, key) => {
    let depsMap = targetMap.get(target)
    if (depsMap) {
        let deps = depsMap.get(key)
        if (deps) {
            deps.forEach(eff => eff())
        }
    }
}

const effect = (eff) => {
    activeEffect = eff
    eff()
    activeEffect = null
}

const reactive = (target) => {
    const handler = {
        get(target, key, receivier) {
            const result = Reflect.get(target, key, receivier)
            track(target, key)
            return result
        },
        set(target, key, value, receivier) {
            const oldValue = target[key]
            const result = Reflect.set(target, key, value, receivier)
            if (result && oldValue !== value) {
                trigger(target, key)
            }
            return result
        }
    }
    return new Proxy(target, handler)
}

const ref = (raw) => {
    const r = {
        get value() {
            track(r, 'value')
            return raw
        },
        set value(newVal) {
            raw = newVal
            trigger(r, 'value')
        }
    }
    return r
}

const computed = (getter) => {
    const result = ref()
    effect(() => result.value = getter())
    return result
}

export {
    reactive,
    ref,
    effect,
    computed
}