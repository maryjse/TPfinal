#ifndef RESORTE_H
#define RESORTE_H

#include<stdlib.h>
#include<lista.h>
#include<stdbool.h>

//TDA resorte:

typedef struct resorte{
size_t longitud; //Longitud del resorte
int pos_inicial[2]; // Posiciones donde se inicie la creacion del resorte. pos_inicial[0] = xi
//pos_inicial[1] = yi
int pos_final[2];//Posiciones donde se finalice el resorte
}resorte_t;


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