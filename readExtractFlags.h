/* Archivo de extension .h encargado de verificar y extraer los datos
 * de Flags proporcionados por llamada en programa main.c
 */

#include "standard_lib.h"

#ifndef readExtractFlags_H
#define readExtractFlags_H

// Buffers y Constantes Macros.
#define buf_flag 64     // Buff para la informacion de los argumentos.

// Estructura de datos para almacenar la informacion de los flahs activos
// segun la serie de argumentos dados por consola.
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
	int EXIT_MODE;
};

/***********************************************************************************/
// Descripcion y definicion de funciones.

// Funcion encargada de mostrar errores de llamado al programa.
// Cuando no se ingresan los archivos o la cantidad correcta.
void ErrorArgument(int, char**);

// Funcion encargada de inicializar todas las estructuras globales
// en algun valor default y principalmente extraer la informacion de los
// argumentos. Retorna la estructura principal de FLAGS con los valores 
// extraidos por consola.
struct flags init_structs(int, char**);

#endif
/***********************************************************************************/




