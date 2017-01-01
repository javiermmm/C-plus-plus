#ifndef __CARBOLDIRECTORIOS_H
#define __CARBOLDIRECTORIOS_H

#include <string>
#include "RecorreDirectorio.h"
#include "Pila.h"

class CArbolDirectorios {
public:
	static unsigned long tamDirectorio (const std::string &ruta);
	static void escribeArbol (const std::string &ruta, std::ostream &output);
	static void escribeArbolYTam (const std::string &ruta, std::ostream &output);
private:
	static unsigned long CArbolDirectorios::tamDirectorioAux (const std::string &ruta, unsigned long& tamTotal);																  //¿static?
	static void escribeArbolAux (const std::string &ruta, std::ostream &output, std::string nombrePantalla, int numBlancos);														  //¿static?
	//static void rellenaPilaRecursiones (const std::string &ruta, CPila<std::string>& pila);
	static unsigned long escribeArbolYTamAux (const std::string &ruta, CPila<std::string>& pilaRes, std::string nombrePantalla, int numBlancos);   //¿static?
};

#endif