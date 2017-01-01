#include "AlgoritmoBurbujaAleatorio.h"
using namespace std;


CAlgoritmoBurbujaAleatorio::CAlgoritmoBurbujaAleatorio () {

	_tam = 0;
	_v = 0; //NULL
	_valoresIniciales = 0; //NULL
}

CAlgoritmoBurbujaAleatorio::~CAlgoritmoBurbujaAleatorio () {}

string  CAlgoritmoBurbujaAleatorio::getDescription () {

	return "Metodo Burbuja con entrada aleatoria";

}

void  CAlgoritmoBurbujaAleatorio::SetUp (int N) {

	TearDown();
	_tam = N;
	_v = new int [N];
	_valoresIniciales = new int [N];
	generarAleatorio (_valoresIniciales, N);

}

void  CAlgoritmoBurbujaAleatorio::Execute () {

	if (_v != 0) {
		for (int i=0; i<_tam; ++i)
			_v[i] = _valoresIniciales[i];
		ordenaBurbuja (_v, _tam);
	}
}