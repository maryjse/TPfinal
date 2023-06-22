#include "resorte.h"
#include "config.h"
#include <stdlib.h>
#include <math.h>

resorte_t *resorte_crear(int xi, int yi) {
    resorte_t *r = malloc(sizeof(resorte_t));
    if (r == NULL)
        return NULL;
    
    r -> pos_inicial[0] = xi;
    r -> pos_inicial[1] = yi;

    return r;
}

bool resorte_agregar_final(resorte_t *resorte, int x_final, int y_final){
    resorte -> longitud = sqrt((resorte -> pos_inicial[0] - x_final)*(resorte -> pos_inicial[0] - x_final) + (resorte -> pos_inicial[1] - y_final)*(resorte -> pos_inicial[1] - y_final));
    if((resorte -> longitud) > L0_MAX){
        return false;
    }

    resorte -> pos_final[0] = x_final;
    resorte -> pos_final[1] = y_final;
    return true;
}

void resorte_destruir(resorte_t *resorte){
    free(resorte);
}



