#ifndef __CSALIDAGNUPLOT_H
#define __CSALIDAGNUPLOT_H

#include "Salida.h"

#include <string>
#include <fstream>

class CSalidaGNUPlot : public CSalida {
public:
	CSalidaGNUPlot (std::string name = "");
	virtual  ~CSalidaGNUPlot ();
	virtual void  InitPrueba (const std::string &desc);
	virtual void  Muestra (int tam, float tiempo);
	virtual void  FinPrueba ();
protected:
	std::ofstream _f;
	std::string _nombre;
};

#endif