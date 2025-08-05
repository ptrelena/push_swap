#!/bin/bash

# MASTER TEST RUNNER
# Script maestro que ejecuta toda la batería de pruebas

# Colores
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
MAGENTA='\033[0;35m'
NC='\033[0m'

echo -e "${MAGENTA}╔══════════════════════════════════════╗${NC}"
echo -e "${MAGENTA}║        PUSH_SWAP TEST SUITE          ║${NC}"
echo -e "${MAGENTA}║          Batería Completa            ║${NC}"
echo -e "${MAGENTA}╚══════════════════════════════════════╝${NC}"
echo

# Verificar que estamos en el directorio correcto
if [ ! -f "push_swap.c" ] && [ ! -f "Makefile" ]; then
    echo -e "${RED}Error: No estás en el directorio del proyecto push_swap${NC}"
    echo "Asegúrate de ejecutar este script desde el directorio que contiene push_swap.c"
    exit 1
fi

# Función para preguntar al usuario
ask_user() {
    while true; do
        read -p "$1 (y/n): " yn
        case $yn in
            [Yy]* ) return 0;;
            [Nn]* ) return 1;;
            * ) echo "Por favor responde y o n.";;
        esac
    done
}

# Compilar el proyecto
echo -e "${YELLOW}🔨 COMPILANDO PROYECTO${NC}"
echo "----------------------------------------"
make clean > /dev/null 2>&1
make

if [ ! -f "./push_swap" ]; then
    echo -e "${RED}❌ Error: No se pudo compilar push_swap${NC}"
    exit 1
fi
echo -e "${GREEN}✅ push_swap compilado exitosamente${NC}"

# Intentar compilar bonus/checker si existe
if grep -q "bonus\|checker" Makefile 2>/dev/null; then
    make bonus > /dev/null 2>&1 || make checker > /dev/null 2>&1
    if [ -f "./checker" ]; then
        echo -e "${GREEN}✅ checker compilado exitosamente${NC}"
    fi
fi

echo

# Hacer ejecutables los scripts de test
chmod +x test_push_swap.sh 2>/dev/null
chmod +x test_checker.sh 2>/dev/null
chmod +x performance_test.sh 2>/dev/null

# Menu de opciones
echo -e "${BLUE}¿Qué tests quieres ejecutar?${NC}"
echo "1. Tests básicos de funcionalidad"
echo "2. Tests de rendimiento"
echo "3. Tests del checker (si está disponible)"
echo "4. Todos los tests"
echo "5. Test rápido (solo casos críticos)"
echo

read -p "Selecciona una opción (1-5): " option

case $option in
    1)
        echo -e "${YELLOW}🧪 EJECUTANDO TESTS BÁSICOS${NC}"
        ./test_push_swap.sh
        ;;
    2)
        echo -e "${YELLOW}⚡ EJECUTANDO TESTS DE RENDIMIENTO${NC}"
        ./performance_test.sh
        ;;
    3)
        if [ -f "./checker" ]; then
            echo -e "${YELLOW}🔍 EJECUTANDO TESTS DEL CHECKER${NC}"
            ./test_checker.sh
        else
            echo -e "${RED}❌ Checker no disponible${NC}"
        fi
        ;;
    4)
        echo -e "${YELLOW}🚀 EJECUTANDO TODOS LOS TESTS${NC}"
        echo
        ./test_push_swap.sh
        echo
        ./performance_test.sh
        echo
        if [ -f "./checker" ]; then
            ./test_checker.sh
        fi
        ;;
    5)
        echo -e "${YELLOW}⚡ TEST RÁPIDO${NC}"
        echo "----------------------------------------"
        
        # Tests críticos rápidos
        echo "🔸 Test sin argumentos:"
        ./push_swap 2>&1; echo "Exit code: $?"
        
        echo "🔸 Test números duplicados:"
        ./push_swap 1 2 2 2>&1; echo "Exit code: $?"
        
        echo "🔸 Test ya ordenado:"
        ./push_swap 1 2 3 4 5; echo "Operaciones: $(./push_swap 1 2 3 4 5 | wc -l)"
        
        echo "🔸 Test 3 elementos (3 2 1):"
        ops=$(./push_swap 3 2 1 | wc -l)
        echo "Operaciones: $ops (máx recomendado: 3)"
        
        echo "🔸 Test 5 elementos aleatorios:"
        random_5=$(shuf -i 1-10 -n 5 | tr '\n' ' ')
        ops=$(./push_swap $random_5 | wc -l)
        echo "Secuencia: $random_5"
        echo "Operaciones: $ops (máx recomendado: 12)"
        
        echo "🔸 Test 100 elementos:"
        random_100=$(shuf -i 1-100 -n 100 | tr '\n' ' ')
        ops=$(./push_swap $random_100 | wc -l)
        echo "Operaciones: $ops (máx recomendado: 700)"
        
        if [ -f "./checker" ]; then
            echo "🔸 Test integración con checker:"
            result=$(./push_swap 3 2 1 | ./checker 3 2 1)
            echo "Resultado checker: $result"
        fi
        
        echo -e "${GREEN}✅ Test rápido completado${NC}"
        ;;
    *)
        echo -e "${RED}Opción inválida${NC}"
        exit 1
        ;;
esac

echo
echo -e "${BLUE}📋 RESUMEN Y RECOMENDACIONES${NC}"
echo "----------------------------------------"
echo "• Para proyecto obligatorio: Tests básicos deben pasar"
echo "• Para bonus: Tests del checker deben pasar"
echo "• Rendimiento objetivo:"
echo "  - 3 elementos: ≤ 3 operaciones"
echo "  - 5 elementos: ≤ 12 operaciones"
echo "  - 100 elementos: ≤ 700 operaciones (≤ 550 excelente)"
echo "  - 500 elementos: ≤ 5500 operaciones (≤ 4500 excelente)"
echo
echo "• Si tienes memory leaks, usa: valgrind --leak-check=full ./push_swap [args]"
echo "• Para más tests: bash test_push_swap.sh"

if ask_user "¿Quieres generar un reporte detallado?"; then
    echo
    echo -e "${YELLOW}📊 GENERANDO REPORTE DETALLADO${NC}"
    
    # Crear archivo de reporte
    report_file="push_swap_report_$(date +%Y%m%d_%H%M%S).txt"
    
    {
        echo "PUSH_SWAP TEST REPORT"
        echo "====================="
        echo "Fecha: $(date)"
        echo "Directorio: $(pwd)"
        echo
        
        echo "COMPILACIÓN:"
        echo "------------"
        make clean > /dev/null 2>&1
        if make 2>&1; then
            echo "✅ Compilación exitosa"
        else
            echo "❌ Error en compilación"
        fi
        echo
        
        echo "TESTS CRÍTICOS:"
        echo "---------------"
        
        # Test casos críticos y guardar resultados
        echo "Test 3 elementos (todas las permutaciones):"
        for perm in "1 2 3" "1 3 2" "2 1 3" "2 3 1" "3 1 2" "3 2 1"; do
            ops=$(./push_swap $perm | wc -l)
            echo "  $perm -> $ops operaciones"
        done
        
        echo
        echo "Test rendimiento 5 elementos (10 casos):"
        for i in {1..10}; do
            random_5=$(shuf -i 1-10 -n 5 | tr '\n' ' ')
            ops=$(./push_swap $random_5 | wc -l)
            echo "  Caso $i: $ops operaciones"
        done
        
        echo
        echo "Test rendimiento 100 elementos (3 casos):"
        for i in {1..3}; do
            random_100=$(shuf -i 1-100 -n 100 | tr '\n' ' ')
            ops=$(./push_swap $random_100 | wc -l)
            echo "  Caso $i: $ops operaciones"
        done
        
    } > "$report_file"
    
    echo -e "${GREEN}✅ Reporte guardado en: $report_file${NC}"
fi

echo
echo -e "${MAGENTA}🎉 Testing completado! Good luck con la evaluación! 🎉${NC}"
