/*
  Fichero para la pr�ctica 3.
  (c) Marco Antonio G�mez Mart�n, 2010
*/
/**
 @file Atleta.h

 \brief Contiene la declaraci�n de la clase CAtleta, que
 guarda la informaci�n de uno de los aletas que
 compiten.
*/
#ifndef _ATLETA_H
#define _ATLETA_H

#include "Pais.h"
#include <string>

/**
 \brief Clase que almacena la informaci�n de un atleta.

 En la pr�ctica, �nicamente guarda su nombre y pa�s de
 procedencia (ambos se inicailizan en el constructor)
 aunque potencialmente podr�a guardar m�s cosas (como por ejemplo
 informaci�n de la fecha de nacimiento, foto, palmar�s, etc.)
*/
class CAtleta {
public:

	/**
	 Constructor de la clase.
	 @param nombre Nombre del atleta.
	 @param pais Pa�s de origen.
	*/
	CAtleta(const std::string &nombre, const CPais &pais) :
			_nombre(nombre),
			_pais(pais) {}

	/// Destructor.
	CAtleta() {}

	/**
	 M�todo para poder acceder al nombre del atleta.
	 @return Nombre del atleta al que representamos.
	*/
	const std::string &getNombre() const { return _nombre; }

	/**
	 M�todo para poder acceder al pa�s de origen del atleta.
	 @return Pa�s de origen del atleta.
	*/
	const CPais &getPais() const { return _pais; }

private:
	std::string _nombre;
	CPais _pais;
};

#endif
