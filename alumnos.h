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
// Precondici�n: alumno inicializado
// Postcondici�n: Muestra el contenido de alumno
void mostrar_alumno (const alumno *);

//Cabecera: alumno *leer_alumnos(unsigned*);
//Precondici�n: Ninguna
//Postcondici�n: Devuelve el n�mero de alumnos e inicializa el vector de alumnos
alumno *leer_alumnos(unsigned*);

//
//
//
void guardar_alumnos(const alumno *alumnos, unsigned n);

#endif /* ALUMNOS_H */
