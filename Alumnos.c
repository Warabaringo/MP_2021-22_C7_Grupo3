// Alumnos.txt

#include <stdio.h>

void mostrar_alumno (alumno);
void guardar_alumno (alumno);

typedef struct{
	char id_alumno[6];
	char nombre_alum[20];
	char direc_alum[30];
	char local_alum[30];
	char curso[30];
	char grupo[10];
}alumno;

int main(){
	alumno a;
	FILE * f;
}

// Cabecera: void mostrar_alumno (alumno)
// Precondición: alumno inicializado
// Postcondición: Muestra el contenido de alumno
void mostrar_alumno (alumno a) {
	printf("%s-", a.id_alumno);
	printf("%s-", a.nombre_alum);
	printf("%s-", a.direc_alum);
	printf("%s-", a.local_alum);
	printf("%s-", a.curso);
	printf("%s\n", a.grupo);
}

// Cabecera void guardar_alumno (alumno, FILE *)
// Precondición: Alumno inicializado 
// Postcondición: Escribe en el alumno.txt los datos del alumno
void guardar_alumno (alumno a, FILE *f) {
	f = fopen("Alumnos.txt","w");
	fprintf(f,"%s-", a.id_alumno);
	fprintf(f,"%s-", a.nombre_alum);
	fprintf(f,"%s-", a.direc_alum);
	fprintf(f,"%s-", a.local_alum);
	fprintf(f,"%s-", a.curso);
	fprintf(f,"%s\n", a.grupo);
	fclose(f);
}
