#ifndef __CALGORITMOMEDALLEROORDENADO_H
#define __CALGORITMOMEDALLEROORDENADO_H

#include <string>
#include "Algoritmo.h"
#include "AlgoritmoSobreMedallero.h"
#include "Secuencia.h"
#include "Pareja.h"
#include "Pais.h"
#include "Medallas.h"

//Esta clase especializa el algoritmo sobre medallero para la prueba con el medallero ordenado
template < class TMedallero>
class CAlgoritmoMedalleroOrdenado : public CAlgoritmoSobreMedallero<TMedallero> {
public:
	CAlgoritmoMedalleroOrdenado () {}

	virtual  ~CAlgoritmoMedalleroOrdenado () {}

	virtual std::string  getDescription () {return "medallero ordenado con N países";}

	virtual void  Execute () {_m->medalleroOrdenado();}
};



#endif