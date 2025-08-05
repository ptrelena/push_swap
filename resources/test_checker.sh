#!/bin/bash

# CHECKER TEST BATTERY
# Batería de pruebas específica para el checker de push_swap

# Colores
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m'

echo -e "${BLUE}========================================${NC}"
echo -e "${BLUE}        CHECKER TEST BATTERY            ${NC}"
echo -e "${BLUE}========================================${NC}"

# Verificar que checker existe
if [ ! -f "./checker" ]; then
    echo -e "${YELLOW}Checker no encontrado, intentando compilar...${NC}"
    make bonus 2>/dev/null || make checker 2>/dev/null
    if [ ! -f "./checker" ]; then
        echo -e "${RED}Checker no disponible, saltando tests${NC}"
        exit 1
    fi
fi

# Función para test de checker
test_checker() {
    local args="$1"
    local operations="$2"
    local expected="$3"
    local description="$4"
    
    result=$(echo "$operations" | ./checker $args 2>&1)
    
    if [ "$result" = "$expected" ]; then
        echo -e "${GREEN}✓ PASS${NC} - $description"
    else
        echo -e "${RED}✗ FAIL${NC} - $description"
        echo "  Expected: $expected"
        echo "  Got: $result"
    fi
}

echo -e "${YELLOW}1. TESTS BÁSICOS DEL CHECKER${NC}"
echo "----------------------------------------"

# Test 1: Ya ordenado sin operaciones
test_checker "1 2 3" "" "OK" "Ya ordenado sin operaciones"

# Test 2: Intercambio simple
test_checker "2 1" "sa" "OK" "Intercambio simple con sa"

# Test 3: Operación que no ordena
test_checker "2 1" "ra" "KO" "Operación que no ordena"

# Test 4: Múltiples operaciones válidas
test_checker "3 2 1" "sa
rra" "OK" "Múltiples operaciones válidas"

# Test 5: Operación inválida
test_checker "1 2 3" "invalid_op" "Error" "Operación inválida"

echo
echo -e "${YELLOW}2. TESTS DE INTEGRACIÓN${NC}"
echo "----------------------------------------"

# Test con push_swap output
if [ -f "./push_swap" ]; then
    echo "Probando integración push_swap + checker..."
    
    test_cases=(
        "3 2 1"
        "5 4 3 2 1"
        "1 5 2 4 3"
        "2 1 4 3"
    )
    
    for test_case in "${test_cases[@]}"; do
        operations=$(./push_swap $test_case)
        result=$(echo "$operations" | ./checker $test_case 2>&1)
        
        if [ "$result" = "OK" ]; then
            echo -e "${GREEN}✓ PASS${NC} - push_swap + checker: $test_case"
        else
            echo -e "${RED}✗ FAIL${NC} - push_swap + checker: $test_case"
            echo "  Checker result: $result"
        fi
    done
fi

echo
echo -e "${YELLOW}3. TESTS DE CASOS LÍMITE${NC}"
echo "----------------------------------------"

# Test con argumentos inválidos
test_checker "1 2 a" "" "Error" "Argumentos inválidos"

# Test con números duplicados
test_checker "1 2 2" "" "Error" "Números duplicados"

# Test sin argumentos
result=$(echo "" | ./checker 2>&1)
exit_code=$?
if [ $exit_code -ne 0 ]; then
    echo -e "${GREEN}✓ PASS${NC} - Sin argumentos (debe dar error)"
else
    echo -e "${RED}✗ FAIL${NC} - Sin argumentos (debe dar error)"
fi

echo
echo -e "${GREEN}Tests del checker completados${NC}"
