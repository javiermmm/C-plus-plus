#include "AlgoritmoInsercionCreciente.h"
using namespace std;


CAlgoritmoInsercionCreciente::CAlgoritmoInsercionCreciente () {

	_tam = 0;
	_v = 0; //NULL
	_valoresIniciales = 0; //NULL
}

CAlgoritmoInsercionCreciente::~CAlgoritmoInsercionCreciente () {}

string  CAlgoritmoInsercionCreciente::getDescription () {

	return "Metodo insercion con entrada creciente";

}

void  CAlgoritmoInsercionCreciente::SetUp (int N) {

	TearDown();
	_tam = N;
	_v = new int [N];
	_valoresIniciales = new int [N];
	generarCreciente (_valoresIniciales, N);

}

void  CAlgoritmoInsercionCreciente::Execute () {

	if (_v != 0) {
		for (int i=0; i<_tam; ++i)
			_v[i] = _valoresIniciales[i];
		ordenaInsercion (_v, _tam);
	}
}