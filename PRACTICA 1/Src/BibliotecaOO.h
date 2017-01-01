#ifndef __BIBLIOTECAOO_H
#define __BIBLIOTECAOO_H

#include "ListaLibrosOO.h"
#include "ListaSociosOO.h"


class CBiblioteca {
public:
	//FCO
	CBiblioteca ();
	CBiblioteca (const CBiblioteca& b);
	CBiblioteca& operator= (const CBiblioteca& b);
	~CBiblioteca ();

	//ACCEDENTES
	CListaLibros dameLibros () const;

	//FUNCIONES
	bool anyadeLibro (const CLibro &nuevoLibro);
	bool buscaLibroPorRegistro (int numRegistro, CLibro &libro) const;
	bool borraLibro (int numRegistro);
	void muestraLibros () const;
	bool anyadeSocio (const CSocio &nuevoSocio);
	bool buscaSocioPorCodigo (int numCodigo, CSocio &socio) const;
	bool borraSocio (int numCodigo);
	void muestraSocios () const;
	bool presta (int codigoSocio, int codigoLibro, const CFecha &f);
	bool devuelve (int codigoSocio, int codigoLibro);
	bool quienTiene (int codigoLibro, CSocio &s) const;
	void muestraPrestamos () const;
protected:
	CListaLibros _libros;
	CListaSocios _socios;
private:
	int _contLibros; //Este campo sirve para llevar el conteo de los libros, ya que a cada nuevo libro que se añada se le asigna el número de regitro consecutivo al último asignado (Empezando en 1).
	int _contSocios; //Este campo sirve para llevar el conteo de los socios, ya que a cada nuevo socio que se añada se le asigna el código de regitro consecutivo al último asignado (Empezando en 101).

	//FUNCIONES AUXILIARES
	bool buscaSocio ( const CListaSocios &socios, int codigoSocio, int &pos) const;
	bool buscaLibro ( const CListaLibros &libros, int codigoLibro, int &pos) const;
	bool buscaPrestamo ( const CListaPrestamos &prestamos, int codigoLibro, int &pos) const;
	void procesaPrestamo (int pos, int pos2, CLibro &li, CSocio & so, const CFecha &f);
	void procesaDevolución (int posLibro, int posSocio, int posPrestamo, CLibro &li, CSocio & so);
};				    
				    
#endif