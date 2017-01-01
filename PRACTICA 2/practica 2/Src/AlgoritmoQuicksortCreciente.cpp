#include "AlgoritmoQuicksortCreciente.h"
using namespace std;


CAlgoritmoQuicksortCreciente::CAlgoritmoQuicksortCreciente () {

	_tam = 0;
	_v = 0; //NULL
	_valoresIniciales = 0;
}

CAlgoritmoQuicksortCreciente::~CAlgoritmoQuicksortCreciente () {}

string  CAlgoritmoQuicksortCreciente::getDescription () {

	return "Metodo quicksort con entrada creciente";

}

void  CAlgoritmoQuicksortCreciente::SetUp (int N) {

	TearDown();
	_tam = N;
	_v = new int [N];
	_valoresIniciales = new int [N];
	generarCreciente (_valoresIniciales, N);

}

void  CAlgoritmoQuicksortCreciente::Execute () {

	if (_v != 0) {
		for (int i=0; i<_tam; ++i)
			_v[i] = _valoresIniciales[i];
		quickSort (_v, _tam);
	}
}