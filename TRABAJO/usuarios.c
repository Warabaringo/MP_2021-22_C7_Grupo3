#include "usuarios.h"
//Esta liberria incluye las siguienes:
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <locale.h>
//#include <windows.h>

//Cabecera: usuario *leer_usuarios(unsigned *nUsuarios);
usuario *leer_usuarios(unsigned *nUsuarios){
	
    usuario *usuarios = NULL;
    usuario user;
	
    FILE *f = fopen("Usuarios.txt", "r");
    char aux[61], *token;
    unsigned n = 0;
	
    while(fgets(aux, 61, f) != NULL) {
        token = strtok(aux, "-");
        strcpy(user.Id_usuario, token);
        token = strtok(NULL, "-");
        strcpy(user.Nomb_usuario, token);
        token = strtok(NULL, "-");
        strcpy(user.Perfil_usuario, token);
        token = strtok(NULL, "-");
        strcpy(user.Usuario, token);
        token = strtok(NULL, "\n");
        strcpy(user.Contrasena, token);


        n++;
        usuarios = (usuario*) realloc(usuarios, n *sizeof(usuario));
        usuarios[n-1] = user;
    }
    
    fclose(f);
    
    *nUsuarios = n;
    
    return usuarios;
} 
//Cabecera: void ver_estructura (const usuario *user, unsigned n);
void ver_estructura(const usuario *user, unsigned n){
	
	int i;
	
	for(i = 0; i < n; i++){
		ver_usuario(&user[i]);
	}
}
//Cabecera: void ver_usuario()
void ver_usuario(const usuario *user){
	
	printf("Id: %s\n", user->Id_usuario);
	printf("Nombre: %s\n", user->Nomb_usuario);
	printf("Perfil: %s\n", user->Perfil_usuario);
	printf("Usuario: %s\n", user->Usuario);
	printf("Contraseña: %s\n\n", user->Contrasena);
}
//Cabecera: void ad_usuario(usuario **user, unsigned *n);
void ad_usuario(usuario **user, unsigned *n){
	usuario us;
	usuario nuevo;
	int i,p;
	char *aux;
	char id;
	char adm[]="Administrador";
	char pro[]="Profesor";
	
	i=1;
	while(!existe_alumno(*user,id,*n) && i<1000){
		if(i<10){
			itoa(id,aux,10);
			strcpy(nuevo.Id_usuario,"00");
			strcat(nuevo.Id_usuario,aux);
		}else{
			if(i<100){
				itoa(id,aux,10);
				strcpy(nuevo.Id_usuario,"0");
				strcat(nuevo.Id_usuario,aux);
			}else{
				itoa(id,aux,10);
				strcpy(nuevo.Id_usuario,aux);
			}
		}
		i++;
		
		printf("Nombre: ");
		fflush(stdin);
		fgets(nuevo.Nomb_usuario,20,stdin);
		cambio(nuevo.Nomb_usuario);
	
		do{
			printf("AVISO!!! SI SE REPITE LA PREGUNTA ES QUE HAS AÑADIDO UN DATO INVALIDO");
			system("pause");
			system("cls");
		
			printf("\nPerfil (1.-Administrador/2.-Profesor)[No puede cambiarse luego]: ");
			fflush(stdin);
			scanf("%i",&p);
			if(p==1){
				strcpy(nuevo.Perfil_usuario,adm);
			}else{
				strcpy(nuevo.Perfil_usuario,pro);
			}	
		}while(p!=1 && p!=2);
		p=0;
	
		printf("Usuario: ");
		fflush(stdin);
		fgets(nuevo.Usuario,30,stdin);
		cambio(nuevo.Usuario);
		
		printf("Contraseña: ");
		fflush(stdin);
		fgets(nuevo.Contrasena,30,stdin);
		cambio(nuevo.Contrasena);
	
		*user = realloc(*user, (*n+1) * sizeof(usuario));
		(*user)[*n] = nuevo;
		(*n)++;
	}
}
//
int  encontrar_usuario (usuario *user,unsigned n,char *id){
	
	int i = 0 , encontrado = - 1 ;
	
	while (i < n && encontrado == - 1 ){
		if ( strcmp (id,user[i].Id_usuario) == 0 )
			encontrado = i;
		i++;
	}
	return encontrado;
}
//Cabecera: void edit_usuario(usuario *user);
void edit_usuario(usuario *user){
	
	int op,p;
	
	char nombre[21],usuario[6],contrasena[9],salir;
	char adm[]="Administrador";
	char pro[]="Profesor";

	do{
		printf("AVISO!!! SI SE REPITE LA PREGUNTA ES QUE HAS AÑADIDO UN DATO INVALIDO");
		system("pause");
		system("cls");
		printf("Que dato quieres cambiar?");
		printf("\n1.- Nombre\n2.- Perfil(Administrador/Profesor)\n3.- Usuario\n4.- Contraseña\n");
		scanf("%i",&op);
	}while(op!=1 && op!=2 && op!=3 && op!=4);
	
	
	do{
		switch(op){
			case 1:
				
				printf("Introduzca el nuevo nombre: ");
				fflush(stdin);
				fgets(nombre,21,stdin);
				strcpy(user->Nomb_usuario,nombre);
				
				break;
			case 2:
				
				printf("Introduzca el nuevo perfil: ");
				do{
					printf("\nPerfil (1.-Administrador/2.-Profesor)[No puede cambiarse luego]: ");
					fflush(stdin);
					scanf("%i",&p);
					if(p==1){
						strcpy(user->Perfil_usuario,adm);
					}else{
						strcpy(user->Perfil_usuario,pro);
					}	
				}while(p!=1 && p!=2);
				p=0;
				
				break;
			case 3:
				
				printf("Introduce el nuevo usuario: ");
				fflush(stdin);
				fgets(usuario,6,stdin);
				strcpy(user->Usuario, usuario);
				
				break;
			case 4:
				
				printf("Introduce la nueva contraseña: ");
				fflush(stdin);
				fgets(contrasena,9,stdin);
				strcpy(user->Contrasena,contrasena);
				
				break;
		}
		
		do{
			printf("AVISO!!! SI SE REPITE LA PREGUNTA ES QUE HAS AÑADIDO UN DATO INVALIDO");
			system("pause");
			system("cls");
			printf("Desea salir del manu? (S)i/(N)o");
			fflush(stdin);
			scanf("%c",&salir);
		}while(salir!='s' && salir!='S' && salir!='n' && salir!='N');	
	}while(salir=='s' || salir=='S' && salir!='n' && salir!='N');
}
//Cabecera: int encontrar_profesor(usuario *usuarios, char *idProfesor, unsigned nUsuario);
int encontrar_profesor(usuario *user, char *idProfesor, unsigned nUsuario){
	
	int encontrado = -1, i = 0;
	
	while(i < nUsuario && encontrado == -1) {
		if(strcmp(user[i].Id_usuario, idProfesor) == 0)
			encontrado = i;
		i++;
	}
	
	return encontrado;
}
//Cabecera: void cambio(char *)
void cambio(char *palabra){
	
	int i;
	
	for(i=0;i<30;i++){
		if(palabra[i]=='\n'){
			palabra[i]='\0';
		}		
	}
}
//Cabecera: int existe_usuario (usuario *user, char *s, unsigned n);
int existe_usuario (usuario *user, char *s, unsigned n){
	
//	usuario user;

	int i,existe;
	
	existe=0;
	
	for(i = 0; i < n; i++) 
		if (strcmp(s, user[i].Id_usuario) == 0)
			existe = 1;
	
	return existe;
}
//Cabecera: void guardar_usuarios(const usuario *usuarios, unsigned n);
void guardar_usuarios(const usuario *usuarios, unsigned n){
	
	usuario user;
	
	FILE *f = fopen("Usuarios.txt","w");
	
	unsigned i;
	
	for(i = 0; i < n; i++){
		fprintf(f,"%s-", user.Id_usuario);
		fprintf(f,"%s-", user.Nomb_usuario);
		fprintf(f,"%s-", user.Perfil_usuario);
		fprintf(f,"%s-", user.Usuario);
		fprintf(f,"%s\n", user.Contrasena);
	}
	
	fclose(f);
}
//Cabecera: void  borrar_usuario (usuario **usuarios,unsigned *n,char *id);
void  borrar_usuario (usuario **usuarios,unsigned *n,char *id){
	
	int i, encontrado;
	
	encontrado = encontrar_usuario(*usuarios,*n,id);
	
	if(encontrado != - 1 ){
		for(i = encontrado; i < (*n)- 1 ; i++)
			(*usuarios)[i] = (*usuarios)[i+ 1 ];
		(*n)--;
		*usuarios = realloc (*usuarios, *n * sizeof (usuario));
	}
}
//FUNCIÓN DE LOS USUARIOS POR PARTE DEL ADMINISTRADOR
//void menu_para_administrador_de_usuarios();
void menu_para_administrador_de_usuarios(){

//	usuario user;
	
	unsigned n;
	
	usuario *user = leer_usuarios(&n);
	
	int op, encontrado;
	char id[4],salir;
	
	do{
		do{
			system("cls");
			printf("Introduzca la operacion deseada\n");
			printf("------------------------------\n");
			printf("1.-Añadir cuenta de usuario\n2.-Modificar cuenta de usuario\n3.-Ver lista de usuarios\n4.-Eliminar cuenta de usuario\n5.-Salir.\n");
			scanf("%i", &op);	
			
		}while(op!=1 && op!=2 && op!=3 && op!=4 && op!=5);
		
		switch(op) {
			case 1:
				
				ad_usuario(&user,&n);
				
				do{
					system("pause");
					system("cls");
					printf("Desea salir del manu? (S)i/(N)o");
					fflush(stdin);
					scanf("%c",&salir);
				}while(salir!='s' && salir!='S' && salir!='n' && salir!='N');
				
				break;
			case 2:
				
				fflush(stdin);
				printf("Pon la Id del usuario que desea editar: ");
				scanf("%s", &id);
				encontrado = encontrar_usuario(user,n,id);
				if(encontrado == -1){
					system("cls");
					printf("EL usuario introducido no se ha encontrado");
				}else{
					edit_usuario(&user[encontrado]);
				}
				
				do{
					system("pause");
					system("cls");
					printf("Desea salir del manu? (S)i/(N)o");
					fflush(stdin);
					scanf("%c",&salir);
				}while(salir!='s' && salir!='S' && salir!='n' && salir!='N');
				
				break;
			case 3:
				
				ver_estructura(user,n);
				
				do{
					system("pause");
					system("cls");
					printf("Desea salir del manu? (S)i/(N)o");
					fflush(stdin);
					scanf("%c",&salir);
				}while(salir!='s' && salir!='S' && salir!='n' && salir!='N');
				
				break;
			case 4:
				
				fflush(stdin);
				puts("Pon la Id del usuario que desea borrar");
				scanf("%s",&id);
				borrar_usuario(&user,&n,id);
				
				do{
					system("pause");
					system("cls");
					printf("Desea salir del manu? (S)i/(N)o");
					fflush(stdin);
					scanf("%c",&salir);
				}while(salir!='s' && salir!='S' && salir!='n' && salir!='N');
				
				break;
			case 5:
				
				salir=='s';
				
				break;
		}
		
	}while(salir=='s' && salir=='S' && salir!='n' && salir!='N');
	
	guardar_usuarios(user,n);
	
	free(user);
}
//Cabecera: int usuario_es_admin(char nombre[6], char contra[9]);
int usuario_es_admin(char nombre[6], char contra[9]){
	
	int i = 0, encontrado = 0, admin = -1;
	
	int *nUsuarios;
	
	usuario *usuarios = leer_usuarios(&nUsuarios);
	
	while(i < nUsuarios && encontrado == 0) {
		if(strcmp(nombre, usuarios[i].Usuario) == 0 && strcmp(contra, usuarios[i].Contrasena) == 0){
			encontrado = 1;
			if(strcmp(usuarios[i].Perfil_usuario, "administrador") == 0){
				admin = 1;
			}	
			else{
				admin = 0;
			}	
		}
		i++;
	}
	
	return admin;
}

// Fichero -> "Usuario.txt"
