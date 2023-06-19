#include "resorte.h"
#include "config.h"
#include "lista.h"
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

resorte_t *resorte_crear(int x_inicial, int y_inicial){
    resorte_t *resorte = malloc(sizeof(resorte_t));
    if (resorte == NULL){
        return NULL;
    }
    resorte -> pos_inicial[0] = x_inicial;
    resorte -> pos_incial[1] = y_inicial;

    return resorte;
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

bool hay_resorte(int pos_x, int pos_y){
    
}


