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
//Precondición: vector de alumnos inicializado, la id tiene que ser de 7 carácteres
//Postcondición: Devuelve el número de elemento del alumno, devolverá -1 si no existe
int encontrar_alumno(alumno *a, unsigned n, char *cid);
// Cabecera: void mostrar_alumno (alumno)
// Precondición: alumno inicializado
// Postcondición: Muestra el contenido de alumno
void mostrar_alumno (const alumno *a);

//Cabecera: alumno *leer_alumnos(unsigned*);
//Precondición: Ninguna
//Postcondición: Devuelve a través del puntero pasado el número de alumnos e inicializa el vector de alumnos
alumno *leer_alumnos(unsigned *nAlumnos);

//Cabecera: void guardar_alumnos(const alumno *alumnos, unsigned n)
//Precondición: Ninguna
//Postcondición: Escribe en el fichero Alumnos.txt los n alumnos pasados
void guardar_alumnos(const alumno *alumnos, unsigned n);

#endif /* ALUMNOS_H */
