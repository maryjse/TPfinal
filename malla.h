#ifndef MALLA_H
#define MALLA_H

#define RESORTES_TOTALES 30

#include "masa.h"
#include "resorte.h"
#include "config.h"
#include "lista.h"


//TDA que representa una malla.
//Contiene las masas y los resortes creados.

typedef struct masas masas_t;

//Crea las masas.
//Post: En caso de no poder crear las masas devuelve NULL.
masas_t *crear_masas();

//Destruye la malla.
//Pre: la masa y los resortes deben existir previamente.
//Post: destruye todas las masas y los resortes.
//void malla_destruir(malla_t *malla);

//Mueve un nodo de la malla.
void mover_nodo(masa_t *m, resorte_t *r, size_t x, size_t y);

//Agrega una masa a la malla.
//Pre: Masa != NULL.
//Post: Si el agregado fue existoso devuelve true.


//Asigna las posiciones de las masas en la malla
//Pre: La malla fue previamente creada
//Post: Asigna las posiciones de las masas, en orden dentro de la malla 
bool asignar_posicion_masa(masas_t *m, size_t pos_x, size_t pos_y);


//masas_t *agregar_masa(malla_t *malla, size_t x, size_t y);

//Agrega un resorte a la malla.
//Pre: Resorte != NULL.
//Post: Si el agregado fue existoso devuelve true.
bool agregar_resorte();

//Verifica si hay alguna masa o resorte en la malla.
//Post: Si esta vacia devuelve true.
//bool malla_esta_vacia();

//Verfica si hay una masa en la posicion indicada.
//bool hay_masa(malla_t *malla,size_t pos_x, size_t pos_y);

//Verfica si hay un resorte en la posicion indicada.
//bool hay_resorte();

//Devuelve por nombre la cantidad de masas totales en la malla
//Pre: La malla que se le pasa fue creada
size_t obtener_masas_totales(masas_t *m);

//Borra la masa que haya en la posicion dada, en caso de haberla
//Pre: La malla fue creada
//Post: Devuelve true si se destruyo una masa en esa posicion
bool borrar_masa(masas_t *m, size_t pos_x, size_t pos_y);

//Iterador para obtener las posiciones de todas las masas dentro de la malla
void iterar_posiciones_masa(masas_t *m, size_t *pos_x, size_t *pos_y, size_t i);

size_t obtener_numero_nodo(masas_t *m, size_t pos_x, size_t pos_y);

bool hay_masa(masa_t *m, size_t pos_x, size_t pos_y);

bool hay_resorte(resorte_t *resorte, size_t pos_x, size_t pos_y);

static double distancia_extremo_resorte(resorte_t *resorte, size_t pos_x, size_t pos_y);

//NOTAS:

//Puntero que apunta a la direccion de memoria apuntada por cada una de las masas almacenadas;
//Si se crea una masa, se hace un realloc en este puntero que agregue una nueva masa en fase de construccion.
//Inicialmente se crea con las dos masas fijas, por lo tanto:
// masas = malloc(2*sizeof(masa_t*));
// *masas[i] = malloc(sizeof(masa_t));
// Resortes que estan dentro de la malla, linkeados a las masas a traves de los punteros
//a la masa en el momento de su creacion.
#endif