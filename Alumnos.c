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
	free(alumnos);	
	return 0;
}
void menu_admin_alumno (alumno *a, unsigned n) {
	int op, encontrado;
	char id[7];
	do{
	puts("Introduzca la operacion deseada");
	printf("------------------------------\n");
	printf("1) Listar alumnos\n2) Modificar alumnos\n3) Dar de alta alumno\n4) Dar de baja alumno\n0) Salir.\n");
	scanf("%i", &op);
	switch(op) {
		case 1:
			mostrar_alumnos(a,n);
			break;
		case 2:
			fflush(stdin);
			puts("Introduzca el id del alumno");
			scanf("%s", &id);
			encontrado = encontrar_alumno(a, n, id);
			if(encontrado == -1)
				puts("Alumno no encontrado");
			else {
				modificar_alumno(a[encontrado]);
			}
			break;
			
	}
	}while(salir_menu() == 0);
}
int salir_menu() {
	int valido = 0, salir = 0;
	char opcion;
	do{
		fflush(stdin);
		puts("¿Desea hacer otra operacion? (s/n)");
		scanf("%c",&opcion);
		switch(opcion){
			case 'S':
				valido = 1;
				salir = 0;
				break;
			case 's':
				valido = 1;
				salir = 0;
				break;
			case 'n':
				valido = 1;
				salir = 1;
				break;
			case 'N':
				valido = 1;
				salir = 1;
				break;
			default:
				puts("Opcion no valida");
				valido = 0;
				break;
		}
	}while(valido == 0);
	return salir;
}
void modificar_alumno(alumno a){
	int op;
	char id[7], nombre[21], direccion[31], localidad[31], curso[31], grupo[11];
	puts("Introduzca que desea cambiar");
	printf("-------------------------\n");
	printf("1)Id\n2)Nombre\n3)Dirección\n4)Localidad\n5)Curso\n6)Grupo\n");
	scanf("%i",&op);
	do{
		switch(op){
			case 1:
				fflush(stdin);
				puts("Introduzca la nueva id");
				fgets(id, 7, stdin);
				strcpy(a.id_alumno,id);
				break;
			case 2:
				fflush(stdin);
				puts("Introduzca el nuevo nombre");
				fgets(nombre,21, stdin);
				strcpy(a.nombre_alum, nombre);
				break;
			case 3:
				fflush(stdin);
				puts("Introduce la nueva direccion");
				fgets(direccion, 31, stdin);
				strcpy(a.direc_alum, direccion);
				break;
			case 4:
				fflush(stdin);
				puts("Introduce la nueva localidad");
				fgets(localidad, 31, stdin);
				strcpy(a.local_alum, localidad);
				break;
			case 5:
				fflush(stdin);
				puts("Introduce el nuevo curso");
				fgets(curso, 31, stdin);
				strcpy(a.curso, curso);
				break;
			case 6:
				fflush(stdin);
				puts("Introduce el nuevo grupo");
				fgets(grupo, 11, stdin);
				strcpy(a.grupo, grupo);
				break;
			default:
				puts("Opcion no valida");
				break;
		}
	}while(salir_menu == 0);
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
//Cabecera: mostrar_alumnos (const alumno *a, unsigned n)
//Precondiciï¿½n: Alumno inicializado
//Postcondiciï¿½n: Muestra por pantalla los n alumnos
void mostrar_alumnos (const alumno *a, unsigned n){
	int i;
	for(i = 0; i < n; i++)
		mostrar_alumno (&a[i]);
}
// Cabecera: void mostrar_alumno (alumno)
// Precondiciï¿½n: alumno inicializado
// Postcondiciï¿½n: Muestra el contenido de alumno
void mostrar_alumno (const alumno *a) {
	printf("ID: %s\n", a->id_alumno);
	printf("Nombre: %s\n", a->nombre_alum);
	printf("Direcciï¿½n: %s\n", a->direc_alum);
	printf("Localidad: %s\n", a->local_alum);
	printf("Curso: %s\n", a->curso);
	printf("Grupo: %s\n", a->grupo);
	puts("-----------------------------");
}

// Cabecera void guardar_alumno (alumno, FILE *)
// Precondiciï¿½n: Alumno inicializado, fichero abierto para escribir
// Postcondiciï¿½n: Escribe en el alumno.txt los datos del alumno
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
