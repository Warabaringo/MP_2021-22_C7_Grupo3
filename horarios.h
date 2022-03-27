#ifndef HORARIOS_H
#define HORARIOS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "alumnos.h"

typedef struct {
    char id_profesor[4];
    int dia_clase;
    int hora_clase;
    char id_materia[5];
    char grupo[11];
} horario;

void menu_admin_horarios();

int encontrar_profesor(horario *horarios, char *idProfesor, unsigned nHorarios);

void agregar_horas(horario *hor);

void eliminar_horas(horario *hor);

void modificar_horas(horario *hor);

void mostrar_horarios(horario *horarios, unsigned nHorarios);

horario *leer_horarios(unsigned *nHorarios);

void mostrar_horario(const horario *hor);
#endif /* HORARIOS_H */
