#include "Arbol.h"
#include "Juego.h"
#include <fstream>
#include <iostream>
#include <vld.h>
using namespace std;

//Menu Principal
int menu() {

	cout << endl << endl;
	cout << "1.- Jugar" << endl;
	cout << "2.- Grabar base de conocimiento" << endl;
	cout << "3.- Cargar base de conocimiento" << endl;
	cout << "4.- Reproducir ultima partida" << endl;
	cout << "5.- Salir" << endl;
	cout << endl << endl;
	cout << "Introduzca una opcion de las anteriores:" << endl << endl;
	int op;
	cin >> op;
	cin.ignore();
	cout << endl << endl;

	return op;
}

int main() {

	CJuego juego = CJuego();
	int op;

	do {
		//Mostrar menu
		op = menu();

		//Evaluar opciones
		switch (op) {
			case 1: juego.jugar();
					break;

			case 2: juego.grabar();
					break;

			case 3: juego.cargar();
					break;

			case 4: juego.reproducir();
					break;
		}
	} while (op != 5);

	return 0;
}