#include "AlgoritmoSobreMedalleroDeporte.h"
using namespace std;

CAlgoritmoSobreMedalleroDeporte::CAlgoritmoSobreMedalleroDeporte () {}

CAlgoritmoSobreMedalleroDeporte::~CAlgoritmoSobreMedalleroDeporte () {}


void  CAlgoritmoSobreMedalleroDeporte::SetUp (int N) {

	_m = new CMedallero();
	_numDeportes = N;
	CPais pA = CPais ("Pais_A");
	CPais pB = CPais ("Pais_B");
	CPais pC = CPais ("Pais_C");
	CSecuencia<CAtleta> clasif;
	_deportes = new CDeporte [_numDeportes];

	for (int i=0; i < N; ++i) {
		_deportes[i] = deporteAleatorio();
		CPrueba prueba = CPrueba ("tituloPrueba", _deportes[i]);

		int numRamdom = rand();
		if ((numRamdom % 3) == 0)
			clasif.inserta(CAtleta ("atleta1", pA));
		if ((numRamdom % 3) == 1)
			clasif.inserta(CAtleta ("atleta2", pB));
		if ((numRamdom % 3) == 2)
			clasif.inserta(CAtleta ("atleta3", pC));

		numRamdom = rand();
		if ((numRamdom % 3) == 0)
			clasif.inserta(CAtleta ("atleta1", pA));
		if ((numRamdom % 3) == 1)
			clasif.inserta(CAtleta ("atleta2", pB));
		if ((numRamdom % 3) == 2)
			clasif.inserta(CAtleta ("atleta3", pC));

		numRamdom = rand();
		if ((numRamdom % 3) == 0)
			clasif.inserta(CAtleta ("atleta1", pA));
		if ((numRamdom % 3) == 1)
			clasif.inserta(CAtleta ("atleta2", pB));
		if ((numRamdom % 3) == 2)
			clasif.inserta(CAtleta ("atleta3", pC));

		_m->clasificacion (prueba, clasif);
	}

}

void  CAlgoritmoSobreMedalleroDeporte::TearDown () {

	delete _m;
	delete []_deportes;
}