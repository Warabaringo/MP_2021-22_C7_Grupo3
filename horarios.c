#include "horarios.h"

void menu_admin_horarios() {
	unsigned nHorarios;
	int op, encontrado, salir;
	char id[4];
	horario *horarios = leer_horarios(&nHorarios);
	
	puts("Introduzca la operacion deseada: agregar horas de clase(1), eliminar horas(2), modificar horas(3), listar horarios(4), salir(0)");
	scanf("%i", &op);
	do{
		switch(op){
			case 1:
				puts("Introduce id de profesor");
				scanf("%s", &id);
				if((encontrado = encontrar_profesor(horarios, id, nHorarios)) == -1)
					puts("Profesor no encontrado");
				else 
					agregar_horas(&horarios[encontrado]);
				
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
}

int encontrar_profesor(horario *horarios, char *idProfesor, unsigned nHorarios) {
	int i = 0, encontrado = -1;
	
	while(encontrado == -1 && i < nHorarios) {
		if(strcmp(horarios[i].id_profesor, idProfesor) == 0)
			encontrado = i;
		i++;
	}
	
	return encontrado;
}

void agregar_horas(horario *hor) {
	unsigned horas;
	
	puts("Introduzca el numero de horas para agregar");
	scanf("%u", &horas);
	
	if((horas+hor->hora_clase) > 6)
		puts("El numero de horas introducido excede el limite permitido, es mayor a 6");
	else
		hor->hora_clase = hor->hora_clase + horas;
	
}

void eliminar_horas(horario *hor) {
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
	static char *nombre_dias[5] = { "Lunes", "Martes", "Miércoles", "Jueves", "Viernes" };
	static char *nombre_horas[6] = {"Primera", "Segunda", "Tercera", "Cuarta", "Quinta", "Sexta"};
	
		
	printf("Id Profesor: %s\n", hor->id_profesor);
	printf("Dia de clase: %i\n", nombre_dias[hor->dia_clase - 1]);
	printf("Hora de clase: %i\n", nombre_horas[hor->hora_clase-1]);
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
        horarios = (horario*) realloc(horarios, n *sizeof(horarios));
        horarios[n-1] = hor;
    }
    fclose(f);
    *nHorarios = n;
    
    return horarios;
}
