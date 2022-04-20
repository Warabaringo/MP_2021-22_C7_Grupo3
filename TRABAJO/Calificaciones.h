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
//Precondici?n: Id_alum ser? la id del propio alumno que deseamos encontrar, nCalificaciones el n?mero de calificaciones que encontramos, nCalifAlumno ser? la calificaci?n de dicho alumno y vCalificaciones la posici?n en la que nos encontramos del vector
//Postcondici?n: Anadir la calificaci?n a un alumno correspondiente

void anadirCalif(char *Id_alum,calificacion **vCalificaciones, int *nCalificaciones,int *nCalifAlumno);

//Cabecera: void listarCalif(char *Id_alum, calificacion*vCalificaciones, int nCalificaciones, int nCalifAlumnos);
//Precondici?n: Id_alum ser? la id del propio alumno que deseamos encontrar, nCalificaciones el n?mero de calificaciones que encontramos, nCalifAlumno ser? la calificaci?n de dicho alumno y vCalificaciones la posici?n en la que nos encontramos del vector
//Postcondici?n: Listar las calificaciones de un alumno seleccionado

void listarCalif(char *Id_alum, calificacion*vCalificaciones, int nCalificaciones, int nCalifAlumnos);

//Cabecera:void eliminarCalif(char *Id_alum, calificacion **vCalificaciones, int *nCalificaciones, int *nCalifAlumnos);
//Precondici?n: Id_alum ser? la id del propio alumno que deseamos encontrar, nCalificaciones el n?mero de calificaciones que encontramos, nCalifAlumno ser? la calificaci?n de dicho alumno y vCalificaciones la posici?n en la que nos encontramos del vector
//Postcondici?n: Eliminar la calificaci?n de un alumno

void eliminarCalif(char *Id_alum, calificacion **vCalificaciones, int *nCalificaciones, int *nCalifAlumnos);

//Cabecera:void modifCalif(char *Id_alum, calificacion **vCalificaciones,int nCalificaciones, int nCalifAlumnos);
//Precondici?n: Id_alum ser? la id del propio alumno que deseamos encontrar, nCalificaciones el n?mero de calificaciones que encontramos, nCalifAlumno ser? la calificaci?n de dicho alumno y vCalificaciones la posici?n en la que nos encontramos del vector
//Postcondici?n: Modificar la calificaci?n de un alumno seleccionado

void modifCalif(char *Id_alum, calificacion **vCalificaciones,int nCalificaciones, int nCalifAlumnos);

#endif // MATERIAS_H_INCLUDED
