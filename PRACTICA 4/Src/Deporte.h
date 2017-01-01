/*
  Fichero para la pr�ctica 4.
  (c) Marco Antonio G�mez Mart�n, 2010
*/
/**
 @file Deporte.h

 \brief Contiene la declaraci�n de la clase CDeporte, que
 guarda la informaci�n de uno de los deportes en los que
 se compite.
*/
#ifndef _DEPORTE_H
#define _DEPORTE_H

#include <string>

/**
 \brief Clase que almacena la informaci�n de un deporte.

 En la pr�ctica, �nicamente guarda su nombre
 (que se inicializa con el constructor), aunque
 potencialmente podr�a guardar m�s cosas (como por ejemplo
 un dibujo para utilizarlo en los res�menes, etc.).
*/
class CDeporte {
public:

	/**
	 Constructor de la clase.
	 @param nombre Nombre del deporte al que representa el objeto.
	*/
	CDeporte(const std::string &nombre) : _nombre(nombre) {}

	/// Constructor sin par�metros; se supone que se establecer�
	/// el nombre con setNombre().
	CDeporte() {};

	/// Destructor.
	~CDeporte() {}

	/**
	 M�todo para poder acceder al nombre del deporte.
	 @return Nombre del deporte al que representamos.
	*/
	const std::string &getNombre() const { return _nombre; }

	/**
	 M�todo para cambiar el nombre del deporte.
	 @param nombre Nuevo nombre del deporte.
	 */
	void setNombre(const std::string &nombre) { _nombre = nombre; }

	// Operaciones de comparaci�n

	/**
	 Operador de comparaci�n.
	 @param rhs Objeto con el que comparamos.
	 @return true si ambas pruebas son igual (en la pr�ctica,
	 se comparan los nombres).
	*/
	bool operator==(const CDeporte &rhs) const { return _nombre == rhs._nombre; }

	/**
	 Operador de comparaci�n.
	 @param rhs Objeto con el que comparamos.
	 @return true si ambas pruebas son distintas (en la pr�ctica,
	 se comparan los nombres).
	*/
	bool operator!=(const CDeporte &rhs) const { return _nombre != rhs._nombre; }

private:

	/// Atributo con el nombre.
	std::string _nombre;
};

#endif
