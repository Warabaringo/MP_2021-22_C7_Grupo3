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
//Precondición: vMaterias es la posición de la materia que se desea dar de alta y nMaterias el número de materias que encontramos
//Postcondición: Da de alta la asignatura elegida

void daraltasig(materia **vMaterias,int *nMaterias);

//Cabecera: void darbajaasig(materia **vMaterias, int *nMaterias);
//Precondición: vMaterias es la posición de la materia que se desea dar de baja y nMaterias el número de materias que encontramos
//Postcondición: Da de baja a la asignatura elegida

void darbajaasig(materia **vMaterias, int *nMaterias);

//Cabecera: void modificarMateria(materia **vMaterias,int nMaterias);
//Precondición: vMaterias es la posición de la materia que se desea modificar y nMaterias el número de materias que encontramos
//Postcondición: Se consigue modificar la materia exitosamente, dándole los valores correspondientes a los de la función "daraltasig"

void modificarMateria(materia **vMaterias,int nMaterias);

//Cabecera: void listarMaterias(materia *vMaterias,int nMaterias);
//Precondición: vMaterias es la posición de la materia que se desea modificar y nMaterias el número de materias que encontramos
//Postcondición: El vector, recorrerá todas las materias correspondientes mostrándolas por pantalla

void listarMaterias(materia *vMaterias,int nMaterias);

//Cabecera: materia *leer_materia(unsigned *nMaterias);
//Precondición: nMaterias es el número de materias que encontramos, cada unsigned son el numero distinto del vector
//Postcondición: Se encargará de leer todas las materias de nuestro fichero

materia *leer_materia(unsigned *nMaterias);


#endif 
