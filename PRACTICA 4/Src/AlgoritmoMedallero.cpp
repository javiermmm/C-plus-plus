#include "AlgoritmoMedallero.h"
using namespace std;


CAlgoritmoMedallero::CAlgoritmoMedallero () {}

CAlgoritmoMedallero::~CAlgoritmoMedallero () {}

std::string  CAlgoritmoMedallero::getDescription () {

	return "medallero con N países";
}

void  CAlgoritmoMedallero::Execute () {

	_m->medallero();
}


