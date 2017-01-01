#ifndef __CALGORITMOCLASIFICACIONPRIMERO_H
#define __CALGORITMOCLASIFICACIONPRIMERO_H

#include <string>
#include "AlgoritmoSobreClasificacion.h"
#include "Secuencia.h"
#include "Pareja.h"
#include "Pais.h"
#include "Medallas.h"
#include "Medallero.h"

//Esta clase especializa el algoritmo sobre clasificación para la prueba con el primer clasificado
class CAlgoritmoClasificacionPrimero : public CAlgoritmoSobreClasificacion {
public:
	CAlgoritmoClasificacionPrimero ();
	virtual  ~CAlgoritmoClasificacionPrimero ();
	virtual std::string  getDescription ();
	virtual void  Execute ();
};



#endif