#ifndef __CALGORITMOSOBREVECTORES_H
#define __CALGORITMOSOBREVECTORES_H

#include <string>
#include "Algoritmo.h"

class CAlgoritmoSobreVectores : public CAlgoritmo {
public:
	CAlgoritmoSobreVectores ();
	virtual  ~CAlgoritmoSobreVectores ();
	virtual std::string  getDescription ()=0 {}
	virtual void  SetUp (int N)=0 {}
	virtual void  Execute ()=0 {}
	virtual void  TearDown ();
protected:
	int *_v;
	int *_valoresIniciales;
	int _tam;
};



#endif