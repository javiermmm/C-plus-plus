#include "AlgoritmoQuicksortDecreciente.h"
using namespace std;

CAlgoritmoQuicksortDecreciente::CAlgoritmoQuicksortDecreciente (){

	_tam = 0;
	_v = 0; //NULL
	_valoresIniciales = 0; //NULL
}

CAlgoritmoQuicksortDecreciente::~CAlgoritmoQuicksortDecreciente () {}

string  CAlgoritmoQuicksortDecreciente::getDescription () {

	return "Metodo quicksort con entrada decreciente";

}

void  CAlgoritmoQuicksortDecreciente::SetUp (int N) {

	TearDown();
	_tam = N;
	_v = new int [N];
	_valoresIniciales = new int [N];
	generarDecreciente (_valoresIniciales, N);

}

void  CAlgoritmoQuicksortDecreciente::Execute () {

	if (_v != 0) {
		for (int i=0; i<_tam; ++i)
			_v[i] = _valoresIniciales[i];
		quickSort (_v, _tam);
	}
}