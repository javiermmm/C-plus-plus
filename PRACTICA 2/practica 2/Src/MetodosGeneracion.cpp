#include "MetodosGeneracion.h"
#include <stdlib.h>


void  generarCreciente (int v[], int num) {

	for (int i = 0; i < num; i++)
		v[i] = i;

}

void  generarDecreciente (int v[], int num) {

	int j = num-1;
	for (int i = 0; i < num; i++) {
		v[i] = j;
		--j;
	}
}
 
void  generarAleatorio (int v[], int num) {

	for (int i = 0; i < num; i++)
		v[i] = rand ();

}
