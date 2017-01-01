#include "AlgoritmoSeleccionCreciente.h"
using namespace std;


CAlgoritmoSeleccionCreciente::CAlgoritmoSeleccionCreciente () {

	_tam = 0;
	_v = 0; //NULL
	_valoresIniciales = 0; //NULL
}

CAlgoritmoSeleccionCreciente::~CAlgoritmoSeleccionCreciente () {}

string  CAlgoritmoSeleccionCreciente::getDescription () {

	return "Metodo Seleccion con entrada creciente";
}

void  CAlgoritmoSeleccionCreciente::SetUp (int N) {

	TearDown();
	_tam = N;
	_v = new int [N];
	_valoresIniciales = new int [N];
	generarCreciente (_valoresIniciales, N);
}

void  CAlgoritmoSeleccionCreciente::Execute () {

	if (_v != 0) {
		for (int i=0; i<_tam; ++i)
			_v[i] = _valoresIniciales[i];
		ordenaSeleccion (_v, _tam);
	}
}