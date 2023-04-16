#include "search_inodo.h"

int directory_exits(int level, char* folder, char* goal, struct flags act_flags){
	char* temp;

	if(level == 0 && (strcmp(folder, goal) == 0 || !act_flags.Region)){
		printf("region\n");
		return TRUE;
	}else if(level == 1 && (strcmp(folder, goal) == 0 || !act_flags.Species)){
		printf("especie\n");
		return TRUE;
	}else if(level == 2 && (strcmp(folder, goal) == 0 || !act_flags.Type)){
		printf("tipo\n");
		return TRUE;
	}else if(level == 3){
		if(!act_flags.Name){
			return TRUE;
		}
		
		temp = calloc( (int)(strlen(goal)) , sizeof(char) );
		
		if(temp == NULL){
			perror("Could not allocate memory");
		}
		strncpy(temp, folder, strlen(goal));
		if(strcmp(temp, goal) == 0){
			free(temp);
			return TRUE;
		}
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

void search_directories(char* dir_name, struct flags act_flags, int level){
	DIR *directory;
	struct dirent *entry;
	struct stat status;
	int fd;
	char *goal;

	//abrimos el directorio
	directory = opendir(dir_name);
	
	//printf("reading files in %s\n", dir_name);
	
	if(directory == NULL){
		printf("Could not open directory\n");
		return;
	}

	chdir(dir_name);

	printf("reading files (1) in %s\n", dir_name);
	
	goal = calloc(64, sizeof(char));
	if(goal == NULL){
		printf("Could not allocate memory");
		return;
	}

	//leemos las entradas del directorio
	if(level == 0 && act_flags.Region){
		strcpy(goal, act_flags.info_region);
	}else if(level == 1 && act_flags.Species){
		strcpy(goal, act_flags.info_species);
	}else if(level == 2 && act_flags.Type){
		strcpy(goal, act_flags.info_type);
	}else if(act_flags.Name){
		strcpy(goal, act_flags.info_name);
	}
	
	//entry = readdir(directory);
	while( (entry = readdir(directory) ) != NULL){
		
		if(strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0 ){
			continue;
		}

		if(directory_exits(level, entry->d_name, goal, act_flags) == TRUE){
			//printf("file -> %s\n", entry->d_name);
			fd = open(entry->d_name, O_RDONLY);
			if(fd < 1){
				printf("Can't open the file: %s\n", entry->d_name);
				return;
			}else if(fstat(fd, &status) == -1){
				printf("Error: can't get the file information of: %s\n", entry->d_name);
			}

			if(S_ISDIR(status.st_mode)){
				//se deben obviar la carpeta actual y la anterior
				if(strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0 ){
					continue;
				}
				search_directories(entry->d_name, act_flags, level+1);
			}else{
				if(strstr(entry->d_name, ".html") != NULL){
					printf("file: %s\n", entry->d_name);
				}
			}
			close(fd);
		}

		//entry = readdir(directory);
	}
	free(goal);
	chdir("..");
	closedir(directory);
}

