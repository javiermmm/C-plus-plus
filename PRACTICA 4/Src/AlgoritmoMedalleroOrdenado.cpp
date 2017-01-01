#include "AlgoritmoMedalleroOrdenado.h"
using namespace std;


CAlgoritmoMedalleroOrdenado::CAlgoritmoMedalleroOrdenado () {}

CAlgoritmoMedalleroOrdenado::~CAlgoritmoMedalleroOrdenado () {}

std::string  CAlgoritmoMedalleroOrdenado::getDescription () {

	return "medallero ordenado con N países";
}

void  CAlgoritmoMedalleroOrdenado::Execute () {

	_m->medalleroOrdenado();
}


