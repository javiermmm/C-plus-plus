#include "AlgoritmoInsercionDecreciente.h"
using namespace std;

CAlgoritmoInsercionDecreciente::CAlgoritmoInsercionDecreciente () {

	_tam = 0;
	_v = 0; //NULL
	_valoresIniciales = 0; //NULL
}

CAlgoritmoInsercionDecreciente::~CAlgoritmoInsercionDecreciente () {}

string  CAlgoritmoInsercionDecreciente::getDescription () {

	return "Metodo insercion con entrada decreciente";

}

void  CAlgoritmoInsercionDecreciente::SetUp (int N) {

	TearDown();
	_tam = N;
	_v = new int [N];
	_valoresIniciales = new int [N];
	generarDecreciente (_valoresIniciales, N);

}

void  CAlgoritmoInsercionDecreciente::Execute () {

	if (_v != 0) {
		for (int i=0; i<_tam; ++i)
			_v[i] = _valoresIniciales[i];
		ordenaInsercion (_v, _tam);
	}
}