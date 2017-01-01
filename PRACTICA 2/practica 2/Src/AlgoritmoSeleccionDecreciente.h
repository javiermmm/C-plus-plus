#ifndef __CALGORITMOSELECCIONDECRECIENTE_H
#define __CALGORITMOSELECCIONDECRECIENTE_H

#include "AlgoritmoSobreVectores.h"
#include "MetodosGeneracion.h"
#include "MetodosOrdenacion.h"

class CAlgoritmoSeleccionDecreciente : public CAlgoritmoSobreVectores {
public:
	CAlgoritmoSeleccionDecreciente ();
	virtual  ~CAlgoritmoSeleccionDecreciente ();
	virtual std::string  getDescription ();
	virtual void  SetUp (int N);
	virtual void  Execute ();
};

#endif