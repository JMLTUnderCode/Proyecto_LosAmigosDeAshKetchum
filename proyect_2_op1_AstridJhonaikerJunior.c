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

#include "standard_lib.h"

int main(int argc, char *argv[]){
  // Verificacion de argumentos de entrada.
	if(argc > 1 && argc < 12){

		// Inicializacion de estructuras fundamentales y Extraccion de flags.
		if(init_structs(argc, argv) == FALSE)
			return EXIT_FAILURE;

		// CHECK ESTRUCTURA FLAGS ACTIVE
		if(Flags_Active.Region){
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
		// FIN CHECK ESTRUCTURA.
			
	} else {
		ErrorArgument(argc, argv);
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}

/******************************************************************/
/*  Definiciones y encabezados de funciones en "standard_lib.h"   */
/******************************************************************/


int init_structs(int argc, char *argv[]){
	// Inicial de todas los flags.
	Flags_Active.Region = 0;
	Flags_Active.Species = 0;
	Flags_Active.Type = 0;
	Flags_Active.Nocount = 0;
	Flags_Active.List = 0;
	Flags_Active.Size = 0;
	Flags_Active.Name = 0;
	
	// Extraccion de Flags.
	int cnt = 1;
	int exit_mode = TRUE;
	while(cnt < argc){
		if(argv[cnt][0] == '-'){
			if( strcmp(argv[cnt], "-r") == 0 ) {
				Flags_Active.Region = 1;
				cnt++;
				if(argv[cnt][0] != '-'){
					strncpy(Flags_Active.info_region, argv[cnt], 64);
				} else {
					exit_mode = FALSE;
					break;
				}

			} else if ( strcmp(argv[cnt], "-s") == 0 ) {
				Flags_Active.Species = 1;
				cnt++;
				if(argv[cnt][0] != '-'){
					strncpy(Flags_Active.info_species, argv[cnt], 64);
				} else {
					exit_mode = FALSE;
					break;
				}

			} else if ( strcmp(argv[cnt], "-t") == 0 ){
				Flags_Active.Type = 1;
				cnt++;
				if(argv[cnt][0] != '-'){
					strncpy(Flags_Active.info_type, argv[cnt], 64);
				} else {
					exit_mode = FALSE;
					break;
				}
			} else if ( strcmp(argv[cnt], "--nocount") == 0 ) {
				Flags_Active.Nocount = 1;

			} else if ( strcmp(argv[cnt], "--list") == 0 ){
				Flags_Active.List = 1;

			} else if ( strcmp(argv[cnt], "--size") == 0 ) {
				Flags_Active.Size = 1;

			} else {
				exit_mode = FALSE;
				break;
			}
		
		} else if ( Flags_Active.Name == 0 ) {
			Flags_Active.Name = 1;
			strncpy(Flags_Active.info_name, argv[cnt], 64);
			
		} else {
			exit_mode = FALSE;
			break;
		}
		cnt++;
	}
	if(exit_mode){
		return TRUE;
	} else {
		ErrorArgument(argc, argv);
		return FALSE;
	}
}

void ErrorArgument(int argc, char *argv[]){
	printf("Error: Number/Names of arguments is incorrent.\n");
	printf("Usage: %s ", argv[0]);
	FORE(k, 1, argc)
		printf(" %s", argv[k]);
	printf("\nCorrect: ./fameChecker [-r <region>] [-s <species>] [-t <type>] [--nocount] [--list] [--size] [name]\n");
}
