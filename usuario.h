#ifndef _LIB_H_
#define _LIB_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>

#define N 20

//ESTRUCTURA PARA LOS DATOS DE CADA USUARIO

typedef struct{
char	Id_usuario[4];
char 	Nomb_usuario[21];
char	Perfil_usuario[16];
char	Usuario[6];
char	Contrasena[9]; 
int     lleno;
}usuario;
//Precondición: Ninguna
//Postcondición: 
usuario *leer_usuarios(unsigned *nUsuarios);
//Precondición: Ninguna
//Postcondición:
void ver_estructura (const usuario *user, unsigned n);
//Precondición: Ninguna
//Postcondición:
void ad_usuario(usuario **user, unsigned *n);
//Precondición: Ninguna
//Postcondición:
void edit_usuario(usuario *user);
//Precondición: Ninguna
//Postcondición: 
int encontrar_profesor(usuario *usuarios, char *idProfesor, unsigned nUsuario);
//Precondición: Ninguna
//Postcondición:
int existe_usuario (usuario *user, char *s, unsigned n);
//Precondición: Ninguna
//Postcondición:
//void 
//Precondición: Ninguna
//Postcondición:
void cambio(char *);
//Precondición: Ninguna
//Postcondición:
void menu_para_administrador_de_usuarios();







#endif
