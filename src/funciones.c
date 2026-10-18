#include "lib.h"

alarma_t inicio(void){
    alarma_t alarma;
    alarma.boton = 0;
    alarma.estado = 0;
    alarma.memoria = 1;
    alarma.puerta = 0;
    alarma.relay = 0;
    alarma.t_set=30;
    alarma.tiempo=0;

    return alarma;
}

alarma_t f_memoria(alarma_t alarma){
    if(alarma.memoria == 0){
        alarma.estado = contador;
        return alarma;
    } else {
        alarma.estado = bloqueo;
        return alarma;
    }
};

alarma_t f_bloqueo(alarma_t alarma){
    alarma.relay = 1;
    alarma.memoria = 1;

    if(alarma.boton == 0){
        alarma.estado = bloqueo;
        return alarma;
    } else {
        alarma.estado = habilitado;
        return alarma;
    }
};

alarma_t f_habilitado(alarma_t alarma){
    alarma.relay = 0;
    alarma.memoria = 0;
    alarma.tiempo = 0;

    if(alarma.puerta == 0){
        alarma.estado = contador;
        return alarma;
    } else {
        alarma.estado = habilitado;
        return alarma;
    }
};

alarma_t f_contador(alarma_t alarma){
    alarma.memoria = 1;

    if(alarma.tiempo > alarma.t_set){
        alarma.estado = bloqueo;
        return alarma;
    } else {
        alarma.estado = contador;
        return alarma;
    }

};