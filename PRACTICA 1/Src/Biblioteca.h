#ifndef __BIBLIOTECA_H
#define __BIBLIOTECA_H

#include "ListaLibros.h"
#include "ListaSocios.h"


struct TBiblioteca {
	TListaLibros libros;
	TListaSocios socios;
	int contLibros; //Este campo sirve para llevar el conteo de los libros, ya que a cada nuevo libro que se añada se le asigna el número de regitro consecutivo al último asignado (Empezando en 1).
	int contSocios;	//Este campo sirve para llevar el conteo de los socios, ya que a cada nuevo socio que se añada se le asigna el código de regitro consecutivo al último asignado (Empezando en 101).
};				    
				    

//FUNCIONES
void inicializaBiblioteca (TBiblioteca &bib);
bool anyadeLibro (TBiblioteca &biblio, const TLibro &nuevoLibro);
bool buscaLibroPorRegistro (const TBiblioteca &biblio, int numRegistro, TLibro &libro);
bool borraLibro (TBiblioteca &biblio, int numRegistro);
void muestraLibros (const TBiblioteca &biblio);
bool anyadeSocio (TBiblioteca &biblio, const TSocio &nuevoSocio);
bool buscaSocioPorCodigo (const TBiblioteca &biblio, int numCodigo, TSocio &socio);
bool borraSocio (TBiblioteca &biblio, int numCodigo);
void muestraSocios (const TBiblioteca &biblio);
bool presta (TBiblioteca &b, int codigoSocio, int codigoLibro, const TFecha &f);
bool devuelve (TBiblioteca &b, int codigoSocio, int codigoLibro);
bool quienTiene (const TBiblioteca &b, int codigoLibro, TSocio &s);
void muestraPrestamos (const TBiblioteca &b);

#endif