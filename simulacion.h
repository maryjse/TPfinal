// TDA SIMULACION:

typedef struct simulacion {
    malla_t *malla;
    size_t x_actual_masa, y_actual_masa, x_anterior_masa, y_anterior_masa;
} simulacion_t;

simulacion_t *calcular_posicion(simulacion_t simulacion, double g, double k, double b);
void iniciar_simulacion();
void destruir_simulacion();