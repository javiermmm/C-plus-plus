#ifndef __CSALIDA_H
#define __CSALIDA_H

#include <string>

//Clase abstracta que sirve de interfaz para las clases CSalidaPantalla, CSalidaGNUPlot y CSalidaWindowsForms
class CSalida {
public:
	virtual  ~CSalida () {}
	virtual void  InitPrueba (const std::string &desc)=0 {}
	virtual void  Muestra (int tam, float tiempo)=0 {}
	virtual void  FinPrueba ()=0 {}
};

#endif