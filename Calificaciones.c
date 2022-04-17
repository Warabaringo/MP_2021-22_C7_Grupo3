#include "Calificaciones.h"

void anadirCalif(char *Id_alum,calificacion **vCalificaciones, int *nCalificaciones,int *nCalifAlumno){

*vCalificaciones=realloc((calificacion *)(*vCalificaciones),((*nCalificaciones)+1)*sizeof(calificacion));

    printf("\nANADIR CALIFICACION\n");

    printf("\nIntroduzca la fecha en este formato (DD/MM/AA):  ");
    scanf("%8s",(*vCalificaciones)[*nCalificaciones].Fecha_calif);

    printf("\n Introduzca la descripcion de la calificacion(30 caracteres max.): ");
    scanf("%30s",(*vCalificaciones)[*nCalificaciones].Descrip_calif);

    printf("\n Introduzca el ID de la materia(4 digitos max.): ");
    scanf("%4s",(*vCalificaciones)[*nCalificaciones].Id_materia);

    printf("\n Introduzca el ID del alumno(3 digitos max.): ");
    scanf("%3s",(*vCalificaciones)[*nCalificaciones].Id_alum);

    printf("\n Introduzca la calificación del alumno(del 0 al 10): ");
    scanf("%d",&(*vCalificaciones)[*nCalificaciones].Valor_calif);

    (*nCalificaciones)++;
    (*nCalifAlumno);
}

void listarCalif(char *Id_alum, calificacion*vCalificaciones, int nCalificaciones, int nCalifAlumnos){
	int i;
    if( nCalifAlumnos == 0){
        printf("\nNo hay calificaciones.\n");
	}
	else{
        for(i=0;i<nCalificaciones;i++){
            printf("\n %s-%s-%s-%s-%d\n",vCalificaciones[i].Fecha_calif,vCalificaciones[i].Descrip_calif,vCalificaciones[i].Id_materia,vCalificaciones[i].Id_alum,vCalificaciones[i].Valor_calif);
        }
	}
}

void eliminarCalif(char *Id_alum, calificacion **vCalificaciones, int *nCalificaciones, int *nCalifAlumnos){
    int p, i;
    char resp=' ';
	char Descrip_calif[30];
	char Id_materia[4];
	
	printf("\nIntroduzca el ID de la materia: ");
	scanf("%4s", Id_materia);
	printf("\nIntroduzca la descripción de la calificación: ");
	scanf("%30s", Descrip_calif);

    if( nCalifAlumnos == 0){
        printf("\nNo hay calificaciones.\n");
    }
    else{
        for(i=0;i<(*nCalificaciones);i++){
            if(strcmp((*vCalificaciones)[i].Id_materia,Id_materia)&&strcmp((*vCalificaciones)[i].Descrip_calif,Descrip_calif)==0){
                p=i;
            }
        }

        while(resp!='s' && resp!='n'){
            printf("\nSe eliminara la calificacion %s-%s-%s-%s-%d\n",(*vCalificaciones)[p].Fecha_calif,(*vCalificaciones)[p].Descrip_calif,(*vCalificaciones)[p].Id_materia,(*vCalificaciones)[p].Id_alum,(*vCalificaciones)[p].Valor_calif);
            printf("¿Esta seguro de eliminar la calificacion? Responda con (s/n)\n");
            fflush(stdin);
            scanf("%c",&resp);
        }

        if(resp=='s'){
            for(i=p;i+1<(*nCalificaciones);i++){
                strcpy((*vCalificaciones)[i].Fecha_calif,(*vCalificaciones)[i+1].Fecha_calif);
                strcpy((*vCalificaciones)[i].Descrip_calif,(*vCalificaciones)[i+1].Descrip_calif);
                strcpy((*vCalificaciones)[i].Id_materia,(*vCalificaciones)[i+1].Id_materia);
                strcpy((*vCalificaciones)[i].Id_alum,(*vCalificaciones)[i+1].Id_alum);
                (*vCalificaciones)[i].Valor_calif=(*vCalificaciones)[i+1].Valor_calif;
            }

            (*nCalificaciones)--;
            (*nCalifAlumnos)--;

            *vCalificaciones=realloc((calificacion *)(*vCalificaciones),(*nCalificaciones)*sizeof(calificacion));
        }
        else{
            printf("\nLa eliminacion de la calificacion ha sido cancelada\n");
        }
    }
}

void modifCalif(char *Id_alum, calificacion **vCalificaciones,int nCalificaciones, int nCalifAlumnos){

    int i;
    int u=-1;
    char resp=' ';
    char Id_materia[4];
    char Descrip_calif[30];
    int nModCalificacion=0;
    calificacion *ModCalificacion;

    ModCalificacion=malloc(sizeof(calificacion));
    
    printf("\nMODIFICAR CALIFICACION\n");
    while(u==-1){
        printf("\nIntroduzca el ID de la materia: \n");
        scanf("%4s", Id_materia);
        printf("\nIntroduzca la descripción de la calificación: \n");
        scanf("%30s", Descrip_calif);
        printf("\n");

        for(i=0;i<nCalificaciones;i++){
            if(strcmp((*vCalificaciones)[i].Id_materia,Id_materia)&&strcmp((*vCalificaciones)[i].Descrip_calif,Descrip_calif)==0){
                u=i;
            }
        }

        if(u==-1){
            printf("\nLa calificacion no existe.\n");

        }
	else{
            printf("\n Informacion Calificacion: %s-%s-%s-%s-%d\n",(*vCalificaciones)[i].Fecha_calif,(*vCalificaciones)[i].Descrip_calif,(*vCalificaciones)[i].Id_materia,(*vCalificaciones)[i].Id_alum,(*vCalificaciones)[i].Valor_calif);

            printf("Introduzca la nueva informacion siguiendo el modelo: \n(FECHA-DESCRIPCION-ID MATERIA-ID ALUMNO-VALOR)\n");

            anadirCalif(Id_alum, &ModCalificacion, &nModCalificacion, &nCalifAlumnos);

            while(resp!='s' && resp!='n'){
                printf("¿Modificar la calificacion? Responda (s/n) \n");
                fflush(stdin);
                scanf("%c",&resp);
            }

            if(resp=='s'){
                (*vCalificaciones)[u]=ModCalificacion[0];
            }
		else{
                printf("\nModificación cancelada.\n");
            }
        }
    }
}

