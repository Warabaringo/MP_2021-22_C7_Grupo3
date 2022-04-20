#ifndef HORARIOS_H
#define HORARIOS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "alumnos.h"
#include "usuarios.h"
#include "Materias.h"

typedef struct {
    char id_profesor[4];
    int dia_clase;
    int hora_clase;
    char id_materia[5];
    char grupo[11];
} horario;

//Cabecera: void men?_admin_horarios()
//Precondici?n: Ninguna
//Poscondici?n: Muestra el men? de administrador para horarios
void menu_admin_horarios();

//Cabecera: void agregar_horario(horario **hor, usuario *usuarios, materia *materias, alumno *alumnos, unsigned nUsuarios, unsigned nMaterias, unsigned nAlumnos, unsigned *nHorarios)
//Precondici?n: Todos los vectores deben estar inicializados, cada unsigned son el n?mero de los distintos elementos de los vectores
//Poscondici?n: Agrega un horario teniendo en cuenta que exista los datos compartidos en otros ficheros
void agregar_horario(horario **hor, usuario *usuarios, materia *materias, alumno *alumnos, 
		unsigned nUsuarios, unsigned nMaterias, unsigned nAlumnos, unsigned *nHorarios);
		
//Cabecera: void eliminar_horario(horario **hor, int encontrado, unsigned *nHorarios)
//Precondici?n: encontrado es la posici?n del horario que se desea eliminar y nHorarios es el n?mero de horarios que hay
//Poscondici?n: Elimina un horario solicitado por el usuario.
void eliminar_horario(horario **hor, int encontrado, unsigned *nHorarios);

//Cabecera: void modificar_horario(horario *hor, materia *materias, usuario *usuarios, alumno *alumnos, unsigned *nHorarios, unsigned nMaterias, unsigned nUsuarios, unsigned nAlumnos, int encontrado);
//Precondici?n: Todos los vectores deben estar inicializados, cada unsigned son el n?mero de los distintos elementos de los vectores, encontrado es el horario que se desea modificar.
//Poscondici?n: Modifica un horario solicitado por el usuario.
void modificar_horario(horario *hor, materia *materias, usuario *usuarios, alumno *alumnos,	
		unsigned *nHorarios, unsigned nMaterias, unsigned nUsuarios, unsigned nAlumnos, int encontrado);
		
//Cabecera: void mostrar_horarios(horario *horarios, unsigned nHorarios)
//Precondici?n: nHorarios es el n?mero de horarios en el vector
//Poscondici?n: Muestra todos los horarios del vector
void mostrar_horarios(horario *horarios, unsigned nHorarios);

//Cabecera: void guardar_horarios(const horario *horarios, unsigned n)
//Precondici?n: n es el numero de horarios y horarios es el vector en s?
//Poscondici?n: Guarda en el fichero todos los horarios

void guardar_horarios(const horario *horarios, unsigned n);

//Cabecera: void guardar_horario (const horario *h, FILE *f)
//Precondici?n: Fichero abierto para escritura
//Poscondici?n: Guarda en el fichero el horario recibido
void guardar_horario (const horario *h, FILE *f);

//Cabecera: horario *leer_horarios(unsigned *nHorarios)
//Precondici?n: Ninguna
//Poscondici?n: Inicializa el vector de horarios y almacena en nHorarios el n?mero de horarios
horario *leer_horarios(unsigned *nHorarios);

//Cabecera: void mostrar_horario(const horario *hor)
//Precondici?n: Ninguna
//Poscondici?n: Muestra por pantalla el horario recibido
void mostrar_horario(const horario *hor);

//Cabecera: void mostrar_horarios(horario *horarios, unsigned nHorarios)
//Precondici?n: nHorarios es el n?mero de horarios que existen
//Poscondici?n: Muestra por pantalla el vector de horarios
void mostrar_horarios(horario *horarios, unsigned nHorarios);
#endif /* HORARIOS_H */
