#ifndef __CALGORITMOBURBUJAALEATORIO_H
#define __CALGORITMOBURBUJAALEATORIO_H

#include "AlgoritmoSobreVectores.h"
#include "MetodosGeneracion.h"
#include "MetodosOrdenacion.h"

class CAlgoritmoBurbujaAleatorio : public CAlgoritmoSobreVectores {
public:
	CAlgoritmoBurbujaAleatorio ();
	virtual  ~CAlgoritmoBurbujaAleatorio ();
	virtual std::string  getDescription ();
	virtual void  SetUp (int N);
	virtual void  Execute ();
};

#endif