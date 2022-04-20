#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alumnos.h"
#include "materias.h"
#include "matricula.h"

void matriculas(){


	unsigned n;
	unsigned m;
	alumno *a = leer_alumnos(&m);
    matricula *b =leer_matricula(&n);
	int encontrado;
	char id[7];
	char idmat[5];
	char s;
	int elec;

	seleccionarid:
	system("cls");
	printf("Selecciona la id del alumno con el que quieres trabajar:");
	scanf("%s", &id);
	encontrado = encontrar_alumno(a, n, id);
	if(encontrado == -1){
		puts("Alumno no encontrado");
		do{
			printf("Quieres intentarlo de nuevo: \nSí[s]\nNo[n].\n");
			fflush(stdin);
        	scanf("%c", &s);
        	if(s=='n' || s== 'N'){
        		menu_admin_alumno();
        		break;
			}
			if(s=='s' || s== 'S'){
        		goto seleccionarid;
        		break;
			}
		}while(s!='n' || s!= 'N' || s!='s' || s!= 'S');
	}
	eleccion:
	system("cls");
	printf("Que deseas hacer:\n\n");
	printf("  1.-Listar matriculas\n  2.-Dar de baja una maticula\n  3.-Dar de alta una maticula\n  4.-Modificar una matricula\n  5.-Volver al menu\n\n(Para escoger entre una de las opciones escriba el numero junto a la opcion que desea)\n\n");
	fflush(stdin);
    scanf("%d",&elec);
    switch(elec){
    	case 1:
    		mostrar_matricula(n);
    	case 2:
            fflush(stdin);
			puts("Introduce la id de la materia para eliminar");
			scanf("%s", &idmat);
			encontrado=encontrar_materia(b,n,idmat);
			if(encontrado == -1){
                puts("Materia no encontrada");
			}
			else{
                eliminar_matricula(&b,&n, idmat);
			}
			break;
    	case 3:
            agregar_matricula(&b,&n,id);
			break;
    	case 4:
            modificar_matricula(&b);
    	default:
    		goto eleccion;
	}
	guardar_matriculas(b,m);

}

void mostrar_matriculas (const matricula *b, unsigned m){
	int i;
	for(i = 0; i < m; i++)
		mostrar_matricula (&b[i]);
}

void mostrar_matricula (const matricula *b) {
	printf("ID ALUMNO: %s\n", b->Id_alumno);
	printf("ID MATERIA: %s\n", b->Id_materia);
	puts("-----------------------------");
}


void eliminar_matricula(matricula **matricula, unsigned *m,char *idmat) {
	int i, encontrado;

	encontrado = encontrar_matricula(*matricula,*m,idmat);
	if(encontrado != -1) {
		for (i = matricula; i < (*m)-1; i++)
			(*matricula)[i] = (*matricula)[i+1];
		(*m)--;
		*matricula = realloc(*matricula, *m * sizeof(matricula));
	}
}

int encontrar_matricula(matricula *b, unsigned m, char *id) {
	int i = 0, encontrado = -1;
	while(i < m && encontrado == -1){
		if(strcmp(id,b[i].Id_alumno) == 0)
			encontrado = i;
		i++;
	}
	return encontrado;
}



void agregar_matricula(matricula **b, unsigned *n,char id) {
	matricula nuevo;
	char idmat[5];

	fflush(stdin);
	puts("Introduzca la id de la materia que quieras añadir");
	fgets(idmat,5,stdin);

    strcpy(nuevo.Id_materia,idmat);
    quitar_salto(nuevo.Id_materia);

    strcpy(nuevo.Id_alumno,id);
    quitar_salto(nuevo.Id_alumno);

    *b = realloc(*b, (*n+1) * sizeof(matricula));
    (*b)[*n] = nuevo;
    (*n)++;
	}

matricula *leer_matricula(unsigned *nMatricula) {
	matricula *matriculas = NULL;
	matricula a;
	FILE *f = fopen("Matriculas.txt", "r");
	char linea[15], *token;
	unsigned n = 0;

	while(fgets(linea, 15, f) != NULL) {
		token = strtok(linea, "-");
		strcpy(a.Id_materia, token);
		token = strtok(NULL, "\n");
		strcpy(a.Id_alumno, token);

		n++;
		matriculas = (matricula*)realloc(matriculas, n * sizeof(matricula));
		matriculas[n-1] = a;
	}

	fclose(f);
	*nMatricula = n;
	return matriculas;
}

void modificar_matricula(matricula *a,unsigned *n){
	char idmat[5];

	int encontrado;

    puts("Introduzca el id de la materia que quieras cambiar");
    fgets(idmat,5, stdin);
    encontrado=encontrar_matricula(a,n,idmat);
    if(encontrado==-1){
            printf("Matricula no encontrada");

    }
    else{
        puts("Introduzca el id de la materia a la que quieras cambiar");
        fgets(idmat,5, stdin);
        encontrado=encontrar_matricula(a,n,idmat);
        if(encontrado==-1){
            printf("Matricula no encontrada");

        }
        else{
            strcpy(a->Id_materia, idmat);
        }

    }


}

void guardar_matriculas(const matricula *matriculas, unsigned n) {
	FILE *f = fopen("Matriculas.txt","w");
	unsigned i;
	for(i = 0; i < n; i++)
		guardar_matricula(&matriculas[i], f);
	fclose(f);
}

void guardar_matricula (const matricula *b, FILE *f) {

	fprintf(f,"%s-", b->Id_materia);
	fprintf(f,"%s\n", b->Id_alumno);

}
