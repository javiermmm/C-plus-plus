#include "AlgoritmoMergesortAleatorio.h"
using namespace std;

CAlgoritmoMergesortAleatorio::CAlgoritmoMergesortAleatorio () {

	_tam = 0;
	_v = 0; //NULL
	_valoresIniciales = 0; //NULL
}

CAlgoritmoMergesortAleatorio::~CAlgoritmoMergesortAleatorio () {}

string  CAlgoritmoMergesortAleatorio::getDescription () {

	return "Metodo mergesort con entrada aleatoria";

}

void  CAlgoritmoMergesortAleatorio::SetUp (int N) {

	TearDown();
	_tam = N;
	_v = new int [N];
	_valoresIniciales = new int [N];
	generarAleatorio (_valoresIniciales, N);

}

void  CAlgoritmoMergesortAleatorio::Execute () {

	if (_v != 0) {
		for (int i=0; i<_tam; ++i)
			_v[i] = _valoresIniciales[i];
		mergeSort (_v, _tam);
	}
}