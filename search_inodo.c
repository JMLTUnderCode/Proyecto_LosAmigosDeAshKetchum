#include "search_inodo.h"

/*Esto muestra el nombre de los archivos en caso de que en la consola se haya pedido listarlos,
dependiendo de si se pidio el tamaño de los archivos o no se mostrara el tamaño de estos en kilobytes*/
void print_info_file(char *file, struct flags act_flags, long int size){
	if (act_flags.List){
		if (!act_flags.Size){
			printf("%s\n", file);
		}
		else{
			printf("%s | size: %ldKb\n", file, size);
		}
	}
}

/*Funcion que dice si el directorio existe o no*/
int directory_exits(int level, char *folder, char *goal, struct flags act_flags) {
	char *temp;
	// Si el primer archivo es un folder con el nombre del objetivo o si no se pidio filtrar por region regresa true
	if (level == 0 && (strcmp(folder, goal) == 0 || !act_flags.Region)){
		return TRUE;
	}
	// Si el segundo archivo es un folder con el nombre del objetivo o si no se pidio filtrar por especie regresa true
	else if (level == 1 && (strcmp(folder, goal) == 0 || !act_flags.Species)){
		return TRUE;
	}
	// Si el tercer archivo es un folder con el nombre del objetivo o si no se pidio filtrar por tipo de personaje regresa true
	else if (level == 2 && (strcmp(folder, goal) == 0 || !act_flags.Type)){
		return TRUE;
	}
	// Caso en el que se busca el cuarto archivo
	else if (level == 3){
		// Si no se tiene un nombre para filtrar regresar true
		if (!act_flags.Name){
			return TRUE;
		}
		// Crear variable vacia
		temp = calloc((int)(strlen(goal)), sizeof(char));

		// Si temp es NULL ocurrio un error y no se puede asignar memoria
		if (temp == NULL){
			perror("Could not allocate memory");
		}
		// Copiar nombre del folder actual en temp
		strncpy(temp, folder, strlen(goal));

		// Revisar si nombre de temp es igual al del folder buscado
		if (strcmp(temp, goal) == 0){
			free(temp);
			return TRUE;
		}
		// Liberar espacio en memoria de temp
		free(temp);
	}

	return FALSE;
}

/*Función que permite navegar por todos los archivos y directorios de un archivo.
 *Argumentos:
 *	dir_name: nombre del directorio a buscar.
 *		  dir_name = "." indica que se buscará iniciando desde la carpeta actual.
 *
 *	act_flags: flags activas al momento de usar el programa. Condicionan la búsqueda.
 */

void search_directories(char *dir_name, struct flags act_flags, int level, int *count, long int *total_size)
{
	DIR *directory;
	struct dirent *entry;
	struct stat status;
	int fd;
	char *goal;

	// abrimos el directorio
	directory = opendir(dir_name);

	if (directory == NULL){
		printf("Could not open directory\n");
		return;
	}

	chdir(dir_name);

	goal = calloc(64, sizeof(char));
	if (goal == NULL){
		printf("Could not allocate memory");
		return;
	}

	// leemos las entradas del directorio
	if (level == 0 && act_flags.Region){
		strcpy(goal, act_flags.info_region);
	}
	else if (level == 1 && act_flags.Species){
		strcpy(goal, act_flags.info_species);
	}
	else if (level == 2 && act_flags.Type){
		strcpy(goal, act_flags.info_type);
	}
	else if (act_flags.Name){
		strcpy(goal, act_flags.info_name);
	}

	while ((entry = readdir(directory)) != NULL){
		// Obviar carpeta actual y anterior
		if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0){
			continue;
		}
		// Revisar si el directorio existe
		if (directory_exits(level, entry->d_name, goal, act_flags) == TRUE){
			fd = open(entry->d_name, O_RDONLY);
			// Caso donde archivo no puede abrirse
			if (fd < 1){
				printf("Can't open the file: %s\n", entry->d_name);
				return;
			}
			// Caso donde no puede leerse la informacion del archivo
			else if (fstat(fd, &status) == -1){
				printf("Error: can't get the file information of: %s\n", entry->d_name);
			}

			if (S_ISDIR(status.st_mode)){
				// se deben obviar la carpeta actual y la anterior
				if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0){
					continue;
				}
				// Llamar funcion recursivamente con el siguiente nivel
				search_directories(entry->d_name, act_flags, level + 1, count, total_size);
			}
			else{
				if (strstr(entry->d_name, ".html") != NULL){
					// Mostrar data del archivo actual
					print_info_file(entry->d_name, act_flags, status.st_size / 1024);
					// Aumentar en 1 la cantidad de archivos
					*(count) += 1;
					// Aumentar tamaño total de los archivos
					*(total_size) += (status.st_size / 1024);
				}
			}
			close(fd);
		}
	}
	free(goal);
	chdir("..");
	closedir(directory);
}
