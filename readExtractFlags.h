/* Archivo de extension .h encargado de verificar y extraer los datos
 * de Flags proporcionados por llamada en programa main.
 */

#include "standard_lib.h"

#ifndef readExtractFlags_H
#define readExtractFlags_H

// Buffers y Constantes Macros.
#define buf_flag 64 // Buff para la informacion de los argumentos.

// Estructura de datos para almacenar la informacion de los flahs activos
// segun la serie de argumentos dados por consola.
struct flags{
	int Region;                  // Si la busqueda debe limitarse por region.
	char info_region[buf_flag];  // La region a buscar.
	int Species;                 // Si la busqueda debe limitarse por especie.
	char info_species[buf_flag]; // La especia a buscar.
	int Type;                    // Si la busqueda debe limitarse por tipo de personaje.
	char info_type[buf_flag];    // El tipo se personaje a buscar.
	int Nocount;                 // Si el numero de archivos no debe aparecer.
	int List;                    // Si debe mostarse el numero de archivos.
	int Size;                    // Si debe mostrarse el tamaño en kilobytes de los archivos.
	int Name;                    // Si la busqueda de un archivo se restringira por nombre.
	char info_name[buf_flag];    // El nombre con el que se restringira la busqueda de los archivos.
	int EXIT_MODE;				       // Si hay un error y el programa debe cerrarse.
};

/***********************************************************************************/
// Descripcion y definicion de funciones.

// Funcion encargada de mostrar errores de llamado al programa.
// Cuando no se ingresan los archivos o la cantidad correcta.
void ErrorArgument(int, char **);

// Funcion encargada de inicializar todas las estructuras globales
// en algun valor default y principalmente extraer la informacion de los
// argumentos. Retorna la estructura principal de FLAGS con los valores
// extraidos por consola.
struct flags init_structs(int, char **);

#endif
/***********************************************************************************/
