#ifndef __CALGORITMOBURBUJACRECIENTE_H
#define __CALGORITMOBURBUJACRECIENTE_H

#include "AlgoritmoSobreVectores.h"
#include "MetodosGeneracion.h"
#include "MetodosOrdenacion.h"

class CAlgoritmoBurbujaCreciente : public CAlgoritmoSobreVectores {
public:
	CAlgoritmoBurbujaCreciente ();
	virtual  ~CAlgoritmoBurbujaCreciente ();
	virtual std::string  getDescription ();
	virtual void  SetUp (int N);
	virtual void  Execute ();
};

#endif