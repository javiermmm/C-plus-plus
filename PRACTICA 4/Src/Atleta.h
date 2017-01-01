/*
  Fichero para la práctica 3.
  (c) Marco Antonio Gómez Martín, 2010
*/
/**
 @file Atleta.h

 \brief Contiene la declaración de la clase CAtleta, que
 guarda la información de uno de los aletas que
 compiten.
*/
#ifndef _ATLETA_H
#define _ATLETA_H

#include "Pais.h"
#include <string>

/**
 \brief Clase que almacena la información de un atleta.

 En la práctica, únicamente guarda su nombre y país de
 procedencia (ambos se inicailizan en el constructor)
 aunque potencialmente podría guardar más cosas (como por ejemplo
 información de la fecha de nacimiento, foto, palmarés, etc.)
*/
class CAtleta {
public:

	/**
	 Constructor de la clase.
	 @param nombre Nombre del atleta.
	 @param pais País de origen.
	*/
	CAtleta(const std::string &nombre, const CPais &pais) :
			_nombre(nombre),
			_pais(pais) {}

	/// Destructor.
	CAtleta() {}

	/**
	 Método para poder acceder al nombre del atleta.
	 @return Nombre del atleta al que representamos.
	*/
	const std::string &getNombre() const { return _nombre; }

	/**
	 Método para poder acceder al país de origen del atleta.
	 @return País de origen del atleta.
	*/
	const CPais &getPais() const { return _pais; }

private:
	std::string _nombre;
	CPais _pais;
};

#endif
