#ifndef __CALGORITMOCLASIFICACIONALEATORIO_H
#define __CALGORITMOCLASIFICACIONALEATORIO_H

#include <string>
#include "AlgoritmoSobreClasificacion.h"
#include "Secuencia.h"
#include "Pareja.h"
#include "Pais.h"
#include "Medallas.h"

//Esta clase especializa el algoritmo sobre clasificación para la prueba aletoria
template <class TMedallero>
class CAlgoritmoClasificacionAleatorio : public CAlgoritmoSobreClasificacion<TMedallero> {
public:
	CAlgoritmoClasificacionAleatorio () {}

	virtual  ~CAlgoritmoClasificacionAleatorio () {}

	virtual std::string  getDescription () {return "clasificación Aleatorio";}

	virtual void  Execute ()  {

		CPrueba prueba = CPrueba ("tituloPrueba", CDeporte ("nombreDeporte"));
		CSecuencia<CAtleta> clasif = CSecuencia<CAtleta> ();
		int paisAleatorio = rand() % _numPaises;
		clasif.inserta(CAtleta ("Atleta_1", _paises[paisAleatorio]));
		clasif.inserta(CAtleta ("Atleta_2", _paises[paisAleatorio]));
		clasif.inserta(CAtleta ("Atleta_3", _paises[paisAleatorio]));

		_m->clasificacion (prueba, clasif);
	}
};



#endif