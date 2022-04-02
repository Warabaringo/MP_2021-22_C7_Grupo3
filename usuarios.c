#include "usuarios.h"

int main () {
	unsigned n;
	usuario *u = leer_usuario(&n);
	
	free(u);
	return 0;
}
usuario *leer_usuarios(unsigned *nUsuarios){
    usuario *usuarios = NULL;
    usuario user;

    FILE *f = fopen("Usuarios.txt", "r");
    char linea[60], *token;
    unsigned n = 0;

    while(fgets(linea, 21, f) != NULL) {
        token = strtok(linea, "-");
        strcpy(user.Id_usuario, token);
        token = strtok(NULL, "-");
        strcpy(user.Nomb_usuario, token);
        token = strtok(NULL, "-");
        strcpy(user.Perfil_usuario, token);
        token = strtok(NULL, "-");
        strcpy(user.Usuario, token);
        token = strtok(NULL, "\n");
        strcpy(user.contrasena, token);


        n++;
        usuarios = (usuario*) realloc(usuarios, n *sizeof(usuario));
        usuarios[n-1] = user;
    }
    fclose(f);
    *nUsuarios = n;
    
    return usuarios;
}

/* void encontrar_profesor(usuario *usuarios, char *idProfesor, unsigned nUsuario){
	int encontrado = -1, i;
	
	while(i < nUsuario && encontrado == -1) {
		if(strcmp(&usuarios[i].Id_usuario, idProfesor) == 0)
			encontrado = i;
		i++;
	}
} */
