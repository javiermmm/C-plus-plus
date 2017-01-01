#ifndef __TABLA_CERRADA_H
#define __TABLA_CERRADA_H

#include <iostream>
#include "Localizacion.h"
#include "excepciones.h"
#include "Secuencia.h"
#include "Pareja.h"

// Posibles longitudes del array donde se almacena la tabla
//
const int maxLongitudes = 9;
const int longitudes[maxLongitudes] = { 43, 103, 229, 463, 1021, 2029, 4093, 8093, 16831};

// Excepciones generadas por las operaciones de este TAD
// Acceso cuando se accede con una clave que no está en la tabla
//class EClaveErronea { };
// Inserción cuando el array está lleno
//class EDesbordamiento { };

// El tipo TClave debe implementar
//    operator==
//    int TClave::num() const

template <class TClave, class TValor>
class CTablaCerrada;

enum TPosicion {vacia, ocupada, borrada};

template <class TClave, class TValor>
class CNodoTablaCerrada {
  private:
    TClave _clave;
    TValor _valor;
    TPosicion _posicion;
    CNodoTablaCerrada( );
  public:
    const TClave& clave() const;
    const TValor& valor() const;
    const TPosicion& posicion() const;
    friend CTablaCerrada<TClave,TValor>;
};

template <class TClave, class TValor>
class CTablaCerrada {
  public:

  // Constructoras, destructora y operador de asignación
     CTablaCerrada( );
     CTablaCerrada( const CTablaCerrada<TClave,TValor>& );
     ~CTablaCerrada( );
     CTablaCerrada<TClave,TValor>& operator=( const CTablaCerrada<TClave,TValor>& );

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

     int numElem( ) const;
     // Pre: true
     // Post: Devuelve el número de elementos almacenados en la tabla

     CSecuencia< CPareja<TClave, TValor> > enumera( ) const;
     // Pre: true
     // Post: Devuelve una secuencia de parejas con los elementos de la tabla

     CSecuencia<TClave> enumeraClave( ) const;
     // Pre: true
     // Post: Devuelve una secuencia con las claves de la tabla

     CSecuencia<TValor> enumeraValor( ) const;
     // Pre: true
     // Post: Devuelve una secuencia con los valores de la tabla

  // Escritura
     void escribe( std::ostream& salida ) const;

  private:
  // Variables privadas
     static const int ocupacion = 50;  // en tanto por ciento
     CNodoTablaCerrada<TClave,TValor>* _espacio;
     int _numElem, _numBorradas, _longitud;

  // Operaciones privadas
     void libera();
     void copia( const CTablaCerrada<TClave,TValor>& );
  // función auxiliar de búsqueda del nodo con una clave dada
     int busca ( const TClave& ) const;
  // Reagrupa las posiciones de la tabla para eliminar las posiciones borradas
     void limpia ();
  // Hace crecer el array donde se almacena la tabla
     void amplia ();
};


//---------------------------------------------------------------------------
// IMPLEMENTACION
//---------------------------------------------------------------------------


  // Clase de los nodos

    template <class TClave, class TValor>
    CNodoTablaCerrada<TClave,TValor>::CNodoTablaCerrada( ) :
      _posicion(vacia) {};

    template <class TClave, class TValor>
    const TClave& CNodoTablaCerrada<TClave,TValor>::clave() const {
      return _clave;
    }

    template <class TClave, class TValor>
    const TValor& CNodoTablaCerrada<TClave,TValor>::valor() const {
      return _valor;
    }

    template <class TClave, class TValor>
    const TPosicion& CNodoTablaCerrada<TClave,TValor>::posicion() const {
      return _posicion;
    }

  // Constructoras, destructora y operador de asignación

     template <class TClave, class TValor>
     CTablaCerrada<TClave,TValor>::CTablaCerrada( ) :
       _numElem(0), _numBorradas(0), _longitud(0),
       _espacio(new CNodoTablaCerrada<TClave,TValor>[longitudes[0]]) {
     };

     template <class TClave, class TValor>
     CTablaCerrada<TClave,TValor>::CTablaCerrada( const CTablaCerrada<TClave,TValor>& tabla ) {
        copia(tabla);
     };

     template <class TClave, class TValor>
     CTablaCerrada<TClave,TValor>::~CTablaCerrada( ) {
       libera();
     };

     template <class TClave, class TValor>
     CTablaCerrada<TClave,TValor>&
     CTablaCerrada<TClave,TValor>::operator=( const CTablaCerrada<TClave,TValor>& tabla ) {
       if( this != &tabla ) {
         libera();
         copia(tabla);
       }
       return *this;
     };


  // Operaciones de las tablas

     // Inserción
     template <class TClave, class TValor>
     void CTablaCerrada<TClave,TValor>::inserta( const TClave& clave,
                                                 const TValor& valor ) {
       int i, n, d, m;
       bool encontrado;

       if ( ( (_numElem + _numBorradas) * 100 / longitudes[_longitud] ) > ocupacion )
//         limpia();
         amplia();
       n = num(clave);
       i = n % longitudes[_longitud];
       d = (n % (longitudes[_longitud]-2)) + 1;
       m = 0; //contabiliza el número de pruebas por si la tabla está llena
       encontrado = false;
       while ( ( ! encontrado ) && (_espacio[i].posicion() == ocupada) && (m < longitudes[_longitud]) ) {
         if ( _espacio[i]._posicion == ocupada )
           encontrado = clave == _espacio[i].clave();
         if ( ! encontrado ) {
           m++;
           i = (i + d) % longitudes[_longitud];
         }
       }
       if ( m == longitudes[_longitud] )
         throw EDesbordamiento();
       else if ( encontrado )
         _espacio[i]._valor = valor;
       else if ( _espacio[i].posicion() == vacia ) {
         _espacio[i]._clave = clave;
         _espacio[i]._valor = valor;
         _espacio[i]._posicion = ocupada;
         _numElem++;
       }
       else if ( _espacio[i].posicion() == borrada ) {
         _espacio[i]._clave = clave;
         _espacio[i]._valor = valor;
         _espacio[i]._posicion = ocupada;
         _numElem++;
         _numBorradas--;
         m++;
         i = (i + d) % longitudes[_longitud];
         while ( ( ! encontrado ) && (_espacio[i].posicion() != vacia) && (m < longitudes[_longitud]) ) {
           if ( _espacio[i].posicion() == ocupada )
             encontrado = clave == _espacio[i].clave();
           if ( ! encontrado ) {
             m++;
             i = (i + d) % longitudes[_longitud];
           }
         }
         if ( encontrado ) {
           _espacio[i]._posicion = borrada;
           _numBorradas++;
         }
       }
     };

     // Borrado
     template <class TClave, class TValor>
     void CTablaCerrada<TClave,TValor>::borra( const TClave& clave ) {
       int i;

       i = busca(clave);
       if ( i != longitudes[_longitud] ) {
         _espacio[i]._posicion = borrada;
         _numElem--;
         _numBorradas++;
       }
     };

     // Consultas
     template <class TClave, class TValor>
     const TValor& CTablaCerrada<TClave,TValor>::consulta( const TClave& clave ) const {
       int i;

       i = busca(clave);
       if ( i == longitudes[_longitud] )
         throw EClaveErronea();
       return _espacio[i].valor();
     };

     template <class TClave, class TValor>
     bool CTablaCerrada<TClave,TValor>::esta( const TClave& clave ) const {
       int i;

       i = busca(clave);
       return i != longitudes[_longitud];
     };

     template <class TClave, class TValor>
     bool CTablaCerrada<TClave,TValor>::esVacio( ) const {
       return _numElem == 0;
     };

     template <class TClave, class TValor>
     int CTablaCerrada<TClave,TValor>::numElem( ) const {
       return _numElem;
     };

     template <class TClave, class TValor>
     CSecuencia< CPareja<TClave, TValor> >
     CTablaCerrada<TClave,TValor>::enumera( ) const {
       CSecuencia< CPareja<TClave, TValor> > resultado;

       for ( int i = 0; i < longitudes[_longitud]; i++ ) {
         if ( _espacio[i].posicion() == ocupada )
           resultado.inserta( CPareja<TClave,TValor>( _espacio[i].clave(),
                                                      _espacio[i].valor()  ) );
       }
       return resultado;
     };

     template <class TClave, class TValor>
     CSecuencia<TClave>
     CTablaCerrada<TClave,TValor>::enumeraClave( ) const {
       CSecuencia< TClave > resultado;

       for ( int i = 0; i < longitudes[_longitud]; i++ ) {
         if ( _espacio[i].posicion() == ocupada )
           resultado.inserta( _espacio[i].clave() );
       }
       return resultado;
     };

     template <class TClave, class TValor>
     CSecuencia<TValor>
     CTablaCerrada<TClave,TValor>::enumeraValor( ) const {
       CSecuencia< TValor > resultado;

       for ( int i = 0; i < longitudes[_longitud]; i++ ) {
         if ( _espacio[i].posicion() == ocupada )
           resultado.inserta( _espacio[i].valor() );
       }
       return resultado;
     };

  // Operaciones de entrada/salida

     template <class TClave, class TValor>
     void CTablaCerrada<TClave,TValor>::escribe( std::ostream& salida ) const {

       for ( int i = 0; i < longitudes[_longitud]; i++ ) {
         salida << i << ":";
         if ( _espacio[i].posicion() == ocupada )
           salida << "(" << _espacio[i].clave() << ", " << _espacio[i].valor()<< ")";
         else if ( _espacio[i].posicion() == borrada )
           salida << "###";
         salida << endl;
       }
     };

  // Operaciones privadas

     // anulación
     template <class TClave, class TValor>
     void CTablaCerrada<TClave,TValor>::libera() {
       delete [] _espacio;
     };

     // copia
     template <class TClave, class TValor>
     void CTablaCerrada<TClave,TValor>::copia(const CTablaCerrada<TClave,TValor>& tabla) {
       _longitud = tabla._longitud;
       _espacio = new CNodoTablaCerrada<TClave,TValor>[longitudes[_longitud]];
       for ( int i = 0; i < longitudes[_longitud]; i++ ) {
         _espacio[i]._posicion = tabla._espacio[i]._posicion;
         if ( _espacio[i]._posicion == ocupada ) {
           _espacio[i]._clave = tabla._espacio[i].clave();
           _espacio[i]._valor = tabla._espacio[i].valor();
         }
       }
       _numElem = tabla._numElem;
       _numBorradas = tabla._numBorradas;
     };

     // función auxiliar de búsqueda del nodo con una clave dada
     template <class TClave, class TValor>
     int CTablaCerrada<TClave,TValor>::busca( const TClave& clave ) const {
       int i, n, d, m;
       bool encontrado;

//       n = clave.num();
       n = num(clave);
       i = n % longitudes[_longitud];
       d = (n % (longitudes[_longitud]-2)) + 1;
       m = 0; //contabiliza el número de pruebas por si la tabla está llena
       encontrado = false;
       while ( (! encontrado) && (_espacio[i].posicion() != vacia) && (m < longitudes[_longitud]) ) {
         if ( _espacio[i]._posicion == ocupada )
           encontrado = clave == _espacio[i].clave();
         if ( ! encontrado ) {
           m++;
           i = (i + d) % longitudes[_longitud];
         }
       }
       if ( ! encontrado )
         i = longitudes[_longitud];
       return i;
     };

     // función auxiliar que limpia la tabla
     //
     //  h(clave) = num(clave) % longitudes[_longitud]
     //  k(clave) = d = (num(clave) % (longitudes[_longitud]-2)) + 1
     //
     //  i_0 = h(clave)
     //  i_m = (i_m-1 + d) % longitudes[_longitud]
     //
     //  i_m-1 = i_m - d        si i_m -d >= 0
     //  i_m-1 = N + i_m - d    si i_m -d < 0
     //
     //
     template <class TClave, class TValor>
     void CTablaCerrada<TClave,TValor>::limpia( ) {
       int n, i_0, i_m, d, pos;
       bool movimiento = true;

       while ( movimiento ) {
         movimiento = false;
         for (int i = 0; i < longitudes[_longitud]; i++ )
           if ( _espacio[i].posicion() == ocupada ) {
             n = num(_espacio[i].clave());
             i_0 = n % longitudes[_longitud];
             d = (n % (longitudes[_longitud]-2)) + 1;
             pos = i_m = i;
             while ( i_m != i_0 ) {
               if ( (i_m - d) >= 0 )
                 i_m = i_m - d;
               else
                 i_m = longitudes[_longitud] + i_m - d;
               if ( _espacio[i_m].posicion() == borrada )
                 pos = i_m;
             }
             if ( pos != i ) {
               _espacio[pos]._clave = _espacio[i].clave();
               _espacio[pos]._valor = _espacio[i].valor();
               _espacio[pos]._posicion = ocupada;
               _espacio[i]._posicion = borrada;
               movimiento = true;
             }
           }
       }
       for (int i = 0; i < longitudes[_longitud]; i++ )
         if ( _espacio[i].posicion() == borrada )
           _espacio[i]._posicion = vacia;
       _numBorradas = 0;
     }

     template <class TClave, class TValor>
     void CTablaCerrada<TClave,TValor>::amplia( ) {
       if ( _longitud < (maxLongitudes - 1) ) {
         _longitud++;
         CNodoTablaCerrada<TClave,TValor> *aux = _espacio;
         _espacio = new CNodoTablaCerrada<TClave,TValor>[longitudes[_longitud]];
         _numBorradas = _numElem = 0;
         for ( int i = 0; i < longitudes[_longitud-1]; i++ )
           if ( aux[i].posicion() == ocupada )
             inserta(aux[i].clave(), aux[i].valor());
         delete [] aux;
       }
     }

     template <class TClave, class TValor>
     std::ostream& operator<< ( std::ostream& salida, const CTablaCerrada<TClave,TValor>& tabla ) {
       CSecuencia< CPareja<TClave,TValor> > aux = tabla.enumera();
       salida << aux << endl;
       return salida;
     }

     template <class TClave, class TValor>
     std::ostream& operator<< ( std::ostream& salida, const CTablaCerrada<TClave,TValor>* tabla ) {
       CSecuencia< CPareja<TClave,TValor> > aux = tabla->enumera();
       salida << aux << endl;
       return salida;
     }

/*     template <class TClave, class TValor>
     ostream& operator<< ( ostream& salida, const CTablaCerrada<TClave,TValor>& tabla ) {
       tabla.escribe(salida);
       return salida;
     }

     template <class TClave, class TValor>
     ostream& operator<< ( ostream& salida, const CTablaCerrada<TClave,TValor>* tabla ) {
       tabla->escribe(salida);
       return salida;
     }
*/

#endif