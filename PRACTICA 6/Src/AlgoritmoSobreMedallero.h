#ifndef _ALGORITMOSOBREMEDALLERO__H
#define _ALGORITMOSOBREMEDALLERO__H

#include <string>
#include "Algoritmo.h"
#include "Secuencia.h"
#include "Pareja.h"
#include "Pais.h"
#include "Medallas.h"
#include "GenerarAleatorios.h"

//clase que identifica a los algoritmos que van a llamar al metodo medallero, en la medición de tiempos, 
//sin especificar si se va a usar su version ordenada o sin ordenar
template <class TMedallero>
class CAlgoritmoSobreMedallero : public CAlgoritmo {
public:
	CAlgoritmoSobreMedallero () {}

	virtual  ~CAlgoritmoSobreMedallero () {}

	virtual std::string  getDescription () = 0;

	virtual void  SetUp (int N) {

		_m = new TMedallero();
		CDeporte dummy = CDeporte ("deporteDummy");
		CPais pais;
		CPais paisDummy = CPais ("paisDummy");
		CPrueba pDummy = CPrueba ("tituloPrueba", dummy);

			for (int i=0; i < N; ++i) {

				int NAleatorio = rand() % (int)(sqrt((double)N));

				CSecuencia<CAtleta> clasif = CSecuencia<CAtleta>();
				pais = paisAleatorio();
				clasif.inserta(CAtleta ("atleta1", pais));

				if (rand() % 2 == 0)
					clasif.inserta(CAtleta ("atleta2", paisDummy));
				else 
					clasif.inserta(CAtleta("atleta2",pais));

				if (rand() % 2 == 0)
					clasif.inserta(CAtleta ("atleta3", paisDummy));
				else 
					clasif.inserta(CAtleta("atleta3",pais)); 

				for (int i=0; i<NAleatorio; ++i )
					_m->clasificacion (pDummy, clasif);
			}

	}

	virtual void  Execute () = 0;

	virtual void  TearDown () {delete _m;}
protected: 
	TMedallero* _m;
};

#endif