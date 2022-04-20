#include "horarios.h"

/**
*										*
*	DEFINICI?N DE FUNCIONES PRIVADAS 	*
*										*
**/
//
//Cabecera: int grupo_libre(const horario *nuevo, const horario *horarios, unsigned n)
//Precondici?n: n es el n?mero de horarios, nuevo es el horario recibido que se quiere verificar si est? libre
//Poscondici?n: Devuelve 1 si el horario est? libre (no existe) o 0 si no est? libre
int grupo_libre(const horario *nuevo, const horario *horarios, unsigned n);
//
//Cabecera: int profesor_libre(const horario *nuevo, const horario *horarios, unsigned n)
//Precondici?n: n es el n?mero de horarios, nuevo es el horario recibido que contiene el profesor (id), hora y d?a que se quiere verificar si est? libre
//Poscondici?n: Devuelve 1 si el profesor est? libre en esa fecha o 0 si no.
int profesor_libre(const horario *nuevo, const horario *horarios, unsigned n);
//
void menu_admin_horarios() {
	unsigned nHorarios, nUsuarios, nAlumnos, nMaterias;
	int op, encontrado;
	char id[4];
	horario *horarios = leer_horarios(&nHorarios);
	usuario *usuarios = leer_usuarios(&nUsuarios);
	alumno *alumnos = leer_alumnos(&nAlumnos);
	materia *materias = leer_materia(&nMaterias);
	
	
	
	do {
		
		puts("Seleccione la operacion deseada:");
		puts("	1.- Agregar horas de clase");
		puts("	2.- Eliminar horas de clase");
		puts("	3.- Modificar horas de clase");
		puts("	4.- Mostrar horarios de clase");
		puts("	0.- Salir");
		scanf("%i", &op);
		
		switch(op){
			case 0:
				puts("Salir");
				break;
			case 1:
				agregar_horario(&horarios, usuarios, materias, alumnos, nUsuarios, nMaterias, nAlumnos, &nHorarios);
				break;
			case 2:
				do {
					mostrar_horarios(horarios, nHorarios);
					puts("Introduce el horario que desee eliminar");
					scanf("%i", &encontrado);
				}while(encontrado < 0 || encontrado > nHorarios);
				eliminar_horario(&horarios, encontrado-1, &nHorarios);
				break;
			case 3:
				do {
					mostrar_horarios(horarios, nHorarios);
					puts("Introduce el horario que desee modificar");
					scanf("%i", &encontrado);
				}while(encontrado < 0 || encontrado > nHorarios);
				modificar_horario(horarios, materias, usuarios, alumnos, &nHorarios, nMaterias, nUsuarios, nAlumnos, encontrado-1);
				break;
			case 4:
				mostrar_horarios(horarios, nHorarios);
				break;
			default:
				puts("Operacion no valida");
				break;
		}
	}while(op != 0);
	
	
	guardar_horarios(horarios, nHorarios);
	free(horarios);
	free(alumnos);
	free(materias);
	free(usuarios);
	
}
//
void agregar_horario(horario **hor, usuario *usuarios, materia *materias, alumno *alumnos, 
		unsigned nUsuarios, unsigned nMaterias, unsigned nAlumnos, unsigned *nHorarios) {
	horario nuevo;
	
	fflush(stdin);
	puts("Introduce el id de profesor");
	fgets(nuevo.id_profesor, 4, stdin);
	quitar_salto(nuevo.id_profesor);
	
	fflush(stdin);
	puts("Introduce el id de la materia");
	fgets(nuevo.id_materia, 5, stdin);
	quitar_salto(nuevo.id_materia);
	
	fflush(stdin);
	puts("Introduce el grupo");
	fgets(nuevo.grupo, 11, stdin);
	quitar_salto(nuevo.grupo);
	
	if(encontrar_profesor(usuarios, nuevo.id_profesor, nUsuarios) == -1 ||
			encontrar_materia(materias, nuevo.id_materia, nMaterias) == -1 ||
			!existe_grupo(alumnos, nAlumnos, nuevo.grupo))
		puts("No existe alguno de los datos introducidos");
	else {
		puts("Introduce la hora de clase");
		scanf("%i", &nuevo.hora_clase);
		
		puts("Introduce el dia de clase");
		scanf("%i", &nuevo.dia_clase);
		
		if(profesor_libre(&nuevo, *hor, *nHorarios)) {
			if(grupo_libre(&nuevo, *hor, *nHorarios)) {
				*hor = realloc(*hor,(*nHorarios+1) * sizeof(horario));
				(*hor)[*nHorarios] = nuevo;
				(*nHorarios)++;
				
				puts("Se ha guardado el siguiente horario: ");
				mostrar_horario(&nuevo);
			}
			else
				puts("El grupo no estaba libre ese dia a esa hora");
		}
		else
			puts("El profesor no estaba libre ese dia a esa hora");
	}
}
//
void eliminar_horario(horario **hor, int encontrado, unsigned *nHorarios) {
	int i;
	
	for(i = encontrado; i < (*nHorarios)-1; i++)
		(*hor)[i] = (*hor)[i+1];

	(*nHorarios)--;
	*hor = realloc(*hor, *nHorarios * sizeof(hor));
}
//
void modificar_horario(horario *hor, materia *materias, usuario *usuarios, alumno *alumnos, 
		unsigned *nHorarios, unsigned nMaterias, unsigned nUsuarios, unsigned nAlumnos, int encontrado) {
	horario nuevo;
	
	fflush(stdin);
	puts("Introduce el id de profesor");
	fgets(nuevo.id_profesor, 4, stdin);
	quitar_salto(nuevo.id_profesor);
	
	fflush(stdin);
	puts("Introduce el id de la materia");
	fgets(nuevo.id_materia, 5, stdin);
	quitar_salto(nuevo.id_materia);
	
	fflush(stdin);
	puts("Introduce el grupo");
	fgets(nuevo.grupo, 11, stdin);
	quitar_salto(nuevo.grupo);
	
	if(encontrar_profesor(usuarios, nuevo.id_profesor, nUsuarios) == -1 ||
			encontrar_materia(materias, nuevo.id_materia, nMaterias) == -1 ||
			!existe_grupo(alumnos, nAlumnos, nuevo.grupo))
		puts("No existe alguno de los datos introducidos");
	else {
		puts("Introduce la hora de clase");
		scanf("%i", &nuevo.hora_clase);
		
		puts("Introduce el dia de clase");
		scanf("%i", &nuevo.dia_clase);
		
		if(profesor_libre(&nuevo, hor, *nHorarios)) {
			if(grupo_libre(&nuevo, hor, *nHorarios)) {
				hor[encontrado] = nuevo;
				puts("Se ha guardado el siguiente horario: ");
				mostrar_horario(&nuevo);
			}
			else
				puts("El grupo no estaba libre ese dia a esa hora");
		}
		else
			puts("El profesor no estaba libre ese dia a esa hora");
	}
}
//
void mostrar_horarios(horario *horarios, unsigned nHorarios) {
	int i;
	
	for(i = 0; i < nHorarios; i++) {
		printf("HORARIO NUMERO %i\n", i+1);
		puts("-------------------------");	
		mostrar_horario(&horarios[i]);
		puts("-------------------------");
	}
}
//
void mostrar_horario(const horario *hor) {
	static char *nombre_dias[5] = { "Lunes", "Martes", "Miercoles", "Jueves", "Viernes" };
	static char *nombre_horas[6] = {"Primera", "Segunda", "Tercera", "Cuarta", "Quinta", "Sexta"};
	
		
	printf("Id Profesor: %s\n", hor->id_profesor);
	printf("Dia de clase: %s\n", nombre_dias[hor->dia_clase - 1]);
	printf("Hora de clase: %s\n", nombre_horas[hor->hora_clase-1]);
	printf("Id materia: %s\n", hor->id_materia);
	printf("Grupo: %s\n", hor->grupo);
}
//
horario *leer_horarios(unsigned *nHorarios){
    horario *horarios = NULL;
    horario hor;

    FILE *f = fopen("Horarios.txt", "r");
    char linea[21], *token;
    unsigned n = 0;

    while(fgets(linea, 21, f) != NULL) {
        token = strtok(linea, "-");
        strcpy(hor.id_profesor, token);
        token = strtok(NULL, "-");
        hor.dia_clase = atoi(token);
        token = strtok(NULL, "-");
        hor.hora_clase = atoi(token);
        token = strtok(NULL, "-");
        strcpy(hor.id_materia, token);
        token = strtok(NULL, "\n");
        strcpy(hor.grupo, token);


        n++;
        horarios = (horario*) realloc(horarios, n *sizeof(horario));
        horarios[n-1] = hor;
    }
    fclose(f);
    *nHorarios = n;
    
    return horarios;
}
//
void guardar_horarios(const horario *horarios, unsigned n) {
	FILE *f = fopen("Horarios.txt","w");
	unsigned i;
	for(i = 0; i < n; i++)
		guardar_horario(&horarios[i], f);
	fclose(f);
}
//
void guardar_horario (const horario *h, FILE *f) {
	fprintf(f,"%s-", h->id_profesor);
	fprintf(f,"%i-", h->dia_clase);
	fprintf(f,"%i-", h->hora_clase);
	fprintf(f,"%s-", h->id_materia);
	fprintf(f,"%s", h->grupo);
}
//
int encontrar_materia(materia *materias, char *idMateria, unsigned nMaterias) {
	int i = 0, encontrado = -1;
	
	while (i < nMaterias && encontrado == -1) {
		if(strcmp(idMateria, materias[i].Id_materia) == 0)
			encontrado = i;
		i++;
	}
	
	return encontrado;
}
//
int grupo_libre(const horario *nuevo, const horario *horarios, unsigned n) {
	int libre = 1, i = 0, dia_clase, hora_clase;
	char grupo[11];
	const horario *actual;
	
	dia_clase = nuevo->dia_clase;
	hora_clase = nuevo->hora_clase;
	strcpy(grupo, nuevo->grupo);
	
	while(libre && i < n) {
		actual = horarios + i;
		if(actual->dia_clase == dia_clase && 
				actual->hora_clase == hora_clase &&
				strcmp(actual->grupo, grupo) == 0)
			libre = 0;
		i++;
	}
	
	return libre;
}
//
int profesor_libre(const horario *nuevo, const horario *horarios, unsigned n) {
	int libre = 1, i = 0, dia_clase, hora_clase;
	char id_profesor[4];
	const horario *actual;
	
	dia_clase = nuevo->dia_clase;
	hora_clase = nuevo->hora_clase;
	strcpy(id_profesor, nuevo->id_profesor);	
	
	while(libre && i < n) {
		actual = horarios + i;
		if(actual->dia_clase == dia_clase && 
				actual->hora_clase == hora_clase &&
				strcmp(actual->id_profesor, id_profesor) == 0)
			libre = 0;
		i++;
	}
	
	return libre;
}
