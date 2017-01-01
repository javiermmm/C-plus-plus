#include "AlgoritmoClasificacionUltimo.h"
using namespace std;

CAlgoritmoClasificacionUltimo::CAlgoritmoClasificacionUltimo () {}

CAlgoritmoClasificacionUltimo::~CAlgoritmoClasificacionUltimo () {}


std::string  CAlgoritmoClasificacionUltimo::getDescription () {

	return "clasificación Último";
}

void  CAlgoritmoClasificacionUltimo::Execute () {

	CPrueba prueba = CPrueba ("tituloPrueba", CDeporte ("nombreDeporte"));
	CSecuencia<CAtleta> clasif = CSecuencia<CAtleta> ();
	clasif.inserta(CAtleta ("Atleta_1", _paises[_numPaises-1]));
	clasif.inserta(CAtleta ("Atleta_2", _paises[_numPaises-1]));
	clasif.inserta(CAtleta ("Atleta_3", _paises[_numPaises-1]));

	_m->clasificacion (prueba, clasif);
}