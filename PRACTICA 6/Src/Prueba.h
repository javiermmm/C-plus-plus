/*
  Fichero para la práctica 4.
  (c) Marco Antonio Gómez Martín, 2010
*/
/**
 @file Prueba.h

 \brief Contiene la declaración de la clase CPrueba, que
 guarda la información de una de las pruebas de la
 competición.
*/
#ifndef _PRUEBA_H
#define _PRUEBA_H

#include "Deporte.h"

#include <string>

/**
 \brief Una prueba es una de las modelidades de competición.

 Una prueba está asociada a un deporte (por ejemplo, Atletismo o
 Tenis), y tiene después un título que lo diferencia del resto
 de pruebas para el mismo deporte, por ejemplo "100 metros lisos"
 o "Dobles femenino".
 */
class CPrueba {
public:

	/**
	 Constructor de la clase; recibe el título de la prueba
	 y el deporte al que pertenece.
	 @param titulo Cadena con el título del deporte.
	 @param dep Deporte al que pertenece.
	 */
	CPrueba(const std::string &titulo,
			const CDeporte &dep) : _titulo(titulo), _deporte(dep) {}

	/// Destructor
	CPrueba() {}

	/**
	 Método para poder acceder al título de la prueba.
	 @return Nombre de la prueba.
	*/
	const std::string &getTitulo() const { return _titulo; }

	/**
	 Método para poder acceder al deporte de la prueba.
	 @return Deporte de la prueba.
	*/
	const CDeporte &getDeporte() const { return _deporte; }

	/**
	 Operador de comparación.
	 @param rhs Objeto con el que comparamos.
	 @return true si ambas pruebas son igual (en la práctica, si
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