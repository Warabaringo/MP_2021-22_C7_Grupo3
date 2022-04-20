#include "usuarios.h"
#include "profesor.h"
#include "horarios.h"
#include "Calificaciones.h"
#include "alumnos.h"
#include "Materias.h"
#include "matricula.h"
//Estas liber�as incluyen las siguienes:
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <locale.h>
//#include <windows.h>

int main() {
	
		// Establecer el idioma a espa�ol
    	setlocale(LC_ALL, "spanish"); // Cambiar locale - Suficiente para m�quinas Linux
    	SetConsoleCP(1252); // Cambiar STDIN -  Para m�quinas Windows
    	SetConsoleOutputCP(1252); // Cambiar STDOUT - Para m�quinas Windows	

		char nombre[6], contra[9];
	
	printf("     	   BINENVENIDO\n----------------------------------\n----------------------------------\n\n");

	do{
		fflush(stdin);
		puts("Introduce el nombre de usuario");
		fgets(nombre, 6, stdin);
		fflush(stdin);
		puts("Introduce la contrasena de usuario");
		fgets(contra, 9, stdin);
	}while(usuario_es_admin(nombre, contra) == -1);
	
	if(usuario_es_admin(nombre, contra) == 0){
		menu_administrador();
	}else{
		menu_profesor();	
	}

	system("pause");
	return 0;
}












