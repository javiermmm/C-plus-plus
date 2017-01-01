#ifndef __LISTALIBROS_H
#define __LISTALIBROS_H

#include "Libro.h"

#define MAX_LIBROS 50

struct TListaLibros {
	int numElems;
	TLibro libros [MAX_LIBROS]; 
};

//FUNCIONES
void inicializaLista (TListaLibros &lista);
bool ponElemento (TListaLibros &lista, const TLibro &elto);
bool borraElemento (TListaLibros &lista, int pos);
int numElems (const TListaLibros &lista);
TLibro dameElem (const TListaLibros &lista, int i);

#endif