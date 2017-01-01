#ifndef __SOCIO_H
#define __SOCIO_H
#include <string>
#include "ListaPrestamos.h"
#include "ListaLibros.h"

enum TTipoSocio {Alumno, Profesor, Becario};

struct TSocio {
	std::string nombre;
	std::string apellidos;
	int numCodigo;
	TTipoSocio tipoSocio;
	TListaPrestamos prestamos;
};

//FUNCIONES
void inicializaSocio (TSocio &s); 
TSocio leerSocio (); 
void muestraSocio (const TSocio &socio, const TListaLibros &libros); 



#endif