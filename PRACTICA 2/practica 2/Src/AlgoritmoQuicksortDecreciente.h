#ifndef __CALGORITMOQUICKSORTDECRECIENTE_H
#define __CALGORITMOQUICKSORTDECRECIENTE_H

#include "AlgoritmoSobreVectores.h"
#include "MetodosGeneracion.h"
#include "MetodosOrdenacion.h"

class CAlgoritmoQuicksortDecreciente : public CAlgoritmoSobreVectores {
public:
	CAlgoritmoQuicksortDecreciente ();
	virtual  ~CAlgoritmoQuicksortDecreciente ();
	virtual std::string  getDescription ();
	virtual void  SetUp (int N);
	virtual void  Execute ();
};

#endif