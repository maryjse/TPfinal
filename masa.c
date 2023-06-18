#include "masa.h"

masa_t *masa_crear(size_t xi, size_t yi) {
    masa_t *m = malloc(sizeof(masa_t));
    if(m == NULL)
        return NULL;
    
    m->x_inicial = xi;
    m->y_inicial = yi;

    return m;
}

void masa_destruir(masa_t *m) {
    free(m);
}
