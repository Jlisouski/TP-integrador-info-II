#include "lib.h"

int main(){
    alarma_t alarma;
    alarma.estado = memoria;
    alarma = inicio();

    while(1){
        switch(alarma.estado){
            case memoria: alarma.estado = f_memoria(alarma);
                break;
            case bloqueo: alarma.estado = f_bloqueo(alarma);
                break;
            case habilitado: alarma.estado = f_habilitado(alarma);
                break;
            case contador: alarma.estado = f_contador(alarma);
                break;
        }
    }
    return 0;
}   