#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Materias.h"
//cabecera: void daraltaasig (materia *vMaterias, int *n)
//precondicion:estrucutura inicializada
//postcondicion: poder dar de alta materias

void daraltasig(materia **vMaterias,int *nMaterias){
    *vMaterias=realloc((materia *)(*vMaterias),((*nMaterias)+1)*sizeof(materia));

    printf("\nIntroduzca el ID de la materia:  ");
    scanf("%4s",(*vMaterias)[*nMaterias].Id_materia);

    printf("\n Introduzca el nombre de la materia: ");
    scanf("%50s",(*vMaterias)[*nMaterias].Nombre_materia);

    printf("\n Introduzca la abreviatura de la materia: ");
     scanf("%3s",(*vMaterias)[*nMaterias].Abrev_materia);
    (*nMaterias)++;

}

//cabecera: void darbajaasig(materia *vMaterias, int *n);
//precondicion: estrucutura
//postcondicion: poder dar de baja una materia

void darbajaasig(materia **vMaterias, int *nMaterias){

    int i;
    int p;
    char resp=' ';
    char Id_materia[4];

    printf("DAR DE BAJA ASIGNATURA");

    printf("Introduzca el id de la materia a dar de baja: ");
    scanf("%4s",Id_materia);
    if( nMaterias == 0){
        printf("No tienes materias\n");
    }else{
        for(i=0;i<(*nMaterias);i++){
            if(strcmp((*vMaterias)[i].Id_materia,Id_materia)==0){
                p=i;
            }
        }
        while(resp!='s' && resp!='n'){
            printf("Se va a eliminar la siguiente materia: %s-%s-%s\n",(*vMaterias)[p].Id_materia,(*vMaterias)[p].Nombre_materia,(*vMaterias)[p].Abrev_materia);
            printf("Confirmar dar de baja materia? (s/n)\n");
            fflush(stdin);
            scanf("%c",&resp);
        }
        if(resp=='s'){
            for(i=p;i+1<(*nMaterias);i++){
            	strcpy((*vMaterias)[i].Id_materia,(*vMaterias)[i+1].Id_materia);
                strcpy((*vMaterias)[i].Nombre_materia,(*vMaterias)[i+1].Nombre_materia);
                strcpy((*vMaterias)[i].Abrev_materia,(*vMaterias)[i+1].Abrev_materia);
            }
            (*nMaterias)--;
            *vMaterias=realloc((materia *)(*vMaterias),(*nMaterias)*sizeof(materia));
        }else{
            printf("Se ha cancelado la dada de baja\n");
        }
    }
}

void modificarMateria(materia **vMaterias,int nMaterias){

    int i;
    int u=-1;
    char resp=' ';
    char Id_materia[4];
    int nModMaterias=0;
    materia *modMaterias;

    modMaterias=malloc(sizeof(materia));

    printf("\nMODIFICAR MATERIA\n");
    while(u==-1){
        printf("\nIntroduzca el ID de la materia a modificar: \n");
        scanf("%4s",Id_materia);
        printf("\n");

        for(i=0;i<nMaterias;i++){
            if(strcmp((*vMaterias)[i].Id_materia,Id_materia)==0){
                u=i;
            }
        }

        if(u==-1){
            printf("\nLa materia no existe, introduzca una materia existente.\n");

        }
	else{
            printf("\nInformacion Materia: %s-%s-%s\n", (*vMaterias)[u].Id_materia, (*vMaterias)[u].Nombre_materia, (*vMaterias)[u].Abrev_materia);

            printf("Introduzca la nueva informacion siguiendo el modelo: \n(ID MATERIA-NOMBRE-ABREVIACION)\n");

            daraltasig(&modMaterias,&nModMaterias);

            while(resp!='s' && resp!='n'){
                printf("?Modificar la materia? Responda (s/n) \n");
                fflush(stdin);
                scanf("%c",&resp);
            }

            if(resp=='s'){
                (*vMaterias)[u]=modMaterias[0];
            }
		else{
                printf("\nModificaci?n cancelada.\n");
            }
        }
    }
}


//cabecera: void listarasig(materia *vMaterias, int nMaterias);
//precondi: estructura materias inicializada
//postcondicon: listar las materias del fichero

void listarMaterias(materia *vMaterias,int nMaterias){

int i;

printf("\nMATERIAS\n");
printf("ID MATERIA-NOMBRE-ABREVIATURA\n");

for(i=0;i<nMaterias;i++){
printf("%s%s%s\n",vMaterias[i].Id_materia,vMaterias[i].Nombre_materia,vMaterias[i].Abrev_materia);
}
}


materia *leer_materia(unsigned *nMaterias) {
	materia *materias = NULL;
	materia a;
	FILE *f = fopen("Materias.txt", "r");
	char linea[127], *token;
	unsigned n = 0;
	
	while(fgets(linea, 127, f) != NULL) {
		token = strtok(linea, "-");
		strcpy(a.Id_materia, token);
		token = strtok(NULL, "-");
		strcpy(a.Nombre_materia, token);
		token = strtok(NULL, "-");
		strcpy(a.Abrev_materia, token);
		token = strtok(NULL, "\n");
			
		n++;
		materias = (materia*)realloc(materias, n * sizeof(materia));
		materias[n-1] = a;
	}
	
	fclose(f);
	*nMaterias = n;
	return materias;
}

