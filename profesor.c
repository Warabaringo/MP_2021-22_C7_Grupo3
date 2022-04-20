#include "profesor.h"
#include "alumnos.h"
#include "horarios.h"
#include "Calificaciones.h"
//Esta liberria incluye las siguienes:
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <locale.h>
//#include <windows.h>
//

//Cabecera: void menu_profesor();
void menu_profesor(){

	unsigned n;

	alumno *a;
	horario *horarios;
	//calificacion *vCalificaciones;
	
	int op, encontrado, existe, opa, cal, *nCalificaciones, *nCalifAlumnos;
	char id[4],salir,aux,grup;
	
	do{
		do{
			printf("AVISO!!! SI SE REPITE LA PREGUNTA ES QUE HAS AÑADIDO UN DATO INVALIDO");
			system("pause");
			system("cls");
			printf("A que grupo desea acceder?\n");
			mostrar_horarios(horarios,n);
			scanf("%s",&grup);
			existe = existe_grupo(a,n,grup);
		
		}while(existe==-1);
		
		do{
			
			printf("(Para seleccionar al alumno con el que va a interactuar ponga su Id)");
			
			encontrado = encontrar_alumno(a,n,id);
		
			if(encontrado != -1) {
				
				do{
					printf("AVISO!!! SI SE REPITE LA PREGUNTA ES QUE HAS AÑADIDO UN DATO INVALIDO");
					system("pause");
					system("cls");
					printf("Que desea hacer con el alumno?\n1.-Ficha del alumno\n2.-Calificaciones del alumno\n3.-Volver\n");
					scanf("%i",&opa);
				}while(opa!=1 && opa!=2 && opa!=3);
			}	
			
			switch(opa){
				case 1:
					
		//			mostrar_alumno (&a[i]);
					
					break;
				case 2:
					do{
						printf("AVISO!!! SI SE REPITE LA PREGUNTA ES QUE HAS AÑADIDO UN DATO INVALIDO");
						system("pause");
						system("cls");
						printf("Que desea hacer con las calificaciones?\n1.-Modificar una existente\n2.-Borrar una existente\n3.-Añadir una nueva\n");
						scanf("%i",&cal);	
					}while(cal!=1 && cal!=2 && cal!=3);
					
					switch(cal){
						case 1:
							
			//				modifCalif(a,vCalificaciones, nCalificaciones, nCalifAlumnos);
							
							break;
						case 2:
							
			//				eliminarCalif();
							
							break;
						case 3:
								
			//				anadirCalif();
							
							break;
					}
					
					break;
				case 3:
					
					printf("Volviendo atrás en el menu...");
					system("pause");
					system("cls");
					break;
			}
		}while(encontrado==-1 || aux!='s' || aux!='S');
		
					
	}while(salir!='s' && salir!='S' && salir!='n' && salir!='N');

}
