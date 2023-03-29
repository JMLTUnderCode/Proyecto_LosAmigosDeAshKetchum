/* Archivo de extension .h encargado de contemplar directivas y macros
 * generales usadas en mayor frecuencia.
 */

/** Directivas For. **/

// For iterador de n pasos a partir de x.
#define FOR(i, x, n) for(int i = x; i - x < n; i++)

// For iterador desde x hasta n sin incluir.
#define FORE(i, x, n) for(int i = x; i < n; i++)

// For iterador desde x hasta n incluido.
#define FORF(i, x, n) for(int i = x; i-1 < n; i++)

/** Fin Directivas **/

/********************************************************************/
/** Macros True and False **/

#ifndef TRUE
	#define TRUE (0 == 0)
#endif

#ifndef FALSE
	#define FALSE !TRUE
#endif

/** Fin Macros **/

/********************************************************************/
/** Comparadores Min y Max  **/

// Min permite comparar dos elementos y retornar el minimo segun el tipo
// de variable a juzgar.
#define min(x, y) \
	({ typeof (x) _x = (x); \
		typeof (y) _y = (y); \
		_x < _y ? _x : _y; })
// Max permite comparar dos elementos y retornar el maximo segun el tipo
// de variable a juzgar.
#define max(x,y) \
	({ typeof (x) _x = (x); \
		typeof (y) _y = (y); \
		_x > _y ? _x : _y; })

/** Fin Comparadores  **/



