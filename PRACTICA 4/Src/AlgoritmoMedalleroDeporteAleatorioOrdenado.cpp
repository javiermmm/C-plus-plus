#include "AlgoritmoMedalleroDeporteAleatorioOrdenado.h"
using namespace std;

CAlgoritmoMedalleroDeporteAleatorioOrdenado::CAlgoritmoMedalleroDeporteAleatorioOrdenado () {}

CAlgoritmoMedalleroDeporteAleatorioOrdenado::~CAlgoritmoMedalleroDeporteAleatorioOrdenado () {}


std::string  CAlgoritmoMedalleroDeporteAleatorioOrdenado::getDescription () {

	return "medallero por Deporte ordenado con 3 pa�ses";
}

void  CAlgoritmoMedalleroDeporteAleatorioOrdenado::Execute () {

	int i = rand() % _numDeportes;
	_m->medalleroDeporteOrdenado(_deportes[i]);
}