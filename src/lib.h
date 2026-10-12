#ifndef LIBRERIA
#define LIBRERIA
#include <stdio.h>

typedef enum{
    memoria=0,
    bloqueo=1,
    habilitado=2,
    contador=3
}estados_t;

typedef struct{
    float tiempo;
    float t_set;
    char memoria;
    char relay;
    char boton;
    char puerta;
}alarma_t;
    
alarma_t inicio(void);
estados_t f_memoria(alarma_t);
estados_t f_bloqueo(alarma_t);
estados_t f_habilitado(alarma_t);
estados_t f_contador(alarma_t);

#endif