#ifndef __CALGORITMOMEDALLEROORDENADO_H
#define __CALGORITMOMEDALLEROORDENADO_H

#include <string>
#include "Algoritmo.h"
#include "AlgoritmoSobreMedallero.h"
#include "Secuencia.h"
#include "Pareja.h"
#include "Pais.h"
#include "Medallas.h"
#include "Medallero.h"

//Esta clase especializa el algoritmo sobre medallero para la prueba con el medallero ordenado
class CAlgoritmoMedalleroOrdenado : public CAlgoritmoSobreMedallero {
public:
	CAlgoritmoMedalleroOrdenado ();
	virtual  ~CAlgoritmoMedalleroOrdenado ();
	virtual std::string  getDescription ();
	virtual void  Execute ();
};



#endif