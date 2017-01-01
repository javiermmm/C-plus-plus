#include "AlgoritmoBurbujaDecreciente.h"
using namespace std;


CAlgoritmoBurbujaDecreciente::CAlgoritmoBurbujaDecreciente () {

	_tam = 0;
	_v = 0; //NULL
	_valoresIniciales = 0; //NULL
}

CAlgoritmoBurbujaDecreciente::~CAlgoritmoBurbujaDecreciente () {}

string  CAlgoritmoBurbujaDecreciente::getDescription () {

	return "Metodo Burbuja con entrada decreciente";

}

void  CAlgoritmoBurbujaDecreciente::SetUp (int N) {

	TearDown();
	_tam = N;
	_v = new int [N];
	_valoresIniciales = new int [N];
	generarDecreciente (_valoresIniciales, N);

}

void  CAlgoritmoBurbujaDecreciente::Execute () {

	if (_v != 0) {
		for (int i=0; i<_tam; ++i)
			_v[i] = _valoresIniciales[i];
		ordenaBurbuja (_v, _tam);
	}
}