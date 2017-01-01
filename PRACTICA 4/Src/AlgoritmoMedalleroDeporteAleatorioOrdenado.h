#ifndef __CALGORITMOMEDALLERODEPORTEORDENADO_H
#define __CALGORITMOMEDALLERODEPORTEORDENADO_H

#include <string>
#include "AlgoritmoSobreMedalleroDeporte.h"
#include "Secuencia.h"
#include "Pareja.h"
#include "Pais.h"
#include "Medallas.h"
#include "Medallero.h"

//Esta clase especializa el algoritmo sobre medallero por deporte para la prueba con el medallero por deporte aleatorio ordenado
class CAlgoritmoMedalleroDeporteAleatorioOrdenado : public CAlgoritmoSobreMedalleroDeporte {
public:
	CAlgoritmoMedalleroDeporteAleatorioOrdenado ();
	virtual  ~CAlgoritmoMedalleroDeporteAleatorioOrdenado ();
	virtual std::string  getDescription ();
	virtual void  Execute ();
};



#endif