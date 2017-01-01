#ifndef __CALGORITMO_H
#define __CALGORITMO_H

#include <string>

//Clase abstracta que actúa de interfaz para los algoritmos que vamos a medir (medallero, medalleroPorDeporte y clasificacion)
//Esta clase es igual que la utilizada en la práctica 2
class CAlgoritmo {
public:
	CAlgoritmo () {}
	virtual  ~CAlgoritmo () {}
	virtual std::string  getDescription ()=0 {}
	virtual void  SetUp (int N)=0 {}
	virtual void  Execute ()=0 {}
	virtual void  TearDown ()=0 {}
};



#endif