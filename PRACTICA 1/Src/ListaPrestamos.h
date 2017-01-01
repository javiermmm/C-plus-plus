#ifndef __LISTAPRESTAMOS_H
#define __LISTAPRESTAMOS_H

#include "Prestamo.h"

#define MAX_PRESTAMOS 50

struct TListaPrestamos {
	int numPrestamos;
	TInfoPrestamo prestamos [MAX_PRESTAMOS];
};

//FUNCIONES
void inicializaLista (TListaPrestamos &lista);
bool ponElemento (TListaPrestamos &lista, const TInfoPrestamo &elto);
bool borraElemento (TListaPrestamos &lista, int pos);
int numElems (const TListaPrestamos &lista);
TInfoPrestamo dameElem (const TListaPrestamos &lista, int i);



#endif