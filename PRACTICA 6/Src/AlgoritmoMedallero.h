#ifndef __CALGORITMOMEDALLERO_H
#define __CALGORITMOMEDALLERO_H

#include <string>
#include "Algoritmo.h"
#include "AlgoritmoSobreMedallero.h"
#include "Secuencia.h"
#include "Pareja.h"
#include "Pais.h"
#include "Medallas.h"

//Esta clase especializa el algoritmo sobre medallero para la prueba con el medallero sin ordenar
template <class TMedallero>
class CAlgoritmoMedallero : public CAlgoritmoSobreMedallero<TMedallero> {
public:
	CAlgoritmoMedallero () {}

	virtual  ~CAlgoritmoMedallero () {}

	virtual std::string  getDescription () {return "medallero con N países";}

	virtual void  Execute () {_m->medallero();}
};



#endif