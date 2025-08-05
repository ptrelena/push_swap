#!/bin/bash

# EVALUATION SPECIFIC TESTS
# Casos específicos que suelen aparecer durante las evaluaciones de 42

# Colores
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m'

echo -e "${BLUE}========================================${NC}"
echo -e "${BLUE}     EVALUATION SPECIFIC TESTS         ${NC}"
echo -e "${BLUE}========================================${NC}"

# Verificar que push_swap existe
if [ ! -f "./push_swap" ]; then
    echo -e "${RED}Error: ./push_swap no encontrado${NC}"
    echo "Ejecuta: make"
    exit 1
fi

# Función para ejecutar test y mostrar resultado
run_test() {
    local description="$1"
    local args="$2"
    local should_work="$3"  # "yes" o "no"
    
    echo -e "${YELLOW}Test: $description${NC}"
    echo "Comando: ./push_swap $args"
    
    if [ "$should_work" = "yes" ]; then
        result=$(./push_swap $args 2>&1)
        exit_code=$?
        
        if [ $exit_code -eq 0 ]; then
            ops_count=$(echo "$result" | wc -l)
            echo -e "${GREEN}✅ Éxito${NC} - $ops_count operaciones"
            
            # Verificar que las operaciones son válidas
            if echo "$result" | grep -qE '^(sa|sb|ss|pa|pb|ra|rb|rr|rra|rrb|rrr)$'; then
                echo -e "${GREEN}✅ Operaciones válidas${NC}"
            else
                echo -e "${RED}❌ Operaciones inválidas detectadas${NC}"
            fi
        else
            echo -e "${RED}❌ Error (exit code: $exit_code)${NC}"
            echo "Output: $result"
        fi
    else
        result=$(./push_swap $args 2>&1)
        exit_code=$?
        
        if [ $exit_code -ne 0 ]; then
            echo -e "${GREEN}✅ Error esperado (exit code: $exit_code)${NC}"
        else
            echo -e "${RED}❌ Debería haber dado error pero no lo hizo${NC}"
            echo "Output: $result"
        fi
    fi
    echo "----------------------------------------"
}

echo -e "${YELLOW}1. CASOS QUE DEBEN FUNCIONAR${NC}"
echo "----------------------------------------"

# Casos básicos que deben funcionar
run_test "Un solo número" "42" "yes"
run_test "Dos números ordenados" "1 2" "yes"
run_test "Dos números desordenados" "2 1" "yes"
run_test "Tres números ya ordenados" "1 2 3" "yes"
run_test "Tres números desordenados" "3 1 2" "yes"
run_test "Cinco números ordenados" "1 2 3 4 5" "yes"
run_test "Cinco números desordenados" "5 3 1 4 2" "yes"
run_test "Números negativos" "-1 -2 0 1 2" "yes"
run_test "INT_MAX e INT_MIN" "2147483647 -2147483648" "yes"
run_test "String con espacios" "\"1 2 3 4 5\"" "yes"
run_test "Múltiples strings" "\"1 2\" \"3 4\" \"5\"" "yes"

echo
echo -e "${YELLOW}2. CASOS QUE DEBEN DAR ERROR${NC}"
echo "----------------------------------------"

# Casos que deben dar error
run_test "Sin argumentos" "" "no"
run_test "Números duplicados" "1 2 3 2" "no"
run_test "Carácter no numérico" "1 2 a 3" "no"
run_test "Número mayor que INT_MAX" "2147483648" "no"
run_test "Número menor que INT_MIN" "-2147483649" "no"
run_test "String vacío" "\"\"" "no"
run_test "Solo espacios" "\"   \"" "no"
run_test "Múltiples espacios" "\"1    2    3\"" "yes"  # Esto debería funcionar
run_test "Número con letras" "123abc" "no"
run_test "Signo sin número" "+" "no"
run_test "Múltiples signos" "++1" "no"

echo
echo -e "${YELLOW}3. CASOS ESPECÍFICOS DE RENDIMIENTO${NC}"
echo "----------------------------------------"

# Casos específicos para medir rendimiento
echo "🔸 Test 3 elementos - todas las permutaciones:"
three_cases=("1 2 3" "1 3 2" "2 1 3" "2 3 1" "3 1 2" "3 2 1")
for case in "${three_cases[@]}"; do
    ops=$(./push_swap $case | wc -l)
    if [ $ops -le 3 ]; then
        echo -e "${GREEN}✅${NC} $case -> $ops ops"
    else
        echo -e "${RED}❌${NC} $case -> $ops ops (debería ser ≤3)"
    fi
done

echo
echo "🔸 Test 5 elementos - casos problemáticos:"
five_cases=("5 4 3 2 1" "1 5 2 4 3" "2 1 4 3 5")
for case in "${five_cases[@]}"; do
    ops=$(./push_swap $case | wc -l)
    if [ $ops -le 12 ]; then
        echo -e "${GREEN}✅${NC} $case -> $ops ops"
    else
        echo -e "${YELLOW}⚠️${NC} $case -> $ops ops (recomendado ≤12)"
    fi
done

echo
echo "🔸 Test casos medianos (10-20 elementos):"
for size in 10 15 20; do
    random_case=$(shuf -i 1-$((size*2)) -n $size | tr '\n' ' ')
    ops=$(./push_swap $random_case | wc -l)
    echo "$size elementos -> $ops operaciones"
done

echo
echo -e "${YELLOW}4. TESTS DE INTEGRACIÓN CON CHECKER${NC}"
echo "----------------------------------------"

if [ -f "./checker" ]; then
    echo "🔸 Verificando que push_swap + checker funcionen juntos:"
    
    test_cases=("3 2 1" "5 4 3 2 1" "1 5 2 4 3")
    
    for case in "${test_cases[@]}"; do
        operations=$(./push_swap $case)
        result=$(echo "$operations" | ./checker $case 2>&1)
        
        if [ "$result" = "OK" ]; then
            echo -e "${GREEN}✅${NC} $case -> Checker: OK"
        else
            echo -e "${RED}❌${NC} $case -> Checker: $result"
        fi
    done
    
    echo
    echo "🔸 Tests del checker con operaciones inválidas:"
    
    # Test con operación inválida
    result=$(echo "invalid_op" | ./checker 1 2 3 2>&1)
    if [[ "$result" == *"Error"* ]] || [ "$result" = "Error" ]; then
        echo -e "${GREEN}✅${NC} Operación inválida -> Error (correcto)"
    else
        echo -e "${RED}❌${NC} Operación inválida -> $result (debería ser Error)"
    fi
    
    # Test con argumentos inválidos al checker
    result=$(./checker 1 2 a 2>&1)
    exit_code=$?
    if [ $exit_code -ne 0 ]; then
        echo -e "${GREEN}✅${NC} Argumentos inválidos al checker -> Error (correcto)"
    else
        echo -e "${RED}❌${NC} Argumentos inválidos al checker -> No dio error"
    fi
    
else
    echo -e "${YELLOW}⚠️ Checker no disponible - saltando tests de integración${NC}"
fi

echo
echo -e "${YELLOW}5. CASOS EXTREMOS Y EDGE CASES${NC}"
echo "----------------------------------------"

# Casos extremos
echo "🔸 Casos extremos de números:"

# Solo números negativos
neg_case="-5 -3 -1 -4 -2"
ops=$(./push_swap $neg_case | wc -l)
echo "Solo negativos ($neg_case) -> $ops ops"

# Mezclado de positivos y negativos
mixed_case="-2 5 -1 3 0"
ops=$(./push_swap $mixed_case | wc -l)
echo "Mezclado ($mixed_case) -> $ops ops"

# Números con rango muy grande
big_range="1 1000000 2 999999 3"
ops=$(./push_swap $big_range | wc -l)
echo "Rango grande ($big_range) -> $ops ops"

echo
echo "🔸 Tests de memoria (si tienes valgrind):"
if command -v valgrind &> /dev/null; then
    echo "Ejecutando test básico con valgrind..."
    valgrind --leak-check=full --error-exitcode=1 ./push_swap 3 2 1 > /dev/null 2>&1
    if [ $? -eq 0 ]; then
        echo -e "${GREEN}✅ Sin memory leaks detectados${NC}"
    else
        echo -e "${RED}❌ Memory leaks detectados${NC}"
    fi
else
    echo -e "${YELLOW}⚠️ Valgrind no disponible${NC}"
fi

echo
echo -e "${BLUE}========================================${NC}"
echo -e "${BLUE}           COMANDOS ÚTILES             ${NC}"
echo -e "${BLUE}========================================${NC}"
echo "• Test rápido: ./push_swap 3 2 1"
echo "• Contar operaciones: ./push_swap 3 2 1 | wc -l"
echo "• Test con checker: ./push_swap 3 2 1 | ./checker 3 2 1"
echo "• Test de memoria: valgrind ./push_swap 3 2 1"
echo "• Generar aleatorios: shuf -i 1-100 -n 5"
echo "• Test automático: ARG=\$(shuf -i 1-100 -n 5 | tr '\\n' ' '); ./push_swap \$ARG | wc -l"

echo
echo -e "${GREEN}✅ Tests de evaluación completados${NC}"
