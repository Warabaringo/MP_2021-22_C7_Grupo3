#include "horarios.h"

void menu_admin_horarios() {
	unsigned nHorarios;
	int op, encontrado, salir;
	char id[4];
	horario *horarios = leer_horarios(&nHorarios);
	usuario *usuarios;
	
	puts("Introduzca la operacion deseada: agregar horas de clase(1), eliminar horas(2), modificar horas(3), listar horarios(4), salir(0)");
	scanf("%i", &op);
	do{
		switch(op){
			case 1:
				agregar_horario(&horarios);
				break;
			case 2:
				puts("Introduce id de profesor");
				scanf("%s", &id);
				if((encontrado = encontrar_profesor(horarios, id, nHorarios)) == -1)
					puts("Profesor no encontrado");
				else {
					eliminar_horas(&horarios[encontrado]);
				}
				break;
			case 3:
				puts("Introduce id de profesor");
				scanf("%s", &id);
				if((encontrado = encontrar_profesor(horarios, id, nHorarios)) == -1)
					puts("Profesor no encontrado");
				else {
					modificar_horas(&horarios[encontrado]);
				}
				break;
			case 4:
				mostrar_horarios(horarios, nHorarios);
				break;
		}
		salir = salir_menu();
	}while(salir == 0);
	free(horarios);
}

void agregar_horario(horario **hor, usuario *usuarios, materia *materias, alumno *alumnos, unsigned nUsuarios, unsigned nMaterias, unsigned nAlumnos) {
	horario nuevo;
	fflush(stdin);
	puts("Introduce el id de profesor");
	scanf("%s", &nuevo.id_profesor);
	fflush(stdin);
	puts("Introduce el id de la materia");
	scanf("%s", &nuevo.id_materia);
	fflush(stdin);
	puts("Introduce el grupo");
	scanf("%s", &nuevo.grupo);
	if(encontrar_profesor(usuarios, nuevo.id_profesor,nUsuarios) == -1 || encontrar_materia(materias, nuevo.id_materia,nMaterias) == -1 || 	existe_grupo(alumnos, nAlumnos, nuevo.grupo) == 0)
		puts("No existe alguno de los datos introducidos");
	else {
		fflush(stdin);
		puts("Introduce la hora de clase");
		scanf("%s", &nuevo.hora_clase);
		fflush(stdin);
		puts("Introduce el dia de clase");
		scanf("%s", &nuevo.dia_clase);	
	}
	
}

void eliminar_horas(horario **hor) {
	unsigned horas;
	
	puts("Introduzca el numero de horas para eliminar");
	scanf("%u", &horas);
	
	if((hor->hora_clase - horas) < 1)
		puts("El numero de horas introducido excede el limite permitido, es menor a 1");
	else
		hor->hora_clase = hor->hora_clase - horas;

}

void modificar_horas(horario *hor) {
	unsigned horas;
	
	puts("Introduzca el numero de horas nuevo");
	scanf("%u", &horas);
	
	if(horas < 1 || horas > 6)
		puts("El numero de horas excede el limite permitido");
	else
		hor->hora_clase = horas;

}

void mostrar_horarios(horario *horarios, unsigned nHorarios) {
	int i;
	
	for(i = 0; i < nHorarios; i++)
		mostrar_horario(&horarios[i]);
		
}

void mostrar_horario(const horario *hor) {
	static char *nombre_dias[5] = { "Lunes", "Martes", "Miercoles", "Jueves", "Viernes" };
	static char *nombre_horas[6] = {"Primera", "Segunda", "Tercera", "Cuarta", "Quinta", "Sexta"};
	
		
	printf("Id Profesor: %s\n", hor->id_profesor);
	printf("Dia de clase: %s\n", nombre_dias[hor->dia_clase - 1]);
	printf("Hora de clase: %s\n", nombre_horas[hor->hora_clase-1]);
	printf("Id materia: %s\n", hor->id_materia);
	printf("Grupo: %s\n", hor->grupo);
}

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

int encontrar_materia(materia *materias, char *idMateria, unsigned nMaterias) {
	int i, encontrado = -1;
	
	while (i < nMateria && encontrado == -1) {
		if(strcmp(idMateria, materias.Id_materia) == 0)
			encontrado = i;
		i++;
	}
	
	return encontrado;
}
