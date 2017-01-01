#ifndef _ALGORITMOSOBREMEDALLERODEPORTE__H
#define _ALGORITMOSOBREMEDALLERODEPORTE__H

#include <string>
#include "Algoritmo.h"
#include "Secuencia.h"
#include "Pareja.h"
#include "Pais.h"
#include "Medallas.h"
#include "Medallero.h"
#include "GenerarAleatorios.h"

//clase que identifica a los algoritmos que van a llamar al metodo medalleroPorDeporte, en la medici�n de tiempos, 
//sin especificar si se va a usar su version ordenada o sin ordenar
class CAlgoritmoSobreMedalleroDeporte : public CAlgoritmo {
public:
	CAlgoritmoSobreMedalleroDeporte ();
	virtual  ~CAlgoritmoSobreMedalleroDeporte ();
	virtual std::string  getDescription () = 0;
	virtual void  SetUp (int N);
	virtual void  Execute () = 0;
	virtual void  TearDown ();
protected: 
	CMedallero* _m;
	CDeporte* _deportes;
	int _numDeportes;
};

#endif