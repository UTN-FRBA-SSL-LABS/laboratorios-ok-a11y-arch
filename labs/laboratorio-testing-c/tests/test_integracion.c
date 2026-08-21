#include <stdio.h>
#include "../src/carrito.h"
#include "minunit/minunit.h"

/*
 * Tests de integracion: verifican que las funciones trabajan bien
 * en combinacion, no de forma aislada.
 */

/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE D — Escribir el test guiado (ver README.md, Parte 8)
 * ═══════════════════════════════════════════════════════════════════════════ */

/* TODO: escribir test_compra_con_descuento() siguiendo la guia del .md */

void test_compra_con_descuento(void) {
    Carrito mi_carrito;
    carrito_init(&mi_carrito);

    /* Los atributos de Producto son: nombre, precio, cantidad */
    Producto pan = {"Pan", 200, 3};
    carrito_agregar(&mi_carrito, pan);

    Producto leche = {"Leche", 350, 2};
    carrito_agregar(&mi_carrito, leche);

    /* Validamos el comportamiento integrado de la suma */
    int total_calculado = carrito_total(&mi_carrito);
    ASSERT_IGUAL(1300, total_calculado);

    /* Validamos la aplicacion del descuento sobre ese total previo */
    int total_final_con_descuento = carrito_descuento(total_calculado, 10);
    ASSERT_IGUAL(1170, total_final_con_descuento);
}
/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE E — Disenar un test propio (ver README.md, Parte 9)
 * ═══════════════════════════════════════════════════════════════════════════ */
void test_agregar_hasta_llenar(void) {
    Carrito mi_carrito;
    carrito_init(&mi_carrito);

    /* Usamos un producto generico para la prueba */
    Producto manzana = {"Manzana", 100, 1};

    /* 1. Llenamos el carrito hasta su capacidad maxima (MAX_ITEMS = 4) */
    carrito_agregar(&mi_carrito, manzana);
    carrito_agregar(&mi_carrito, manzana);
    carrito_agregar(&mi_carrito, manzana);
    carrito_agregar(&mi_carrito, manzana);

    /* 2. Verificamos que el conteo alcanzo el limite exacto */
    ASSERT_IGUAL(4, carrito_contar(&mi_carrito));

    /* 3. Verificamos que el sistema rechace un quinto elemento (debe devolver 0) */
    int operacion_rechazada = carrito_agregar(&mi_carrito, manzana);
    ASSERT_IGUAL(0, operacion_rechazada);

    /* 4. Verificamos que el estado interno del carrito no se corrompio */
    ASSERT_IGUAL(4, carrito_contar(&mi_carrito));
}
/* TODO: escribir test_agregar_hasta_llenar() */

int main(void) {
    printf("=== Tests de integracion ===");
    /* Descomentar a medida que agregues las funciones: */
     test_compra_con_descuento();  
     test_agregar_hasta_llenar();  
    RESUMEN();
    return EXIT_CODE();
}
