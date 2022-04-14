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

//Cabecera: void menú_admin_horarios()
//Precondición: Ninguna
//Poscondición: Muestra el menú de administrador para horarios
void menu_admin_horarios();

//Cabecera: void agregar_horario(horario **hor, usuario *usuarios, materia *materias, alumno *alumnos, unsigned nUsuarios, unsigned nMaterias, unsigned nAlumnos, unsigned *nHorarios)
//Precondición: Todos los vectores deben estar inicializados, cada unsigned son el número de los distintos elementos de los vectores
//Poscondición: Agrega un horario teniendo en cuenta que exista los datos compartidos en otros ficheros
void agregar_horario(horario **hor, usuario *usuarios, materia *materias, alumno *alumnos, 
		unsigned nUsuarios, unsigned nMaterias, unsigned nAlumnos, unsigned *nHorarios);
		
//Cabecera: void eliminar_horario(horario **hor, int encontrado, unsigned *nHorarios)
//Precondición: encontrado es la posición del horario que se desea eliminar y nHorarios es el número de horarios que hay
//Poscondición: Elimina un horario solicitado por el usuario.
void eliminar_horario(horario **hor, int encontrado, unsigned *nHorarios);

//Cabecera: void modificar_horario(horario *hor, materia *materias, usuario *usuarios, alumno *alumnos, unsigned *nHorarios, unsigned nMaterias, unsigned nUsuarios, unsigned nAlumnos, int encontrado);
//Precondición: Todos los vectores deben estar inicializados, cada unsigned son el número de los distintos elementos de los vectores, encontrado es el horario que se desea modificar.
//Poscondición: Modifica un horario solicitado por el usuario.
void modificar_horario(horario *hor, materia *materias, usuario *usuarios, alumno *alumnos,	
		unsigned *nHorarios, unsigned nMaterias, unsigned nUsuarios, unsigned nAlumnos, int encontrado);
		
//Cabecera: void mostrar_horarios(horario *horarios, unsigned nHorarios)
//Precondición: nHorarios es el número de horarios en el vector
//Poscondición: Muestra todos los horarios del vector
void mostrar_horarios(horario *horarios, unsigned nHorarios);

//Cabecera: void guardar_horarios(const horario *horarios, unsigned n)
//Precondición: n es el numero de horarios y horarios es el vector en sí
//Poscondición: Guarda en el fichero todos los horarios

void guardar_horarios(const horario *horarios, unsigned n);

//Cabecera: void guardar_horario (const horario *h, FILE *f)
//Precondición: Fichero abierto para escritura
//Poscondición: Guarda en el fichero el horario recibido
void guardar_horario (const horario *h, FILE *f);

//Cabecera: horario *leer_horarios(unsigned *nHorarios)
//Precondición: Ninguna
//Poscondición: Inicializa el vector de horarios y almacena en nHorarios el número de horarios
horario *leer_horarios(unsigned *nHorarios);

//Cabecera: void mostrar_horario(const horario *hor)
//Precondición: Ninguna
//Poscondición: Muestra por pantalla el horario recibido
void mostrar_horario(const horario *hor);

//Cabecera: void mostrar_horarios(horario *horarios, unsigned nHorarios)
//Precondición: nHorarios es el número de horarios que existen
//Poscondición: Muestra por pantalla el vector de horarios
void mostrar_horarios(horario *horarios, unsigned nHorarios);
#endif /* HORARIOS_H */
