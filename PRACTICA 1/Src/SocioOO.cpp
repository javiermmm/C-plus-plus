#include "SocioOO.h"
#include <iostream>
using namespace std;

//Constructor predeterminado
CSocio::CSocio (string nombre, string apellidos, TTipoSocio tipo, CListaPrestamos lp) : 
				_nombre(nombre), _apellidos(apellidos), _tipoSocio(tipo), _prestamos(lp){}

//Constructor por copia
CSocio::CSocio (const CSocio& s) {
	_nombre = s._nombre;
	_apellidos = s._apellidos;
	_tipoSocio = s._tipoSocio;
	_numCodigo = s._numCodigo;
	_prestamos = (s._prestamos); 
}

//Operador de asignación
CSocio& CSocio::operator= (const CSocio& s) {
	_nombre = s._nombre;
	_apellidos = s._apellidos;
	_tipoSocio = s._tipoSocio;
	_numCodigo = s._numCodigo;
	_prestamos = (s._prestamos);

	return *this;
}

//Destructor
CSocio::~CSocio() {}

//ACCEDENTES
string CSocio::dameNombre() const {
	return _nombre;
}

string CSocio::dameApellidos() const {
	return _apellidos;
}

int CSocio::dameNumCodigo() const {
	return _numCodigo;
}

CSocio::TTipoSocio CSocio::dameTipoSocio() const {
	return _tipoSocio;
}

CListaPrestamos CSocio::damePrestamos() const {
	return _prestamos;
}

//MUTADORES
void CSocio::ponNombre (string nombre) {
	_nombre = nombre;
}

void CSocio::ponApellidos (string apellidos) {
	_apellidos = apellidos;
}

void CSocio::ponCodigo(int numCodigo) {
	_numCodigo = numCodigo;
}

void CSocio::ponTipoSocio (TTipoSocio tipo) {
	_tipoSocio = tipo;
}

void CSocio::ponPrestamos (CListaPrestamos lp) {
	_prestamos = lp;
}

//leemos de teclado un socio, que creamos y devolvemos
CSocio CSocio::leerSocio () {

	CSocio s;
	int op;
	cout << "Introduzca nombre: " << endl;
	getline (cin, s._nombre);
	cout << "Introduzca apellidos: " << endl;
	getline (cin, s._apellidos);

	do {
		cout << "Elija el tipo de socio: (1-3)" << endl;
		cout << "1.- Alumno." << endl;
		cout << "2.- Profesor." << endl;
		cout << "3.- Becario." << endl;
		cin >> op;
	} while ((op < 1) || (op > 3));

	switch (op) {
	case 1: s._tipoSocio = Alumno;
		    break;
	case 2: s._tipoSocio = Profesor;
		    break;
	case 3: s._tipoSocio = Becario;
		    break;
	}

	s._prestamos = CListaPrestamos();

	return s;
}

//Mostramos por pantalla un socio, con el formato especificado
//libros [IN]: lista de libros en la que vamos buscando los libros que el socio tiene prestado. Conceptualmente es un parámetro de entrada, pero lo ponemos como referencia constante por motivos de eficiencia
void CSocio::muestraSocio (const CListaLibros &libros) const {

	cout << endl <<_numCodigo << ": " << _nombre << " " << _apellidos;
	cout << " (";
	if (_tipoSocio == Alumno)
		cout << "Alumno)";
	if (_tipoSocio == Profesor)
		cout << "Profesor)";
	if (_tipoSocio == Becario)
		cout << "Becario)";

	if (_prestamos.numElems()== 0)
		cout << endl << "Sin libros prestados" << endl;
	else {
		for (int i = 0; i < _prestamos.numElems(); ++i) {
			int j = 0;
			bool encontrado = false;
			while ((j < libros.numElems()) && !encontrado) {
				if (libros.dameElem(j).dameNumRegistro() == _prestamos.dameElem(i).dameNumRegistro())
					encontrado = true;
				else
					++j;
			}
			if (encontrado) {
				cout << endl;
				libros.dameElem(j).muestraLibro();
			}
		}
	}
}
