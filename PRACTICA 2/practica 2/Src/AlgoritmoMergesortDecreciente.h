#ifndef __CALGORITMOMERGESORTDECRECIENTE_H
#define __CALGORITMOMERGESORTDECRECIENTE_H

#include "AlgoritmoSobreVectores.h"
#include "MetodosGeneracion.h"
#include "MetodosOrdenacion.h"

class CAlgoritmoMergesortDecreciente : public CAlgoritmoSobreVectores {
public:
	CAlgoritmoMergesortDecreciente ();
	virtual  ~CAlgoritmoMergesortDecreciente ();
	virtual std::string  getDescription ();
	virtual void  SetUp (int N);
	virtual void  Execute ();
};

#endif