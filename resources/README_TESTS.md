# 🧪 PUSH_SWAP TEST BATTERY

Batería completa de pruebas para el proyecto push_swap de 42 Madrid.

## 📋 Descripción

Esta batería de tests está diseñada para verificar que tu implementación de push_swap cumple con todos los requisitos del proyecto, incluyendo:

- ✅ Funcionalidad básica
- ✅ Manejo de errores
- ✅ Validación de entrada
- ✅ Rendimiento (número de operaciones)
- ✅ Tests del checker (bonus)
- ✅ Memory leaks
- ✅ Casos límite y edge cases

## 🚀 Uso Rápido

```bash
# Compilar el proyecto
make

# Ejecutar todos los tests
./run_all_tests.sh

# Test rápido (solo casos críticos)
./run_all_tests.sh
# Selecciona opción 5
```

## 📁 Scripts Disponibles

### 1. `run_all_tests.sh` - **SCRIPT PRINCIPAL**
Script maestro con menú interactivo para ejecutar diferentes tipos de tests.

```bash
./run_all_tests.sh
```

**Opciones:**
- Tests básicos de funcionalidad
- Tests de rendimiento
- Tests del checker
- Todos los tests
- Test rápido

### 2. `test_push_swap.sh` - Tests Básicos
Tests completos de funcionalidad, validación y rendimiento básico.

```bash
./test_push_swap.sh
```

**Incluye:**
- Tests de funcionalidad básica
- Validación de entrada
- Tests de rendimiento (5, 100, 500 elementos)
- Casos límite
- Memory leaks (si tienes valgrind)

### 3. `test_checker.sh` - Tests del Checker (Bonus)
Tests específicos para el programa checker.

```bash
./test_checker.sh
```

### 4. `performance_test.sh` - Tests de Rendimiento
Tests detallados de rendimiento con diferentes tamaños.

```bash
./performance_test.sh
```

### 5. `evaluation_tests.sh` - Tests de Evaluación
Casos específicos que suelen aparecer durante las evaluaciones.

```bash
./evaluation_tests.sh
```

## 📊 Criterios de Evaluación

### Operaciones Máximas Recomendadas:
- **3 elementos:** ≤ 3 operaciones
- **5 elementos:** ≤ 12 operaciones
- **100 elementos:** ≤ 700 operaciones (≤ 550 excelente)
- **500 elementos:** ≤ 5500 operaciones (≤ 4500 excelente)

### Casos que DEBEN funcionar:
- ✅ Ya ordenado (sin operaciones)
- ✅ Un solo número
- ✅ Números negativos
- ✅ INT_MAX e INT_MIN
- ✅ Múltiples argumentos como strings

### Casos que DEBEN dar error:
- ❌ Sin argumentos
- ❌ Números duplicados
- ❌ Caracteres no numéricos
- ❌ Números fuera del rango de int
- ❌ Strings vacíos

## 🔧 Casos de Prueba Específicos

### Tests Básicos:
```bash
./push_swap 1 2 3        # Sin operaciones
./push_swap 2 1          # 1 operación (sa)
./push_swap 3 2 1        # ≤ 3 operaciones
./push_swap "1 2 3 4 5"  # Parsing de string
```

### Tests de Error:
```bash
./push_swap 1 2 2        # Duplicados -> Error
./push_swap 1 2 a        # No numérico -> Error
./push_swap 2147483648   # > INT_MAX -> Error
```

### Tests de Rendimiento:
```bash
# Generar caso aleatorio de 100 elementos
ARG=$(shuf -i 1-100 -n 100 | tr '\n' ' ')
./push_swap $ARG | wc -l

# Test con checker
./push_swap 3 2 1 | ./checker 3 2 1
```

## 🧠 Memory Leaks

Si tienes `valgrind` instalado:

```bash
valgrind --leak-check=full ./push_swap 3 2 1
```

## 📈 Generación de Reportes

El script principal puede generar reportes detallados:

```bash
./run_all_tests.sh
# Selecciona "Todos los tests"
# Al final preguntará si quieres generar reporte
```

## 🎯 Para la Evaluación

Ejecuta antes de la evaluación:

```bash
./evaluation_tests.sh
```

Este script contiene casos específicos que suelen aparecer durante las evaluaciones de 42.

## 🛠️ Troubleshooting

### Si no compila:
```bash
make clean
make
```

### Si los scripts no son ejecutables:
```bash
chmod +x *.sh
```

### Para debug detallado:
```bash
./push_swap 3 2 1    # Ver operaciones
echo $?              # Ver exit code
```

## 📝 Notas Importantes

1. **Compilación:** Los scripts intentan compilar automáticamente si no encuentran el ejecutable
2. **Checker:** Los tests del checker solo se ejecutan si el archivo existe
3. **Valgrind:** Los tests de memory leaks solo se ejecutan si valgrind está disponible
4. **Rendimiento:** Los números son aproximados, pueden variar según tu algoritmo

## 🏆 Checklist Pre-Evaluación

- [ ] `make` compila sin errores ni warnings
- [ ] Tests básicos pasan (./test_push_swap.sh)
- [ ] Sin memory leaks
- [ ] Casos de error manejan correctamente
- [ ] Rendimiento dentro de límites esperados
- [ ] Checker funciona (si hiciste bonus)

---

**¡Good luck con tu evaluación! 🍀**

*Esta batería de tests está diseñada para ser exhaustiva pero no reemplaza tu propio testing y comprensión del código.*
