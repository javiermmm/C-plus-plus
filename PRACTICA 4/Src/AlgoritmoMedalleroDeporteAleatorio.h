#ifndef __CALGORITMOMEDALLERODEPORTEALEATORIO_H
#define __CALGORITMOMEDALLERODEPORTEALEATORIO_H

#include <string>
#include "AlgoritmoSobreMedalleroDeporte.h"
#include "Secuencia.h"
#include "Pareja.h"
#include "Pais.h"
#include "Medallas.h"
#include "Medallero.h"

//Esta clase especializa el algoritmo sobre medallero por deporte para la prueba con el medallero por deporte aleatorio sin ordenar
class CAlgoritmoMedalleroDeporteAleatorio : public CAlgoritmoSobreMedalleroDeporte {
public:
	CAlgoritmoMedalleroDeporteAleatorio ();
	virtual  ~CAlgoritmoMedalleroDeporteAleatorio ();
	virtual std::string  getDescription ();
	virtual void  Execute ();
};



#endif