#ifndef __PRESTAMOOO_H
#define __PRESTAMOOO_H

#include "FechaOO.h"
#include "ListaLibrosOO.h"

class CInfoPrestamo {
public:
	//FCO
	CInfoPrestamo (CFecha f = CFecha());
	CInfoPrestamo (int numRegistro, CFecha f);
	CInfoPrestamo (const CInfoPrestamo& p);
	CInfoPrestamo& operator= (const CInfoPrestamo& p);
	~CInfoPrestamo();

	//ACCEDENTES
	int dameNumRegistro() const;
	CFecha dameFecha() const;

	//MUTADORES
	void ponNumRegistro (int num);
	void ponFecha (CFecha f);

	//FUNCIONES
	bool libroPrestado (const CListaLibros &libros, CLibro &infoLibroPrestado) const;
protected:
	int _numRegistro;
	CFecha _fechaDev;
};

#endif 