#ifndef __CALGORITMOBURBUJADECRECIENTE_H
#define __CALGORITMOBURBUJADECRECIENTE_H

#include "AlgoritmoSobreVectores.h"
#include "MetodosGeneracion.h"
#include "MetodosOrdenacion.h"

class CAlgoritmoBurbujaDecreciente : public CAlgoritmoSobreVectores {
public:
	CAlgoritmoBurbujaDecreciente ();
	virtual  ~CAlgoritmoBurbujaDecreciente ();
	virtual std::string  getDescription ();
	virtual void  SetUp (int N);
	virtual void  Execute ();
};

#endif