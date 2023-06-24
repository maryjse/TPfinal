#include "malla.h"
#include <stdlib.h>
#include <math.h>

bool hay_masa(masa_t *masa, size_t pos_x, size_t pos_y) {
    double distancia = sqrt(pow(pos_x - masa->x, 2) + pow(pos_y - masa->y, 2));
    if(distancia <= EPSILON_MASA) {
        return true;
    }
    return false;
}

bool hay_resorte(resorte_t *resorte, size_t pos_x, size_t pos_y) {
    double distancia;
    double p_pj[2] = {pos_x - resorte->pos_inicial[0], pos_y - resorte->pos_inicial[1]};
    double pk_pj[2] = {resorte->pos_final[0] - resorte->pos_inicial[0], resorte->pos_final[1] - resorte->pos_inicial[1]};

    double dividendo = (p_pj[0] * pk_pj[0]) + (p_pj[1] * pk_pj[1]);
    double divisor = pow(pk_pj[0], 2) + pow(pk_pj[1], 2);

    double alpha = dividendo / divisor;

    double distancia_a_punto_recta[2] ={alpha * pk_pj[0] + resorte->pos_inicial[0], alpha * pk_pj[1] + resorte->pos_inicial[1]};

    if(alpha <= 0) {
        distancia = sqrt(pow(p_pj[0], 2)+ pow(p_pj[1], 2));
    }

    else if(alpha >= 1) {
        distancia = sqrt(pow(resorte->pos_final[0] - pos_x, 2) + pow(resorte->pos_final[1] - pos_y, 2));
    }

    else {
        distancia = sqrt(pow(distancia_a_punto_recta[0] - pos_x, 2) + pow(distancia_a_punto_recta[1] - pos_y, 2));
    }
    return (distancia <= EPSILON_RESORTE);
}

void mover_nodo(masa_t *m, resorte_t *r, size_t x, size_t y) {
    if(hay_resorte(r, m->x, m->y)) {
        if(distancia_extremo_resorte(r, x, y) >= 1) {
            r->pos_final[0] = x;
            r->pos_final[1] = y;
        } else if(distancia_extremo_resorte(r, x, y) <= 0) {
            r->pos_inicial[0] = x;
            r->pos_inicial[1] = y;
        }
    }
}

static double distancia_extremo_resorte(resorte_t *resorte, size_t pos_x, size_t pos_y) {
    double distancia;
    double p_pj[2] = {pos_x - resorte->pos_inicial[0], pos_y - resorte->pos_inicial[1]};
    double pk_pj[2] = {resorte->pos_final[0] - resorte->pos_inicial[0], resorte->pos_final[1] - resorte->pos_inicial[1]};

    double dividendo = (p_pj[0] * pk_pj[0]) + (p_pj[1] * pk_pj[1]);
    double divisor = pow(pk_pj[0], 2) + pow(pk_pj[1], 2);

    double alpha = dividendo / divisor;

    double distancia_a_punto_recta[2] ={alpha * pk_pj[0] + resorte->pos_inicial[0], alpha * pk_pj[1] + resorte->pos_inicial[1]};

    if(alpha <= 0) {
        distancia = sqrt(pow(p_pj[0], 2)+ pow(p_pj[1], 2));
    }

    else if(alpha >= 1) {
        distancia = sqrt(pow(resorte->pos_final[0] - pos_x, 2) + pow(resorte->pos_final[1] - pos_y, 2));
    }

    else {
        distancia = sqrt(pow(distancia_a_punto_recta[0] - pos_x, 2) + pow(distancia_a_punto_recta[1] - pos_y, 2));
    }

    return alpha;
}

// //lista_t *lista_resortes = lista_crear();

// masas_t *crear_masas() {

//     masas_t *m = malloc(sizeof(masas_t));
//     if(m == NULL){
//         return NULL;
//     }

//     m -> xi = malloc(10*sizeof(size_t));
//     if(m -> xi == NULL){
//         free(m);
//         return NULL;
//     }

//     m -> yi = malloc(10*sizeof(size_t));
//     if(m -> yi == NULL){
//         free(m -> xi);
//         free(m);
//         return NULL;
//     }

//     // m -> es_fijo = malloc(10*sizeof(bool));
//     // if(m ->es_fijo == NULL){
//     //     free(m -> xi);
//     //     free(m -> yi);
//     //     free(m);
//     // }

//     m -> masa_actual = 0;
    
//     // for(size_t i = 0; i < MASA_TOTAL; i++){
//     //     m->masa[i] = masa_crear(-100,-100);
//     // }

//     return m;
// }

// bool asignar_posicion_masa(masas_t *m, size_t pos_x, size_t pos_y){
//     if(m -> masa_actual > 9){
//         return false;
//     }
//     m->masa[m -> masa_actual] = masa_crear(pos_x, pos_y);
//     m -> xi[m -> masa_actual] = pos_x;
//     m -> yi[m -> masa_actual] = pos_y;
//     m -> masa_actual++;
//     return true;
// }

// void iterar_posiciones_masa(masas_t *m, size_t *pos_x, size_t *pos_y, size_t i){
//     *pos_x = m -> xi[i];
//     *pos_y = m -> yi[i];
// }

// bool borrar_masa(masas_t *m, size_t pos_x, size_t pos_y){
//     for(size_t i = 0; i <= m -> masa_actual; i++){
//         if(m -> xi[i] == pos_x && m -> yi[i] == pos_y){
//             masa_destruir(m -> masa[i]);
//             m -> masa_actual--;
//             return true;
//         }
//     }
//     return false;
// }

// size_t obtener_masas_totales(masas_t *m){
//     return m -> masa_actual + 1;
// }

// size_t obtener_numero_nodo(masas_t *m, size_t pos_x, size_t pos_y){
//     for(size_t i = 0; i <= m -> masa_actual; i++){
//         if(m -> xi[i] == pos_x && m -> yi[i] == pos_y){
//             return i;
//         }
//     }
// }

// bool hay_masa(masas_t *m, size_t pos_x, size_t pos_y){
//     for(size_t i = 0; i <= m -> masa_actual; i++){
//         if(m -> xi[i] == pos_x && m -> yi[i] == pos_y){
//             return true;
//         }
//     }
//     return false;
// }

// bool agregar_resorte(resorte_t *resorte){

// }


// struct malla {
//     lista_t *masas;
//     lista_t *resortes;
// };

// malla_t *malla_crear() {
//     malla_t *malla = malloc(sizeof(malla_t));
//     malla->masas = lista_crear();
//     malla->resortes = lista_crear();
// }

// void malla_destruir(malla_t *malla) {
//     lista_destruir(malla->masas, masa_destruir);
//     lista_destruir(malla->resortes, resorte_destruir);
//     free(malla);
// }

// masa_t *agregar_masa(malla_t *malla, size_t x, size_t y) {
//     masa_t *masa = masa_crear(x, y);
//     if(masa == NULL)
//         return NULL;
    
//     lista_insertar_primero(malla->masas, masa);
//     return masa;
// }

// bool obtener_posicion(malla_t *malla, void (*posicion)(void *, size_t *, size_t*)) {
//     posicion(malla -> masas -> dato, *)
// }



// masa_t *agregar_masa(malla_t *malla, size_t x, size_t y) {
//     if((malla->masas)->masas_totales >= MASA_TOTAL)
//         return NULL;
    
//     cambiar_posicion_masa((malla->masas)->masa[(malla->masas)->masas_totales], x, y);
//     (malla->masas)->masas_totales++;
//     return (malla->masas)->masa[(malla->masas)->masas_totales];
// }



// masas_t *masas_crear() {
//     masas_t *m = malloc(sizeof(masas_t));
//     if(m == NULL)
//         return NULL;
        
//     m->masas_totales = 0;

//     for(size_t i = 0; i < 10; i++)
//          m->masa[i] = masa_crear(-100,-100);
//     return m;
// }



// masa_t *obtener_masa(masas_t *masas, size_t i){
//     return masas -> masa[i];
// }



// malla_t *malla_crear() {
//     malla_t *m = malloc(sizeof(malla_t));
//     if(m == NULL)
//         return NULL;
    
//     m->masas = malloc(sizeof(masas_t));
//     if(m->masas == NULL) {
//         free(m);
//         return NULL;
//     }

//     (m->masas)->masas_totales = 0;
    
//     for(size_t i = 0; i < MASA_TOTAL; i++)
//         (m->masas)->masa[i] = masa_crear(-100,-100);

//     m->resortes = lista_crear();
//     return m;
// }


// void malla_destruir(malla_t *malla) {
//     free(malla->masas);
//     lista_destruir(malla->resortes, resorte_destruir);
//     free(malla);
// }


// bool agregar_resorte(malla_t *malla, size_t x, size_t y) {
//     resorte_t *resorte = resorte_crear(x, y);
//     if(lista_insertar_ultimo(malla->resortes, resorte))
//         return true;
//     return false;
// }


// size_t obtener_masas_totales(malla_t *malla) {
//     return (malla->masas)->masas_totales;
// }


/*
bool borrar_masa(malla_t *malla, size_t pos_x, size_t pos_y){
    size_t x, y;
    for(size_t i = 0; i < MASA_TOTAL; i++){
        obtener_posicion(m -> masa[i], &x, &y);
        if(x == pos_x && y == pos_y){
            masa_destruir(m -> masa[i]);
            return true;
        }
    return false;
    }
}
*/
