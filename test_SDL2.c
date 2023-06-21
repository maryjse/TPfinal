#include <SDL2/SDL.h>
#include <stdbool.h>
#include "lista.h"
//#include "malla.h"
#include "masa.h"
//#include "resorte.h"
//#include "simulacion.h"
#define ANCHO 10
#include "config.h"

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
    typedef struct masas{
        masa_t **masa;
        size_t masas_totales;
    } masas_t;

    masas_t *m = malloc(sizeof(masas_t));

    bool agregar_masa(masas_t *m, int xi, int yi){
            
        m -> masa = malloc( 10 * sizeof(masa_t*));
        if(m -> masa == NULL){
            return false;
        }
        m->masa[m -> masas_totales] = masa_crear(xi, yi);
        
        m->masas_totales++;
        return true;
    }

    // masas_t *m = malloc(sizeof(masas_t));
    // m -> masa[0] = masa_crear(0,0);
    // m ->masa[1] = masa_crear(0,0);

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
    
    // END código del alumno

    unsigned int ticks = SDL_GetTicks();
    while(1) {
        if(SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                break;

            // BEGIN código del alumno
            if(event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
                estoy_dibujando = true;
                iniciox = event.motion.x;
                inicioy = event.motion.y;

                //PRUEBA:

                agregar_masa(m,iniciox,inicioy);

                //if(agregar_masa(m, iniciox, inicioy)) {
                 //   cambiar_posicion_masa(m -> masa[i], iniciox, inicioy);
               // }
               
                /*
                if(!hay_masa(iniciox, inicioy)){
                    masa_t *m1 = crear_masa();
                }
                
            else if(event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT && event.type == SDL_MOUSEMOTION){

                //lista_t *resorte_i = crear_resorte();
                lista_insertar_primero(resorte_i, masa_existente);
            }

                */
                
                

            }
            else if(event.type == SDL_MOUSEMOTION) {
                coordx = event.motion.x;
                coordy = event.motion.y;
                
                
            }
            else if(event.type == SDL_MOUSEBUTTONUP && event.button.button == SDL_BUTTON_LEFT) {

                
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

float ancho1 = 10;

//Dibujo de las masas fijas:
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

        size_t pos1x, pos1y;
        size_t pos2x, pos2y; //HABRIA QUE HACER UN VECTOR QUE GUARDE LAS POSICIONES

        //masa_t *m1 = masa_crear(iniciox, inicioy);

        // for(size_t i = 0; i < m->masas_totales; i++) {
        //     obtener_posicion(m->masa[i], pos2x, pos2y);
        // }

        obtener_posicion(m->masa[0], &pos1x, &pos1y);
        obtener_posicion(m->masa[1], &pos2x, &pos2y);

        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_Rect masa_1 = {pos1x - ANCHO/2, pos1y - ANCHO/2, ANCHO, ANCHO};
        SDL_RenderDrawRect(renderer, &masa_1);

        SDL_Rect masa_2 = {pos2x - ANCHO/2, pos2y - ANCHO/2, ANCHO, ANCHO};
        SDL_RenderDrawRect(renderer, &masa_2);


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
