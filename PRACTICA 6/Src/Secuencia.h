#ifndef __SECUENCIA_H
#define __SECUENCIA_H

#include <iostream>
#include "excepciones.h"

template <class TElem>
class CSecuencia;

template <class TElem>
class CNodoSecuencia {
  private:
    TElem _elem;
    CNodoSecuencia<TElem>* _sig;
    CNodoSecuencia( );
    CNodoSecuencia( const TElem&, CNodoSecuencia<TElem>* = 0);
  public:
    const TElem& elem() const;
    CNodoSecuencia<TElem> * sig() const;
    friend CSecuencia<TElem>;
};

template <class TElem>
class CSecuencia {
  public:

  // Constructoras, destructora y operador de asignación
     CSecuencia ();
     // O( TElem::TElem() ), O(1) sobre tipos predefinidos
     
     CSecuencia (const CSecuencia<TElem>&);
     // O( n' * TElem::TElem(TElem&) ), O(n') sobre tipos predefinidos
     // siendo n' el número de elementos de la secuencia a copiar

     ~CSecuencia ();
     // O( n * TElem::~TElem() ), O(n) sobre tipos predefinidos

     CSecuencia<TElem>& operator= ( const CSecuencia<TElem>& );
     // O( n * TElem::~TElem() + n' * TElem::TElem(TElem&) ),
     // O( n + n' ) sobre tipos predefinidos
     // siendo n' el número de elementos de la secuencia a asignar

  // Operaciones de las secuencias
     void inserta (const TElem&);
     // Pre: true
     // Post: Se añade un elemento a la secuencia, delante del punto de interés
     // O( TElem::TElem(TElem&) ), O(1) sobre tipos predefinidos

     void borra ();
     // Pre: ! esFin( )
     // Post: Elimina el elemento que está detrás del punto de interés
     // Lanza la excepción EAccesoIndebido si el punto de interés está al final
     // O( TElem::~TElem() ), O(1) sobre tipos predefinidos

     const TElem& actual () const;
     // Pre: ! esFin( )
     // Post: Devuelve el elemento a continuación del punto de interés
     // Lanza la excepción EAccesoIndebido si el punto de interés está al final
     // O(1)

     void avanza ();
     // Pre: ! esFin( )
     // Post: Avanza una posición el punto de interés
     // Lanza la excepción EAccesoIndebido si el punto de interés está al final
     // O(1)

     void reinicia ();
     // Pre: true
     // Post: Coloca el punto de interés al principio de la secuencia
     // O(1)

     bool esFin () const;
     // Pre: true
     // Post: Determina si el punto de interés está al final de la secuencia
     // O(1)

     bool esVacio () const;
     // Pre: true
     // Post: Determina si la secuencia está vacía
     // O(1)

	 int numElems () const;
	 // Pre: true
	 // Post: Determina el número de elementos de la secuencia
	 // O(n)

  protected:
  // Variables privadas
     CNodoSecuencia<TElem> *_pri, *_ant;
	 int _numElems;

  // Operaciones privadas
     void libera();
     void copia( const CSecuencia<TElem>& );
};

//---------------------------------------------------------------------------
// IMPLEMENTACION
//---------------------------------------------------------------------------


  // Clase de los nodos

    // Es necesaria una constructora sin parámetros (sin elem) para poder
    // construir el nodo fantasma. El campo _elem de ese nodo contendrá
    // basura si se trata de un tipo primitivo o el resultado de llamar
    // a la constructora por defecto si no lo es.
    template <class TElem>
    CNodoSecuencia<TElem>::CNodoSecuencia () : _sig(0) {
    };

    template <class TElem>
    CNodoSecuencia<TElem>::CNodoSecuencia (const TElem& elem,
                                           CNodoSecuencia<TElem>* sig) :
      _elem(elem), _sig(sig) {
    };

    template <class TElem>
    const TElem& CNodoSecuencia<TElem>::elem () const {
      return _elem;
    }

    template <class TElem>
    CNodoSecuencia<TElem>* CNodoSecuencia<TElem>::sig () const {
      return _sig;
    }


  // Constructoras, destructora y operador de asignación

     template <class TElem>
     CSecuencia<TElem>::CSecuencia () {
       _pri = _ant = new CNodoSecuencia<TElem>();
	   _numElems = 0;
     };

     template <class TElem>
     CSecuencia<TElem>::CSecuencia (const CSecuencia<TElem>& secuencia) {
        copia(secuencia);
     };

     template <class TElem>
     CSecuencia<TElem>::~CSecuencia () {
       libera();
     };

     template <class TElem>
     CSecuencia<TElem>&
     CSecuencia<TElem>::operator= (const CSecuencia<TElem>& secuencia) {
       if( this != &secuencia ) {
         libera();
         copia(secuencia);
       }
       return *this;
     };


  // Operaciones de las secuencias

     template <class TElem>
     void CSecuencia<TElem>::inserta (const TElem& elem) {
       CNodoSecuencia<TElem>* nuevo = new CNodoSecuencia<TElem> ( elem, _ant->sig() );
       _ant->_sig = nuevo;
       _ant = nuevo;
	   _numElems++;
     };

     template <class TElem>
     const TElem& CSecuencia<TElem>::actual () const {
       if( esFin() )
         throw EAccesoIndebido("Error: el punto de interés está al final");
       return _ant->sig()->elem();
     };

     template <class TElem>
     void CSecuencia<TElem>::borra () {
       if( esFin() )
         throw EAccesoIndebido("Error: el punto de interés está al final");
       CNodoSecuencia<TElem>* act = _ant->sig();
       _ant->_sig = act->sig();
       delete act;
	   _numElems--;
     };

     template <class TElem>
     void CSecuencia<TElem>::avanza () {
       if( esFin() )
         throw EAccesoIndebido("Error: el punto de interés está al final");
       _ant = _ant->sig();
     };

     template <class TElem>
     void CSecuencia<TElem>::reinicia () {
       _ant = _pri;
     };

     template <class TElem>
     bool CSecuencia<TElem>::esFin () const {
       return _ant->sig() == 0;
     };

     template <class TElem>
     bool CSecuencia<TElem>::esVacio () const {
       return _numElems == 0;
     };

	 template <class TElem>
	 int CSecuencia<TElem>::numElems () const {
		 return _numElems;
		 /*
		 int contador = 0;
		 CNodoSecuencia<TElem>* tmp = _pri;
		 while (tmp->sig() != 0) {
			contador++;
			tmp = tmp->sig();
		 }
		 return contador;
		 */
	 };

/*
  // Operaciones de entrada/salida

     template <class TElem>
     void CSecuencia<TElem>::escribe( ostream & salida ) const {
       if ( _pri == _ant ) salida << "<--" << endl;
       CNodoSecuencia<TElem>* tmp = _pri->sig();
       while ( tmp != 0 ) {
         salida << tmp->elem() << endl;
         if ( tmp == _ant ) salida << "<--" << endl;
         tmp = tmp->sig();
       }
     };

     template <class TElem>
     void CSecuencia<TElem>::escribeLn( ostream & salida ) const {
       escribe(salida);
     }

     template <class TElem>
     ostream& operator<<( ostream& salida, const CSecuencia<TElem>& sec ) {
       sec.escribe(salida);
       return salida;
     };
*/
  // Operaciones privadas

     template <class TElem>
     void CSecuencia<TElem>::libera() {
       while ( _pri != 0 ){
         _ant = _pri;
         _pri = _pri->sig();
         delete _ant;
       }
     };

     template <class TElem>
     void CSecuencia<TElem>::copia(const CSecuencia<TElem>& secuencia) {
       CNodoSecuencia<TElem> *antCopia, *actCopia, *act;
       act = secuencia._pri;
       actCopia = _ant = _pri = new CNodoSecuencia<TElem>( );
       while ( act->sig() != 0 ) {
         act = act->sig();
         antCopia = actCopia;
         actCopia = new CNodoSecuencia<TElem>( act->elem(), 0 );
         if ( secuencia._ant == act ) _ant = actCopia;
         antCopia->_sig = actCopia;
       }
	   _numElems = secuencia._numElems;
     };

#endif