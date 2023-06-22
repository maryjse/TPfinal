#ifndef MASA_H
#define MASA_H

#include <stdlib.h>
#include <stdbool.h>

//TDA que representa una masa.
//Contiene la posición inicial de la masa y su valor.
typedef struct masa{
    size_t x, y;
    float masa; //tenemos que ver que masa tendra la masa..
} masa_t;

//Crea una masa.
//Post: En caso de no poder crear la masa devuelve NULL.
masa_t *masa_crear(size_t xi, size_t yi);

//Destruye la masa.
//Pre: La masa debe estar previamente creada.
void masa_destruir(masa_t *m);

//Devuelve la posición de una masa.
//Pre: Masa != NULL.
//Post: Devuelve la posicion de la masa sin modificarla.
void obtener_posicion(const masa_t *m, size_t *pos_x, size_t *pos_y);

//Cambia la posicion de una masa existente.
//Pre: Masa != NULL.
void cambiar_posicion_masa(masa_t *masa, size_t nueva_x, size_t nueva_y); 

#endif