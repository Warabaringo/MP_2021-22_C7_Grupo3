#ifndef ALUMNOS_H
#define ALUMNOS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	char id_alumno[7];
	char nombre_alum[21];
	char direc_alum[31];
	char local_alum[31];
	char curso[31];
	char grupo[11];
} alumno;

//Cabecera: int encontrar_alumno(alumno *a, unsigned n, char *)
//Precondici?n: vector de alumnos inicializado, la id tiene que ser de 7 car?cteres
//Postcondici?n: Devuelve el n?mero de elemento del alumno, devolver? -1 si no existe
int encontrar_alumno(alumno *a, unsigned n, char *id);

// Cabecera: void mostrar_alumno (alumno)
// Precondici?n: alumno inicializado
// Postcondici?n: Muestra el contenido de alumno
void mostrar_alumno (const alumno *a);

//Cabecera: alumno *leer_alumnos(unsigned*);
//Precondici?n: Ninguna
//Postcondici?n: Devuelve a trav?s del puntero pasado el n?mero de alumnos e inicializa el vector de alumnos
alumno *leer_alumnos(unsigned *nAlumnos);

//Cabecera: void guardar_alumnos(const alumno *alumnos, unsigned n)
//Precondici?n: Ninguna
//Postcondici?n: Escribe en el fichero Alumnos.txt los n alumnos pasados
void guardar_alumnos(const alumno *alumnos, unsigned n);

//Cabecera: void menu_admin_alumno (alumno *a, unsigned n)
//Precondici?n:Ninguna
//Postcondici?n: Muestra el menu de administrador para alumnos
void menu_admin_alumno();

//Cabecera: int salir_menu();
//Precondici?n: Ninguna
//Postcondici?n: Devuelve 1 si se quiere salir del men? y 0 si no
int salir_menu();

//Cabecera: void agregar_alumno(alumno **a, unsigned *n)
//Precondici?n: n es el n?mero de alumnos y el vector a tiene que estar inicializado
//Postcondici?n: Agrega un nuevo alumno introducido por el usuario
void agregar_alumno(alumno **a, unsigned *n);

//Cabecera: void modificar_alumno(alumno a)
//Precondici?n: Ninguna
//Postcondici?n: Modifica el alumno introducido seg?n quiera el usuario
void modificar_alumno(alumno *a);

//Cabecera: void mostrar_alumnos (const alumno *a, unsigned n)
//Precondici?n: n es el n?mero de alumnos
//Postcondici?n: Muestra todos los alumnos del vector
void mostrar_alumnos (const alumno *a, unsigned n);

//Cabecera: void quitar_salto(char *s)
//Precondici?n: Ninguna
//Postcondici?n: Quita de la cadena el car?cter '\n'
void quitar_salto(char *s);

//Cabecera: void eliminar_alumno(alumno **a, unsigned n, int pos)
//Precondici?n: n es el n?mero de alumnos y pos es la posici?n del alumno en el vector
//Postcondici?n: Elimina el alumno de la posici?n indicada
void eliminar_alumno(alumno **alumnos, unsigned *n,char *id);

//Cabecera: int existe alumno(alumno *a, char *s, unsigned n)
//Precondici?n: s es la id del alumno a encontrar y n es el n?mero de alumnos
//Postcondici?n: Devuelve 1 si el alumno existe y 0 si no
int existe_alumno (alumno *a, char *s, unsigned n);

//Cabecera: void guardar_alumno (const alumno *a, FILE *f)
//Precondici?n: Fichero abierto para escritura
//Postcondici?n: Guarda el alumno en el fichero
void guardar_alumno(const alumno *a, FILE *f);

//Cabecera: int existe_grupo(alumno *a, unsigned n, char *grupo)
//Precondici?n: Vector de alumnos a inicializado, n es el n?mero de alumnos
//Poscondici?n: Devuelve 0 si no existe el grupo y 1 si existe
int existe_grupo(alumno *a, unsigned n, char *grupo);

#endif /* ALUMNOS_H */
