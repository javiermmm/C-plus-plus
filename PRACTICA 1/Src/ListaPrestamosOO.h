#ifndef __LISTAPRESTAMOSOO_H
#define __LISTAPRESTAMOSOO_H

#include "PrestamoOO.h"

class CListaPrestamos {
public:
	enum {MAX_PRESTAMOS = 10};

	//FCO
	CListaPrestamos ();
	CListaPrestamos (const CListaPrestamos& lb);
	CListaPrestamos& operator= (const CListaPrestamos& lb);
	~CListaPrestamos ();

	//FUNCIONES
	bool ponElemento (const CInfoPrestamo &elto);
	bool borraElemento (int pos);
	int numElems () const;
	CInfoPrestamo dameElem (int i) const;
protected:
	int _numPrestamos;
	CInfoPrestamo _prestamos [MAX_PRESTAMOS];
};

#endif