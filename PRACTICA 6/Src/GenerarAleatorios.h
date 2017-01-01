#ifndef _GENERARALEATORIOS__H
#define _GENERARALEATORIOS__H

#include "Pais.h"
#include "Deporte.h"
#include <string>

//Este método genera una cadena de caracteres aleatoria, de longitud, el parámetro (en la cabecera j).
//j [IN]: longitud que va a tener la cadena generada
//Se devuelve la cadena ya generada
std::string randomString (int j);

//Este método utiliza el método anterior para generar un pais aleatorio cuyo nombre sea una cadena aleatoria
//Se devuelve un país construido a partir de su nombre (aleatorio)
CPais paisAleatorio();

//Este método utiliza el método anterior para generar un deporte aleatorio cuyo nombre sea una cadena aleatoria
//Se devuelve un deporte construido a partir de su nombre (aleatorio)
CDeporte deporteAleatorio();


#endif