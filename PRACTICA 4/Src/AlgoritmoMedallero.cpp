#include "AlgoritmoMedallero.h"
using namespace std;


CAlgoritmoMedallero::CAlgoritmoMedallero () {}

CAlgoritmoMedallero::~CAlgoritmoMedallero () {}

std::string  CAlgoritmoMedallero::getDescription () {

	return "medallero con N pa�ses";
}

void  CAlgoritmoMedallero::Execute () {

	_m->medallero();
}


