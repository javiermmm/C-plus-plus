#ifndef __EXCEPCIONES_H
#define __EXCEPCIONES_H

#include <string>

//Excepci�n que controla los accesos indebidos (operaciones no v�lidas) de la pila din�mica implementada en Pila.h
class EAccesoIndebido {
public:
	EAccesoIndebido( std::string mensaje = "ERROR" ) : _mensaje(mensaje) {};
	const std::string& mensaje () {return _mensaje;};
private:
	std::string _mensaje;
};

#endif