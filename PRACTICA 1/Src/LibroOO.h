#ifndef __LIBROOO_H
#define __LIBROOO_H

#include <string>

class CLibro {
public:
	enum TEstado {Disponible, Prestado, NoDisponible};
	//FCO
	CLibro (std::string titulo = "", std::string autor = "", TEstado estado = Disponible);
	CLibro (const CLibro& l);
	CLibro& operator= (const CLibro& l);
	~CLibro();

	//ACCEDENTES
	std::string dameTitulo() const;
	std::string dameAutor() const;
	int dameNumRegistro() const;
	TEstado dameEstado() const;

	//MUTADORES
	void ponTitulo (std::string titulo);
	void ponAutor (std::string autor);
	void ponNumRegistro(int numRegistro);
	void ponEstado (TEstado estado);

	//FUNCIONES
	static CLibro leerLibro ();
	void muestraLibro () const;
protected:
	std::string _titulo;
	std::string _autor;
	int _numRegistro;
	TEstado _estado;
};

#endif