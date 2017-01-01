#ifndef __CALGORITMOCLASIFICACIONPRIMERO_H
#define __CALGORITMOCLASIFICACIONPRIMERO_H

#include <string>
#include "AlgoritmoSobreClasificacion.h"
#include "Secuencia.h"
#include "Pareja.h"
#include "Pais.h"
#include "Medallas.h"

//Esta clase especializa el algoritmo sobre clasificación para la prueba con el primer clasificado
template <class TMedallero>
class CAlgoritmoClasificacionPrimero : public CAlgoritmoSobreClasificacion<TMedallero> {
public:
	CAlgoritmoClasificacionPrimero () {}

	virtual  ~CAlgoritmoClasificacionPrimero () {}

	virtual std::string  getDescription () {return "Clasificación Primero";}

	virtual void  Execute () {

		CPrueba prueba = CPrueba ("tituloPrueba", CDeporte ("nombreDeporte"));
		CSecuencia<CAtleta> clasif = CSecuencia<CAtleta> ();
		clasif.inserta(CAtleta ("Atleta_1", _paises[0]));
		clasif.inserta(CAtleta ("Atleta_2", _paises[0]));
		clasif.inserta(CAtleta ("Atleta_3", _paises[0]));

		_m->clasificacion (prueba, clasif);
	}
};



#endif