#!/bin/bash

# PERFORMANCE TEST GENERATOR
# Genera casos de prueba específicos para medir rendimiento

# Colores
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m'

echo -e "${BLUE}========================================${NC}"
echo -e "${BLUE}    PERFORMANCE TEST GENERATOR         ${NC}"
echo -e "${BLUE}========================================${NC}"

# Verificar que push_swap existe
if [ ! -f "./push_swap" ]; then
    echo -e "${RED}Error: ./push_swap no encontrado${NC}"
    exit 1
fi

# Función para generar números aleatorios únicos
generate_random() {
    local count=$1
    local max_val=$2
    shuf -i 1-$max_val -n $count | tr '\n' ' '
}

# Función para medir rendimiento
measure_performance() {
    local size=$1
    local iterations=$2
    local max_operations_good=$3
    local max_operations_excellent=$4
    
    echo -e "${YELLOW}Testando $iterations casos de $size elementos:${NC}"
    
    local total_ops=0
    local excellent_count=0
    local good_count=0
    local ok_count=0
    local poor_count=0
    
    for i in $(seq 1 $iterations); do
        local random_nums=$(generate_random $size $((size * 2)))
        local result=$(./push_swap $random_nums)
        local ops_count=$(echo "$result" | wc -l)
        
        total_ops=$((total_ops + ops_count))
        
        if [ $ops_count -le $max_operations_excellent ]; then
            excellent_count=$((excellent_count + 1))
        elif [ $ops_count -le $max_operations_good ]; then
            good_count=$((good_count + 1))
        elif [ $ops_count -le $((max_operations_good + 200)) ]; then
            ok_count=$((ok_count + 1))
        else
            poor_count=$((poor_count + 1))
        fi
        
        printf "Test %d/%d: %d operaciones\r" $i $iterations $ops_count
    done
    
    echo ""
    local avg_ops=$((total_ops / iterations))
    
    echo "Resultados:"
    echo "  Promedio de operaciones: $avg_ops"
    echo -e "  ${GREEN}Excelente (<= $max_operations_excellent ops): $excellent_count${NC}"
    echo -e "  ${BLUE}Bueno (<= $max_operations_good ops): $good_count${NC}"
    echo -e "  ${YELLOW}OK: $ok_count${NC}"
    echo -e "  ${RED}Pobre: $poor_count${NC}"
    echo ""
}

echo -e "${YELLOW}1. CASOS ESPECÍFICOS PROBLEMÁTICOS${NC}"
echo "----------------------------------------"

# Casos que suelen dar problemas
problematic_cases=(
    "1 2 3 4 5"                    # Ya ordenado
    "5 4 3 2 1"                    # Orden inverso
    "2 1 4 3 6 5 8 7 10 9"         # Pares intercambiados
    "1 3 5 7 9 2 4 6 8 10"         # Impares primero
    "10 9 8 7 6 5 4 3 2 1"         # Descendente
)

for case in "${problematic_cases[@]}"; do
    result=$(./push_swap $case)
    ops_count=$(echo "$result" | wc -l)
    echo "Caso: $case -> $ops_count operaciones"
done

echo
echo -e "${YELLOW}2. TESTS DE RENDIMIENTO AUTOMÁTICOS${NC}"
echo "----------------------------------------"

# Test 3 elementos (todas las permutaciones)
echo "Testando todas las permutaciones de 3 elementos:"
three_element_cases=(
    "1 2 3"  "1 3 2"  "2 1 3"  "2 3 1"  "3 1 2"  "3 2 1"
)

for case in "${three_element_cases[@]}"; do
    result=$(./push_swap $case)
    ops_count=$(echo "$result" | wc -l)
    printf "%-10s -> %d ops\n" "$case" $ops_count
done

echo
# Test 5 elementos
measure_performance 5 20 12 8

# Test 100 elementos
measure_performance 100 10 700 550

# Test 500 elementos
measure_performance 500 5 5500 4500

echo -e "${YELLOW}3. CASOS EXTREMOS${NC}"
echo "----------------------------------------"

# Caso con muchos números pequeños
echo "Testando números pequeños (1-10):"
small_nums=$(generate_random 10 10)
result=$(./push_swap $small_nums)
ops_count=$(echo "$result" | wc -l)
echo "10 números (1-10): $ops_count operaciones"

# Caso con rango grande
echo "Testando rango grande:"
large_range=$(shuf -i 1-1000000 -n 100 | tr '\n' ' ')
result=$(./push_swap $large_range)
ops_count=$(echo "$result" | wc -l)
echo "100 números (1-1000000): $ops_count operaciones"

# Caso con números negativos
echo "Testando números negativos:"
negative_nums=$(shuf -i -500-500 -n 50 | tr '\n' ' ')
result=$(./push_swap $negative_nums)
ops_count=$(echo "$result" | wc -l)
echo "50 números (-500 a 500): $ops_count operaciones"

echo
echo -e "${YELLOW}4. GENERADOR DE CASOS PERSONALIZADOS${NC}"
echo "----------------------------------------"

echo "Para generar tus propios casos de prueba:"
echo "# Generar 100 números aleatorios:"
echo "shuf -i 1-100 -n 100 | tr '\\n' ' '"
echo ""
echo "# Generar caso específico y testear:"
echo "ARG=\$(shuf -i 1-500 -n 500 | tr '\\n' ' '); ./push_swap \$ARG | wc -l"
echo ""
echo "# Testear con checker:"
echo "ARG=\"3 2 1\"; ./push_swap \$ARG | ./checker \$ARG"

echo
echo -e "${GREEN}Tests de rendimiento completados${NC}"
