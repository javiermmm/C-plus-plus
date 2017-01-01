#include "AlgoritmoSobreClasificacion.h"
using namespace std;

CAlgoritmoSobreClasificacion::CAlgoritmoSobreClasificacion () {};

CAlgoritmoSobreClasificacion::~CAlgoritmoSobreClasificacion () {};

void  CAlgoritmoSobreClasificacion::SetUp (int N) {

	_m = new CMedallero();
	_numPaises = N;
	_paises = new CPais [_numPaises];
	CPrueba prueba = CPrueba ("tituloPrueba", CDeporte("nombreDeporte"));
	for (int i=0; i<_numPaises; ++i) {
		_paises[i] = paisAleatorio();
		CSecuencia<CAtleta> clasif = CSecuencia<CAtleta>();
		clasif.inserta(CAtleta ("Atleta_1", _paises[i]));
		clasif.inserta(CAtleta ("Atleta_2", _paises[i]));
		clasif.inserta(CAtleta ("Atleta_3", _paises[i]));
		_m->clasificacion(prueba, clasif);
	}
}

void  CAlgoritmoSobreClasificacion::TearDown () {

	delete _m;
	delete [] _paises;
}