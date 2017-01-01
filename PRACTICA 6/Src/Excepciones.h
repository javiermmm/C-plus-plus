#ifndef __EXCEPCIONES_H
#define __EXCEPCIONES_H

#include <string>

//Clases que implementan los distintos tipos de excepciones 
//lanzadas por los TAD usados (Secuencia y Tablas Abierta y Cerrada)

class EDesbordamiento {
  public:
    EDesbordamiento( std::string mensaje = "" ) : _mensaje(mensaje) { };
    std::string mensaje ( ) const {
      return _mensaje;
    };
  private:
    std::string _mensaje;
};

class EAccesoIndebido {
  public:
    EAccesoIndebido( std::string mensaje = "" ) : _mensaje(mensaje) { };
    std::string mensaje ( ) const {
      return _mensaje;
    };
  private:
    std::string _mensaje;
};

class EClaveErronea {
  public:
    EClaveErronea( std::string mensaje = "" ) : _mensaje(mensaje) { };
    std::string mensaje ( ) const {
      return _mensaje;
    };
  private:
    std::string _mensaje;
};

#endif