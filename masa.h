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
