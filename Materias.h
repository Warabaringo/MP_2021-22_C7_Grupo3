#ifndef MATERIAS_H_INCLUDED
#define MATERIAS_H_INCLUDED

#include<stdio.h>
#include<string.h>

typedef struct{
char Id_materia [4];
char Nombre_materia [50];
char Abrev_materia [3];
}materia;

materia *vMaterias;

void daraltasig(materia **vMaterias,int *nMaterias);
void darbajaasig(materia **vMaterias, int *nMaterias);
void modificarMateria(materia **vMaterias,int nMaterias);
void listarMaterias(materia *vMaterias,int nMaterias);
materia *leer_materia(unsigned *nMaterias);
#endif // MATERIAS_H_INCLUDED
