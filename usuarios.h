#ifndef USUARIOS_H
#define USUARIOS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
	char Id_usuario[4];
	char Nomb_usuario[21];
	char *Perfil_usuario;
	char Usuario[6];
	char contrasena[9];
	int lleno;
} usuario;
usuario *leer_usuarios(unsigned *nUsuarios);

#endif /* USUARIOS_H */
