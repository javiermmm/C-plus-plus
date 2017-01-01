#ifndef __EXCEPCIONES_H
#define __EXCEPCIONES_H

#include <string>

//Excepción que controla los accesos indebidos (operaciones no válidas) de la pila dinámica implementada en Pila.h
class EAccesoIndebido {
public:
	EAccesoIndebido( std::string mensaje = "ERROR" ) : _mensaje(mensaje) {};
	const std::string& mensaje () {return _mensaje;};
private:
	std::string _mensaje;
};

#endif