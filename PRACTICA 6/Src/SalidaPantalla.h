#ifndef __CSALIDAPANTALLA_H
#define __CSALIDAPANTALLA_H

#include <string>
#include "Salida.h"

//Clase que especializa la clase CSalida para mostrar por pantalla
class CSalidaPantalla : public CSalida {
public:
	virtual  ~CSalidaPantalla ();
	virtual void  InitPrueba (const std::string &desc);
	virtual void  Muestra (int tam, float tiempo);
	virtual void  FinPrueba ();
};

#endif