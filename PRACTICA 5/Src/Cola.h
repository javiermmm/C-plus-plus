#ifndef cola_dinamicaH
#define cola_dinamicaH

#include <iostream>
#include "excepciones.h"
using namespace std;

template <class TElem>
class TColaDinamica;

template <class TElem>
class TNodoCola {
  private:
    TElem _elem;
    TNodoCola<TElem>* _sig;
    TNodoCola( const TElem&, TNodoCola<TElem>* = 0 );
  public:
    const TElem& elem() const;
    TNodoCola<TElem> * sig() const;
    friend TColaDinamica<TElem>;
};

template <class TElem>
class TColaDinamica {
  public:

  // Constructoras, destructora y operador de asignación
     TColaDinamica( );
     // O(1)

     TColaDinamica( const TColaDinamica<TElem>& );
     // O(n' * TElem::TElem(TElem&)), O(n') sobre tipos predefinidos
     // donde n' es el número de elementos de la cola a copiar

     ~TColaDinamica( );
     // O(n * TElem::~TElem()), O(n) sobre tipos predefinidos

     TColaDinamica<TElem>& operator=( const TColaDinamica<TElem>& );
     // O(n * TElem::~TElem() + n' * TElem::TElem(TElem&) ), 
     // O(n+n') sobre tipos predefinidos
     // donde n' es el número de elementos de la cola a asignar


  // Operaciones de las colas
     void ponDetras(const TElem&);
     // Pre: true
     // Post: Se añade 'elem' al final de la cola
     // O(TElem::TElem(TElem&)), O(1) sobre tipos predefinidos

     const TElem& primero( ) const;
     // Pre: ! esVacio( )
     // Post: Devuelve el primer elemento de la cola
     // Lanza la excepción EAccesoIndebido si la cola está vacía
     // O(1)

     void quitaPrim( );
     // Pre: ! esVacio( )
     // Post: Elimina el primer elemento de la cima
     // Lanza la excepción EAccesoIndebido si la cola está vacía
     // O(TElem::~TElem()), O(1) sobre tipos predefinidos

     bool esVacio( ) const;
     // Pre: true
     // Post: Devuelve true | false según si la pila está o no vacía
     // O(1)

  // Escritura
     void escribe( ostream& salida ) const;
     // O(n)

     void escribeLn( ostream& salida ) const;
     // O(n)

  private:
  // Variables privadas
     TNodoCola<TElem> *_prim, *_ult;

  // Operaciones privadas
     void libera();
     void copia(const TColaDinamica<TElem>& pila);
};

//---------------------------------------------------------------------------
// IMPLEMENTACION
//---------------------------------------------------------------------------


  // Clase de los nodos

    template <class TElem>
    TNodoCola<TElem>::TNodoCola( const TElem& elem, TNodoCola<TElem>* sig ) :
      _elem(elem), _sig(sig) {
    };

    template <class TElem>
    const TElem& TNodoCola<TElem>::elem() const {
      return _elem;
    }

    template <class TElem>
    TNodoCola<TElem>* TNodoCola<TElem>::sig() const {
      return _sig;
    }


  // Constructoras, destructora y operador de asignación

     template <class TElem>
     TColaDinamica<TElem>::TColaDinamica( ) :
       _prim(0), _ult(0) {
     };

     template <class TElem>
     TColaDinamica<TElem>::TColaDinamica( const TColaDinamica<TElem>& cola ) {
        copia(cola);
     };

     template <class TElem>
     TColaDinamica<TElem>::~TColaDinamica( ) {
       libera();
     };

     template <class TElem>
     TColaDinamica<TElem>&
     TColaDinamica<TElem>::operator=( const TColaDinamica<TElem>& cola ) {
       if( this != &cola ) {
         libera();
         copia(cola);
       }
       return *this;
     };


  // Operaciones de las colas

     template <class TElem>
     void TColaDinamica<TElem>::ponDetras(const TElem& elem) {
       TNodoCola<TElem>* p = new TNodoCola<TElem>(elem);
       if( _ult != 0 )
         _ult->_sig = p;
       else
         _prim = p;
       _ult = p;
     };

     template <class TElem>
     const TElem& TColaDinamica<TElem>::primero( ) const {
       if( esVacio() )
         throw EAccesoIndebido("Error: no existe el primero de la cola vacía");
       else
         return _prim->elem();
     };

     template <class TElem>
     void TColaDinamica<TElem>::quitaPrim( ) {
       if( esVacio() )
         throw EAccesoIndebido("Error: no se puede quitar el primero de la cola vacía");
       else {
         TNodoCola<TElem>* tmp = _prim;
         _prim = _prim->sig();
         if( _prim == 0 )
           _ult = 0;
         delete tmp;
       }
     };

     template <class TElem>
     bool TColaDinamica<TElem>::esVacio( ) const {
       return _prim == 0;
     };

  // Operaciones de entrada/salida

     template <class TElem>
     void TColaDinamica<TElem>::escribe( ostream& salida ) const {
       TNodoCola<TElem>* tmp = _prim;
       while ( tmp != 0 ) {
         salida << tmp->elem() << endl;
         tmp = tmp->sig();
       }
     };

     template <class TElem>
     void TColaDinamica<TElem>::escribeLn( ostream& salida ) const {
       escribe(salida);
     }

     template <class TElem>
     ostream& operator<< ( ostream& salida, const TColaDinamica<TElem>& cola ) {
       cola.escribe(salida);
       return salida;
     }

     template <class TElem>
     ostream& operator<< ( ostream& salida, const TColaDinamica<TElem>* cola ) {
       cola->escribe(salida);
       return salida;
     }

  // Operaciones privadas

     template <class TElem>
     void TColaDinamica<TElem>::libera() {
       while (_prim != 0) {
         TNodoCola<TElem>* tmp = _prim;
         _prim = _prim->sig();
         delete tmp;
       }
     };

     template <class TElem>
     void TColaDinamica<TElem>::copia(const TColaDinamica<TElem>& cola) {
       if ( cola.esVacio() )
         _prim = _ult = 0;
       else {
         TNodoCola<TElem> *antCopia, *actCopia, *act;
         act = cola._prim;
         _prim = new TNodoCola<TElem>( act->elem(), 0 );
         actCopia = _prim;
         while ( act->sig() != 0 ) {
           act = act->sig();
           antCopia = actCopia;
           actCopia = new TNodoCola<TElem>( act->elem(), 0 );
           antCopia->_sig = actCopia;
         }
         _ult = actCopia;
       }
     };

#endif
