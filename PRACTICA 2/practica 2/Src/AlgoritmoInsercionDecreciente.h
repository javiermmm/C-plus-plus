#ifndef __CALGORITMOINSERCIONDECRECIENTE_H
#define __CALGORITMOINSERCIONDECRECIENTE_H

#include "AlgoritmoSobreVectores.h"
#include "MetodosGeneracion.h"
#include "MetodosOrdenacion.h"

class CAlgoritmoInsercionDecreciente : public CAlgoritmoSobreVectores {
public:
	CAlgoritmoInsercionDecreciente ();
	virtual  ~CAlgoritmoInsercionDecreciente ();
	virtual std::string  getDescription ();
	virtual void  SetUp (int N);
	virtual void  Execute ();
};

#endif