#ifndef MATERIAS_H_INCLUDED
#define MATERIAS_H_INCLUDED

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct{
char Fecha_calif [8];
char Descrip_calif [30];
char Id_materia [4];
char Id_alum [6];
int Valor_calif;
}calificacion;

calificacion *vCalificaciones;

int nCalifAlumnos;

void anadirCalif(char *, calificacion **, int *, int * );
void listarCalif(char *, calificacion*, int, int );
void eliminarCalif(char *, calificacion **, int *, int *);
void modifCalif(char *, calificacion **, int, int);

#endif // MATERIAS_H_INCLUDED
