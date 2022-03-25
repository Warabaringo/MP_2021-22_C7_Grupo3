#ifndef HORARIOS_H
#define HORARIOS_H

typedef struct {
    char id_profesor[4];
    int dia_clase;
    int hora_clase;
    char id_materia[5];
    char grupo[11];
} horario;

#endif /* HORARIOS_H */