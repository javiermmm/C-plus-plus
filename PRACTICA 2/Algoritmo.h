#ifndef __CALGORITMO_H
#define __CALGORITMO_H

#include <string>

//Clase para representar a los algoritmos.
//Es una clase abstracta con todos sus m�todos virtuales puros, de manera
//que se utiliza a modo de interfaz.
class CAlgoritmo {
public:
	//Constructor
	CAlgoritmo () {}

	//Destructor
	virtual  ~CAlgoritmo () {}

	//Funci�n que devuelve la descripcion del algoritmo
	virtual std::string  getDescription ()=0 {}

	//Funci�n que inicializa el algoritmo, rellenando los vectores
	virtual void  SetUp (int N)=0 {}

	//Funci�n que ejecuta el algoritmo
	virtual void  Execute ()=0 {}

	//Funci�n que borra los recursos usados
	virtual void  TearDown ()=0 {}
};



#endif