#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./rubiks.h"

T_cubo_rubik *crearCubo(int tamano)
{
    T_cubo_rubik *cubo = malloc(sizeof(T_cubo_rubik));
    cubo->tamano = tamano;
    // cubo->nombre = scanf("%s.txt", cubo->nombre);
    if (cubo == NULL)
    {
        printf("No hay memoria para el cubo");
        eliminarCubo(cubo);
        exit(1);
    }
    int *ix = malloc(sizeof(int) * 6 * tamano * tamano);
    if (ix == NULL)
    {
        printf("no hay memoria para el cubo");
        exit(1);
    }
    for (int iLado = 0; iLado < 6; iLado++)
    {
        cubo->lados[iLado] = ix + (iLado * tamano * tamano);
        for (int i = 0; i < tamano * tamano; i++)
        {
            cubo->lados[iLado][i] = iLado;
        }
    }
    // fopen(cubo->nombre, "w");
    // fprintf(cubo->nombre, cubo);
    // fclose(cubo->nombre);
    return cubo;
}

void eliminarCubo(T_cubo_rubik *cubo)
{
    if (cubo)
    {
        free(cubo->lados[0]);
        cubo->lados[0] = NULL;
    }
    else if (cubo->nombre)
    {
        free(cubo);
        cubo = NULL;
    }
}

void ladoFilaAcadena(T_cubo_rubik *cubo, int lado, int fila, char *cadena)
{
    char aux[1000] = "0";
    for (int i = 0; i < cubo->tamano; i++)
    {
        aux[0] = '0' + cubo->lados[lado][fila * cubo->tamano + i];
        // aux[0] = '0' + cubo->lados[0][0];
        strcat(cadena, aux);
    }
    strcat(cadena, " ");
}

void mostrarCubo(T_cubo_rubik *cubo)
{
    char cadena[1000] = "";
    if (cubo == NULL || cubo->lados == NULL)
    {
        return;
    }
    for (int i = 0; i < cubo->tamano; i++)
    {
        ladoFilaAcadena(cubo, 0, i, cadena);
        strcat(cadena, "\n");
    }
    for (int i = 0; i < cubo->tamano; i++) {
        for (int iLado = 1; iLado < 5 ; iLado++)
        {
            ladoFilaAcadena(cubo, iLado, i, cadena);
            strcat(cadena, " ");
        }
        strcat(cadena, "\n");
    }
    for (int i = 0; i < cubo->tamano; i++)
    {
        ladoFilaAcadena(cubo, 5, i, cadena);
        strcat(cadena, "\n");
    }
    printf("%s", cadena);
}