#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
char	Id[3];
char 	Nombre[20];
char	Perfil[15];
char	Usuario[5];
char	Contrasena[8]; 
int     lleno;
}usuario;

usuario a[5];

void ad_usuario();
void fichero();
void v(char *);
void ver_usuario();
void buscar();
void vacio();
void cambio(char *);

int main() {
	
	vacio();
	
	fichero(); 	
	system("pause");
	system("cls");
	//ad_usuario();
	//system("pause");
	//system("cls");
	ver_usuario();
	system("pause");
	//buscar();
	
	system("pause");
	return 0;
}

void ad_usuario(){
	int i,add,p;
	char aux[]="00";
	char aux2[]="0";
	char aux3[3];
	char adm[]="Administrador";
	char pro[]="Profesor";
	for(i=0;i<1;i++){
		if(a[i].lleno==0){
			if(i>99){
				itoa(i+1,aux,10);
				strcpy(a[i].Id,aux);
			}else{
				if(i>9){
					itoa(i+1,aux3,10);
					strcat(aux3,aux2);
					strcpy(a[i].Id,aux3);	
				}else{
					itoa(i+1,aux3,10);
					strcat(aux3,aux);
					strcpy(a[i].Id,aux3);
				}
			}
			
			printf("\n");
			printf("Nombre: ");
			fflush(stdin);
			fgets(a[i].Nombre,20,stdin);
			cambio(a[i].Nombre);
			printf("\n");
			do{
				printf("Perfil (1.-Administrador/2.-Profesor): ");
				fflush(stdin);
				scanf("%i",&p);
				if(p==1){
					strcpy(a[i].Perfil,adm);
				}else{
					strcpy(a[i].Perfil,pro);
				}	
			}while(p!=1 && p!=2);
			printf("\n");
			printf("Usuario: ");
			fflush(stdin);
			fgets(a[i].Usuario,5,stdin);
			cambio(a[i].Usuario);
			printf("\n");
			printf("Contrasena: ");
			fflush(stdin);
			fgets(a[i].Contrasena,8,stdin);		
			cambio(a[i].Contrasena);
			a[i].lleno=1;	
		}
	}
	
	
}

void fichero(){
	int i,j;
	char aux[20];
	char token;
	FILE *f;

	f=fopen("hola.txt","r");
	if(f==NULL){
		printf("no se ha podido abrir el archivo");
		exit(1);
	}

	for(i=0;!feof(f);i++){
		v(aux);
		token='\0';
		for(j=0;token=='-';j++){
			token=fgetc(f);
			aux[j]=token;
		}
		strcpy(a[i].Id,aux);
		
		for(j=0;token=='-';j++){
			token=fgetc(f);
			aux[j]=token;
		}
		strcpy(a[i].Nombre,aux);
		
		for(j=0;token=='-';j++){
			token=fgetc(f);
			aux[j]=token;
		}
		strcpy(a[i].Perfil,aux);
		
		for(j=0;token=='-';j++){
			token=fgetc(f);
			aux[j]=token;
		}
		strcpy(a[i].Usuario,aux);
		
		for(j=0;token=='\n';j++){
			token=fgetc(f);
			aux[j]=token;
		}
		strcpy(a[i].Contrasena,aux);
		
		a[i].lleno=1;
	}
		
}

void v(char v[]){
	int i;
	
	for(i=0;i<20;i++){
		v[i]='\0';
	}
}

void ver_usuario(){
	int i;
	for(i=0;i<5;i++){
		if(a[i].lleno==1){
			printf("Id: %s -Nombre: %s -Perfil: %s -Usuario: %s -Contrasena: %s\n",a[i].Id,a[i].Nombre,a[i].Perfil,a[i].Usuario,a[i].Contrasena);
			printf("\n");
		}	
	}
}
//
void buscar(){
	
	int i,op;
	char aux[20], aux2[20];;
	printf("usuario: ");
	fflush(stdin);
	fgets(aux,5,stdin);
	cambio(aux);
	
	contra:
	
	printf("\ncontrasena: ");
	fflush(stdin);
	fgets(aux2,8,stdin);
	cambio(aux2);
	
	for(i=0;i<3;i++){
		if(strcmp(aux,a[i].Usuario)==0){
			
			if(strcmp(aux2,a[i].Contrasena)==0){
			
				system("cls");
				printf("Usuario encontrado\n");
				system("pause");
				system("cls");
				printf("Bienbenido");
				system("pause");
				break;
			
			}else{
				
				system("cls");
				printf("Contrasena incorrecta");
				system("pause");
				system("cls");
				printf("Desea introducir la constrasena de nuevo?");
				printf("\n1.-Si");
				printf("\n2.-No");
				scanf("%i",&op);
			
				if(op==1){
					system("cls");
					goto contra;				
				}else{
					exit(1);
				}
			}
		}else{
			system("cls");
			printf("Usuario no encontrado");
			exit(1);
		}	
	}
}

void vacio(){
	int i;
	
	for(i=0;i<5;i++){
		a[i].lleno=0;	
	}
}

void cambio(char palabra[20]){
	int i;
	for(i=0;i<20;i++){
		if(palabra[i]=='\n'){
			palabra[i]=='\0';
		}
	}
}







