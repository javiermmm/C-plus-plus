#include "AlgoritmoInsercionAleatorio.h"
using namespace std;

CAlgoritmoInsercionAleatorio::CAlgoritmoInsercionAleatorio () {

	_tam = 0;
	_v = 0; //NULL
	_valoresIniciales = 0; //NULL
}

CAlgoritmoInsercionAleatorio::~CAlgoritmoInsercionAleatorio () {}

string  CAlgoritmoInsercionAleatorio::getDescription () {

	return "Metodo insercion con entrada aleatoria";

}

void  CAlgoritmoInsercionAleatorio::SetUp (int N) {

	TearDown();
	_tam = N;
	_v = new int [N];
	_valoresIniciales = new int [N];
	generarAleatorio (_valoresIniciales, N);

}

void  CAlgoritmoInsercionAleatorio::Execute () {

	if (_v != 0) {
		for (int i=0; i<_tam; ++i)
			_v[i] = _valoresIniciales[i];
		ordenaInsercion (_v, _tam);
	}
}