#include "GenerarAleatorios.h"
using namespace std;

string randomString (int j) {

	string ret;
    for(int i=0; i <= j; i++) {
		char r = (char) (65 + rand() % (90 - 65 + 1));
						//65 = código ASCII de 'A'
						//90 = código ASCII de 'Z'
		ret += r;
	}

	return ret;
}

CPais paisAleatorio() {
	
	string cad;
	cad = randomString (16);

	return CPais (cad);
}

CDeporte deporteAleatorio() {
	
	string cad;
	cad = randomString (16);

	return CDeporte (cad);
}