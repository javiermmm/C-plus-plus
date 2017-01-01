#include "MetodosGeneracion.h"
#include <stdlib.h>

//Este método rellena un vector de enteros con números en orden creciente
//v[] [IN]: puntero al vector que se rellena
//num [IN]: Longitud máxima del vector
void  generarCreciente (int v[], int num) {

	for (int i = 0; i < num; i++)
		v[i] = i;

}

//Este método rellena un vector de enteros con números en orden decreciente
//v[] [IN]: puntero al vector que se rellena
//num [IN]: Longitud máxima del vector
void  generarDecreciente (int v[], int num) {

	int j = num-1;
	for (int i = 0; i < num; i++) {
		v[i] = j;
		--j;
	}
}

//Este método rellena un vector de enteros con números en orden aleatorio
//v[] [IN]: puntero al vector que se rellena
//num [IN]: Longitud máxima del vector
void  generarAleatorio (int v[], int num) {

	for (int i = 0; i < num; i++)
		v[i] = rand ();

}
