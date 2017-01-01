#ifndef __CALGORITMOQUICKSORTALEATORIO_H
#define __CALGORITMOQUICKSORTALEATORIO_H

#include "AlgoritmoSobreVectores.h"
#include "MetodosGeneracion.h"
#include "MetodosOrdenacion.h"

class CAlgoritmoQuicksortAleatorio : public CAlgoritmoSobreVectores {
public:
	CAlgoritmoQuicksortAleatorio ();
	virtual  ~CAlgoritmoQuicksortAleatorio ();
	virtual std::string  getDescription ();
	virtual void  SetUp (int N);
	virtual void  Execute ();
};

#endif