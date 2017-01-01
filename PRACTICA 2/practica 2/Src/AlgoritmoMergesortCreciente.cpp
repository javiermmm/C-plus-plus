#include "AlgoritmoMergesortCreciente.h"
using namespace std;


CAlgoritmoMergesortCreciente::CAlgoritmoMergesortCreciente () {

	_tam = 0;
	_v = 0; //NULL
	_valoresIniciales = 0; //NULL
}

CAlgoritmoMergesortCreciente::~CAlgoritmoMergesortCreciente () {}

string  CAlgoritmoMergesortCreciente::getDescription () {

	return "Metodo mergesort con entrada creciente";

}

void  CAlgoritmoMergesortCreciente::SetUp (int N) {

	TearDown();
	_tam = N;
	_v = new int [N];
	_valoresIniciales = new int [N];
	generarCreciente (_valoresIniciales, N);

}

void  CAlgoritmoMergesortCreciente::Execute () {

	if (_v != 0) {
		for (int i=0; i<_tam; ++i)
			_v[i] = _valoresIniciales[i];
		mergeSort (_v, _tam);
	}
}
