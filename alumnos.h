#ifndef ALUMNOS_H
#define ALUMNOS_H

typedef struct {
	char id_alumno[7];
	char nombre_alum[21];
	char direc_alum[31];
	char local_alum[31];
	char curso[31];
	char grupo[11];
} alumno;

//Cabecera: int encontrar_alumno(alumno *a, unsigned n, char *)
//Precondici�n: vector de alumnos inicializado, la id tiene que ser de 7 car�cteres
//Postcondici�n: Devuelve el n�mero de elemento del alumno, devolver� -1 si no existe
int encontrar_alumno(alumno *a, unsigned n, char *cid);

// Cabecera: void mostrar_alumno (alumno)
// Precondici�n: alumno inicializado
// Postcondici�n: Muestra el contenido de alumno
void mostrar_alumno (const alumno *a);

//Cabecera: alumno *leer_alumnos(unsigned*);
//Precondici�n: Ninguna
//Postcondici�n: Devuelve a trav�s del puntero pasado el n�mero de alumnos e inicializa el vector de alumnos
alumno *leer_alumnos(unsigned *nAlumnos);

//Cabecera: void guardar_alumnos(const alumno *alumnos, unsigned n)
//Precondici�n: Ninguna
//Postcondici�n: Escribe en el fichero Alumnos.txt los n alumnos pasados
void guardar_alumnos(const alumno *alumnos, unsigned n);

//Cabecera: void menu_admin_alumno (alumno *a, unsigned n)
//Precondición:Vector de alumno inicializado
//Postcondición: Muestra el menu de administrador para alumnos
void menu_admin_alumno (alumno *a, unsigned n);

//Cabecera: int salir_menu();
//Precondición: Ninguna
//Postcondición: Devuelve 1 si se quiere salir del menú y 0 si no
int salir_menu();

//Cabecera: void agregar_alumno(alumno **a, unsigned *n)
//Precondición: n es el número de alumnos y el vector a tiene que estar inicializado
//Postcondición: Agrega un nuevo alumno introducido por el usuario
void agregar_alumno(alumno **a, unsigned *n);

//Cabecera: void modificar_alumno(alumno a)
//Precondición: Ninguna
//Postcondición: Modifica el alumno introducido según quiera el usuario
void modificar_alumno(alumno a);

//Cabecera: void mostrar_alumnos (const alumno *a, unsigned n)
//Precondición: n es el número de alumnos
//Postcondición: Muestra todos los alumnos del vector
void mostrar_alumnos (const alumno *a, unsigned n);

//Cabecera: void quitar_salto(char *s)
//Precondición: Ninguna
//Postcondición: Quita de la cadena el carácter '\n'
void quitar_salto(char *s);

//Cabecera: void eliminar_alumno(alumno **a, unsigned n, int pos)
//Precondición: n es el número de alumnos y pos es la posición del alumno en el vector
//Postcondición: Elimina el alumno de la posición indicada
void eliminar_alumno(alumno **a, unsigned n, int pos);

//Cabecera: int existe alumno(alumno *a, char *s, unsigned n)
//Precondición: s es la id del alumno a encontrar y n es el número de alumnos
//Postcondición: Devuelve 1 si el alumno existe y 0 si no
int existe_alumno (alumno *a, char *s, unsigned n);

//Cabecera: void guardar_alumno (const alumno *a, FILE *f)
//Precondición: Fichero abierto para escritura
//Postcondición: Guarda el alumno en el fichero
void guardar_alumno(const alumno *a, FILE *f);
#endif /* ALUMNOS_H */
