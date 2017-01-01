#ifndef __EXCEPCIONES_H
#define __EXCEPCIONES_H

#include <string>

//Excepci�n que controla los accesos indebidos (operaciones no v�lidas) de la secuencia din�mica implementada en CSecuencia.h
class EAccesoIndebido {
public:
	EAccesoIndebido( std::string mensaje = "ERROR" ) : _mensaje(mensaje) {};
	const std::string& mensaje () const {return _mensaje;};
private:
	std::string _mensaje;
};

#endif