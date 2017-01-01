/*
  Fichero para la pr�ctica 4.
  (c) Marco Antonio G�mez Mart�n, 2010
*/
/**
 @file Pais.h

 \brief Contiene la declaraci�n de la clase CPais, que
 guarda la informaci�n de un pa�s participante en
 las competiciones.
*/
#ifndef _PAIS_H
#define _PAIS_H

#include <string>
#include "Localizacion.h"


/**
 \brief Clase que almacena la informaci�n de un pa�s.

 En la pr�ctica, �nicamente guarda el nombre de ese
 pa�s (que se inicializa con el constructor), aunque
 potencialmente podr�a guardar m�s cosas (como por ejemplo
 la bandera, el himno, etc.).
*/
class CPais {
public:

	/**
	 Constructor de la clase.
	 @param nombre Nombre del pa�s al que representa el objeto.
	*/
	CPais(const std::string &nombre) : _nombre(nombre) {}

	/// Constructor sin par�metros; se supone que se establecer�
	/// el nombre con setNombre().
	CPais() {};

	/// Destructor.
	~CPais() {}

	/**
	 M�todo para cambiar el nombre del pa�s.
	 @param nombre Nuevo nombre del pa�s.
	 */
	void setNombre(const std::string &nombre) { _nombre = nombre; }

	/**
	 M�todo para poder acceder al nombre del pa�s.
	 @return Nombre del pa�s al que representamos.
	*/
	const std::string &getNombre() const { return _nombre; }

	// Operaciones de comparaci�n

	/**
	 Operador de comparaci�n.
	 @param rhs Objeto con el que comparamos.
	 @return true si ambas pruebas son igual (en la pr�ctica,
	 se comparan los nombres).
	*/
	bool operator==(const CPais &rhs) const { return _nombre == rhs._nombre; }

	/**
	 Operador de comparaci�n.
	 @param rhs Objeto con el que comparamos.
	 @return true si ambas pruebas son distintas (en la pr�ctica,
	 se comparan los nombres).
	*/
	bool operator!=(const CPais &rhs) const { return _nombre != rhs._nombre; }

	/**
	 Operador de comparaci�n.
	 @param rhs Objeto con el que comparamos.
	 @return true si el objeto impl�cito (<code>this</code>) es menor que
	 el par�metro (en la pr�ctica, se comparan los nombres).
	*/
	bool operator<(const CPais &rhs) const { return _nombre < rhs._nombre; }

	//Funcion de localizacion
	int num () const { return ::num(_nombre);}

private:

	/// Atributo con el nombre.
	std::string _nombre;
};

#endif
