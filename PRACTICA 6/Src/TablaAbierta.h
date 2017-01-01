#ifndef __TABLA_ABIERTA_H
#define __TABLA_ABIERTA_H

#include "excepciones.h"
#include "Localizacion.h"
#include "Pareja.h"
#include "Secuencia.h"
#include <iostream>

// Excepciones generadas por las operaciones de este TAD
// Acceso cuando se accede con una clave que no está en la tabla
// class EClaveErronea { };

// El tipo TClave debe implementar
//    operator==
//    int TClave::num() const

template <class TClave, class TValor>
class CTablaAbierta;

template <class TClave, class TValor>
class CNodoTablaAbierta {
  private:
    TClave _clave;
    TValor _valor;
    CNodoTablaAbierta<TClave,TValor> *_sig;
    CNodoTablaAbierta( const TClave&, const TValor&, CNodoTablaAbierta<TClave,TValor>* );
  public:
    const TClave& clave() const;
    const TValor& valor() const;
    CNodoTablaAbierta<TClave,TValor> * sig() const;
    friend CTablaAbierta<TClave,TValor>;
};

template <class TClave, class TValor>
class CTablaAbierta {
  public:

  // Constructoras, destructora y operador de asignación
     CTablaAbierta( );
     CTablaAbierta( const CTablaAbierta<TClave,TValor>& );
     ~CTablaAbierta( );
     CTablaAbierta<TClave,TValor>& operator=( const CTablaAbierta<TClave,TValor>& );

  // Operaciones de las tablas
     void inserta( const TClave&, const TValor& );
     // Pre : true
     // Post : inserta un par (clave, valor),
     //        si la clave ya está, se sustituye el valor antiguo

     void borra( const TClave& );
     // Pre : true
     // Post : elimina un par (clave, valor) a partir de una clave dada,
     //        si la clave no está, la tabla no se modifica

     // observadoras
     const TValor& consulta( const TClave& ) const;
     // Pre : esta( clave )
     // Post : devuelve el valor asociado con la clave dada
     // Lanza la excepción EClaveErronea si la tabla no contiene dicha clave

     bool esta( const TClave& ) const;
     // Pre : true
     // Post : devuelve true | false según si la tabla contiene o no la clave

     bool esVacio( ) const;
     // Pre: true
     // Post: Devuelve true | false según si la tabla está o no vacía

	 CSecuencia< CPareja<TClave, TValor> > enumera( ) const;
     // Pre: true
     // Post: Devuelve una secuencia de parejas con los elementos de la tabla

  // Escritura
     void escribe( std::ostream& salida ) const;

  private:
  // Variables privadas
     static const int longMax = 10000;
     CNodoTablaAbierta<TClave,TValor>* _espacio[longMax];

  // Operaciones privadas
     void libera();
     void copia( const CTablaAbierta<TClave,TValor>& );
  // función hash
     int localiza( const TClave&) const;
  // función auxiliar de búsqueda del nodo con una clave dada
     void busca ( const TClave&, CNodoTablaAbierta<TClave,TValor>* &,
                  CNodoTablaAbierta<TClave,TValor>* & ) const;


};

//---------------------------------------------------------------------------
// IMPLEMENTACION
//---------------------------------------------------------------------------


  // Clase de los nodos

    template <class TClave, class TValor>
    CNodoTablaAbierta<TClave,TValor>::CNodoTablaAbierta( const TClave& clave,
                                           const TValor& valor,
                                           CNodoTablaAbierta<TClave,TValor>* sig = 0 ) :
      _clave(clave), _valor(valor), _sig(sig) {
    };

    template <class TClave, class TValor>
    const TClave& CNodoTablaAbierta<TClave,TValor>::clave() const {
      return _clave;
    }

    template <class TClave, class TValor>
    const TValor& CNodoTablaAbierta<TClave,TValor>::valor() const {
      return _valor;
    }

    template <class TClave, class TValor>
    CNodoTablaAbierta<TClave,TValor>* CNodoTablaAbierta<TClave,TValor>::sig() const {
      return _sig;
    }

  // Constructoras, destructora y operador de asignación

     template <class TClave, class TValor>
     CTablaAbierta<TClave,TValor>::CTablaAbierta( ) {
       for ( int i = 0; i < longMax; i++ )
         _espacio[i] = 0; 
     };

     template <class TClave, class TValor>
     CTablaAbierta<TClave,TValor>::CTablaAbierta( const CTablaAbierta<TClave,TValor>& tabla ) {
        copia(tabla);
     };

     template <class TClave, class TValor>
     CTablaAbierta<TClave,TValor>::~CTablaAbierta( ) {
       libera();
     };

     template <class TClave, class TValor>
     CTablaAbierta<TClave,TValor>&
     CTablaAbierta<TClave,TValor>::operator=( const CTablaAbierta<TClave,TValor>& tabla ) {
       if( this != &tabla ) {
         libera();
         copia(tabla);
       }
       return *this;
     };


  // Operaciones de las tablas

     // Inserción
     template <class TClave, class TValor>
     void CTablaAbierta<TClave,TValor>::inserta( const TClave& clave,
                                                 const TValor& valor ) {
       int i;
       CNodoTablaAbierta<TClave,TValor> *act, *ant;
       i = localiza( clave );
       act = _espacio[i];
       busca( clave, act, ant );
       if ( act != 0 )
         act->_valor = valor;
       else {
         act = new CNodoTablaAbierta<TClave,TValor>(clave, valor, _espacio[i]);
         _espacio[i] = act;
       }
     };

     // Borrado
     template <class TClave, class TValor>
     void CTablaAbierta<TClave,TValor>::borra( const TClave& clave ) {
       int i;
       CNodoTablaAbierta<TClave,TValor> *act, *ant;

       i = localiza(clave);
       act = _espacio[i];
       busca( clave, act, ant );
       if ( act != 0 ) {
         if ( ant != 0 )
           ant->_sig = act->sig();
         else
           _espacio[i] = act->sig();
         delete act;
       }
     };

     // Consultas
     template <class TClave, class TValor>
     const TValor& CTablaAbierta<TClave,TValor>::consulta( const TClave& clave ) const {

       int i;
       CNodoTablaAbierta<TClave,TValor> *act, *ant;

       i = localiza(clave);
       act = _espacio[i];
       busca( clave, act, ant );
       if ( act == 0 )
         throw EClaveErronea();
       return act->valor();
     };

     template <class TClave, class TValor>
     bool CTablaAbierta<TClave,TValor>::esta( const TClave& clave ) const {
       int i;
       CNodoTablaAbierta<TClave,TValor> *act, *ant;

       i = localiza(clave);
       act = _espacio[i];
       busca( clave, act, ant );
       return act != 0;
     };

     template <class TClave, class TValor>
     bool CTablaAbierta<TClave,TValor>::esVacio( ) const {
       int i = 0;
       bool vacio = true;

       while ( vacio && (i < longMax) ) {
         vacio = _espacio[i] == 0;
         i++;
       }
       return vacio;
     };

	 template <class TClave, class TValor>
	 CSecuencia< CPareja<TClave, TValor> > CTablaAbierta<TClave,TValor>::enumera( ) const {

		 CSecuencia< CPareja<TClave, TValor> > res;
		 CNodoTablaAbierta<TClave,TValor> *tmp;
		 for (int i = 0; i<longMax; ++i) {
			 tmp = _espacio[i];
			 while (tmp != 0) {
				 res.inserta(CPareja<TClave, TValor> (tmp->clave(), tmp->valor()));
				 tmp = tmp->sig();
			 }
		 }

		 return res;
	 }

  // Operaciones de entrada/salida

     template <class TClave, class TValor>
     void CTablaAbierta<TClave,TValor>::escribe( std::ostream& salida ) const {
       CNodoTablaAbierta<TClave,TValor> *act;

       for ( int i = 0; i < longMax; i++ ) {
         act = _espacio[i];
         salida << i << ":";
         while ( act != 0 ) {
           salida << "(" << act->clave() << ", " << act->valor() << + ")";
           act = act->sig();
         }
         salida << endl;
       }
     };

  // Operaciones privadas

     // anulación
     template <class TClave, class TValor>
     void CTablaAbierta<TClave,TValor>::libera() {
       int i;
       CNodoTablaAbierta<TClave,TValor> *act, *aux;

       for ( i = 0; i < longMax; i++ ) {
         act = _espacio[i];
         while ( act != 0 ) {
          aux = act->sig();
          delete act;
          act = aux;
         }
       }
     };

     // copia
     template <class TClave, class TValor>
     void CTablaAbierta<TClave,TValor>::copia(const CTablaAbierta<TClave,TValor>& tabla) {
       CNodoTablaAbierta<TClave,TValor> *act, *actCopia, *antCopia;

       for ( int i = 0; i < longMax; i++ ) {
         if ( tabla._espacio[i] != 0 ) {
           act = tabla._espacio[i];
           actCopia = new CNodoTablaAbierta<TClave,TValor>(act->clave(), act->valor());
           _espacio[i] = actCopia;
           while ( act->sig() != 0 ) {
             act = act->sig();
             antCopia = actCopia;
             actCopia = new CNodoTablaAbierta<TClave,TValor>(act->clave(), act->valor());
             antCopia->_sig = actCopia;
           }
         }
         else
           _espacio[i] = 0;
       }
     };

     // función hash
     template <class TClave, class TValor>
     int CTablaAbierta<TClave,TValor>::localiza( const TClave& clave) const {
//       return clave.num() % longMax;
        return num(clave) % longMax;
     };

     // función auxiliar de búsqueda del nodo con una clave dada
     template <class TClave, class TValor>
     void CTablaAbierta<TClave,TValor>::busca( const TClave& clave,
                                               CNodoTablaAbierta<TClave,TValor>* & act,
                                               CNodoTablaAbierta<TClave,TValor>* & ant ) const {
       bool encontrado = false;

       ant = 0;
       while ((! encontrado) && (act != 0) ) {
         encontrado = clave == act->clave();
         if ( ! encontrado ) {
           ant = act;
           act = act->sig();
         }
       }
     };


#endif
