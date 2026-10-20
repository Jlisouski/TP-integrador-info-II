#include "lib.h"

int main(){
    alarma_t alarma;
    alarma.estado = memoria;
    alarma = inicio();

    while(1){
        switch(alarma.estado){
            case memoria: alarma = f_memoria(alarma);
                break;
            case bloqueo: alarma = f_bloqueo(alarma);
                break;
            case habilitado: alarma = f_habilitado(alarma);
                break;
            case contador: alarma = f_contador(alarma);
                break;
        }
    }
    return 0;
}   