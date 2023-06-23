#include "malla.h"
#include <stdlib.h>

typedef struct masas{
	size_t *xi;
	size_t *yi;
	masa_t *masa[10];
	//bool *es_fijo;
    size_t masa_actual;
} masas_t;

//lista_t *lista_resortes = lista_crear();

masas_t *crear_masas() 

    masas_t *m = malloc(sizeof(masas_t));
    if(m == NULL){
        return NULL;
    }

    m -> xi = malloc(10*sizeof(size_t));
    if(m -> xi == NULL){
        free(m);
        return NULL;
    }

masa_t *agregar_masa(malla_t *malla, size_t x, size_t y) {
    masa_t *masa = masa_crear(x, y);
    if(masa == NULL)
        return NULL;
    
    lista_insertar_primero(malla->masas, masa);
    return masa;
}

bool obtener_posicion(malla_t *malla, void (*posicion)(void *, size_t *, size_t*)) {
    posicion(malla -> masas -> dato, *)
}



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


//LISTA ENLAZADA DE MASAS:
malla_t *malla_crear() {
    malla_t *malla = malloc(sizeof(malla_t));
    malla->masas = lista_crear();
    malla->resortes = lista_crear();
}

void malla_destruir(malla_t *malla) {
    lista_destruir(malla->masas, masa_destruir);
    lista_destruir(malla->resortes, resorte_destruir);
    free(malla);
}

masa_t *agregar_masa(malla_t *malla, size_t x, size_t y) {
    masa_t *masa = masa_crear(x, y);
    if(masa == NULL)
        return NULL;
    
    lista_insertar_primero(malla->masas, masa);
    return masa;
}

bool obtener_posicion(malla_t *malla, void (*posicion)(void *, size_t *, size_t*)) {
    posicion(malla -> masas -> dato, *)
}
*/
