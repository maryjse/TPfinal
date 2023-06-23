#include <SDL2/SDL.h>
#include "malla.h"
#include "masa.h"
//#include "simulacion.h"
#define ANCHO 10

#ifdef TTF
#include <SDL2/SDL_ttf.h>

void escribir_texto(SDL_Renderer *renderer, TTF_Font *font, const char *s, int x, int y) {
    SDL_Color color = {255, 255, 255};  // Estaría bueno si la función recibe un enumerativo con el color, ¿no?
    SDL_Surface *surface = TTF_RenderText_Solid(font, s, color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);

    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = surface->w;
    rect.h = surface->h;

    SDL_RenderCopy(renderer, texture, NULL, &rect);

    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
}
#endif

//PRUEBA:
    // typedef struct masas {
    //     masa_t *masa[10];
    //     size_t masas_totales;
    // } masas_t;

    // masas_t *masas_crear() {
    //     masas_t *m = malloc(sizeof(masas_t));
    //     if(m == NULL)
    //         return NULL;
        
    //     m->masas_totales = 0;

    //     for(size_t i = 0; i < MASA_TOTAL; i++)
    //         m->masa[i] = masa_crear(-100,-100);
        
    //     return m;
    // }

    // masas
    // bool agregar_masa(masas_t *m, int xi, int yi) {
    //     //m -> masa = malloc( 10 * sizeof(masa_t*));
    //    // if(m -> masa == NULL){
    //       //  return false;
    //     //}
    //     cambiar_posicion_masa(m -> masa[m -> masas_totales], xi, yi);
        
    //     m->masas_totales++;
    //     return true;
    // }

int main(int argc, char *argv[]) {
    SDL_Init(SDL_INIT_VIDEO);

#ifdef TTF
    TTF_Init();
    TTF_Font* font = TTF_OpenFont("FreeSansBold.ttf", 24);
    if(font == NULL) {
        fprintf(stderr, "No pudo cargarse la tipografía\n");
        return 1;
    }
#endif

    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Event event;

    SDL_CreateWindowAndRenderer(VENTANA_ANCHO, VENTANA_ALTO, 0, &window, &renderer);
    SDL_SetWindowTitle(window, "Mono Bridge");

    int dormir = 0;

    // BEGIN código del alumno
    bool estoy_dibujando = false;
    int coordx = 0, coordy = 0;
    int iniciox, inicioy;
    int derechox, derechoy;
    int finalrx, finalry;
    // masa_t *masa_i[10];
    // malla_t *malla = malla_crear();
    //masas_t *m = crear_masas();
    resorte_t *r;
    size_t masas_totales;

    lista_t *lista_resortes = lista_crear();
    lista_t *lista_masas = lista_crear();
    
    // END código del alumno

    unsigned int ticks = SDL_GetTicks();
    while(1) {
        //masas_totales = obtener_masas_totales(m);
        masas_totales = lista_largo(lista_masas);

        if(SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                break;
            
            // BEGIN código del alumno
           // masas_totales = obtener_masas_totales(malla);
            if(event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
                estoy_dibujando = true;
                iniciox = event.motion.x;
                inicioy = event.motion.y;
                //PRUEBA:      
                if(masas_totales < MASA_TOTAL){

                    masa_t *m = masa_crear(iniciox, inicioy);
                    lista_insertar_ultimo(lista_masas, m);

                    // if(!hay_masa(m, iniciox, inicioy)){  
                    //     asignar_posicion_masa(m, iniciox, inicioy);         
                    // }
                     r = resorte_crear(iniciox, inicioy);
                }
            }

            // else if(event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_RIGHT){
            //     derechox = event.motion.x;
            //     derechoy = event.motion.y;
                

            // }

            else if(event.type == SDL_MOUSEMOTION) {
                coordx = event.motion.x;
                coordy = event.motion.y;
                
            }
            
            else if(event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT && event.type == SDL_MOUSEMOTION){

            
            }


            else if(event.type == SDL_MOUSEBUTTONUP && event.button.button == SDL_BUTTON_LEFT) {

                finalrx = event.motion.x;
                finalry = event.motion.y;
                if(resorte_agregar_final(r, finalrx, finalry))
                    lista_insertar_ultimo(lista_resortes, r);

                    
                //Si no hay masa creo una masa:
                //masa_t *m1 = masa_crear(coordx, coordy);
                
                //lista_insertar_ultimo(resorte_i,mi);

                //Si ya existe una masa hago:
                //lista_insertar_ultimo(resorte_i,masa_existente);

                estoy_dibujando = false; 
            }
            // END código del alumno

            continue;
        }
        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0x00);

        // BEGIN código del alumno
#ifdef TTF
        escribir_texto(renderer, font, "Mono Bridge", 100, 20);
        escribir_texto(renderer, font, "Nivel 1", 100, 60); //Nombre del nivel
        char aux[100];
        sprintf(aux, "%03d, %03d", coordx, coordy);
        escribir_texto(renderer, font, aux, VENTANA_ANCHO - 100, VENTANA_ALTO - 34);
#endif

        //Dibujo de las masas fijas:
        float ancho1 = 10;
        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_Rect masa_fija_1 = {100 - ancho1/2, 350 - ancho1/2, ancho1, ancho1};
        SDL_Rect masa_fija_2 = {280 - ancho1/2, 350 - ancho1/2, ancho1, ancho1};
        SDL_RenderDrawRect(renderer, &masa_fija_1);
        SDL_RenderDrawRect(renderer, &masa_fija_2);


        if(estoy_dibujando) {
            SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0x00);
            SDL_RenderDrawLine(renderer, iniciox, inicioy, coordx, coordy);

            SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0x00, 0x00);

            float ancho = 10;
            SDL_Rect r1 = {coordx - ancho/2, coordy - ancho/2, ancho, ancho};
            SDL_RenderDrawRect(renderer, &r1);

            SDL_Rect r2 = {iniciox - ancho/2, inicioy - ancho/2, ancho, ancho};
            SDL_RenderDrawRect(renderer, &r2);


        }

        //PRUEBA:
        //Matriz que guarda las posiciones de las masas
        size_t posiciones[10][2];
       
         lista_iter_t *ld;
         size_t i;
        for(i = 0, ld = lista_iter_crear(lista_masas); !lista_iter_al_final(ld); lista_iter_avanzar(ld), i++) {
            //iterar_posiciones_masa(m, &posiciones[i][0], &posiciones[i][1], i);
            masa_t *m = lista_iter_ver_actual(ld);

            obtener_posicion(m, &posiciones[i][0], &posiciones[i][1]);
            
        }
        lista_iter_destruir(ld);

        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

       //Tabla de busqueda para las masas 
        SDL_Rect masas[] ={
            [0] = {posiciones[0][0] - ANCHO/2, posiciones[0][1] - ANCHO/2, ANCHO, ANCHO},
            [1] = {posiciones[1][0] - ANCHO/2, posiciones[1][1] - ANCHO/2, ANCHO, ANCHO},
            [2] = {posiciones[2][0] - ANCHO/2, posiciones[2][1] - ANCHO/2, ANCHO, ANCHO},
            [3] = {posiciones[3][0] - ANCHO/2, posiciones[3][1] - ANCHO/2, ANCHO, ANCHO},
            [4] = {posiciones[4][0] - ANCHO/2, posiciones[4][1] - ANCHO/2, ANCHO, ANCHO},
            [5] = {posiciones[5][0] - ANCHO/2, posiciones[5][1] - ANCHO/2, ANCHO, ANCHO},
            [6] = {posiciones[6][0] - ANCHO/2, posiciones[6][1] - ANCHO/2, ANCHO, ANCHO},
            [7] = {posiciones[7][0] - ANCHO/2, posiciones[7][1] - ANCHO/2, ANCHO, ANCHO},
            [8] = {posiciones[8][0] - ANCHO/2, posiciones[8][1] - ANCHO/2, ANCHO, ANCHO},
            [9] = {posiciones[9][0] - ANCHO/2, posiciones[9][1] - ANCHO/2, ANCHO, ANCHO},
        };

        //Dibujado de las masas
        for(size_t i = 0; i < masas_totales; i++){
            SDL_RenderDrawRect(renderer, &masas[i]);
            
        }

        lista_iter_t *li;
        for (li = lista_iter_crear(lista_resortes); !lista_iter_al_final(li); lista_iter_avanzar(li)) {
            resorte_t *resorte = lista_iter_ver_actual(li);
            int iniciales[2];
            int finales[2];
            obtener_posiciones(resorte, iniciales, finales);
            SDL_RenderDrawLine(renderer, iniciales[0], iniciales[1], finales[0], finales[1]);
        }
        lista_iter_destruir(li);
       
       
        
        // for(size_t i = 0; i < masas_totales; i++){
        //     if(posiciones[i][0] == derechox && posiciones[i][1] == derechoy){
        //         cambiar_posicion_masa(m -> masa[i], -100, -100);
        //         m -> masas_totales--;
        //     }
        // } 


        
        // END código del alumno

        SDL_RenderPresent(renderer);
        ticks = SDL_GetTicks() - ticks;
        if(dormir) {
            SDL_Delay(dormir);
            dormir = 0;
        }
        else if(ticks < 1000 / JUEGO_FPS)
            SDL_Delay(1000 / JUEGO_FPS - ticks);
        ticks = SDL_GetTicks();
    }

    // BEGIN código del alumno

    // END código del alumno

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

#ifdef TTF
    TTF_CloseFont(font);
    TTF_Quit();
#endif
    SDL_Quit();
    return 0;
}
