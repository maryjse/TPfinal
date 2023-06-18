#ifndef MASA_H
#define MASA_H

//TDA que representa una masa.
//Contiene la posición inicial de la masa y su valor.
typedef struct masa{
    int xi, yi;
    float masa;
} masa_t;

//Crea una masa.
//Post: En caso de no poder crear la masa devuelve NULL.
masa_t *masa_crear();

//Destruye la masa.
//Pre: La masa debe estar previamente creada.
void masa_destruir(masa_t *m);

//Devuelve la posición de una masa.
//Pre: Masa != NULL.
//Post: Devuelve la posicion de la masa sin modificarla.
void obtener_posicion(const masa_t *m, int *pos_x, int *pos_y);

//Devuelve true en caso de existir una masa en la posición querida.
bool hay_masa(int x, int y);
//Itero todas las masas que tengo en la simulacion y si consigo una en esa posicion devuelvo true.

void cambiar_posicion_masa(masa_t *masa); //Recibe un puntero a masa y cambia su posicion.
//Pre: La masa no es NULL. 

#endif