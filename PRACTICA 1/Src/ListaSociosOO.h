#ifndef __LISTASOCIOSOO_H
#define __LISTASOCIOSOO_H
#include "SocioOO.h"

class CListaSocios {
public:
	enum {MAX_SOCIOS = 150};

	//FCO
	CListaSocios ();
	CListaSocios (const CListaSocios &ls);
	CListaSocios& operator= (const CListaSocios& ls);
	~CListaSocios ();

	//FUNCIONES
	bool ponElemento (const CSocio &elto);
	bool borraElemento (int pos);
	int numElems () const;
	CSocio  dameElem (int i) const;
protected:
	int _numSocios;
	CSocio _socios [MAX_SOCIOS];
};

#endif