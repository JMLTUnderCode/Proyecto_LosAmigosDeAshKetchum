#include "standard_lib.h"
#include "readExtractFlags.h"

/***** funciones *****/

int directory_exists(int, char*, char*, struct flags);

//funcion encargada de navegar por los directorios.
void search_directories(char*, struct flags, int);

//funcion para hacer los calculos de los flag --list, --size, --noncount y [name].
