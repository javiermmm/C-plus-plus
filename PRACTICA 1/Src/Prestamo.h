#ifndef __PRESTAMO_H
#define __PRESTAMO_H

#include "Fecha.h"
#include "ListaLibros.h"

struct TInfoPrestamo {
	int numRegistro;
	TFecha fechaDev;
};

//FUNCIONES
void inicializaPrestamo (TInfoPrestamo &p);
void inicializaPrestamo (TInfoPrestamo &p, int numRegistro, const TFecha &f);
bool libroPrestado (const TInfoPrestamo &p, const TListaLibros &libros, TLibro &infoLibroPrestado);

#endif 