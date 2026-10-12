#include "lib.h"

int main(){
    estados_t estado = memoria;
    alarma_t alarma;
    
    alarma = inicio();

    while(1){
        switch(estado){
            case memoria: f_memoria(alarma);
                break;
            case bloqueo: f_bloqueo(alarma);
                break;
            case habilitado: f_habilitado(alarma);
                break;
            case contador: f_contador(alarma);
                break;
        }
    }
}   