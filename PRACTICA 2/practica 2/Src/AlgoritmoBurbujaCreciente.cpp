#include "AlgoritmoBurbujaCreciente.h"
using namespace std;


CAlgoritmoBurbujaCreciente::CAlgoritmoBurbujaCreciente () {

	_tam = 0;
	_v = 0; //NULL
	_valoresIniciales = 0; //NULL
}

CAlgoritmoBurbujaCreciente::~CAlgoritmoBurbujaCreciente () {}

string  CAlgoritmoBurbujaCreciente::getDescription () {

	return "Metodo Burbuja con entrada creciente";

}

void  CAlgoritmoBurbujaCreciente::SetUp (int N) {

	TearDown();
	_tam = N;
	_v = new int [N];
	_valoresIniciales = new int [N];
	generarCreciente (_valoresIniciales, N);

}

void  CAlgoritmoBurbujaCreciente::Execute () {

	if (_v != 0) {
		for (int i=0; i<_tam; ++i)
			_v[i] = _valoresIniciales[i];
		ordenaBurbuja (_v, _tam);
	}
}