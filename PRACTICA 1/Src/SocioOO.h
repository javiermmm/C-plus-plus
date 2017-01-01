#ifndef __SOCIOOO_H
#define __SOCIOOO_H
#include <string>
#include "ListaPrestamosOO.h"
#include "ListaLibrosOO.h"

class CSocio {
public:
	enum TTipoSocio {Alumno, Profesor, Becario};
	//FCO
	CSocio (std::string nombre = "", std::string apellidos = "", TTipoSocio tipo = Alumno, CListaPrestamos lp = CListaPrestamos());
	CSocio (const CSocio& l);
	CSocio& operator= (const CSocio& l);
	~CSocio();

	//ACCEDENTES
	std::string dameNombre() const;
	std::string dameApellidos() const;
	int dameNumCodigo() const;
	TTipoSocio dameTipoSocio() const;
	CListaPrestamos damePrestamos() const;

	//MUTADORES
	void ponNombre (std::string nombre);
	void ponApellidos (std::string apellidos);
	void ponCodigo(int numCodigo);
	void ponTipoSocio (TTipoSocio tipo);
	void ponPrestamos (CListaPrestamos lp);

	//FUNCIONES
	static CSocio leerSocio (); 
	void muestraSocio (const CListaLibros &libros) const; 
protected:
	std::string _nombre;
	std::string _apellidos;
	int _numCodigo;
	TTipoSocio _tipoSocio;
	CListaPrestamos _prestamos;
};




#endif