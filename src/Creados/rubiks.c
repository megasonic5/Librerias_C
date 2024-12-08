#ifdef _RUBIKS_C
#define _RUBIKS_C 1

#include <stdio.h>
#include "rubiks.h"

T_cubo_rubik crearCubo(int tamano_x,int tamano_y) {
    int tamano = tamano_x*tamano_y;
    T_cubo_rubik *cubo = malloc(sizeof(T_cubo_rubik));
    cubo->nombre=scanf("%s.txt",cubo->nombre);
    if(cubo==NULL) {
        printf("No hay memoria para el cubo");
        eliminarCubo(cubo);
        return;
    }
    int *ix=malloc(sizeof(int)*6*tamano);
    if(ix==NULL) {
        printf("no hay memoria para el cubo");
        eliminarCubo(ix);
    }
    for(int i=0;i<6;i++) {
        cubo->lados[i]=P+i*tamano;
        for(int ilado=0;ilado<tamano;ilado++) {
            cubo->lados[i][ilado]=i;
        }
    }
    fopen(cubo->nombre,"w");
    fprintf(cubo->nombre,cubo);
    fclose(cubo->nombre);
    return cubo;
}

void eliminarCubo(T_cubo_rubik *cubo) {
    if(*cubo) {
        
    } else if(cubo->nombre) {
        remove(cubo->nombre);
    }
}
