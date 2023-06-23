#ifndef RESORTE_H
#define RESORTE_H

#include "lista.h"
#include <stdlib.h>

//TDA que representa un resorte.
//Contiene la longitud del resorte, y dos vectores de longitud 2 que guarda sus x e y.
//La posición inicial donde se inicia la creación del resorte
//y posiciones donde finaliza el resorte.

typedef struct resorte {
    size_t longitud; 
    int pos_inicial[2];
    int pos_final[2];
    float k;
} resorte_t;


//Crea un resorte
resorte_t *resorte_crear(int x_inicial, int y_inicial); //Funcion que crea un nuevo resorte
//Pre: recibe las posiciones donde se creo una masa previamente
//Post: devuelve un resorte nuevo o NULL en caso de falla

void resorte_destruir(resorte_t *resorte);//Destruye el resorte previamente creado

bool resorte_agregar_final(resorte_t *resorte, int x_final, int y_final); //Recibe un resorte y le agrega la posicion donde termina de construirse
//Pre: el resorte fue creado
//Post: Se termina de construir el resorte o se destruye, dependiendo de si se pasa la longitud maxima o no

bool hay_resorte(int pos_x, int pos_y); //Comprueba si hay un resorte en esa posicion.
//No se como hacer esta funcion, pero se me ocurre que si las posiciones estan entre una recta trazada entre
//pos_inicial y pos_final de algun resorte de la lista sea true;

//debo usar la lista que se da en clase para guardar los resortes
//cuando el usuario clickee sobre una masa creada se inicia la creacion de un resorte

#endif