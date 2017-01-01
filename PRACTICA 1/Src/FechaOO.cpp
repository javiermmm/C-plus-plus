#include "FechaOO.h"
#include <iostream>
using namespace std;

//Inicializamos la fecha utilizando el dia, mes y año que nos pasan como argumentos
//dia, mes, anyo [IN]: Son los datos que queremos que tenga la fecha
CFecha::CFecha (int  dia,  int  mes,  int  anyo) : _dia(dia), _mes(mes), _anyo(anyo) {}

//Inicializamos la fecha a partir de los datos del parámetro "f"
//f [IN]: Es la fecha que se va a copiar. Conceptualmente es de entrada pero lo ponemos como referencia constante por motivos de eficiencia.
CFecha::CFecha (const CFecha &f) {
	_dia = f._dia;
	_mes = f._mes;
	_anyo = f._anyo;
}

//Operador de igualdad
//f [IN]: Es la fecha que se va a copiar. Conceptualmente es de entrada pero lo ponemos como referencia constante por motivos de eficiencia.
CFecha& CFecha::operator= (const CFecha &f) {
	_dia = f._dia;
	_mes = f._mes;
	_anyo = f._anyo;

	return *this;
}

//Destructor
CFecha::~CFecha () {}

//Mostramos por pantalla la fecha con el formato dd/mm/aaaa
void CFecha::muestraFecha () const {
	cout << _dia << "/" << _mes << "/" << _anyo;
}

//leermos de teclado los datos de una fecha, que creamos y devolvemos
CFecha CFecha::leerFecha (){
	
	CFecha f;
	cout << "Introduzca el dia"<<endl;
	cin >> f._dia;
	cout << "Introduzca el mes"<<endl;
	cin >> f._mes;
	cout << "Introduzca el año"<<endl;
	cin >> f._anyo;

	return f;
}