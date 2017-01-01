#include "AlgoritmoMedalleroDeporteAleatorio.h"
using namespace std;

CAlgoritmoMedalleroDeporteAleatorio::CAlgoritmoMedalleroDeporteAleatorio () {}

CAlgoritmoMedalleroDeporteAleatorio::~CAlgoritmoMedalleroDeporteAleatorio () {}

std::string  CAlgoritmoMedalleroDeporteAleatorio::getDescription () {

	return "medallero por Deporte con 3 países";
}

void  CAlgoritmoMedalleroDeporteAleatorio::Execute () {

	int i = rand() % _numDeportes;
	_m->medalleroDeporte(_deportes[i]);
}


