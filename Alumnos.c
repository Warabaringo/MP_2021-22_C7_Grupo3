// Alumnos.txt

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "alumnos.h"



int main(){
	unsigned i, n;
	int a;
	alumno *alumnos = leer_alumnos(&n);
	char id[7];
//	alumno a;
//	strcpy(a.id_alumno, "123456");
//	strcpy(a.nombre_alum, "Alumno");
//	strcpy(a.direc_alum, "Calle direccion");
//	strcpy(a.local_alum, "Localidad");
//	strcpy(a.curso, "4 ESO");
//	strcpy(a.grupo, "A");
//	FILE * f;
//	f = fopen("Alumnos.txt", "w");
//	
//	mostrar_alumno(&a);
//	guardar_alumno(&a, f);
//	fclose(f);
	
//	for(i = 0; i < n; i++)
//		mostrar_alumno(&alumnos[i]);	
	return 0;
}

int encontrar_alumno(alumno *a, unsigned n, char *id) {
	int i = 0, encontrado = -1;
	while(i < n && encontrado == -1){
		if(strcmp(id,a[i].id_alumno) == 0)
			encontrado = i;
		i++;
	}
	return encontrado;
}
// Cabecera: void mostrar_alumno (alumno)
// Precondición: alumno inicializado
// Postcondición: Muestra el contenido de alumno
void mostrar_alumno (const alumno *a) {
	printf("ID: %s\n", a->id_alumno);
	printf("Nombre: %s\n", a->nombre_alum);
	printf("Dirección: %s\n", a->direc_alum);
	printf("Localidad: %s\n", a->local_alum);
	printf("Curso: %s\n", a->curso);
	printf("Grupo: %s\n", a->grupo);
	puts("-----------------------------");
}

// Cabecera void guardar_alumno (alumno, FILE *)
// Precondición: Alumno inicializado, fichero abierto para escribir
// Postcondición: Escribe en el alumno.txt los datos del alumno
void guardar_alumno (const alumno *a, FILE *f) {
//	f = fopen("Alumnos.txt", "w");
	fprintf(f,"%s-", a->id_alumno);
	fprintf(f,"%s-", a->nombre_alum);
	fprintf(f,"%s-", a->direc_alum);
	fprintf(f,"%s-", a->local_alum);
	fprintf(f,"%s-", a->curso);
	fprintf(f,"%s\n", a->grupo);
//	fclose(f);
}

void guardar_alumnos(const alumno *alumnos, unsigned n) {
	FILE *f = fopen("Alumnos.txt","w");
	unsigned i;
	for(i = 0; i < n; i++)
		guardar_alumno(&alumnos[i], f);
	fclose(f);
}

alumno *leer_alumnos(unsigned *nAlumnos) {
	alumno *alumnos = NULL;
	alumno a;
	FILE *f = fopen("Alumnos.txt", "r");
	char linea[127], *token;
	unsigned n = 0;
	
	while(fgets(linea, 127, f) != NULL) {
		token = strtok(linea, "-");
		strcpy(a.id_alumno, token);
		token = strtok(NULL, "-");
		strcpy(a.nombre_alum, token);
		token = strtok(NULL, "-");
		strcpy(a.direc_alum, token);
		token = strtok(NULL, "-");
		strcpy(a.local_alum, token);
		token = strtok(NULL, "-");
		strcpy(a.curso, token);
		token = strtok(NULL, "\n");
		strcpy(a.grupo, token);
		
		n++;
		alumnos = (alumno*)realloc(alumnos, n * sizeof(alumno));
		alumnos[n-1] = a;
	}
	
	fclose(f);
	*nAlumnos = n;
	return alumnos;
}
