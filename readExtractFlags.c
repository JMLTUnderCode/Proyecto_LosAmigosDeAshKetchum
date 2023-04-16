#include "readExtractFlags.h"

void ErrorArgument(int argc, char *argv[]){
	printf("Error: Number/Names of arguments is incorrent.\n");
	printf("Usage: %s ", argv[0]);
	FORE(k, 1, argc)
		printf(" %s", argv[k]);
	printf("\nCorrect: ./fameChecker [-r <region>] [-s <species>] [-t <type>] [-c | --nocount] [-l | --list] [-sz | --size] [name]\n\n");
	printf("    -r: Indica que debe limitarse la busqueda por region.\n");
	printf("        El nombre de la region debe llevar la misma grafia\n");
	printf("        que el directorio que la contiene.\n\n");
	printf("    -s: Indica la especie:\n");
	printf("        > \"pokemon\": para indicar que se debe contar solamente\n");
	printf("                     los archivos HTML en lso directorios de\n");
	printf("                     pokemones que correspondan con los criterios\n");
	printf("                     de busqueda.\n");
	printf("        > \"trainer\": para indicar que se debe contar solamente\n");
	printf("                     los humanos.\n\n");
	printf("    -t: Indica el tipo de apariciones:\n");
	printf("        > \"main\":       Para los personajes principales.\n");
	printf("        > \"recurring\":  Para los personajes recurrentes.\n");
	printf("        > \"gym_leader\": Para los lideres de gimnasio.\n");
	printf("        > \"one_time\":   Para los personajes que aparecen solo una vez.\n\n");
	printf("    -c o --nocount: Indica si debe aparecer el numero de archivos\n");
	printf("                    encontrados.(Por defecto, se muestra.)\n");
	printf("                    Si el flag esta presente, no se debe mostrar.\n\n");
	printf("    -l o --list: Indica si se deben dar los nombres de los archivos\n");
	printf("                 encontrados. (Por defecto, no se muestran.)\n\n");
	printf("    -sz o --size: Indica si se debe mostrar el tamaño en kilobytes\n");
	printf("                  (1024 bytes) de los archivos. (Por defecto, no\n");
	printf("                  se muestra.) Si esta incluido este flag, se muestra\n");
	printf("                  a cada archivo encontrado su tamaño.\n\n");
	printf("    [name]: Permite restringir la busqueda a archivos que comiencen\n");
	printf("            con el nombre dado.\n\n");
}

struct flags init_structs(int argc, char *argv[]){
	// Inicial de todas los flags.
	struct flags Flags_Active;
	Flags_Active.Region = FALSE;
	Flags_Active.Species = FALSE;
	Flags_Active.Type = FALSE;
	Flags_Active.Nocount = FALSE;
	Flags_Active.List = FALSE;
	Flags_Active.Size = FALSE;
	Flags_Active.Name = FALSE;
	Flags_Active.EXIT_MODE = FALSE;
	
	// Extraccion de Flags.
	int cnt = 1;
	while(cnt < argc){
		if(argv[cnt][0] == '-'){
			if( strcmp(argv[cnt], "-r") == 0 ) {
				Flags_Active.Region = TRUE;
				cnt++;
				if(argv[cnt][0] != '-'){
					strncpy(Flags_Active.info_region, argv[cnt], 64);
				} else {
					Flags_Active.EXIT_MODE = TRUE;
					break;
				}

			} else if ( strcmp(argv[cnt], "-s") == 0 ) {
				Flags_Active.Species = TRUE;
				cnt++;
				if(argv[cnt][0] != '-'){
					strncpy(Flags_Active.info_species, argv[cnt], 64);				
			} else {
					Flags_Active.EXIT_MODE = TRUE;
					break;
				}

			} else if ( strcmp(argv[cnt], "-t") == 0 ){
				Flags_Active.Type = TRUE;
				cnt++;
				if(argv[cnt][0] != '-'){
					strncpy(Flags_Active.info_type, argv[cnt], 64);
				} else {
					Flags_Active.EXIT_MODE = TRUE;
					break;
				}
			} else if ( strcmp(argv[cnt], "--nocount") == 0 || strcmp(argv[cnt], "-c") == 0 ) {
				Flags_Active.Nocount = TRUE;

			} else if ( strcmp(argv[cnt], "--list") == 0 || strcmp(argv[cnt], "-l") == 0 ){
				Flags_Active.List = TRUE;

			} else if ( strcmp(argv[cnt], "--size") == 0 || strcmp(argv[cnt], "-sz") == 0 ) {
				Flags_Active.Size = TRUE;

			} else {
				Flags_Active.EXIT_MODE = TRUE;
				break;
			}
		
		} else if ( Flags_Active.Name == 0 ) {
			Flags_Active.Name = TRUE;
			strncpy(Flags_Active.info_name, argv[cnt], 64);
			
		} else {
			Flags_Active.EXIT_MODE = TRUE;
			break;
		}
		cnt++;
	}

	return Flags_Active;
}
