#include "AlgoritmoSeleccionDecreciente.h"
using namespace std;

CAlgoritmoSeleccionDecreciente::CAlgoritmoSeleccionDecreciente () {

	_tam = 0;
	_v = 0; //NULL
	_valoresIniciales = 0;//NULL
}

CAlgoritmoSeleccionDecreciente::~CAlgoritmoSeleccionDecreciente () {}

string  CAlgoritmoSeleccionDecreciente::getDescription () {

	return "Metodo Seleccion con entrada decreciente";

}

void  CAlgoritmoSeleccionDecreciente::SetUp (int N) {

	TearDown();
	_tam = N;
	_v = new int [N];
	_valoresIniciales = new int [N];
	generarDecreciente (_valoresIniciales, N);

}

void  CAlgoritmoSeleccionDecreciente::Execute () {

	if (_v != 0) {
		for (int i=0; i<_tam; ++i)
			_v[i] = _valoresIniciales[i];
		ordenaSeleccion (_v, _tam);
	}
}