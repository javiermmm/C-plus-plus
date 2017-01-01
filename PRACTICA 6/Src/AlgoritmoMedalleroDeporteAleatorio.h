#ifndef __CALGORITMOMEDALLERODEPORTEALEATORIO_H
#define __CALGORITMOMEDALLERODEPORTEALEATORIO_H

#include <string>
#include "AlgoritmoSobreMedalleroDeporte.h"
#include "Secuencia.h"
#include "Pareja.h"
#include "Pais.h"
#include "Medallas.h"

//Esta clase especializa el algoritmo sobre medallero por deporte para la prueba con el medallero por deporte aleatorio sin ordenar
template <class TMedallero>
class CAlgoritmoMedalleroDeporteAleatorio : public CAlgoritmoSobreMedalleroDeporte<TMedallero> {
public:
	CAlgoritmoMedalleroDeporteAleatorio () {}

	virtual  ~CAlgoritmoMedalleroDeporteAleatorio () {}

	virtual std::string  getDescription () {return "medallero por Deporte con 3 países";}

	virtual void  Execute () {

		int i = rand() % _numDeportes;
		_m->medalleroDeporte(_deportes[i]);
	}
};



#endif