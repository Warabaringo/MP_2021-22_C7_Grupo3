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

//Cabecera: void daraltasig(materia **vMaterias,int *nMaterias);
//Precondici?n: vMaterias es la posici?n de la materia que se desea dar de alta y nMaterias el n?mero de materias que encontramos
//Postcondici?n: Da de alta la asignatura elegida

void daraltasig(materia **vMaterias,int *nMaterias);

//Cabecera: void darbajaasig(materia **vMaterias, int *nMaterias);
//Precondici?n: vMaterias es la posici?n de la materia que se desea dar de baja y nMaterias el n?mero de materias que encontramos
//Postcondici?n: Da de baja a la asignatura elegida

void darbajaasig(materia **vMaterias, int *nMaterias);

//Cabecera: void modificarMateria(materia **vMaterias,int nMaterias);
//Precondici?n: vMaterias es la posici?n de la materia que se desea modificar y nMaterias el n?mero de materias que encontramos
//Postcondici?n: Se consigue modificar la materia exitosamente, d?ndole los valores correspondientes a los de la funci?n "daraltasig"

void modificarMateria(materia **vMaterias,int nMaterias);

//Cabecera: void listarMaterias(materia *vMaterias,int nMaterias);
//Precondici?n: vMaterias es la posici?n de la materia que se desea modificar y nMaterias el n?mero de materias que encontramos
//Postcondici?n: El vector, recorrer? todas las materias correspondientes mostr?ndolas por pantalla

void listarMaterias(materia *vMaterias,int nMaterias);

//Cabecera: materia *leer_materia(unsigned *nMaterias);
//Precondici?n: nMaterias es el n?mero de materias que encontramos, cada unsigned son el numero distinto del vector
//Postcondici?n: Se encargar? de leer todas las materias de nuestro fichero

materia *leer_materia(unsigned *nMaterias);


#endif 
