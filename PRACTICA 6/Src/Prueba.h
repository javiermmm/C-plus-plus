/*
  Fichero para la pr�ctica 4.
  (c) Marco Antonio G�mez Mart�n, 2010
*/
/**
 @file Prueba.h

 \brief Contiene la declaraci�n de la clase CPrueba, que
 guarda la informaci�n de una de las pruebas de la
 competici�n.
*/
#ifndef _PRUEBA_H
#define _PRUEBA_H

#include "Deporte.h"

#include <string>

/**
 \brief Una prueba es una de las modelidades de competici�n.

 Una prueba est� asociada a un deporte (por ejemplo, Atletismo o
 Tenis), y tiene despu�s un t�tulo que lo diferencia del resto
 de pruebas para el mismo deporte, por ejemplo "100 metros lisos"
 o "Dobles femenino".
 */
class CPrueba {
public:

	/**
	 Constructor de la clase; recibe el t�tulo de la prueba
	 y el deporte al que pertenece.
	 @param titulo Cadena con el t�tulo del deporte.
	 @param dep Deporte al que pertenece.
	 */
	CPrueba(const std::string &titulo,
			const CDeporte &dep) : _titulo(titulo), _deporte(dep) {}

	/// Destructor
	CPrueba() {}

	/**
	 M�todo para poder acceder al t�tulo de la prueba.
	 @return Nombre de la prueba.
	*/
	const std::string &getTitulo() const { return _titulo; }

	/**
	 M�todo para poder acceder al deporte de la prueba.
	 @return Deporte de la prueba.
	*/
	const CDeporte &getDeporte() const { return _deporte; }

	/**
	 Operador de comparaci�n.
	 @param rhs Objeto con el que comparamos.
	 @return true si ambas pruebas son igual (en la pr�ctica, si
	 tienen el mismo nombre).
	*/
	bool operator==(const CPrueba &rhs) const { return _titulo == rhs._titulo; }

	//Funcion de localizacion
	int num () { return _deporte.num();}

private:
	std::string _titulo;

	CDeporte _deporte;
};

#endif