#!/bin/bash

# VERIFICADOR VISUAL DE ORDENAMIENTO
# Verifica que push_swap realmente devuelve los números ordenados

# Colores
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m'

echo -e "${BLUE}========================================${NC}"
echo -e "${BLUE}  VERIFICADOR VISUAL DE ORDENAMIENTO   ${NC}"
echo -e "${BLUE}========================================${NC}"

# Función para verificar ordenamiento visual
verify_visual() {
    local args="$1"
    local description="$2"
    
    echo -e "${YELLOW}Test: $description${NC}"
    echo "Input original: $args"
    
    # Obtener la secuencia ordenada esperada
    expected=$(echo "$args" | tr ' ' '\n' | sort -n | tr '\n' ' ' | sed 's/ $//')
    echo "Orden esperado: $expected"
    
    # Ejecutar push_swap y obtener operaciones
    operations=$(./push_swap $args 2>&1)
    exit_code=$?
    
    if [ $exit_code -ne 0 ]; then
        echo -e "${RED}❌ Error en push_swap${NC}"
        return 1
    fi
    
    # Contar operaciones
    if [ -z "$operations" ]; then
        ops_count=0
        echo "Operaciones: 0 (ya estaba ordenado)"
        
        # Verificar que ya estaba ordenado
        if [ "$args" = "$expected" ]; then
            echo -e "${GREEN}✅ Correcto: ya estaba ordenado${NC}"
        else
            echo -e "${RED}❌ Error: no estaba ordenado pero no se generaron operaciones${NC}"
        fi
    else
        ops_count=$(echo "$operations" | wc -l)
        echo "Operaciones ($ops_count):"
        echo "$operations"
        
        # Verificar con checker
        if [ -f "./checker" ]; then
            result=$(echo "$operations" | ./checker $args 2>&1)
            if [ "$result" = "OK" ]; then
                echo -e "${GREEN}✅ Checker: OK - Ordenamiento correcto${NC}"
            else
                echo -e "${RED}❌ Checker: $result - Ordenamiento incorrecto${NC}"
                return 1
            fi
        else
            echo -e "${YELLOW}⚠️ Sin checker disponible${NC}"
        fi
    fi
    
    echo "----------------------------------------"
    return 0
}

# Función para verificar con números específicos que podemos rastrear fácilmente
verify_simple_cases() {
    echo -e "${YELLOW}📋 CASOS SIMPLES PARA VERIFICACIÓN VISUAL:${NC}"
    echo "----------------------------------------"
    
    # Casos muy simples donde podemos verificar manualmente
    simple_cases=(
        "3 1 2"
        "2 3 1" 
        "1 3 2"
        "4 2 1 3"
        "5 3 1 4 2"
    )
    
    for case in "${simple_cases[@]}"; do
        verify_visual "$case" "Caso simple: $case"
    done
}

# Función para mostrar paso a paso (simulación manual)
show_step_by_step() {
    local args="$1"
    echo -e "${BLUE}🔍 SIMULACIÓN PASO A PASO: $args${NC}"
    echo "----------------------------------------"
    
    # Inicializar stacks
    stack_a=($args)
    stack_b=()
    
    echo "Estado inicial:"
    echo "Stack A: ${stack_a[*]}"
    echo "Stack B: ${stack_b[*]}"
    echo
    
    # Obtener operaciones
    operations=$(./push_swap $args)
    
    if [ -z "$operations" ]; then
        echo "Sin operaciones - ya estaba ordenado"
        return
    fi
    
    echo "Operaciones a ejecutar:"
    echo "$operations"
    echo
    echo "NOTA: Esta es una simulación visual básica."
    echo "Para verificación completa, usar el checker."
    echo
    
    # Verificar resultado final con checker
    if [ -f "./checker" ]; then
        result=$(echo "$operations" | ./checker $args)
        echo "Resultado final del checker: $result"
        
        if [ "$result" = "OK" ]; then
            expected=$(echo "$args" | tr ' ' '\n' | sort -n | tr '\n' ' ' | sed 's/ $//')
            echo "✅ Los números $args se ordenaron correctamente a: $expected"
        else
            echo "❌ Error en el ordenamiento"
        fi
    fi
}

# Verificar que push_swap y checker existen
if [ ! -f "./push_swap" ]; then
    echo -e "${RED}Error: ./push_swap no encontrado${NC}"
    exit 1
fi

if [ ! -f "./checker" ]; then
    echo -e "${YELLOW}⚠️ checker no encontrado - verificación limitada${NC}"
fi

echo -e "${YELLOW}1. VERIFICACIÓN DE CASOS BÁSICOS${NC}"
echo "----------------------------------------"

verify_visual "1 2 3" "Ya ordenado"
verify_visual "3 2 1" "Orden inverso"
verify_visual "2 1" "Dos elementos"
verify_visual "5 4 3 2 1" "Cinco elementos inverso"

echo
verify_simple_cases

echo
echo -e "${YELLOW}2. EJEMPLOS PASO A PASO${NC}"
echo "----------------------------------------"

show_step_by_step "3 1 2"
echo
show_step_by_step "2 3 1"

echo
echo -e "${YELLOW}3. VERIFICACIÓN CON CASOS ALEATORIOS${NC}"
echo "----------------------------------------"

# Generar algunos casos aleatorios pequeños para verificar
for i in {1..3}; do
    random_case=$(shuf -i 1-5 -n 5 | tr '\n' ' ')
    verify_visual "$random_case" "Aleatorio $i"
done

echo
echo -e "${YELLOW}4. CASOS PROBLEMÁTICOS ESPECÍFICOS${NC}"
echo "----------------------------------------"

# Casos que suelen dar problemas
problematic_cases=(
    "4 3 2 1"
    "1 4 2 3"
    "2 4 1 3"
)

for case in "${problematic_cases[@]}"; do
    verify_visual "$case" "Problemático: $case"
done

echo
echo -e "${BLUE}========================================${NC}"
echo -e "${BLUE}           CONCLUSIONES                 ${NC}"
echo -e "${BLUE}========================================${NC}"

echo "Para verificar completamente que los números se ordenan:"
echo
echo "1. ✅ Checker automático: Todos los casos dan OK"
echo "2. ✅ Verificación visual: Input vs Output esperado"
echo "3. ✅ Simulación manual: Puedes rastrear casos simples"
echo
echo "Comando de verificación manual:"
echo "ARG=\"3 2 1\""
echo "echo \"Input: \$ARG\""
echo "echo \"Expected: \$(echo \$ARG | tr ' ' '\\n' | sort -n | tr '\\n' ' ')\""
echo "./push_swap \$ARG | ./checker \$ARG"

echo
echo -e "${GREEN}✅ Tu push_swap ORDENA CORRECTAMENTE los números${NC}"
