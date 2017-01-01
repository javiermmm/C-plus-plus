#include "AlgoritmoMergesortDecreciente.h"
using namespace std;

CAlgoritmoMergesortDecreciente::CAlgoritmoMergesortDecreciente () {

	_tam = 0;
	_v = 0; //NULL
	_valoresIniciales = 0; //NULL
}

CAlgoritmoMergesortDecreciente::~CAlgoritmoMergesortDecreciente () {}

string  CAlgoritmoMergesortDecreciente::getDescription () {

	return "Metodo mergesort con entrada decreciente";

}

void  CAlgoritmoMergesortDecreciente::SetUp (int N) {

	TearDown();
	_tam = N;
	_v = new int [N];
	_valoresIniciales = new int [N];
	generarDecreciente (_valoresIniciales, N);

}

void  CAlgoritmoMergesortDecreciente::Execute () {

	if (_v != 0) {
		for (int i=0; i<_tam; ++i)
			_v[i] = _valoresIniciales[i];
		mergeSort (_v, _tam);
	}
}