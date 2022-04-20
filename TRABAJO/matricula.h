#ifndef MATRICULA_H_INCLUDED
#define MATRICULA_H_INCLUDED

#include<stdio.h>
#include<string.h>

void matriculas();

typedef struct{
char Id_materia [5];
char Id_alumno [7];
}matricula;

matricula *leer_matricula(unsigned *nMatricula);

int encontrar_matricula(matricula *b, unsigned m, char *id);

void eliminar_matricula(matricula **matricula, unsigned *m,char *idmat);

void mostrar_matricula (const matricula *b);

void mostrar_matriculas (const matricula *b, unsigned m);

void agregar_matricula(matricula **b, unsigned *n,char id);



void guardar_matriculas(const matricula *matriculas, unsigned n);

void guardar_matricula (const matricula *b, FILE *f);


#endif // MATRICULA_H_INCLUDED
