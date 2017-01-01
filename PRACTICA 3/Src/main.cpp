#include "RecorreDirectorio.h"
#include "Pila.h"
#include "ArbolDirectorios.h"
#include <iostream>
#include <string>
using namespace std;

//Función que muestra por pantalla un menú con la ayuda
void ayuda () {

	cout << endl << "Tree.exe -[s|n|t|h] <directorios>" << endl;
	cout << "Parametros:" << endl;
	cout << "        -s: tamaño del directorio." << endl;
	cout << "        -n: arbol del directorio no adornado (sin tamaños)." << endl;
	cout << "        -t: arbol del directorio." << endl;
	cout << "        -h: muestra esta ayuda." << endl << endl;
}

//argc[IN]: representa el numero de argumentos de entrada
//argv[IN]: son los argumentos guardados como cadena
int main (int argc, const char* argv[]) {

	CArbolDirectorios ad;
	if (argc == 1)
		cout << endl << ".: " << ad.tamDirectorio (".") << " bytes" << endl;
	//compara el parametro dado por teclado con las opciones
	if (argc == 2) {
		string param = argv [1];
		if (param == "-h")
			ayuda ();
		if (param == "-s")
				cout << endl << ".: " << ad.tamDirectorio (".") << " bytes" << endl;
		if (param == "-n")		
			ad.escribeArbol (".", cout);			
		if (param == "-t")			
			ad.escribeArbolYTam (".", cout);
	}
	if (argc >=3) {
		string param = argv [1];
		int i = 2;
		//muestra la ayuda
		if (param == "-h")
			ayuda ();
		//Escribe el tamaño del directorio
		if (param == "-s")
			while (i < argc) {
				cout << endl << argv [i] << ": " << ad.tamDirectorio (argv [i]) << " bytes" << endl;
				i++;
			}
		//Escribe el arbol sin el tamaño
		if (param == "-n")
			while (i < argc) {
				ad.escribeArbol (argv [i], cout);
				i++;
			}
		//Escribe el arbol con el tamaño
		if (param == "-t")
			while (i < argc) {
				ad.escribeArbolYTam (argv [i], cout);
				i++;
			}
	}
	
	return 0;
}