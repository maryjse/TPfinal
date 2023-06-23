#include "malla.h"
#include <stdlib.h>

// typedef struct masas{
// 	//size_t *xi;
// 	//size_t *yi;
// 	masa_t *masa[10];
// 	//bool *es_fijo;
//     size_t cant_masas;
// } masas_t;

typedef struct masas {
    masa_t *masa[10];
    size_t masas_totales;
} masas_t;

masas_t *masas_crear() {
    masas_t *m = malloc(sizeof(masas_t));
    if(m == NULL)
        return NULL;
        
    m->masas_totales = 0;

    for(size_t i = 0; i < 10; i++)
         m->masa[i] = masa_crear(-100,-100);
    return m;
}


masas_t *crear_masas() {

    masas_t *m = malloc(sizeof(masas_t));
    if(m == NULL){
        return NULL;
    }


    // m -> es_fijo = malloc(10*sizeof(bool));
    // if(m ->es_fijo == NULL){
    //     free(m -> xi);
    //     free(m -> yi);
    //     free(m);
    // }

    m -> cant_masas = 0;
    

    return m;
}

bool asignar_posicion_masa(masas_t *m, size_t pos_x, size_t pos_y){
    if(m -> cant_masas > 9){
        return false;
    }
    m->masa[m -> cant_masas] = masa_crear(pos_x, pos_y);
    m -> cant_masas++;
    return true;
}

void iterar_posiciones_masa(masas_t *m, size_t *pos_x, size_t *pos_y, size_t i){
    *pos_x = m -> xi[i];
    *pos_y = m -> yi[i];
}

bool borrar_masa(masas_t *m, size_t pos_x, size_t pos_y){
    for(size_t i = 0; i <= m -> masa_actual; i++){
        if(m -> xi[i] == pos_x && m -> yi[i] == pos_y){
            masa_destruir(m -> masa[i]);
            m -> masa_actual--;
            return true;
        }
    }
    return false;
}

size_t obtener_masas_totales(masas_t *m){
    return m -> masa_actual + 1;
}

size_t obtener_numero_nodo(masas_t *m, size_t pos_x, size_t pos_y){
    for(size_t i = 0; i <= m -> masa_actual; i++){
        if(m -> xi[i] == pos_x && m -> yi[i] == pos_y){
            return i;
        }
    }
}

bool hay_masa(masas_t *m, size_t pos_x, size_t pos_y) {
    for(size_t i = 0; i <= m -> masa_actual; i++) {
        if(m -> xi[i] == pos_x && m -> yi[i] == pos_y) {
            return true;
        }
    }
    return false;
}

bool agregar_resorte(resorte_t *resorte){

}



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
