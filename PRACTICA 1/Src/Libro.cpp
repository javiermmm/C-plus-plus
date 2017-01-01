#include "Libro.h"
#include <iostream>
#include <string>
using namespace std;

//Leemos un libro de teclado, cre�ndolo y devolvi�ndolo.
TLibro leerLibro () {

	TLibro l;
	string respuesta;
	cout << "Introduzca el nombre del autor del libro" << endl;
	getline(cin, l.autor);
	cout << "Introduzca el nombre del libro" << endl;
	getline (cin, l.titulo);
	do {
		cout << "Esta disponible para el pr�stamo? (si/no)" << endl;
		cin >> respuesta;
	} while ((respuesta != "si") && (respuesta != "no") && (respuesta != "Si") && (respuesta != "No") && (respuesta != "SI") && (respuesta != "NO"));
	if  ((respuesta == "si") || (respuesta == "Si") || (respuesta == "SI")) 
		l.estado = Disponible;
	else
		l.estado = NoDisponible;

	return l;
}

//Mostramos por pantalla el libro dado como par�metro
//libro [IN]: libro que vamos a mostrar. Conceptualmente es un par�metro de entrada, pero lo ponemos como referencia constante por motivos de eficiencia.
void muestraLibro (const TLibro &libro) {

	cout << libro.numRegistro << ": " << libro.titulo << " (" << libro.autor << ") [";
	if (libro.estado == Disponible) 
		cout << "D]";				                // NO A�adimos endl, para que pase los tests
	if (libro.estado == NoDisponible)
		cout << "ND]";
	if (libro.estado == Prestado)
		cout << "P]" ;
}