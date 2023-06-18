#include "lista.h"

//TDA masa:

typedef struct masa{
    int xi, yi; //Posicion en la que se crea la masa
    float masa; //Valor de la masa, sera igual para todas las masas creadas
    lista_t **resortes; //Arreglo de punteros a resortes a los cuales este conectado la masa
    //Este arreglo se modifica segun lo que pase en la malla
}masa_t;

masa_t *masa_crear();//Crea la masa, Pos: devuelve NULL si no se pudo crear o un puntero a la masa creada
void masa_destruir(masa_t *m);//Destruye la masa. Pre:La masa fue creada
void obtener_posicion(const masa_t *m, int *pos_x, int *pos_y); //devuelve por interfaz la posicion de la masa, 
//Pre: La masa no es NULL, Pos: Se devuelve la posicion de la masa sin modificarla

bool hay_masa(int x, int y) // Para las posiciones introducidas, devuelve si hay una masa en ese lugar o no.
 //Itero todas las masas que tengo en la simulacion y si consigo una en esa posicion devuelvo true.

 void cambiar_posicion_masa(masa_t *masa) //Recibe un puntero a masa y cambia su posicion.
//Pre: La masa no es NULL. 

//TDA resorte:

//debo usar la lista que se da en clase
//cuando el usuario clickee sobre una masa creada se inicia la creacion de un resorte
 lista_t* resorte_i = lista_crear() //Se crea un resorte que por ahora no esta asociado a ninguna masa

//luego de crear el resorte, se le debe insertar el dato del nodo (masa) al que se este uniendo.
lista_insertar_primero(resorte_i, masa_t *masa);
//si resorte es mayor a LO_MAX se llama a 
lista_destruir(resorte_i);
//si se clickea sobre una una posicion sin masa se debe crear una masa y ademas agregarlo a la lista resorte:

m2 = *masa_crear();

lista_insertar_ultimo(resorte_i, m2); //Inserta en la ultima posicion de la lista la masa creada

//Con las posiciones de las masas previamente obtenidas con obtener_posicion hago la norma int n =||p2 -p1|| 
lista_insertar_ultimo(resorte_i, &n) //Se inserta en la ultima posicion del resorte su longitud.
//Si la longitud es mayor a LO_MAX no se estira mas el resorte.



 lista_destruir(resorte_i, free); //Destruye el resorte 


//TDA malla:
//La malla debe relacionar las masas con los resortes.

typedef struct malla{
    masa_t **masas; //Puntero que apunta a la direccion de memoria apuntada por cada una de las masas almacenadas;
    //Si se crea una masa, se hace un realloc en este puntero que agregue una nueva masa en fase de construccion.
    //Inicialmente se crea con las dos masas fijas, por lo tanto:
    masas = malloc(2*sizeof(masa_t*));
    *masas[i] = malloc(sizeof(masa_t)); 0 <= i < 2; //(para el inicio)

    lista_t **resortes // Resortes que estan dentro de la malla, linkeados a las masas a traves de los punteros
    //a la masa en el momento de su creacion.


}
