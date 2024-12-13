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
    }
    else if (cubo)
    {
        free(cubo);
        cubo = NULL;
    }
}

void ladoFilaACadena(T_cubo_rubik *cubo, int lado, int fila, char *cadena)
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
        ladoFilaACadena(cubo, 0, i, cadena);
        strcat(cadena, "\n");
    }
    for (int i = 0; i < cubo->tamano; i++)
    {
        for (int iLado = 1; iLado < 5; iLado++)
        {
            ladoFilaACadena(cubo, iLado, i, cadena);
            strcat(cadena, " ");
        }
        strcat(cadena, "\n");
    }
    for (int i = 0; i < cubo->tamano; i++)
    {
        ladoFilaACadena(cubo, 5, i, cadena);
        strcat(cadena, "\n");
    }
    printf("%s", cadena);
    if (cuboOrdenado(cubo))
        printf("El cubo esta ordenado\n");
    else
        printf("El cubo esta desordenado\n");
}

void giraCubo(T_cubo_rubik *cubo, int cara, int direccion)
{
}

void desordenarCubo(T_cubo_rubik *cubo)
{
}

void ordenaCubo(T_cubo_rubik *cubo)
{
}

int cuboOrdenado(T_cubo_rubik *cubo)
{
    for (int iLado = 0; iLado < 6; iLado++)
    {
        int color = cubo->lados[iLado][0];
        for (int i = 1; i < cubo->tamano * cubo->tamano; i++)
        {
            if (cubo->lados[iLado][i] != color)
                return 0;
        }
    }
    return 1;
}

void guardarCubo(T_cubo_rubik *cubo, char *nombre) {
    //strcat(nombre, ".txt");
    FILE *f = fopen(nombre,"wb");
    fwrite(&cubo->tamano, sizeof(int), 1, f);
    fwrite(cubo->lados[0], sizeof(int), cubo->tamano * cubo->tamano * 6, f);
    fclose(f);
}

T_cubo_rubik *leerCubo(char *nombre) {
    //strcat(nombre, ".txt");
    FILE *f = fopen(nombre,"rb");
    int tamano;
    T_cubo_rubik *cubo;
    fread(&tamano, sizeof(int), 1, f);
    cubo = crearCubo(tamano);
    fread(cubo->lados[0], sizeof(int), cubo->tamano * cubo->tamano * 6, f);
    fclose(f);
    return cubo;
}

T_cubo_rubik *clonarCubo(T_cubo_rubik *cubo)
{
    T_cubo_rubik *cuboNuevo = crearCubo(cubo->tamano);
    for (int iLado = 0; iLado < 6; iLado++)
    {
        for (int i = 0; i < cuboNuevo->tamano * cubo->tamano; i++)
        {
            cuboNuevo->lados[iLado][i] = cubo->lados[iLado][i];
        }
    }
    return cuboNuevo;
}