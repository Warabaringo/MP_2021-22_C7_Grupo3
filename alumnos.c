// Alumnos.txt
#include "alumnos.h"

void menu_admin_alumno () {
	unsigned n;
	alumno *a = leer_alumnos(&n);
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
			else
				modificar_alumno(&a[encontrado]);
			break;
		case 3:
			agregar_alumno(&a,&n);
			break;
		case 4:
			fflush(stdin);
			puts("Introduce la id del alumno para eliminar");
			scanf("%s", &id);
			eliminar_alumno(&a,&n, id);
			break;
	}
	}while(salir_menu() == 0);
	
	guardar_alumnos(a,n);
	free(a);
}
int salir_menu() {
	int valido = 0, salir = 0;
	char opcion;
	do{
		fflush(stdin);
		puts("�Desea hacer otra operacion? (s/n)");
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
int existe_alumno (alumno *a, char *s, unsigned n){
	int i, existe = 0;
	
	for(i = 0; i < n; i++) 
		if (strcmp(s, a[i].id_alumno) == 0)
			existe = 1;
	
	return existe;
}
void agregar_alumno(alumno **a, unsigned *n) {
	alumno nuevo;
	char id[7];
	
	fflush(stdin);
	puts("Introduzca la id del nuevo alumno");
	fgets(id,7,stdin);
	if(!existe_alumno(*a,id,*n)){
		strcpy(nuevo.id_alumno,id);
		quitar_salto(nuevo.id_alumno);
	
		fflush(stdin);
		puts("Introduce el nombre del nuevo alumno");
		fgets(nuevo.nombre_alum,20,stdin);
		quitar_salto(nuevo.nombre_alum);
	
		fflush(stdin);
		puts("Introduce la direccion del nuevo alumno");
		fgets(nuevo.direc_alum,30,stdin);
		quitar_salto(nuevo.direc_alum);
	
		fflush(stdin);
		puts("Introduce la localidad del nuevo alumno");
		fgets(nuevo.local_alum,30,stdin);
		quitar_salto(nuevo.local_alum);
		
		fflush(stdin);
		puts("Introduce el curso del nuevo alumno");
		fgets(nuevo.curso,30,stdin);
		quitar_salto(nuevo.curso);
			
		fflush(stdin);
		puts("Introduce el grupo del nuevo alumno");
		fgets(nuevo.grupo,10,stdin);
		quitar_salto(nuevo.grupo);
	
		*a = realloc(*a, (*n+1) * sizeof(alumno));
		(*a)[*n] = nuevo;
		(*n)++;
	}
	else
		puts("Alumno ya existente");
}
void eliminar_alumno(alumno **alumnos, unsigned *n,char *id) {
	int i, encontrado;
	
	encontrado = encontrar_alumno(*alumnos,*n,id);
	if(encontrado != -1) {
		for (i = encontrado; i < (*n)-1; i++)
			(*alumnos)[i] = (*alumnos)[i+1]; 
		(*n)--;
		*alumnos = realloc(*alumnos, *n * sizeof(alumno));
	}
}
void modificar_alumno(alumno *a){
	int op;
	char id[7], nombre[21], direccion[31], localidad[31], curso[31], grupo[11];
	puts("Introduzca que desea cambiar");
	printf("-------------------------\n");
	printf("1)Id\n2)Nombre\n3)Direccion\n4)Localidad\n5)Curso\n6)Grupo\n");
	scanf("%i",&op);
	do{
		switch(op){
			case 1:
				fflush(stdin);
				puts("Introduzca la nueva id");
				fgets(id, 7, stdin);
				strcpy(a->curso,id);
				break;
			case 2:
				fflush(stdin);
				puts("Introduzca el nuevo nombre");
				fgets(nombre,21, stdin);
				strcpy(a->nombre_alum, nombre);
				break;
			case 3:
				fflush(stdin);
				puts("Introduce la nueva direccion");
				fgets(direccion, 31, stdin);
				strcpy(a->direc_alum, direccion);
				break;
			case 4:
				fflush(stdin);
				puts("Introduce la nueva localidad");
				fgets(localidad, 31, stdin);
				strcpy(a->local_alum, localidad);
				break;
			case 5:
				fflush(stdin);
				puts("Introduce el nuevo curso");
				fgets(curso, 31, stdin);
				strcpy(a->curso, curso);
				break;
			case 6:
				fflush(stdin);
				puts("Introduce el nuevo grupo");
				fgets(grupo, 11, stdin);
				strcpy(a->grupo, grupo);
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

int existe_grupo(alumno *a, unsigned n, char *grupo) {
	int i = 0, existe = 0;
	
	while(i < n && !existe) {
		if(strcmp(grupo, a[i].grupo) == 0)
			existe = 1;
		i++;
	}
	
	return existe;
}

//Cabecera: mostrar_alumnos (const alumno *a, unsigned n)
//Precondici�n: Alumno inicializado
//Postcondici�n: Muestra por pantalla los n alumnos
void mostrar_alumnos (const alumno *a, unsigned n){
	int i;
	for(i = 0; i < n; i++)
		mostrar_alumno (&a[i]);
}
// Cabecera: void mostrar_alumno (alumno)
// Precondici�n: alumno inicializado
// Postcondici�n: Muestra el contenido de alumno
void mostrar_alumno (const alumno *a) {
	printf("ID: %s\n", a->id_alumno);
	printf("Nombre: %s\n", a->nombre_alum);
	printf("Direcci�n: %s\n", a->direc_alum);
	printf("Localidad: %s\n", a->local_alum);
	printf("Curso: %s\n", a->curso);
	printf("Grupo: %s\n", a->grupo);
	puts("-----------------------------");
}

// Cabecera void guardar_alumno (alumno, FILE *)
// Precondici�n: Alumno inicializado, fichero abierto para escribir
// Postcondici�n: Escribe en el alumno.txt los datos del alumno
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

void quitar_salto(char *s) {
	char *pos = strchr(s, '\n');
	if(pos != NULL)
		*pos = '\0';
}
