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

// Cabecera: void mostrar_alumno (alumno)
// Precondición: alumno inicializado
// Postcondición: Muestra el contenido de alumno
void mostrar_alumno (const alumno *);

//Cabecera: alumno *leer_alumnos(unsigned*);
//Precondición: Ninguna
//Postcondición: Devuelve el número de alumnos e inicializa el vector de alumnos
alumno *leer_alumnos(unsigned*);

//
//
//
void guardar_alumnos(const alumno *alumnos, unsigned n);

#endif /* ALUMNOS_H */
