#ifndef __CALGORITMOSELECCIONALEATORIO_H
#define __CALGORITMOSELECCIONALEATORIO_H

#include "AlgoritmoSobreVectores.h"
#include "MetodosGeneracion.h"
#include "MetodosOrdenacion.h"

class CAlgoritmoSeleccionAleatorio : public CAlgoritmoSobreVectores {
public:
	CAlgoritmoSeleccionAleatorio ();
	virtual  ~CAlgoritmoSeleccionAleatorio ();
	virtual std::string  getDescription ();
	virtual void  SetUp (int N);
	virtual void  Execute ();
};

#endif