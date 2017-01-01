#include "Socio.h"
#include <iostream>
#include <string>
using namespace std;

//Inicializamos el estado de un socio
//s [IN-OUT]: socio que queremos inicializar
void inicializaSocio (TSocio &s){

	s.apellidos = "";
	s.nombre = "";
	inicializaLista (s.prestamos);
	s.tipoSocio = Alumno;
}

//leemos de teclado un socio, que creamos y devolvemos
TSocio leerSocio (){

	TSocio s;
	int op;
	cout << "Introduzca nombre: " << endl;
	getline(cin, s.nombre);
	cout << "Introduzca apellidos: " << endl;
	getline(cin, s.apellidos);

	do {
		cout << "Elija el tipo de socio: (1-3)" << endl;
		cout << "1.- Alumno." << endl;
		cout << "2.- Profesor." << endl;
		cout << "3.- Becario." << endl;
		cin >> op;
	} while ((op < 1) || (op > 3));

	switch (op) {
	case 1: s.tipoSocio = Alumno;
		    break;
	case 2: s.tipoSocio = Profesor;
		    break;
	case 3: s.tipoSocio = Becario;
		    break;
	}

	inicializaLista (s.prestamos);

	return s;
}

//Mostramos por pantalla un socio dado, con el formato especificado
//socio [IN]: socio que mostramos. Conceptualmente es un parámetro de entrada, pero lo ponemos como referencia constante por motivos de eficiencia
//libros [IN]: lista de libros en la que vamos buscando los libros que el socio tiene prestado. Conceptualmente es un parámetro de entrada, pero lo ponemos como referencia constante por motivos de eficiencia
void muestraSocio (const TSocio &socio, const TListaLibros &libros){

	cout << endl << socio.numCodigo << ": " << socio.nombre << " " << socio.apellidos;
	cout << " (";
	if (socio.tipoSocio == Alumno)
		cout << "Alumno)";
	if (socio.tipoSocio == Profesor)
		cout << "Profesor)";
	if (socio.tipoSocio == Becario)
		cout << "Becario)";

	if (numElems (socio.prestamos) == 0)
		cout << endl << "Sin libros prestados" << endl;
	else {
		for (int i = 0; i < numElems (socio.prestamos); ++i) {
			int j = 0;
			bool encontrado = false;
			while ((j < numElems (libros)) && !encontrado) {
				if (dameElem (libros, j).numRegistro == dameElem (socio.prestamos, i).numRegistro)
					encontrado = true;
				else
					++j;
			}
			if (encontrado) {
				cout << endl;
				muestraLibro (dameElem(libros, j));
			}
		}
	}
}