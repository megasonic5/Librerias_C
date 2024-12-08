#include "./Creados/rubiks.h"
#include "./Creados/rubiks.c"



void main() {
    T_cubo_rubik *cubo = crearCubo(3);
    mostrarCubo(cubo);
    eliminarCubo(cubo);
}