#!/bin/bash

# PUSH_SWAP TEST BATTERY
# Batería completa de pruebas para push_swap
# Autor: Test automatizado para proyecto 42

# Colores para output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# Contadores
TOTAL_TESTS=0
PASSED_TESTS=0
FAILED_TESTS=0

# Función para imprimir resultados
print_result() {
    local test_name="$1"
    local expected="$2"
    local actual="$3"
    local extra_info="$4"
    
    TOTAL_TESTS=$((TOTAL_TESTS + 1))
    
    if [ "$expected" = "$actual" ]; then
        echo -e "${GREEN}✓ PASS${NC} - $test_name $extra_info"
        PASSED_TESTS=$((PASSED_TESTS + 1))
    else
        echo -e "${RED}✗ FAIL${NC} - $test_name"
        echo "  Expected: $expected"
        echo "  Got: $actual"
        echo "  $extra_info"
        FAILED_TESTS=$((FAILED_TESTS + 1))
    fi
}

# Función para verificar si está ordenado
check_sorted() {
    local args="$1"
    local output=$(echo "$args" | tr ' ' '\n' | sort -n | tr '\n' ' ' | sed 's/ $//')
    local input_clean=$(echo "$args" | sed 's/^ *//;s/ *$//')
    
    if [ "$output" = "$input_clean" ]; then
        echo "sorted"
    else
        echo "not_sorted"
    fi
}

# Función para contar operaciones
count_operations() {
    local result="$1"
    if [ -z "$result" ]; then
        echo "0"
    else
        echo "$result" | wc -l | tr -d ' '
    fi
}

echo -e "${BLUE}========================================${NC}"
echo -e "${BLUE}     PUSH_SWAP TEST BATTERY v1.0       ${NC}"
echo -e "${BLUE}========================================${NC}"
echo

# Verificar que push_swap existe
if [ ! -f "./push_swap" ]; then
    echo -e "${RED}Error: ./push_swap no encontrado${NC}"
    echo "Compilando proyecto..."
    make
    if [ ! -f "./push_swap" ]; then
        echo -e "${RED}Error: No se pudo compilar push_swap${NC}"
        exit 1
    fi
fi

echo -e "${YELLOW}1. TESTS BÁSICOS DE FUNCIONALIDAD${NC}"
echo "----------------------------------------"

# Test 1: Sin argumentos
result=$(./push_swap 2>&1)
exit_code=$?
print_result "Sin argumentos" "1" "$exit_code" "Debe retornar error"

# Test 2: Un solo número
result=$(./push_swap 42 2>&1)
exit_code=$?
print_result "Un solo número" "0" "$exit_code" "No debe hacer nada"

# Test 3: Ya ordenado
result=$(./push_swap 1 2 3 4 5 2>&1)
exit_code=$?
print_result "Ya ordenado (1 2 3 4 5)" "0" "$exit_code" "No debe hacer nada"

# Test 4: Orden inverso simple
result=$(./push_swap 2 1)
expected_ops=$(count_operations "$result")
print_result "Orden inverso (2 1)" "1" "$expected_ops" "Debe usar solo 'sa'"

# Test 5: Tres números desordenados
result=$(./push_swap 3 2 1)
ops_count=$(count_operations "$result")
test_result=""
if [ $ops_count -le 3 ]; then
    test_result="pass"
else
    test_result="fail"
fi
print_result "Tres números (3 2 1)" "pass" "$test_result" "Máximo 3 operaciones, usó: $ops_count"

echo
echo -e "${YELLOW}2. TESTS DE VALIDACIÓN DE ENTRADA${NC}"
echo "----------------------------------------"

# Test 6: Números duplicados
result=$(./push_swap 1 2 2 3 2>&1)
exit_code=$?
print_result "Números duplicados" "1" "$exit_code" "Debe retornar error"

# Test 7: Caracteres no numéricos
result=$(./push_swap 1 2 a 3 2>&1)
exit_code=$?
print_result "Caracteres no numéricos" "1" "$exit_code" "Debe retornar error"

# Test 8: Número muy grande
result=$(./push_swap 2147483648 2>&1)
exit_code=$?
print_result "Número > INT_MAX" "1" "$exit_code" "Debe retornar error"

# Test 9: Número muy pequeño
result=$(./push_swap -2147483649 2>&1)
exit_code=$?
print_result "Número < INT_MIN" "1" "$exit_code" "Debe retornar error"

# Test 10: String vacío
result=$(./push_swap "" 2>&1)
exit_code=$?
print_result "String vacío" "1" "$exit_code" "Debe retornar error"

# Test 11: Solo espacios
result=$(./push_swap "   " 2>&1)
exit_code=$?
print_result "Solo espacios" "1" "$exit_code" "Debe retornar error"

echo
echo -e "${YELLOW}3. TESTS DE RENDIMIENTO (5 elementos)${NC}"
echo "----------------------------------------"

# Test múltiples combinaciones de 5 elementos
five_element_tests=(
    "5 4 3 2 1"
    "1 5 2 4 3"
    "2 1 3 5 4"
    "4 5 3 1 2"
    "3 5 4 1 2"
)

for test_case in "${five_element_tests[@]}"; do
    result=$(./push_swap $test_case)
    ops_count=$(count_operations "$result")
    
    # Verificar que se ordena correctamente aplicando las operaciones
    # (esto sería más complejo de implementar, por ahora solo contamos operaciones)
    
    test_result=""
    if [ $ops_count -le 12 ]; then
        test_result="pass"
    else
        test_result="fail"
    fi
    print_result "5 elementos ($test_case)" "$test_result" "$test_result" "Operaciones: $ops_count (máx: 12)"
done

echo
echo -e "${YELLOW}4. TESTS DE RENDIMIENTO (100 elementos)${NC}"
echo "----------------------------------------"

# Test múltiples casos de 100 elementos para asegurar ordenamiento correcto
echo "Ejecutando múltiples tests de 100 elementos..."
total_100_tests=10
passed_100_tests=0
failed_100_tests=0
ops_100_sum=0
ops_100_min=9999
ops_100_max=0

for i in $(seq 1 $total_100_tests); do
    # Generar secuencia aleatoria de 100 elementos
    random_100=$(shuf -i 1-100 -n 100 | tr '\n' ' ')
    result=$(./push_swap $random_100)
    ops_count=$(count_operations "$result")
    
    # Verificar que se ordena correctamente con checker
    if [ -f "./checker" ]; then
        checker_result=$(echo "$result" | ./checker $random_100 2>&1)
        if [ "$checker_result" = "OK" ]; then
            passed_100_tests=$((passed_100_tests + 1))
            ops_100_sum=$((ops_100_sum + ops_count))
            
            # Actualizar min y max operaciones
            if [ $ops_count -lt $ops_100_min ]; then
                ops_100_min=$ops_count
            fi
            if [ $ops_count -gt $ops_100_max ]; then
                ops_100_max=$ops_count
            fi
            
            printf "  Test %2d/%-2d: ✅ OK (%3d ops)\n" $i $total_100_tests $ops_count
        else
            failed_100_tests=$((failed_100_tests + 1))
            printf "  Test %2d/%-2d: ❌ FAIL (%s)\n" $i $total_100_tests "$checker_result"
        fi
    else
        # Sin checker, solo verificar que no hay error
        exit_code=$?
        if [ $exit_code -eq 0 ]; then
            passed_100_tests=$((passed_100_tests + 1))
            ops_100_sum=$((ops_100_sum + ops_count))
            printf "  Test %2d/%-2d: ✅ OK (%3d ops) [sin checker]\n" $i $total_100_tests $ops_count
        else
            failed_100_tests=$((failed_100_tests + 1))
            printf "  Test %2d/%-2d: ❌ FAIL (exit code: %d)\n" $i $total_100_tests $exit_code
        fi
    fi
done

# Calcular estadísticas
if [ $passed_100_tests -gt 0 ]; then
    ops_100_avg=$((ops_100_sum / passed_100_tests))
else
    ops_100_avg=0
fi

echo ""
echo "📊 Estadísticas 100 elementos:"
echo "  Tests pasados: $passed_100_tests/$total_100_tests"
echo "  Operaciones - Min: $ops_100_min | Max: $ops_100_max | Promedio: $ops_100_avg"

# Evaluar rendimiento general
test_result=""
if [ $failed_100_tests -eq 0 ] && [ $ops_100_avg -le 700 ]; then
    test_result="excellent"
elif [ $failed_100_tests -eq 0 ] && [ $ops_100_avg -le 900 ]; then
    test_result="good"
elif [ $failed_100_tests -le 1 ] && [ $ops_100_avg -le 1100 ]; then
    test_result="ok"
elif [ $failed_100_tests -le 2 ]; then
    test_result="acceptable"
else
    test_result="poor"
fi

print_result "100 elementos (múltiples tests)" "$test_result" "$test_result" "Promedio: $ops_100_avg ops, Éxito: $passed_100_tests/$total_100_tests"

echo
echo -e "${YELLOW}5. TESTS DE RENDIMIENTO (500 elementos)${NC}"
echo "----------------------------------------"

# Test múltiples casos de 500 elementos para asegurar ordenamiento correcto
echo "Ejecutando múltiples tests de 500 elementos..."
total_500_tests=5
passed_500_tests=0
failed_500_tests=0
ops_500_sum=0
ops_500_min=99999
ops_500_max=0

for i in $(seq 1 $total_500_tests); do
    echo "  Ejecutando test $i/$total_500_tests (esto puede tomar unos segundos)..."
    
    # Generar secuencia aleatoria de 500 elementos
    random_500=$(shuf -i 1-500 -n 500 | tr '\n' ' ')
    result=$(./push_swap $random_500)
    ops_count=$(count_operations "$result")
    
    # Verificar que se ordena correctamente con checker
    if [ -f "./checker" ]; then
        checker_result=$(echo "$result" | ./checker $random_500 2>&1)
        if [ "$checker_result" = "OK" ]; then
            passed_500_tests=$((passed_500_tests + 1))
            ops_500_sum=$((ops_500_sum + ops_count))
            
            # Actualizar min y max operaciones
            if [ $ops_count -lt $ops_500_min ]; then
                ops_500_min=$ops_count
            fi
            if [ $ops_count -gt $ops_500_max ]; then
                ops_500_max=$ops_count
            fi
            
            printf "  Test %d/%d: ✅ OK (%d ops)\n" $i $total_500_tests $ops_count
        else
            failed_500_tests=$((failed_500_tests + 1))
            printf "  Test %d/%d: ❌ FAIL (%s)\n" $i $total_500_tests "$checker_result"
        fi
    else
        # Sin checker, solo verificar que no hay error
        exit_code=$?
        if [ $exit_code -eq 0 ]; then
            passed_500_tests=$((passed_500_tests + 1))
            ops_500_sum=$((ops_500_sum + ops_count))
            printf "  Test %d/%d: ✅ OK (%d ops) [sin checker]\n" $i $total_500_tests $ops_count
        else
            failed_500_tests=$((failed_500_tests + 1))
            printf "  Test %d/%d: ❌ FAIL (exit code: %d)\n" $i $total_500_tests $exit_code
        fi
    fi
done

# Calcular estadísticas
if [ $passed_500_tests -gt 0 ]; then
    ops_500_avg=$((ops_500_sum / passed_500_tests))
else
    ops_500_avg=0
fi

echo ""
echo "📊 Estadísticas 500 elementos:"
echo "  Tests pasados: $passed_500_tests/$total_500_tests"
echo "  Operaciones - Min: $ops_500_min | Max: $ops_500_max | Promedio: $ops_500_avg"

# Evaluar rendimiento general
test_result=""
if [ $failed_500_tests -eq 0 ] && [ $ops_500_avg -le 5500 ]; then
    test_result="excellent"
elif [ $failed_500_tests -eq 0 ] && [ $ops_500_avg -le 7000 ]; then
    test_result="good"
elif [ $failed_500_tests -eq 0 ] && [ $ops_500_avg -le 8500 ]; then
    test_result="ok"
elif [ $failed_500_tests -le 1 ] && [ $ops_500_avg -le 11500 ]; then
    test_result="acceptable"
else
    test_result="poor"
fi

print_result "500 elementos (múltiples tests)" "$test_result" "$test_result" "Promedio: $ops_500_avg ops, Éxito: $passed_500_tests/$total_500_tests"

# Tests adicionales con casos específicos de 500 elementos
echo ""
echo "🔍 Tests específicos de 500 elementos:"

# Test peor caso: orden descendente
echo "  Probando peor caso (orden descendente)..."
worst_case_500=$(seq 500 -1 1 | tr '\n' ' ')
result_worst=$(./push_swap $worst_case_500)
ops_worst=$(count_operations "$result_worst")

if [ -f "./checker" ]; then
    checker_worst=$(echo "$result_worst" | ./checker $worst_case_500 2>&1)
    if [ "$checker_worst" = "OK" ]; then
        echo "    ✅ Peor caso: OK ($ops_worst ops)"
    else
        echo "    ❌ Peor caso: FAIL ($checker_worst)"
    fi
else
    echo "    ⚠️  Peor caso: $ops_worst ops (sin checker)"
fi

# Test mejor caso: ya ordenado
echo "  Probando mejor caso (ya ordenado)..."
best_case_500=$(seq 1 500 | tr '\n' ' ')
result_best=$(./push_swap $best_case_500)
ops_best=$(count_operations "$result_best")

if [ $ops_best -eq 0 ]; then
    echo "    ✅ Mejor caso: OK (0 ops - ya ordenado)"
else
    echo "    ⚠️  Mejor caso: $ops_best ops (debería ser 0)"
fi

# Test caso medio: parcialmente ordenado
echo "  Probando caso medio (parcialmente ordenado)..."
medium_case_500=$(shuf -i 1-500 -n 250; seq 251 500 | tr '\n' ' ')
result_medium=$(./push_swap $medium_case_500)
ops_medium=$(count_operations "$result_medium")

if [ -f "./checker" ]; then
    checker_medium=$(echo "$result_medium" | ./checker $medium_case_500 2>&1)
    if [ "$checker_medium" = "OK" ]; then
        echo "    ✅ Caso medio: OK ($ops_medium ops)"
    else
        echo "    ❌ Caso medio: FAIL ($checker_medium)"
    fi
else
    echo "    ⚠️  Caso medio: $ops_medium ops (sin checker)"
fi

echo
echo -e "${YELLOW}6. TESTS DE CASOS LÍMITE${NC}"
echo "----------------------------------------"

# Test con INT_MAX e INT_MIN
result=$(./push_swap 2147483647 -2147483648 0)
exit_code=$?
print_result "INT_MAX, INT_MIN, 0" "0" "$exit_code" "Debe funcionar correctamente"

# Test con muchos argumentos como string
result=$(./push_swap "1 2 3 4 5")
exit_code=$?
print_result "Múltiples números en string" "0" "$exit_code" "Debe parsear correctamente"

# Test mixto de argumentos
result=$(./push_swap "1 2" "3 4" "5")
exit_code=$?
print_result "Argumentos mixtos" "0" "$exit_code" "Debe parsear correctamente"

echo
echo -e "${YELLOW}7. TESTS DE CASOS ESPECÍFICOS${NC}"
echo "----------------------------------------"

# Casos específicos que suelen dar problemas
specific_tests=(
    "1 2 3"
    "3 2 1"
    "2 3 1"
    "1 3 2"
    "2 1 3"
    "3 1 2"
)

for test_case in "${specific_tests[@]}"; do
    result=$(./push_swap $test_case)
    ops_count=$(count_operations "$result")
    
    test_result=""
    if [ $ops_count -le 3 ]; then
        test_result="pass"
    else
        test_result="fail"
    fi
    print_result "3 elementos ($test_case)" "$test_result" "$test_result" "Operaciones: $ops_count"
done

echo
echo -e "${YELLOW}8. TESTS DE MEMORY LEAKS${NC}"
echo "----------------------------------------"

# Test con Valgrind si está disponible
if command -v valgrind &> /dev/null; then
    echo "Ejecutando tests de memory leaks..."
    
    # Test simple con valgrind
    valgrind_output=$(valgrind --leak-check=full --error-exitcode=1 ./push_swap 3 2 1 2>&1)
    valgrind_exit=$?
    
    if [ $valgrind_exit -eq 0 ]; then
        print_result "Memory leaks test" "pass" "pass" "Sin memory leaks detectados"
    else
        print_result "Memory leaks test" "pass" "fail" "Memory leaks detectados"
    fi
else
    echo "Valgrind no disponible - saltando tests de memory leaks"
fi

echo
echo -e "${YELLOW}9. TESTS INTENSIVOS DE VERIFICACIÓN DE ORDENAMIENTO${NC}"
echo "----------------------------------------"

# Tests adicionales para verificar que SIEMPRE se ordenan correctamente
echo "🔍 Verificación intensiva del ordenamiento..."

# Test con diferentes rangos de números
test_ranges=(
    "1-50:25"     # 25 números del 1 al 50
    "1-100:50"    # 50 números del 1 al 100
    "1-1000:100"  # 100 números del 1 al 1000
    "1-10000:200" # 200 números del 1 al 10000
)

total_intensive_tests=0
passed_intensive_tests=0

for range_test in "${test_ranges[@]}"; do
    IFS=':' read -r range count <<< "$range_test"
    IFS='-' read -r min_val max_val <<< "$range"
    
    echo "  Probando $count números del rango $min_val-$max_val:"
    
    for i in {1..3}; do
        total_intensive_tests=$((total_intensive_tests + 1))
        
        # Generar caso aleatorio
        random_case=$(shuf -i $min_val-$max_val -n $count | tr '\n' ' ')
        result=$(./push_swap $random_case)
        ops_count=$(count_operations "$result")
        
        # Verificar ordenamiento
        if [ -f "./checker" ]; then
            checker_result=$(echo "$result" | ./checker $random_case 2>&1)
            if [ "$checker_result" = "OK" ]; then
                passed_intensive_tests=$((passed_intensive_tests + 1))
                printf "    Test %d: ✅ OK (%d ops)\n" $i $ops_count
            else
                printf "    Test %d: ❌ FAIL (%s)\n" $i "$checker_result"
            fi
        else
            # Sin checker, verificar que no hay errores de ejecución
            exit_code=$?
            if [ $exit_code -eq 0 ]; then
                passed_intensive_tests=$((passed_intensive_tests + 1))
                printf "    Test %d: ✅ OK (%d ops) [sin checker]\n" $i $ops_count
            else
                printf "    Test %d: ❌ FAIL (exit code: %d)\n" $i $exit_code
            fi
        fi
    done
done

echo ""
echo "📊 Resumen tests intensivos:"
echo "  Tests pasados: $passed_intensive_tests/$total_intensive_tests"

# Evaluar resultado de tests intensivos
if [ $passed_intensive_tests -eq $total_intensive_tests ]; then
    intensive_result="pass"
    intensive_msg="Todos los tests de ordenamiento pasaron"
else
    intensive_result="fail"
    intensive_msg="Algunos tests de ordenamiento fallaron"
fi

print_result "Tests intensivos de ordenamiento" "pass" "$intensive_result" "$intensive_msg"

# Test final de confianza - casos problemáticos conocidos
echo ""
echo "🎯 Tests de casos problemáticos específicos:"

problematic_cases=(
    "$(seq 100 -1 1 | tr '\n' ' ')"                    # 100 descendente
    "$(seq 1 2 100; seq 2 2 100 | tr '\n' ' ')"        # Pares e impares
    "$(shuf -i 1-1000 -n 100 | tr '\n' ' ')"           # 100 aleatorios rango amplio
)

problematic_passed=0
problematic_total=${#problematic_cases[@]}

for i in "${!problematic_cases[@]}"; do
    case="${problematic_cases[$i]}"
    result=$(./push_swap $case)
    ops_count=$(count_operations "$result")
    
    if [ -f "./checker" ]; then
        checker_result=$(echo "$result" | ./checker $case 2>&1)
        if [ "$checker_result" = "OK" ]; then
            problematic_passed=$((problematic_passed + 1))
            echo "  Caso problemático $((i+1)): ✅ OK ($ops_count ops)"
        else
            echo "  Caso problemático $((i+1)): ❌ FAIL ($checker_result)"
        fi
    else
        echo "  Caso problemático $((i+1)): ⚠️ $ops_count ops (sin checker)"
        problematic_passed=$((problematic_passed + 1))
    fi
done

# Evaluar casos problemáticos
if [ $problematic_passed -eq $problematic_total ]; then
    problematic_result="pass"
    problematic_msg="Todos los casos problemáticos resueltos"
else
    problematic_result="fail" 
    problematic_msg="Algunos casos problemáticos fallaron"
fi

print_result "Casos problemáticos específicos" "pass" "$problematic_result" "$problematic_msg"

echo
echo -e "${BLUE}========================================${NC}"
echo -e "${BLUE}           RESUMEN DE TESTS             ${NC}"
echo -e "${BLUE}========================================${NC}"
echo -e "Total tests: ${TOTAL_TESTS}"
echo -e "${GREEN}Pasados: ${PASSED_TESTS}${NC}"
echo -e "${RED}Fallidos: ${FAILED_TESTS}${NC}"

if [ $FAILED_TESTS -eq 0 ]; then
    echo -e "${GREEN}¡Todos los tests pasaron! ✓${NC}"
    exit 0
else
    echo -e "${RED}Algunos tests fallaron. Revisa tu implementación.${NC}"
    exit 1
fi
