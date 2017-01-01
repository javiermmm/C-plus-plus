#include "AlgoritmoSeleccionAleatorio.h"
using namespace std;

CAlgoritmoSeleccionAleatorio::CAlgoritmoSeleccionAleatorio () {

	_tam = 0;
	_v = 0; //NULL
	_valoresIniciales = 0; //NULL
}

CAlgoritmoSeleccionAleatorio::~CAlgoritmoSeleccionAleatorio () {}

string  CAlgoritmoSeleccionAleatorio::getDescription () {

	return "Metodo Seleccion con entrada aleatoria";

}

void  CAlgoritmoSeleccionAleatorio::SetUp (int N) {

	TearDown();
	_tam = N;
	_v = new int [N];
	_valoresIniciales = new int [N];
	generarAleatorio (_valoresIniciales, N);

}

void  CAlgoritmoSeleccionAleatorio::Execute () {

	if (_v != 0) {
		for (int i=0; i<_tam; ++i)
			_v[i] = _valoresIniciales[i];
		ordenaSeleccion (_v, _tam);
	}
}

