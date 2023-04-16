#include "standard_lib.h"
#include "readExtractFlags.h"

/***** funciones *****/
//funcion que determina si es posible seguir realizando la busqueda de archivos, bien sea
//por encontrar coincidencia de nombres o si es posible seguir navegando por los directorios
int directory_exists(int, char*, char*, struct flags);

//funcion encargada de navegar por los directorios y filtrar archivos..
void search_directories(char*, struct flags, int, int*, long int*);

//funcion para hacer los calculos e impresion de los flag --list, --size, --noncount.
void print_info_file(char*, struct flags, long int); 
