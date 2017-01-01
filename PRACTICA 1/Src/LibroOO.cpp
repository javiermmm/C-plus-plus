#include "LibroOO.h"
#include <iostream>
#include <string>
using namespace std;

//Constructor predeterminado
CLibro::CLibro (string titulo, string autor, TEstado estado) : _titulo(titulo), _autor(autor), _estado(estado) {}

//Constructor por copia
CLibro::CLibro (const CLibro& l) {
	_titulo = l._titulo;
	_autor = l._autor;
	_estado = l._estado;
	_numRegistro = l._numRegistro;
}

//Operador de asignación
CLibro& CLibro::operator= (const CLibro& l) {
	_titulo = l._titulo;
	_autor = l._autor;
	_estado = l._estado;
	_numRegistro = l._numRegistro;

	return *this;
}

//Destructor
CLibro::~CLibro() {}

//ACCEDENTES
string CLibro::dameTitulo() const {
	return _titulo;
}

string CLibro::dameAutor() const{
	return _autor;
}

int CLibro::dameNumRegistro() const{
	return _numRegistro;
}

CLibro::TEstado CLibro::dameEstado() const{
	return _estado;
}

//MUTADORES
void CLibro::ponTitulo (string titulo) {
	_titulo = titulo;
}

void CLibro::ponAutor (string autor) {
	_autor = autor;
}

void CLibro::ponNumRegistro(int numRegistro) {
	_numRegistro = numRegistro;
}

void CLibro::ponEstado (TEstado estado) {
	_estado = estado;
}


//Leemos un libro de teclado, creándolo y devolviéndolo.
CLibro CLibro::leerLibro () {

	CLibro l;
	string respuesta;
	cout << "Introduzca el nombre del autor del libro" << endl;
	getline (cin, l._autor);
	cout << "Introduzca el nombre del libro" << endl;
	getline(cin, l._titulo);
	do {
		cout << "Esta disponible para el préstamo? (si/no)" << endl;
		cin >> respuesta;
	} while ((respuesta != "si") && (respuesta != "no") && (respuesta != "Si") && (respuesta != "No") && (respuesta != "SI") && (respuesta != "NO"));
	if  ((respuesta == "si") || (respuesta == "Si") || (respuesta == "SI")) 
		l._estado = Disponible;
	else
		l._estado = NoDisponible;

	return l;
}

//Mostramos por pantalla un libro
void CLibro::muestraLibro () const {

	cout << _numRegistro << ": " << _titulo << " (" << _autor << ") [";
	if (_estado == Disponible)
		cout << "D]";						//NO añadimos el endl, para que pase los tests
	if (_estado == NoDisponible)
		cout << "ND]";
	if (_estado == Prestado)
		cout << "P]";
}