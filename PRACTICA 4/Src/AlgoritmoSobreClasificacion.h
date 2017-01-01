#ifndef _ALGORITMOSOBRECLASIFICACION__H
#define _ALGORITMOSOBRECLASIFICACION__H

#include <string>
#include "Algoritmo.h"
#include "Secuencia.h"
#include "Pareja.h"
#include "Pais.h"
#include "Medallas.h"
#include "Medallero.h"
#include "GenerarAleatorios.h"

//clase que identifica los algoritmos que van a probar en la medición de tiempos, el método clasificación,
//sin llegar a concretar el tipo de prueba en aleatorio, primero o ultimo.
class CAlgoritmoSobreClasificacion : public CAlgoritmo {
public:
	CAlgoritmoSobreClasificacion ();
	virtual ~CAlgoritmoSobreClasificacion ();
	virtual std::string  getDescription () = 0;
	virtual void  SetUp (int N);
	virtual void  Execute () = 0;
	virtual void  TearDown ();
protected: 
	CMedallero* _m;
	CPais* _paises;
	int _numPaises;
};


#endif