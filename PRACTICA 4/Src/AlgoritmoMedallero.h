#ifndef __CALGORITMOMEDALLERO_H
#define __CALGORITMOMEDALLERO_H

#include <string>
#include "Algoritmo.h"
#include "AlgoritmoSobreMedallero.h"
#include "Secuencia.h"
#include "Pareja.h"
#include "Pais.h"
#include "Medallas.h"
#include "Medallero.h"

//Esta clase especializa el algoritmo sobre medallero para la prueba con el medallero sin ordenar
class CAlgoritmoMedallero : public CAlgoritmoSobreMedallero {
public:
	CAlgoritmoMedallero ();
	virtual  ~CAlgoritmoMedallero ();
	virtual std::string  getDescription ();
	virtual void  Execute ();
};



#endif