#ifdef _RUBIKS_C
#define _RUBIKS_C 1

#include <stdio.h>
#include "rubiks.h"

T_cubo_rubik crearCubo(int tamano) {
    T_cubo_rubik *cubo = malloc(sizeof(T_cubo_rubik));
    if(cubo==NULL) {
        printf("No hay memoria para el cubo");
        exit(1);
    }
    int *P=malloc(sizeof(int)*6*tamano*tamano);
    if(P==NULL) {
        printf("no hay memoria para el cubo");
        exit(1);
    }
    for(int i=0;i<6;i++) {
        cubo->lados[i]=P+i*tamano*tamano;
        for(int ilado=0;ilado<tamano*tamano;ilado++) {
            cubo->lados[i][ilado]=i;
        }
    }
    return cubo;
}
