#ifndef __CSALIDAWINDOWSFORMS_H
#define __CSALIDAWINDOWSFORMS_H

#include "Salida.h"

#include <string>
#include <fstream>
#include <vcclr.h>

class CSalidaWindowsForms : public CSalida {
public:
	CSalidaWindowsForms (gcroot<System::Windows::Forms::TextBox ^> tb);
	virtual  ~CSalidaWindowsForms ();
	virtual void  InitPrueba (const std::string &desc);
	virtual void  Muestra (int tam, float tiempo);
	virtual void  FinPrueba ();
protected:
	gcroot<System::Windows::Forms::TextBox ^> _tb;
};

#endif