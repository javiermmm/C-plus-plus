#ifndef __CALGORITMOCLASIFICACIONULTIMO_H
#define __CALGORITMOCLASIFICACIONULTIMO_H

#include <string>
#include "AlgoritmoSobreClasificacion.h"
#include "Secuencia.h"
#include "Pareja.h"
#include "Pais.h"
#include "Medallas.h"
#include "Medallero.h"

//Esta clase especializa el algoritmo sobre clasificación para la prueba con el último clasificado
class CAlgoritmoClasificacionUltimo : public CAlgoritmoSobreClasificacion {
public:
	CAlgoritmoClasificacionUltimo ();
	virtual  ~CAlgoritmoClasificacionUltimo ();
	virtual std::string  getDescription ();
	virtual void  Execute ();
};



#endif