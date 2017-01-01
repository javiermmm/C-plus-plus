#ifndef _ALGORITMOSOBREMEDALLERO__H
#define _ALGORITMOSOBREMEDALLERO__H

#include <string>
#include "Algoritmo.h"
#include "Secuencia.h"
#include "Pareja.h"
#include "Pais.h"
#include "Medallas.h"
#include "Medallero.h"
#include "GenerarAleatorios.h"

//clase que identifica a los algoritmos que van a llamar al metodo medallero, en la medición de tiempos, 
//sin especificar si se va a usar su version ordenada o sin ordenar
class CAlgoritmoSobreMedallero : public CAlgoritmo {
public:
	CAlgoritmoSobreMedallero ();
	virtual  ~CAlgoritmoSobreMedallero ();
	virtual std::string  getDescription () = 0;
	virtual void  SetUp (int N);
	virtual void  Execute () = 0;
	virtual void  TearDown ();
protected: 
	CMedallero* _m;
};

#endif