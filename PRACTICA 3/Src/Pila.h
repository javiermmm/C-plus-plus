#ifndef __CPILA_H
#define __CPILA_H

#include "Excepciones.h"
#include <iostream>

template <class TElem>
class CPila {
public:
	// Constructores, destructor y operador de asignación
	CPila ( );
	CPila ( const CPila<TElem>& );
	~CPila( );
	CPila<TElem>& operator=( const CPila<TElem>& );

	// Operaciones de las pilas
	void push(const TElem&);
	// Pre: true
	// Post: Se añade 'elem' a la cima de la pila

	const TElem& top( ) const;
	// Pre: ! esVacio( )
	// Post: Devuelve el elemento que está en la cima
	// Lanza la excepción TPilaArray<TElem>::Vacio si la pila está vacía

	void pop( );
	// Pre: ! esVacio( )
	// Post: Elimina el elemento que está en la cima
	// Lanza la excepción TPilaArray::Vacio si la pila está vacía

	bool empty( ) const;
	// Pre: true
	// Post: Devuelve true | false según si la pila está o no vacía

	// Comparación
	bool operator==( const CPila& ) const;
	// Pre: true
	// Post: Determina si dos pilas coinciden
protected:

	//NODOPILA------------------------------------
	template <class TElem>
	class CNodoPila {
	private:
		TElem _elem;
		CNodoPila<TElem>* _sig;
		CNodoPila( const TElem& elem, CNodoPila<TElem>* sig = 0 )  : _elem(elem), _sig(sig) {};
	public:
		const TElem& elem() const {return _elem;};
		CNodoPila<TElem> * sig() const {return _sig;};
		friend CPila<TElem>;
	};
	//FIN NODOPILA-------------------------------


	// Variables privadas
	CNodoPila<TElem>* _cima;

	// Operaciones privadas
	void libera();
	void copia(const CPila<TElem>& pila);
};




//IMPLEMENTACIÓN

//Operaciones Privadas
template <class TElem>
void CPila<TElem>::libera() {
	while (_cima != 0) {
		CNodoPila<TElem>* tmp = _cima;
		_cima = _cima->_sig;
		delete tmp;
	}
}

template <class TElem>
void CPila<TElem>::copia(const CPila<TElem>& pila) {
	if ( pila.empty() )
		_cima = 0;
	else {
		CNodoPila<TElem> *antCopia, *actCopia, *act;
		act = pila._cima;
		_cima = new CNodoPila<TElem>( act->_elem, 0 );
		actCopia = _cima;
		while ( act->_sig != 0 ) {
			act = act->_sig;
			antCopia = actCopia;
			actCopia = new CNodoPila<TElem>( act->_elem, 0 );
			antCopia->_sig = actCopia;
		}
	}
};

//Constructores, Destructor y Operador de Asignación
template <class TElem>
CPila<TElem>::CPila( ) : _cima(0) {};

template <class TElem>
CPila<TElem>::CPila( const CPila<TElem>& pila ) {
	copia(pila);
};

template <class TElem>
CPila<TElem>::~CPila( ) {
	libera();
};

template <class TElem>
CPila<TElem>& CPila<TElem>::operator=( const CPila<TElem>& pila ) {
	if( this != &pila ) {
		libera();
		copia(pila);
	}
	return *this;
};

//Introduce un elemento (elem) en la pila
template <class TElem>
void CPila<TElem>::push(const TElem& elem) {
	_cima = new CNodoPila<TElem> ( elem, _cima );
};

//Devuelve el elemento que está en la cima
template <class TElem>
const TElem& CPila<TElem>::top( ) const {
	if( empty() )
		throw EAccesoIndebido();
	else
		return _cima->elem();
};

//Saca un elemento de la pila
template <class TElem>
void CPila<TElem>::pop( ) {
	if( empty() )
		throw EAccesoIndebido();
	else {
		CNodoPila<TElem>* tmp = _cima;
		_cima = _cima->sig();
		delete tmp;
	}
};

//Devuelve si la pila está vacía
template <class TElem>
bool CPila<TElem>::empty( ) const {
	return _cima == 0;
};

#endif