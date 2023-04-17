/*                 Universidad Simon Bolivar
 * Departamento de Computacion y Tecnologia de la Informacion
 *             CI-3825: Sistemas de Operacion I
 *                Prof. Fernando Torre Mora
 *
 *           -> PROYECTO 2 ENERO - MARZO 2023  <-
 *                Los amigos de Ash Ketchum
 * Estudiantes:
 * Astrid Alvarado  18-10938
 * Jhonaiker Blanco 18-10784
 * Junior Lara      17-10303
 *
 * PD:
 *
 *
 */

#include "readExtractFlags.h"
#include "search_inodo.h"

int main(int argc, char *argv[]){
	// Verificacion de argumentos de entrada.
	if (argc > 1 && argc < 12){
		long int total_size = 0;
		int count = 0;
		char path[PATH_MAX];

		// Inicializacion y verificacion de exito de estructuras fundamentales
		// y Extraccion de flags.
		struct flags Flags_Active = init_structs(argc, argv);
		if (Flags_Active.EXIT_MODE){
			ErrorArgument(argc, argv);
			return EXIT_FAILURE;
		}

		// FIN CHECK ESTRUCTURA.
		if (getcwd(path, sizeof(path)) == NULL){
			perror("Error getting the current path");
			return EXIT_FAILURE;
		}

		// Funcion encargada de navegar por directorios y filtrar archivos
		search_directories(path, Flags_Active, 0, &count, &total_size);

		printf("\n");
		// Si se pide contar los archivos mostrar la cantidad
		if (!Flags_Active.Nocount){
			printf("Total files found: %d\n", count);
		}

		// Si se pide no contar los archivos y hay 0 archivos mostrar mensaje de error
		if (Flags_Active.Nocount && count == 0){
			printf("Not file found \n\n");
		}

		// Si se puede mostrar el tamaño de los archivos pero no se pide listarlo mostrar el tamaño total
		if (Flags_Active.Size && !Flags_Active.List){
			printf("Total amount of information found: %ldKb\n", total_size);
		}
	}
	else{
		ErrorArgument(argc, argv);
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
