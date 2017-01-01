/*
  Fichero para la práctica 4.
  (c) Marco Antonio Gómez Martín, 2010
*/
/**
 @file Pais.h

 \brief Contiene la declaración de la clase CPais, que
 guarda la información de un país participante en
 las competiciones.
*/
#ifndef _PAIS_H
#define _PAIS_H

#include <string>
#include "Localizacion.h"


/**
 \brief Clase que almacena la información de un país.

 En la práctica, únicamente guarda el nombre de ese
 país (que se inicializa con el constructor), aunque
 potencialmente podría guardar más cosas (como por ejemplo
 la bandera, el himno, etc.).
*/
class CPais {
public:

	/**
	 Constructor de la clase.
	 @param nombre Nombre del país al que representa el objeto.
	*/
	CPais(const std::string &nombre) : _nombre(nombre) {}

	/// Constructor sin parámetros; se supone que se establecerá
	/// el nombre con setNombre().
	CPais() {};

	/// Destructor.
	~CPais() {}

	/**
	 Método para cambiar el nombre del país.
	 @param nombre Nuevo nombre del país.
	 */
	void setNombre(const std::string &nombre) { _nombre = nombre; }

	/**
	 Método para poder acceder al nombre del país.
	 @return Nombre del país al que representamos.
	*/
	const std::string &getNombre() const { return _nombre; }

	// Operaciones de comparación

	/**
	 Operador de comparación.
	 @param rhs Objeto con el que comparamos.
	 @return true si ambas pruebas son igual (en la práctica,
	 se comparan los nombres).
	*/
	bool operator==(const CPais &rhs) const { return _nombre == rhs._nombre; }

	/**
	 Operador de comparación.
	 @param rhs Objeto con el que comparamos.
	 @return true si ambas pruebas son distintas (en la práctica,
	 se comparan los nombres).
	*/
	bool operator!=(const CPais &rhs) const { return _nombre != rhs._nombre; }

	/**
	 Operador de comparación.
	 @param rhs Objeto con el que comparamos.
	 @return true si el objeto implícito (<code>this</code>) es menor que
	 el parámetro (en la práctica, se comparan los nombres).
	*/
	bool operator<(const CPais &rhs) const { return _nombre < rhs._nombre; }

	//Funcion de localizacion
	int num () const { return ::num(_nombre);}

private:

	/// Atributo con el nombre.
	std::string _nombre;
};

#endif
