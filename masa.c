#include "masa.h"
#include <stdlib.h>

masa_t *masa_crear(size_t xi, size_t yi) {
    masa_t *m = malloc(sizeof(masa_t));
    if(m == NULL)
        return NULL;
    
    m->x = xi;
    m->y = yi;

    return m;
}

void masa_destruir(masa_t *m) {
    free(m);   
}

void obtener_posicion(const masa_t *m, size_t *pos_x, size_t *pos_y) {
    *pos_x = m -> x;
    *pos_y = m -> y;
}

void cambiar_posicion_masa(masa_t *masa, size_t nueva_x, size_t nueva_y){
    masa->x = nueva_x;
    masa->y = nueva_y;
}
