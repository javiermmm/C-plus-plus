#ifndef __CSALIDAWINDOWSFORMS_H
#define __CSALIDAWINDOWSFORMS_H

#include "Salida.h"

#include <string>
#include <fstream>
#include <vcclr.h>

class CSalidaWindowsForms : public CSalida {
public:
	CSalidaWindowsForms (gcroot<System::Windows::Forms::TextBox ^> tb, gcroot<System::Windows::Forms::ProgressBar ^> barra);
	virtual  ~CSalidaWindowsForms ();
	virtual void  InitPrueba (const std::string &desc);
	virtual void  Muestra (int tam, float tiempo);
	virtual void  FinPrueba ();
	void setNumPasos (int numPasos);
protected:
	gcroot<System::Windows::Forms::TextBox ^> _tb;
	gcroot<System::Windows::Forms::ProgressBar ^> _barra;
	int _numPasos;             
};

#endif