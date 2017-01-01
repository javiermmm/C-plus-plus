#include "MetodosGeneracion.h"
#include <stdlib.h>

//Este m�todo rellena un vector de enteros con n�meros en orden creciente
//v[] [IN]: puntero al vector que se rellena
//num [IN]: Longitud m�xima del vector
void  generarCreciente (int v[], int num) {

	for (int i = 0; i < num; i++)
		v[i] = i;

}

//Este m�todo rellena un vector de enteros con n�meros en orden decreciente
//v[] [IN]: puntero al vector que se rellena
//num [IN]: Longitud m�xima del vector
void  generarDecreciente (int v[], int num) {

	int j = num-1;
	for (int i = 0; i < num; i++) {
		v[i] = j;
		--j;
	}
}

//Este m�todo rellena un vector de enteros con n�meros en orden aleatorio
//v[] [IN]: puntero al vector que se rellena
//num [IN]: Longitud m�xima del vector
void  generarAleatorio (int v[], int num) {

	for (int i = 0; i < num; i++)
		v[i] = rand ();

}
