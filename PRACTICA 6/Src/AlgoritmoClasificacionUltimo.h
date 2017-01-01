#ifndef __CALGORITMOCLASIFICACIONULTIMO_H
#define __CALGORITMOCLASIFICACIONULTIMO_H

#include <string>
#include "AlgoritmoSobreClasificacion.h"
#include "Secuencia.h"
#include "Pareja.h"
#include "Pais.h"
#include "Medallas.h"

//Esta clase especializa el algoritmo sobre clasificación para la prueba con el último clasificado
template <class TMedallero>
class CAlgoritmoClasificacionUltimo : public CAlgoritmoSobreClasificacion<TMedallero> {
public:
	CAlgoritmoClasificacionUltimo () {}

	virtual  ~CAlgoritmoClasificacionUltimo () {}

	virtual std::string  getDescription () {return "clasificación Último";}

	virtual void  Execute () {

		CPrueba prueba = CPrueba ("tituloPrueba", CDeporte ("nombreDeporte"));
		CSecuencia<CAtleta> clasif = CSecuencia<CAtleta> ();
		clasif.inserta(CAtleta ("Atleta_1", _paises[_numPaises-1]));
		clasif.inserta(CAtleta ("Atleta_2", _paises[_numPaises-1]));
		clasif.inserta(CAtleta ("Atleta_3", _paises[_numPaises-1]));

		_m->clasificacion (prueba, clasif);
	}
};



#endif