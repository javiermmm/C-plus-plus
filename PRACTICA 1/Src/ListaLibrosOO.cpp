#include "ListaLibrosOO.h"

//Constructor predeterminado
CListaLibros::CListaLibros () {
	_numLibros = 0;
}

//Constructor por copia
CListaLibros::CListaLibros (const CListaLibros& lb) {
	_numLibros = lb._numLibros;
	for (int i = 0; i < _numLibros; ++i)
		_libros[i] = lb._libros[i];
}

//Operador de asignación
CListaLibros& CListaLibros::operator= (const CListaLibros& lb) {
	_numLibros = lb._numLibros;
	for (int i = 0; i < _numLibros; ++i)
		_libros[i] = lb._libros[i];

	return *this;
}

//Destructor
CListaLibros::~CListaLibros () {}

//Añadimos el elemento "elto" (un libro) a la lista de libros, realizando inserción ordenada.
//elto [IN]: Nuevo libro que tratamos de añadir. Conceptualmente es un parámetro de entrada, pero lo ponemos como referencia constante por motivos de eficiencia
//Devolvemos un valor booleano que indica si la operación se ha podido realizar o no.
bool CListaLibros::ponElemento (const CLibro &elto) {

	if (_numLibros == MAX_LIBROS)
		return false;
	else {
		int i = 0;
		bool encontrado = false;
		while (( i < _numLibros) && !encontrado) {
			if (_libros[i].dameNumRegistro() > elto.dameNumRegistro())
				encontrado = true;
			else ++i;
		}

		for (int j = _numLibros-1; j >= i; --j)
			_libros[j+1] = _libros[j];

		_libros[i] = elto;
		++_numLibros;
		return true;
	}
}

//Eliminamos el elemento (un libro) ubicado en la posicion "pos" de la lista de libros. 
//pos [IN]: posición que ocupa el elemento (el libro) que queremos borrar en la lista.
//Devolvemos un valor booleano que indica si la operción se ha podido realizar o no.
bool CListaLibros::borraElemento (int pos){

	if ((pos < 0) || (pos > _numLibros-1))
		return false;
	else { 
		if (pos < _numLibros-1) {
			for (int i = pos; i < _numLibros-1; ++i)
				_libros[i] = _libros[i+1];
		 }
		--_numLibros;
		return true;
	}
}

//Consultamos el número de elementos de la lista.
//Devolvemos un entero correspondiente a la longitud de la lista.
int CListaLibros::numElems () const{
	return _numLibros;
}

//Accedemos al elemento (libro) que ocupa la posicion "i" en la lista y lo devolvemos.
//i [IN]: Posición en la que se encuentra el elemento que vamos a recuperar.
//Devolvemos el libro que ocupa la posición "i" en la lista.
CLibro CListaLibros::dameElem (int i) const {

	if ((i >= 0) && (i < _numLibros))
		return _libros[i];
	else
		return CLibro();
}