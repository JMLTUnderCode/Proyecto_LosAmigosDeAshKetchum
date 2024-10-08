#include "standard_lib.h"
#include "readExtractFlags.h"

/***** Funciones *****/
// Funcion que determina si es posible seguir realizando la busqueda de archivos, bien sea
// por encontrar coincidencia de nombres o si es posible seguir navegando por los directorios.
int directory_exists(int, char*, char*, struct flags);

// Funcion encargada de navegar por los directorios y filtrar archivos.
void search_directories(char*, struct flags, int, int*, long int*);

// Funcion para hacer los calculos e impresion de los flag --list, --size, --noncount.
void print_info_file(char*, struct flags, long int); 
