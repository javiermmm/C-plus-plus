#ifndef __CALGORITMOMERGESORTALEATORIO_H
#define __CALGORITMOMERGESORTALEATORIO_H

#include "AlgoritmoSobreVectores.h"
#include "MetodosGeneracion.h"
#include "MetodosOrdenacion.h"

class CAlgoritmoMergesortAleatorio : public CAlgoritmoSobreVectores {
public:
	CAlgoritmoMergesortAleatorio ();
	virtual  ~CAlgoritmoMergesortAleatorio ();
	virtual std::string  getDescription ();
	virtual void  SetUp (int N);
	virtual void  Execute ();
};

#endif