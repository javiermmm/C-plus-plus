/*
  Fichero para la práctica 4.
  (c) Marco Antonio Gómez Martín, 2010
*/
/**
 @file Deporte.h

 \brief Contiene la declaración de la clase CDeporte, que
 guarda la información de uno de los deportes en los que
 se compite.
*/
#ifndef _DEPORTE_H
#define _DEPORTE_H

#include <string>

/**
 \brief Clase que almacena la información de un deporte.

 En la práctica, únicamente guarda su nombre
 (que se inicializa con el constructor), aunque
 potencialmente podría guardar más cosas (como por ejemplo
 un dibujo para utilizarlo en los resúmenes, etc.).
*/
class CDeporte {
public:

	/**
	 Constructor de la clase.
	 @param nombre Nombre del deporte al que representa el objeto.
	*/
	CDeporte(const std::string &nombre) : _nombre(nombre) {}

	/// Constructor sin parámetros; se supone que se establecerá
	/// el nombre con setNombre().
	CDeporte() {};

	/// Destructor.
	~CDeporte() {}

	/**
	 Método para poder acceder al nombre del deporte.
	 @return Nombre del deporte al que representamos.
	*/
	const std::string &getNombre() const { return _nombre; }

	/**
	 Método para cambiar el nombre del deporte.
	 @param nombre Nuevo nombre del deporte.
	 */
	void setNombre(const std::string &nombre) { _nombre = nombre; }

	// Operaciones de comparación

	/**
	 Operador de comparación.
	 @param rhs Objeto con el que comparamos.
	 @return true si ambas pruebas son igual (en la práctica,
	 se comparan los nombres).
	*/
	bool operator==(const CDeporte &rhs) const { return _nombre == rhs._nombre; }

	/**
	 Operador de comparación.
	 @param rhs Objeto con el que comparamos.
	 @return true si ambas pruebas son distintas (en la práctica,
	 se comparan los nombres).
	*/
	bool operator!=(const CDeporte &rhs) const { return _nombre != rhs._nombre; }

private:

	/// Atributo con el nombre.
	std::string _nombre;
};

#endif
