#include "SalidaPantalla.h"
#include <iostream>
using namespace std;

CSalidaPantalla::~CSalidaPantalla () {}

void  CSalidaPantalla::InitPrueba (const std::string &desc){

	cout << desc;
	cout << endl << "-------------------------------------------------------" << endl;
}

void  CSalidaPantalla::Muestra (int tam, float tiempo){

	cout << tam << "              " << tiempo << endl;
}

void  CSalidaPantalla::FinPrueba (){

	cout << endl << "-----------------------FIN DATOS-----------------------" << endl << endl << endl;
}
