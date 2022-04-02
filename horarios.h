#ifndef HORARIOS_H
#define HORARIOS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "alumnos.h"
#include "Materias.h"
#include "usuarios.h"

typedef struct {
    char id_profesor[4];
    int dia_clase;
    int hora_clase;
    char id_materia[5];
    char grupo[11];
} horario;

void menu_admin_horarios();

void agregar_horario(horario **hor, usuario *usuarios, materia *materias, alumno *alumnos, 
		unsigned nUsuarios, unsigned nMaterias, unsigned nAlumnos, unsigned *nHorarios);

void eliminar_horario(horario **hor, int encontrado, unsigned *nHorarios);

void modificar_horario(horario *hor, materia *materias, usuario *usuarios, alumno *alumnos,	
		unsigned *nHorarios, unsigned nMaterias, unsigned nUsuarios, unsigned nAlumnos, int encontrado);

void mostrar_horarios(horario *horarios, unsigned nHorarios);

void guardar_horarios(const horario *horarios, unsigned n);

void guardar_horario (const horario *h, FILE *f);

horario *leer_horarios(unsigned *nHorarios);

void mostrar_horario(const horario *hor);
#endif /* HORARIOS_H */
