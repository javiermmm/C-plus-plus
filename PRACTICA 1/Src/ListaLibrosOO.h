#ifndef __LISTALIBROSOO_H
#define __LISTALIBROSOO_H

#include "LibroOO.h"


class CListaLibros {
public:
	enum {MAX_LIBROS = 50};

	//FCO
	CListaLibros ();
	CListaLibros (const CListaLibros& lb);
	CListaLibros& operator= (const CListaLibros& lb);
	~CListaLibros ();

	//FUNCIONES
	bool ponElemento (const CLibro &elto);
	bool borraElemento (int pos);
	int numElems () const;
	CLibro dameElem (int i) const;
protected:
	int _numLibros;
	CLibro _libros [MAX_LIBROS]; 
};

#endif