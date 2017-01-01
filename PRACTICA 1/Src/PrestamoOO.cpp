#include "PrestamoOO.h"

//Constructor Predeterminado
CInfoPrestamo::CInfoPrestamo (CFecha f) : _fechaDev(f) {}

//Constructor parametrizado
CInfoPrestamo::CInfoPrestamo (int numRegistro, CFecha f) : _fechaDev(f), _numRegistro(numRegistro) {}

//Constructor por copia
CInfoPrestamo::CInfoPrestamo (const CInfoPrestamo& p) {
	_numRegistro = p._numRegistro;
	_fechaDev = p._fechaDev;
}

//Operador de asignación
CInfoPrestamo& CInfoPrestamo::operator= (const CInfoPrestamo& p) {
	_numRegistro = p._numRegistro;
	_fechaDev = p._fechaDev;

	return *this;
}

//Destructor
CInfoPrestamo::~CInfoPrestamo() {}

//ACCEDENTES
int CInfoPrestamo::dameNumRegistro() const{
	return _numRegistro;
}

CFecha CInfoPrestamo::dameFecha() const{
	return _fechaDev;
}

//MUTADORES
void CInfoPrestamo::ponNumRegistro (int num) {
	_numRegistro = num;
}

void CInfoPrestamo::ponFecha (CFecha f) {
	_fechaDev = f;
}

//Comprobamos si el libro relacionado con el prestamo en cuestión se encuentra en la lista de libros "libros",
//y si es así, devolvemos los datos de dicho libro mediante "infoLibroPrestado"
//libros [IN]: lista de libros en la que buscaremos si el libro relacionado con el prestamo está o no.  Conceptualmente es un parámetro de entrada, pero lo ponemos como referencia constante por motivos de eficiencia
//infoLibroPrestado [OUT]: Libro que contendrá la informacion del libro que buscabamos, en caso de haberlo encontrado, y en caso contrario, no modificará su estado.
//Devolvemos un valor booleano que indica si hemos encontrado el libro o no.
bool CInfoPrestamo::libroPrestado (const CListaLibros &libros, CLibro &infoLibroPrestado) const{

	int i = 0;
	bool encontrado = false;
	while ((i < libros.numElems()) && !encontrado) {
		if (libros.dameElem(i).dameNumRegistro () == _numRegistro) {
			encontrado = true;
			infoLibroPrestado = libros.dameElem(i);
		}
		else 
			++i;
	}
	return encontrado;
}