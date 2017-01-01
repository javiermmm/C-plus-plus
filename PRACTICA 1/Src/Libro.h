#ifndef __LIBRO_H
#define __LIBRO_H

#include <string>

enum TEstado {Disponible, Prestado, NoDisponible};

struct TLibro {
	std::string titulo;
	std::string autor;
	int numRegistro;
	TEstado estado;
};

//FUNCIONES
TLibro leerLibro ();
void muestraLibro (const TLibro &libro);


#endif