#ifndef _ALGORITMOSOBRECLASIFICACION__H
#define _ALGORITMOSOBRECLASIFICACION__H

#include <string>
#include "Algoritmo.h"
#include "Secuencia.h"
#include "Pareja.h"
#include "Pais.h"
#include "Medallas.h"
#include "GenerarAleatorios.h"

//clase que identifica los algoritmos que van a probar en la medición de tiempos, el método clasificación,
//sin llegar a concretar el tipo de prueba en aleatorio, primero o ultimo.
template <class TMedallero>
class CAlgoritmoSobreClasificacion : public CAlgoritmo {
public:
	CAlgoritmoSobreClasificacion () {}

	virtual ~CAlgoritmoSobreClasificacion () {}

	virtual std::string  getDescription () = 0;

	virtual void  SetUp (int N) {

		_m = new TMedallero();
		_numPaises = N;
		_paises = new CPais [_numPaises];
		CPrueba prueba = CPrueba ("tituloPrueba", CDeporte("nombreDeporte"));
		for (int i=0; i<_numPaises; ++i) {
			_paises[i] = paisAleatorio();
			CSecuencia<CAtleta> clasif = CSecuencia<CAtleta>();
			clasif.inserta(CAtleta ("Atleta_1", _paises[i]));
			clasif.inserta(CAtleta ("Atleta_2", _paises[i]));
			clasif.inserta(CAtleta ("Atleta_3", _paises[i]));
			_m->clasificacion(prueba, clasif);
		}
	}

	virtual void  Execute () = 0;

	virtual void  TearDown () {

		delete _m;
		delete [] _paises;
	}
protected: 
	TMedallero* _m;
	CPais* _paises;
	int _numPaises;
};


#endif