// Libreria estandar .h que incluye librerias basicas y fundamentales
// para el lenguaje C. Esta libreria se encarga de definir directivas, 
// macros, definiciones de funciones basicas usadas recurrentemente en C.

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

