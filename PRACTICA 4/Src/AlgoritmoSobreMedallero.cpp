#include "AlgoritmoSobreMedallero.h"
using namespace std;

CAlgoritmoSobreMedallero::CAlgoritmoSobreMedallero () {}

CAlgoritmoSobreMedallero::~CAlgoritmoSobreMedallero () {}

void  CAlgoritmoSobreMedallero::SetUp (int N) {

	_m = new CMedallero();
	CDeporte dummy = CDeporte ("deporteDummy");
	CPais pais;
	CPais paisDummy = CPais ("paisDummy");
	CPrueba pDummy = CPrueba ("tituloPrueba", dummy);

	int NAleatorio = rand() % (int)(sqrt((double)N));

	for (int i=0; i < N; ++i) {
		CSecuencia<CAtleta> clasif = CSecuencia<CAtleta>();
		pais = paisAleatorio();
		clasif.inserta(CAtleta ("atleta1", pais));

		if (rand() % 2 == 0)
			clasif.inserta(CAtleta ("atleta2", paisDummy));
		else 
			clasif.inserta(CAtleta("atleta2",pais));

		if (rand() % 2 == 0)
			clasif.inserta(CAtleta ("atleta3", paisDummy));
		else 
			clasif.inserta(CAtleta("atleta3",pais)); 

		for (int i=0; i<NAleatorio; ++i )
			_m->clasificacion (pDummy, clasif);
	}

}

void  CAlgoritmoSobreMedallero::TearDown () {

	delete _m;
}
