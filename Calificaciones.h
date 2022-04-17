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

//Cabecera: void anadirCalif(char *Id_alum,calificacion **vCalificaciones, int *nCalificaciones,int *nCalifAlumno);
//Precondición: Id_alum será la id del propio alumno que deseamos encontrar, nCalificaciones el número de calificaciones que encontramos, nCalifAlumno será la calificación de dicho alumno y vCalificaciones la posición en la que nos encontramos del vector
//Postcondición: Anadir la calificación a un alumno correspondiente

void anadirCalif(char *Id_alum,calificacion **vCalificaciones, int *nCalificaciones,int *nCalifAlumno);

//Cabecera: void listarCalif(char *Id_alum, calificacion*vCalificaciones, int nCalificaciones, int nCalifAlumnos);
//Precondición: Id_alum será la id del propio alumno que deseamos encontrar, nCalificaciones el número de calificaciones que encontramos, nCalifAlumno será la calificación de dicho alumno y vCalificaciones la posición en la que nos encontramos del vector
//Postcondición: Listar las calificaciones de un alumno seleccionado

void listarCalif(char *Id_alum, calificacion*vCalificaciones, int nCalificaciones, int nCalifAlumnos);

//Cabecera:void eliminarCalif(char *Id_alum, calificacion **vCalificaciones, int *nCalificaciones, int *nCalifAlumnos);
//Precondición: Id_alum será la id del propio alumno que deseamos encontrar, nCalificaciones el número de calificaciones que encontramos, nCalifAlumno será la calificación de dicho alumno y vCalificaciones la posición en la que nos encontramos del vector
//Postcondición: Eliminar la calificación de un alumno

void eliminarCalif(char *Id_alum, calificacion **vCalificaciones, int *nCalificaciones, int *nCalifAlumnos);

//Cabecera:void modifCalif(char *Id_alum, calificacion **vCalificaciones,int nCalificaciones, int nCalifAlumnos);
//Precondición: Id_alum será la id del propio alumno que deseamos encontrar, nCalificaciones el número de calificaciones que encontramos, nCalifAlumno será la calificación de dicho alumno y vCalificaciones la posición en la que nos encontramos del vector
//Postcondición: Modificar la calificación de un alumno seleccionado

void modifCalif(char *Id_alum, calificacion **vCalificaciones,int nCalificaciones, int nCalifAlumnos);

#endif // MATERIAS_H_INCLUDED
