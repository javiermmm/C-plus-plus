#include "AlgoritmoClasificacionAleatorio.h"
using namespace std;

CAlgoritmoClasificacionAleatorio::CAlgoritmoClasificacionAleatorio () {}

CAlgoritmoClasificacionAleatorio::~CAlgoritmoClasificacionAleatorio () {}


std::string  CAlgoritmoClasificacionAleatorio::getDescription () {

	return "clasificación Aleatorio";
}

void  CAlgoritmoClasificacionAleatorio::Execute () {

	CPrueba prueba = CPrueba ("tituloPrueba", CDeporte ("nombreDeporte"));
	CSecuencia<CAtleta> clasif = CSecuencia<CAtleta> ();
	int paisAleatorio = rand() % _numPaises;
	clasif.inserta(CAtleta ("Atleta_1", _paises[paisAleatorio]));
	clasif.inserta(CAtleta ("Atleta_2", _paises[paisAleatorio]));
	clasif.inserta(CAtleta ("Atleta_3", _paises[paisAleatorio]));

	_m->clasificacion (prueba, clasif);
}