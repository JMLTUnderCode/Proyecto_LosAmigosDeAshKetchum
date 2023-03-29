/* Archivo de extension .h encargado de verificar y extraer los datos
 * de Flags proporcionados por llamada en funcion main.c
 */

#include "unix_lib.h"
#include "macro_direct.h"

// Buffers y Constantes.
#define buf_flag 64     // Buff para la informacion de los argumentos.

// Estructura de datos para almacenar la informacion de los flahs activos
// segun la serie de argumentos datos por consola.
struct flags {
	int Region;
	char info_region[buf_flag];
	int Species;
	char info_species[buf_flag];
	int Type;
	char info_type[buf_flag];
	int Nocount;
	int List;
	int Size;
	int Name;
	char info_name[buf_flag];
};

struct flags Flags_Active;

/***********************************************************************************/
// Descripcion y definicion de funciones.

// Funcion encargada de mostrar errores de llamado al programa.
// Cuando no se ingresan los archivos o la cantidad correcta.
void ErrorArgument(int argc, char *argv[]){
	printf("Error: Number/Names of arguments is incorrent.\n");
	printf("Usage: %s ", argv[0]);
	FORE(k, 1, argc)
		printf(" %s", argv[k]);
	printf("\nCorrect: ./fameChecker [-r <region>] [-s <species>] [-t <type>] [--nocount] [--list] [--size] [name]\n");
}

// Funcion encargada de inicializar todas las estructuras globales
// en algun valor default y principalmente extraer la informacion de los
// argumentos. Retorna true en caso de flags correcto y extraccion
// exitosa, en caso contrario muestra los posibles errores.
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

/***********************************************************************************/




