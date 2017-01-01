#include "AlgoritmoSobreVectores.h"



CAlgoritmoSobreVectores::CAlgoritmoSobreVectores () {}

CAlgoritmoSobreVectores::~CAlgoritmoSobreVectores () {}

void  CAlgoritmoSobreVectores::TearDown () {

	if (_v != 0) {
		delete []_v;
		_v = 0;
		_tam = 0;
	}

	if (_valoresIniciales != 0) {
		delete []_valoresIniciales;
		_valoresIniciales = 0;
		_tam = 0;
	}

}