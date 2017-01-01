#ifndef __CALGORITMOINSERCIONCRECIENTE_H
#define __CALGORITMOINSERCIONCRECIENTE_H

#include "AlgoritmoSobreVectores.h"
#include "MetodosGeneracion.h"
#include "MetodosOrdenacion.h"

class CAlgoritmoInsercionCreciente : public CAlgoritmoSobreVectores {
public:
	CAlgoritmoInsercionCreciente ();
	virtual  ~CAlgoritmoInsercionCreciente ();
	virtual std::string  getDescription ();
	virtual void  SetUp (int N);
	virtual void  Execute ();
};

#endif