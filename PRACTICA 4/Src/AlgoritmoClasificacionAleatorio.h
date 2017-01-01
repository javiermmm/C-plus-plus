#ifndef __CALGORITMOCLASIFICACIONALEATORIO_H
#define __CALGORITMOCLASIFICACIONALEATORIO_H

#include <string>
#include "AlgoritmoSobreClasificacion.h"
#include "Secuencia.h"
#include "Pareja.h"
#include "Pais.h"
#include "Medallas.h"
#include "Medallero.h"

//Esta clase especializa el algoritmo sobre clasificación para la prueba aletoria
class CAlgoritmoClasificacionAleatorio : public CAlgoritmoSobreClasificacion {
public:
	CAlgoritmoClasificacionAleatorio ();
	virtual  ~CAlgoritmoClasificacionAleatorio ();
	virtual std::string  getDescription ();
	virtual void  Execute ();
};



#endif