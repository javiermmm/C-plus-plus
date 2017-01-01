#include "AlgoritmoClasificacionPrimero.h"
using namespace std;

CAlgoritmoClasificacionPrimero::CAlgoritmoClasificacionPrimero () {}

CAlgoritmoClasificacionPrimero::~CAlgoritmoClasificacionPrimero () {}


std::string  CAlgoritmoClasificacionPrimero::getDescription () {

	return "Clasificación Primero";
}

void  CAlgoritmoClasificacionPrimero::Execute () {

	CPrueba prueba = CPrueba ("tituloPrueba", CDeporte ("nombreDeporte"));
	CSecuencia<CAtleta> clasif = CSecuencia<CAtleta> ();
	clasif.inserta(CAtleta ("Atleta_1", _paises[0]));
	clasif.inserta(CAtleta ("Atleta_2", _paises[0]));
	clasif.inserta(CAtleta ("Atleta_3", _paises[0]));

	_m->clasificacion (prueba, clasif);
}