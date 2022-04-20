#ifndef _USUARIOS_H_
#define _USUARIOS_H_

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
}usuario;

//Precondici�n: Ninguna
//Postcondici�n: 
usuario *leer_usuarios(unsigned *nUsuarios);
//Precondici�n: Ninguna
//Postcondici�n:
void ver_estructura (const usuario *user, unsigned n);
//Precondici�n: Ninguna
//Postcondici�n:
void ver_usuario(const usuario *user);
//Precondici�n: Ninguna
//Postcondici�n:
void ad_usuario(usuario **user, unsigned *n);
//Precondici�n: Ninguna
//Postcondici�n:
void guardar_usuarios(const usuario *usuarios, unsigned n);
//Precondici�n: Ninguna
//Postcondici�n:
void  borrar_usuario (usuario **usuarios,unsigned *n,char *id);
//Precondici�n: Ninguna
//Postcondici�n:
void edit_usuario(usuario *user);
//Precondici�n: Ninguna
//Postcondici�n: 
int encontrar_profesor(usuario *usuarios, char *idProfesor, unsigned nUsuario);
//Precondici�n: Ninguna
//Postcondici�n:
int existe_usuario (usuario *user, char *s, unsigned n);
//Precondici�n: Ninguna
//Postcondici�n:
void cambio(char *);
//Precondici�n: Ninguna
//Postcondici�n:
void menu_para_administrador_de_usuarios();
//Precondici�n: 
//Postcondici�n: 
int usuario_es_admin(char nombre[6], char contra[9]);
#endif