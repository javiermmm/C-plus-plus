#ifndef __CALGORITMOMEDALLERODEPORTEORDENADO_H
#define __CALGORITMOMEDALLERODEPORTEORDENADO_H

#include <string>
#include "AlgoritmoSobreMedalleroDeporte.h"
#include "Secuencia.h"
#include "Pareja.h"
#include "Pais.h"
#include "Medallas.h"

//Esta clase especializa el algoritmo sobre medallero por deporte para la prueba con el medallero por deporte aleatorio ordenado
template <class TMedallero>
class CAlgoritmoMedalleroDeporteAleatorioOrdenado : public CAlgoritmoSobreMedalleroDeporte<TMedallero> {
public:
	CAlgoritmoMedalleroDeporteAleatorioOrdenado () {}

	virtual  ~CAlgoritmoMedalleroDeporteAleatorioOrdenado () {}

	virtual std::string  getDescription () {return "medallero por Deporte ordenado con 3 países";}

	virtual void  Execute ()  {

		int i = rand() % _numDeportes;
		_m->medalleroDeporteOrdenado(_deportes[i]);
	}
};



#endif