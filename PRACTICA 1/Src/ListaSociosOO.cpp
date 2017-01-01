#include "ListaSociosOO.h"

//Constructor predeterminado
CListaSocios::CListaSocios () {
	_numSocios = 0;
}

//Constructor por copia
CListaSocios::CListaSocios (const CListaSocios &ls) {
	_numSocios = ls._numSocios;
	for (int i = 0; i < _numSocios; ++i)
		_socios[i] = ls._socios[i];
}

//Operador de asignación
CListaSocios& CListaSocios::operator= (const CListaSocios& ls){
	_numSocios = ls._numSocios;
	for (int i = 0; i < _numSocios; ++i)
		_socios[i] = ls._socios[i];

	return *this;
}

//Destructor
CListaSocios::~CListaSocios () {}

//Añadimos el elemento "elto" (un socio) a la lista de socios, realizando inserción ordenada.
//elto [IN]: Nuevo socio que tratamos de añadir. Conceptualmente es un parámetro de entrada, pero lo ponemos como referencia constante por motivos de eficiencia
//Devolvemos un valor booleano que indica si la operación se ha podido realizar o no.
bool CListaSocios::ponElemento (const CSocio &elto) {

	if (_numSocios == MAX_SOCIOS)
		return false;
	else {
		int i = 0;
		bool encontrado = false;
		while (( i < _numSocios) && !encontrado) {
			if (_socios[i].dameNumCodigo() > elto.dameNumCodigo())
				encontrado = true;
			else ++i;
		}

		for (int j = _numSocios-1; j >= i; --j)
			_socios[j+1] = _socios[j];

		_socios[i] = elto;
		++_numSocios;
		return true;
	}

}

//Eliminamos el elemento (un socio) ubicado en la posicion "pos" de la lista de socios. 
//pos [IN]: posición que ocupa el elemento (el socio) que queremos borrar en la lista.
// Devolvemos un valor booleano que indica si la operción se ha podido realizar o no.
bool CListaSocios::borraElemento (int pos) {

	if ((pos < 0) || (pos > _numSocios-1))
		return false;
	else { 
		if (pos < _numSocios-1) {
			for (int i = pos; i < _numSocios-1; ++i)
				_socios[i] = _socios[i+1];
		 }
		--_numSocios;
		return true;
	}
}

//Consultamos el número de elementos de la lista.
//Devolvemos un entero correspondiente a la longitud de la lista.
int CListaSocios::numElems () const {
	
	return _numSocios;
}

//Accedemos al elemento (socio) que ocupa la posicion "i" en la lista y lo devolvemos.
//i [IN]: Posición en la que se encuentra el elemento que vamos a recuperar.
//Devolvemos el socio que ocupa la posición "i" en la lista.
CSocio  CListaSocios::dameElem (int i) const {
	
	if ((i >= 0) && (i < _numSocios))
		return _socios[i];
	else
		return CSocio();
}
