//TDA MALLA:

typedef struct malla{
    masa_t **masas; //Puntero que apunta a la direccion de memoria apuntada por cada una de las masas almacenadas;
    //Si se crea una masa, se hace un realloc en este puntero que agregue una nueva masa en fase de construccion.
    //Inicialmente se crea con las dos masas fijas, por lo tanto:
    masas = malloc(2*sizeof(masa_t*));
    *masas[i] = malloc(sizeof(masa_t)); 0 <= i < 2; //(para el inicio)

    lista_t **resortes // Resortes que estan dentro de la malla, linkeados a las masas a traves de los punteros
    //a la masa en el momento de su creacion.


}