#include "AlgoritmoQuicksortAleatorio.h"
using namespace std;

CAlgoritmoQuicksortAleatorio::CAlgoritmoQuicksortAleatorio () {

	_tam = 0;
	_v = 0; //NULL
	_valoresIniciales = 0; //NULL
}

CAlgoritmoQuicksortAleatorio::~CAlgoritmoQuicksortAleatorio () {}

string  CAlgoritmoQuicksortAleatorio::getDescription () {

	return "Metodo quicksort con entrada aleatoria";

}

void  CAlgoritmoQuicksortAleatorio::SetUp (int N) {

	TearDown();
	_tam = N;
	_v = new int [N];
	_valoresIniciales = new int [N];
	generarAleatorio (_valoresIniciales, N);

}

void  CAlgoritmoQuicksortAleatorio::Execute () {

	if (_v != 0) {
		for (int i=0; i<_tam; ++i)
			_v[i] = _valoresIniciales[i];
		quickSort (_v, _tam);
	}
}