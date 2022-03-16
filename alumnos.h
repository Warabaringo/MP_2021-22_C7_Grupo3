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

#endif /* ALUMNOS_H */
