#ifndef __CALGORITMOINSERCIONALEATORIO_H
#define __CALGORITMOINSERCIONALEATORIO_H

#include "AlgoritmoSobreVectores.h"
#include "MetodosGeneracion.h"
#include "MetodosOrdenacion.h"

class CAlgoritmoInsercionAleatorio : public CAlgoritmoSobreVectores {
public:
	CAlgoritmoInsercionAleatorio ();
	virtual  ~CAlgoritmoInsercionAleatorio ();
	virtual std::string  getDescription ();
	virtual void  SetUp (int N);
	virtual void  Execute ();
};

#endif