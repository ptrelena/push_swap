#!/bin/bash

# VERIFICADOR DE ORDENAMIENTO CORRECTO
# Verifica que push_swap realmente ordene los números

# Colores
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m'

echo -e "${BLUE}========================================${NC}"
echo -e "${BLUE}   VERIFICADOR DE ORDENAMIENTO         ${NC}"
echo -e "${BLUE}========================================${NC}"

# Función para simular las operaciones y verificar si el resultado final está ordenado
verify_sorting() {
    local args="$1"
    local description="$2"
    
    echo -e "${YELLOW}Test: $description${NC}"
    echo "Input: $args"
    
    # Ejecutar push_swap y obtener las operaciones
    operations=$(./push_swap $args 2>&1)
    exit_code=$?
    
    if [ $exit_code -ne 0 ]; then
        echo -e "${RED}❌ Error en push_swap (exit code: $exit_code)${NC}"
        echo "Output: $operations"
        echo "----------------------------------------"
        return 1
    fi
    
    # Contar operaciones
    if [ -z "$operations" ]; then
        ops_count=0
    else
        ops_count=$(echo "$operations" | wc -l)
    fi
    
    echo "Operaciones ($ops_count):"
    if [ $ops_count -gt 0 ]; then
        echo "$operations"
    else
        echo "(ninguna - ya ordenado)"
    fi
    
    # Verificar que las operaciones sean válidas
    if [ $ops_count -gt 0 ]; then
        invalid_ops=$(echo "$operations" | grep -v '^(sa|sb|ss|pa|pb|ra|rb|rr|rra|rrb|rrr)$')
        if [ -n "$invalid_ops" ]; then
            echo -e "${RED}❌ Operaciones inválidas detectadas:${NC}"
            echo "$invalid_ops"
            echo "----------------------------------------"
            return 1
        fi
    fi
    
    # Si tenemos checker, usarlo para verificar
    if [ -f "./checker" ]; then
        result=$(echo "$operations" | ./checker $args 2>&1)
        if [ "$result" = "OK" ]; then
            echo -e "${GREEN}✅ Checker: OK - Ordenamiento correcto${NC}"
        else
            echo -e "${RED}❌ Checker: $result - Ordenamiento incorrecto${NC}"
            echo "----------------------------------------"
            return 1
        fi
    else
        # Verificación manual: ordenar los números de entrada y comparar
        sorted_input=$(echo "$args" | tr ' ' '\n' | sort -n | tr '\n' ' ' | sed 's/ $//')
        input_clean=$(echo "$args" | sed 's/^ *//;s/ *$//')
        
        if [ "$sorted_input" = "$input_clean" ]; then
            if [ $ops_count -eq 0 ]; then
                echo -e "${GREEN}✅ Ya estaba ordenado y no se hicieron operaciones${NC}"
            else
                echo -e "${YELLOW}⚠️  Ya estaba ordenado pero se hicieron $ops_count operaciones${NC}"
            fi
        else
            echo -e "${YELLOW}⚠️  Sin checker no podemos verificar el ordenamiento final${NC}"
            echo "Se recomienda compilar el checker para verificación completa"
        fi
    fi
    
    echo "----------------------------------------"
    return 0
}

# Verificar que push_swap existe
if [ ! -f "./push_swap" ]; then
    echo -e "${RED}Error: ./push_swap no encontrado${NC}"
    exit 1
fi

# Intentar compilar checker si no existe
if [ ! -f "./checker" ]; then
    echo -e "${YELLOW}Intentando compilar checker...${NC}"
    make bonus 2>/dev/null || make checker 2>/dev/null
    if [ -f "./checker" ]; then
        echo -e "${GREEN}✅ Checker compilado${NC}"
    else
        echo -e "${YELLOW}⚠️  Checker no disponible - verificación limitada${NC}"
    fi
    echo
fi

echo -e "${YELLOW}1. CASOS BÁSICOS${NC}"
echo "----------------------------------------"

verify_sorting "1 2 3" "Ya ordenado (3 elementos)"
verify_sorting "3 2 1" "Desordenado (3 elementos)"
verify_sorting "2 1" "Desordenado (2 elementos)"
verify_sorting "5 4 3 2 1" "Orden inverso (5 elementos)"
verify_sorting "1 5 2 4 3" "Mezclado (5 elementos)"

echo
echo -e "${YELLOW}2. CASOS CON NÚMEROS NEGATIVOS${NC}"
echo "----------------------------------------"

verify_sorting "-1 -2 0 1 2" "Con negativos"
verify_sorting "-5 -3 -1 -4 -2" "Solo negativos"
verify_sorting "0" "Solo cero"

echo
echo -e "${YELLOW}3. CASOS LÍMITE${NC}"
echo "----------------------------------------"

verify_sorting "2147483647 -2147483648" "INT_MAX e INT_MIN"
verify_sorting "42" "Un solo número"

echo
echo -e "${YELLOW}4. CASOS ALEATORIOS${NC}"
echo "----------------------------------------"

# Test con números aleatorios pequeños
for i in {1..3}; do
    random_case=$(shuf -i 1-10 -n 5 | tr '\n' ' ')
    verify_sorting "$random_case" "Aleatorio $i (5 elementos)"
done

# Test con más elementos
random_medium=$(shuf -i 1-20 -n 10 | tr '\n' ' ')
verify_sorting "$random_medium" "Aleatorio (10 elementos)"

echo
echo -e "${YELLOW}5. TODAS LAS PERMUTACIONES DE 3 ELEMENTOS${NC}"
echo "----------------------------------------"

three_perms=("1 2 3" "1 3 2" "2 1 3" "2 3 1" "3 1 2" "3 2 1")
for perm in "${three_perms[@]}"; do
    verify_sorting "$perm" "Permutación: $perm"
done

echo
echo -e "${BLUE}========================================${NC}"
echo -e "${BLUE}           CONCLUSIONES                 ${NC}"
echo -e "${BLUE}========================================${NC}"

if [ -f "./checker" ]; then
    echo -e "${GREEN}✅ Verificación completa realizada con checker${NC}"
    echo "Si todos los tests muestran 'Checker: OK', tu push_swap"
    echo "está ordenando correctamente los números."
else
    echo -e "${YELLOW}⚠️  Verificación limitada sin checker${NC}"
    echo "Para una verificación completa, compila el checker:"
    echo "make bonus    (o)    make checker"
    echo
    echo "También puedes verificar manualmente:"
    echo "ARG=\"3 2 1\"; ./push_swap \$ARG | ./checker \$ARG"
fi

echo
echo "Para hacer una verificación manual completa:"
echo "1. Toma un caso de prueba: ARG=\"5 4 3 2 1\""
echo "2. Ejecuta: ./push_swap \$ARG"
echo "3. Aplica manualmente las operaciones a los stacks"
echo "4. Verifica que el stack A quede ordenado y B vacío"
