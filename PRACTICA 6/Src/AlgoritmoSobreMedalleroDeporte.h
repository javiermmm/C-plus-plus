#ifndef _ALGORITMOSOBREMEDALLERODEPORTE__H
#define _ALGORITMOSOBREMEDALLERODEPORTE__H

#include <string>
#include "Algoritmo.h"
#include "Secuencia.h"
#include "Pareja.h"
#include "Pais.h"
#include "Medallas.h"
#include "GenerarAleatorios.h"

//clase que identifica a los algoritmos que van a llamar al metodo medalleroPorDeporte, en la medición de tiempos, 
//sin especificar si se va a usar su version ordenada o sin ordenar
template <class TMedallero>
class CAlgoritmoSobreMedalleroDeporte : public CAlgoritmo {
public:
	CAlgoritmoSobreMedalleroDeporte () {}

	virtual  ~CAlgoritmoSobreMedalleroDeporte () {}

	virtual std::string  getDescription () = 0;

	virtual void  SetUp (int N) {

		_m = new TMedallero();
		_numDeportes = N;
		CPais pA = CPais ("Pais_A");
		CPais pB = CPais ("Pais_B");
		CPais pC = CPais ("Pais_C");
		CSecuencia<CAtleta> clasif;
		_deportes = new CDeporte [_numDeportes];

		for (int i=0; i < N; ++i) {
			_deportes[i] = deporteAleatorio();
			CPrueba prueba = CPrueba ("tituloPrueba", _deportes[i]);

			int numRamdom = rand();
			if ((numRamdom % 3) == 0)
				clasif.inserta(CAtleta ("atleta1", pA));
			if ((numRamdom % 3) == 1)
				clasif.inserta(CAtleta ("atleta2", pB));
			if ((numRamdom % 3) == 2)
				clasif.inserta(CAtleta ("atleta3", pC));

			numRamdom = rand();
			if ((numRamdom % 3) == 0)
				clasif.inserta(CAtleta ("atleta1", pA));
			if ((numRamdom % 3) == 1)
				clasif.inserta(CAtleta ("atleta2", pB));
			if ((numRamdom % 3) == 2)
				clasif.inserta(CAtleta ("atleta3", pC));

			numRamdom = rand();
			if ((numRamdom % 3) == 0)
				clasif.inserta(CAtleta ("atleta1", pA));
			if ((numRamdom % 3) == 1)
				clasif.inserta(CAtleta ("atleta2", pB));
			if ((numRamdom % 3) == 2)
				clasif.inserta(CAtleta ("atleta3", pC));

			_m->clasificacion (prueba, clasif);
		}

	}

	virtual void  Execute () = 0;

	virtual void  TearDown () {

		delete _m;
		delete []_deportes;
	}
protected: 
	TMedallero* _m;
	CDeporte* _deportes;
	int _numDeportes;
};

#endif