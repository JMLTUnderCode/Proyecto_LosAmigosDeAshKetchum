/***********************************************************************************/
// Inclusiones de librerias C.
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/time.h>
#include <unistd.h>

/***********************************************************************************/
// Descripcion, definicion, creacion e inicializacion de variables globales.

// Directivas For.
#define FOR(i, x, n) for (int i = x; i - x < n; i++) // Itera n, desde x.
#define FORE(i, x, n) for (int i = x; i < n; i++) // Itera x a menor n.
#define FORF(i, x, n) for (int i = x; i-1 < n; i++) // Itera x a n.

// Macros True and False.
#ifndef TRUE
	#define TRUE (0 == 0)
#endif
#ifndef FALSE
	#define FALSE !TRUE
#endif

// Definicion de funcion min/max para dos valores x e y.
#define min(x, y) \
	({ typeof (x) _x = (x); \
			typeof (y) _y = (y); \
			_x < _y ? _x : _y; })
#define max(x, y) \
	({ typeof (x) _x = (x); \
			typeof (y) _y = (y); \
			_x > _y ? _x : _y; })

// Buffers y Constantes Macros.
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



// Funcion encargada de inicializar todas las estructuras globales
// en algun valor default y principalmente extraer la informacion de los
// argumentos. Retorna true en caso de flags correcto y extraccion
// exitosa, en caso contrario muestra los posibles errores.
int init_structs(int, char **);

// Funcion encargada de mostrar errores de llamado al programa.
// Cuando no se ingresan los archivos o la cantidad correcta.
void ErrorArgument(int, char **);

/***********************************************************************************/

