#ifndef __EXCEPCIONES_H
#define __EXCEPCIONES_H

#include <string>

//Excepci�n que controla los accesos indebidos (operaciones no v�lidas) a los TAD's
class EAccesoIndebido {
public:
	EAccesoIndebido( std::string mensaje = "ERROR" ) : _mensaje(mensaje) {};
	inline const std::string& mensaje () const {return _mensaje;};
private:
	std::string _mensaje;
};


//Excepci�n que controla los deserializaci�n de TAD's, es decir, cuando se recupera su estado de disco
class EFormatoIncorrecto {
public:
	EFormatoIncorrecto( std::string mensaje = "" ) : _mensaje(mensaje) {};
	inline const std::string& mensaje () const {return _mensaje;};
private:
	std::string _mensaje;
};


#endif