#ifndef __LISTASOCIOS_H
#define __LISTASOCIOS_H
#include "Socio.h"

#define MAX_SOCIOS 150
struct TListaSocios {
	int numSocios;
	TSocio socios [MAX_SOCIOS];
};

//FUNCIONES
void inicializaLista (TListaSocios &lista);
bool ponElemento (TListaSocios &lista, const TSocio &elto);
bool borraElemento (TListaSocios &lista, int pos);
int numElems (const TListaSocios &lista);
TSocio  dameElem (const TListaSocios &lista, int i);


#endif