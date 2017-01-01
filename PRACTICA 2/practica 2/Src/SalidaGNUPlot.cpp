#include "SalidaGNUPlot.h"

#include <iostream>
#include <fstream>
using namespace std;

CSalidaGNUPlot::CSalidaGNUPlot (string name) : _nombre(name) {}

CSalidaGNUPlot::~CSalidaGNUPlot () {}

void  CSalidaGNUPlot::InitPrueba (const std::string &desc) {

	_f.open(_nombre);
}

void  CSalidaGNUPlot::Muestra (int tam, float tiempo) {

	if (_f.is_open())
		_f << tam << " " << tiempo << endl;
}

void  CSalidaGNUPlot::FinPrueba () {

	_f.close();
}
