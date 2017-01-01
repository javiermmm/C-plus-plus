#include "ListaPrestamosOO.h"

//Constructor predeterminado
CListaPrestamos::CListaPrestamos () {
	_numPrestamos = 0;
}

//Constructor por copia
CListaPrestamos::CListaPrestamos (const CListaPrestamos& lp) {
	_numPrestamos= lp._numPrestamos;
	for (int i = 0; i < _numPrestamos; ++i)
		_prestamos[i] = lp._prestamos[i];
}

//Operador de asignaci�n
CListaPrestamos& CListaPrestamos::operator= (const CListaPrestamos& lp) {
	_numPrestamos = lp._numPrestamos;
	for (int i = 0; i < _numPrestamos; ++i)
		_prestamos[i] = lp._prestamos[i];

	return *this;
}

//Destructor
CListaPrestamos::~CListaPrestamos () {}

//A�adimos el elemento "elto" (un prestamo) a la lista de prestamos, coloc�ndolo por el final.
//elto [IN]: Nuevo prestamo que tratamos de a�adir. Conceptualmente es un par�metro de entrada, pero lo ponemos como referencia constante por motivos de eficiencia
//Devolvemos un valor booleano que indica si la operaci�n se ha podido realizar o no.
bool CListaPrestamos::ponElemento (const CInfoPrestamo &elto) {

	if (_numPrestamos == MAX_PRESTAMOS)
		return false;
	else {
		_prestamos[_numPrestamos] = elto;
		++_numPrestamos;
		return true;
	}
}

//Eliminamos el elemento (un prestamo) ubicado en la posicion "pos" de la lista de prestamos.
//pos [IN]: posici�n que ocupa el elemento (el prestamo) que queremos borrar en la lista.
// Devolvemos un valor booleano que indica si la operci�n se ha podido realizar o no.
bool CListaPrestamos::borraElemento (int pos) {

	if ((pos < 0) || (pos > _numPrestamos-1))
		return false;
	else { 
		if (pos < _numPrestamos-1) {
			for (int i = pos; i < _numPrestamos-1; ++i)
				_prestamos[i] = _prestamos[i+1];
		 }
		--_numPrestamos;
		return true;
	}
}

//Consultamos el n�mero de elementos de la lista.
//Devolvemos un entero correspondiente a la longitud de la lista.
int CListaPrestamos::numElems () const {
	return _numPrestamos;
}

//Accedemos al elemento (prestamo) que ocupa la posicion "i" en la lista y lo devolvemos.
//i [IN]: Posici�n en la que se encuentra el elemento que vamos a recuperar.
//Devolvemos el prestamo que ocupa la posici�n "i" en la lista.
CInfoPrestamo CListaPrestamos::dameElem (int i) const {

	if ((i >= 0) && (i < _numPrestamos))
		return _prestamos[i];
	else
		return CInfoPrestamo();
}