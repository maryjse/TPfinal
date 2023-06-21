#ifndef MALLA_H
#define MALLA_H

#include "lista.h"
#include "masa.h"
#include "resorte.h"

typedef struct masas{
    masa_t *masa[MASA_TOTAL];
    size_t masas_totales;
} masas_t;

typedef struct resortes {
    lista_t *resorte;
    size_t resortes_totales;
} resortes_t;

//TDA que representa una malla.
//Contiene las masas y los resortes creados.
typedef struct malla malla_t;

//Destruye la malla.
//Pre: la masa y los resortes deben existir previamente.
//Post: destruye todas las masas y los resortes.
void malla_destruir(malla_t *malla);

//Mueve un nodo de la malla.
void mover_nodo(malla_t *malla);

//Agrega una masa a la malla.
//Pre: Masa != NULL.
//Post: Si el agregado fue existoso devuelve true.
bool agregar_masa();

//Agrega un resorte a la malla.
//Pre: Resorte != NULL.
//Post: Si el agregado fue existoso devuelve true.
bool agregar_resorte();

//Verifica si hay alguna masa o resorte en la malla.
//Post: Si esta vacia devuelve true.
bool malla_esta_vacia();

//Verfica si hay una masa en la posicion indicada.
bool hay_masa();

//Verfica si hay un resorte en la posicion indicada.
bool hay_resorte();

//NOTAS:

//Puntero que apunta a la direccion de memoria apuntada por cada una de las masas almacenadas;
//Si se crea una masa, se hace un realloc en este puntero que agregue una nueva masa en fase de construccion.
//Inicialmente se crea con las dos masas fijas, por lo tanto:
// masas = malloc(2*sizeof(masa_t*));
// *masas[i] = malloc(sizeof(masa_t));
// Resortes que estan dentro de la malla, linkeados a las masas a traves de los punteros
//a la masa en el momento de su creacion.
#endif