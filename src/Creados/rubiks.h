#ifndef _RUBIKS_H
    #define _RUBIKS_H 1

    typedef struct {
        int tamano;
        int *lados[6];
        char *nombre;
    } T_cubo_rubik;

    T_cubo_rubik *crearCubo(int tamano);
    void eliminarCubo(T_cubo_rubik *cubo);
    void giraCubo(T_cubo_rubik *cubo,int cara,int direccion);
    void desordenarCubo(T_cubo_rubik *cubo);
    void ordenaCubo(T_cubo_rubik *cubo);
    void cuboOrdenado(T_cubo_rubik *cubo);
    void mostrarCubo(T_cubo_rubik *cubo);
    void guardarCubo(T_cubo_rubik *cubo);
    void ladoFilaACadena(T_cubo_rubik *cubo, int lado, int fila, char *cadena);

#endif
