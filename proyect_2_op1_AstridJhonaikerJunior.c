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
	if(argc > 1 && argc < 12){
		char path[PATH_MAX];

		// Inicializacion y verificacion de exito de estructuras fundamentales
		// y Extraccion de flags.
		struct flags Flags_Active = init_structs(argc, argv);
		if(Flags_Active.EXIT_MODE){ 
			ErrorArgument(argc, argv);
			return EXIT_FAILURE;
		}

		// CHECK ESTRUCTURA FLAGS ACTIVE
		/*if(Flags_Active.Region){
			printf("\nRegion: %s", Flags_Active.info_region);
		}
		if(Flags_Active.Species){
			printf("\nSpecie: %s", Flags_Active.info_species);
		}
		if(Flags_Active.Type){
			printf("\nType: %s", Flags_Active.info_type);
		}
		if(Flags_Active.Nocount){
			printf("\nNocount: ACTIVE");
		} else {
			printf("\nNocount: INACTIVE");
		}
		if(Flags_Active.List){
			printf("\nList: ACTIVE");
		} else {
			printf("\nList: INACTIVE");
		}
		if(Flags_Active.Size){
			printf("\nSize: ACTIVE");
		} else {
			printf("\nSize: INACTIVE");
		}
		if(Flags_Active.Name){
			printf("\nName: %s", Flags_Active.info_name);
		}
		printf("\n");
		*/
		// FIN CHECK ESTRUCTURA.
		if(getcwd(path, sizeof(path)) == NULL){
			perror("Error getting the current path");
			return EXIT_FAILURE;
		}

		search_directories(path, Flags_Active, 0);
			
	} else {
		ErrorArgument(argc, argv);
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
