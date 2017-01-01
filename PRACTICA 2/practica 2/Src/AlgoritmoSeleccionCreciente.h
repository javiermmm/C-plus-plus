#ifndef __CALGORITMOSELECCIONCRECIENTE_H
#define __CALGORITMOSELECCIONCRECIENTE_H

#include "AlgoritmoSobreVectores.h"
#include "MetodosGeneracion.h"
#include "MetodosOrdenacion.h"

class CAlgoritmoSeleccionCreciente : public CAlgoritmoSobreVectores {
public:
	CAlgoritmoSeleccionCreciente ();
	virtual  ~CAlgoritmoSeleccionCreciente ();
	virtual std::string  getDescription ();
	virtual void  SetUp (int N);
	virtual void  Execute ();
};

#endif