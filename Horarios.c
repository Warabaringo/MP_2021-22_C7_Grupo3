#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Horarios.h"

int main() {

}

horario *leer_horario(unsigned *nProfesor){
    horario *horarios = NULL;
    horario hor;

    FILE *f = fopen("Horarios.txt", "r");
    char linea[127], *token;
    unsigned n = 0;

    while(fgets(linea, 127, f) != NULL) {
        token = strok(linea, "-");
        strcpy(hor.id_profesor, token);
        token = strtok
    }
}
