#ifndef arbin_dinamicoH
#define arbin_dinamicoH

#include <iostream>
#include <fstream>
#include <string>
#include "secuencia.h"
#include "cola.h"
#include "excepciones.h"

using namespace std;

template <class TElem>
class CArbol;

template <class TElem>
class TNodoArbin {
  private:
    TElem _elem;
    TNodoArbin<TElem> *_iz, *_dr;
    TNodoArbin( const TElem&, TNodoArbin<TElem>*, TNodoArbin<TElem>* );
  public:
    const TElem& elem() const;
    TNodoArbin<TElem> * iz() const;
    TNodoArbin<TElem> * dr() const;
    friend CArbol<TElem>;
};

template <class TElem>
class CArbol
{
  public:

  // Constructoras, destructora y operador de asignación
     CArbol( );
	 inline CArbol (const TElem &e);
     inline CArbol( const CArbol<TElem>& );
     ~CArbol( );
     inline CArbol<TElem>& operator=( const CArbol<TElem>& );

  // Operaciones de los árboles
     inline CArbol<TElem> hijoIz ( ) const;
     // Pre : ! esVacio( )
     // Post : devuelve una copia del subárbol izquierdo
     // Lanza la excepción EAccesoIndebido si el árbol está vacío

     inline CArbol<TElem> hijoDr ( ) const;
     // Pre : ! esVacio( )
     // Post : devuelve una copia del subárbol derecho
     // Lanza la excepción EAccesoIndebido si el árbol está vacío

     // observadoras
     inline const TElem& raiz( ) const;
     // Pre : ! esVacio( )
     // Post : devuelve el elemento almacenado en la raíz
     // Lanza la excepción EAccesoIndebido si el árbol está vacío

     inline bool esVacio( ) const;
     // Pre: true
     // Post: Devuelve true | false según si el árbol está o no vacío

     // Recorridos
     inline CSecuencia<TElem> preOrd( ) const;
     // Pre : true
     // Post : devuelve el recorrido en pre-orden del árbol

     inline CSecuencia<TElem> postOrd( ) const;
     // Pre : true
     // Post : devuelve el recorrido en post-orden del árbol

     inline CSecuencia<TElem> inOrd( ) const;
     // Pre : true
     // Post : devuelve el recorrido en in-orden del árbol

     inline bool esMont( ) const;
     // Pre : true
     // Post : devuelve true | false según si el árbol es o no un montículo

  // Escritura
     inline void escribe( ostream& salida ) const;

  //FUNCIONES AÑADIDAS

	 //Operador de comparacion. Dos Arboles son iguales, si coinciden su estructura 
	 //y su contenido y tienen el punto de interes en nodos homólogos
	 //rhs[IN]: arbol de entrada con el que comparamos.
	 //RETURN: Se devuelve un bool que indica si los arboles son iguales o no
	 inline bool  CArbol<TElem>::operator== (const CArbol &rhs) const;

	 //Cálculo del numero de hojas de un arbol. El numero de hojas de un arbol se 
	 //corresponde con el numero de animales, vegetales o minerales
	 //que tenga el arbol en cuestion
	 //RETURN: Se devuelve un entero que representa la cantidad.
	 inline unsigned int  numHojas () const;

	 //Funcion que obtiene el elemento apuntado por el punto de interes del arbol.
	 //RETURN: Se devuelve un TElem, con el elemento concreto.
	 //Lanza la excepcion EAccesoIndebido si el punto de interés apunta a nulo.
	 inline const TElem&  actual () const;

	 //Comprobación para ver si hemos llegado al final de una rama del arbol
	 //RETURN: Se devuelve un bool que indica si se ha llegado al final (True) o no (False)
	 inline bool esFin () const;

	 //Comprobación para ver si el punto de interés del arbol apunta a un nodo que es hoja
	 //RETURN: Se devuelve un bool que indica si el PI es una hoja (True) o no (False)
	 inline bool esHojaPI () const;

	 //Colocación del punto de interes del arbol en la raiz del mismo
	 inline void reinicia ();

	 //Equivalencia con el avanza de las secuencias, moviendo en este caso, el PI
	 //por el hijo izquierdo.
	 //Lanza la excepcion EAccesoIndebido si el punto de interés apunta a nulo.
	 inline void bajaIzda ();

	 //Equivalencia con el avanza de las secuencias, moviendo en este caso, el PI
	 //por el hijo derecho.
	 //Lanza la excepcion EAccesoIndebido si el punto de interés apunta a nulo.
	 inline void bajaDcha ();

	 //Modifica el contenido (TElem) del elemento apuntado por el PI.
	 //e[IN]: elemento nuevo que queremos poner en el arbol
	 //Lanza la excepcion EAccesoIndebido si esFin() devuelve true
	 inline void cambiaActual (const TElem& e);

	 //Inserción de un nuevo elemento en el hijo derecho del nodo apuntado por el PI
	 //e[IN]: elemento nuevo que queremos poner en el arbol
	 //Lanza la excepcion EAccesoIndebido si esFin() devuelve true o si ya existía un hijo derecho
	 inline void anyadeDr (const TElem& e);

	 //Inserción de un nuevo elemento en el hijo izquierdo del nodo apuntado por el PI
	 //e[IN]: elemento nuevo que queremos poner en el arbol
	 //Lanza la excepcion EAccesoIndebido si esFin() devuelve true o si ya existía un hijo izquierdo
	 inline void anyadeIz (const TElem& e);

	 //Procedimiento que carga, con el formato concreto indicado, el arbol que sea
	 //in[IN]: Flujo de datos de entrada del que extraeremos los datos a cargar
	 //Lanza la excepcion EFormatoIncorrecto si el formato de los datos de carga no es el adecuado
	 inline void carga (std::istream &in);

	 //Procedimiento que guarda, con el formato concreto indicado, el arbol que sea
	 //out[OUT]: Flujo de datos de entrada al que volcamos los datos a guardar
	 inline void salva (std::ostream &out) const;


  protected:
  // Variables privadas
     TNodoArbin<TElem>* _ra;
	 TNodoArbin<TElem>* _pi;

  // Operaciones privadas
     void libera();
     static void CArbol<TElem>::liberaAux( TNodoArbin<TElem>* );
     void copia( const CArbol<TElem>& );
     static TNodoArbin<TElem>* copiaAux( TNodoArbin<TElem>* p, TNodoArbin<TElem>* pi1, TNodoArbin<TElem>*& pi2);
  // operación privada de escritura
     static void escribeAux( ostream& salida, TNodoArbin<TElem>* p, string prefijo );
  // Constructora privada para los subárboles
     CArbol( TNodoArbin<TElem>* );

  //AÑADIDAS
	 //Funcion auxiliar que hace la recursion para realizar la comparacion.
	 //Se le pasan dos parametros mas: los puntos de interes de los arboles a comparar.
	 bool esIgualAux (TNodoArbin<TElem>* p, TNodoArbin<TElem>* q, TNodoArbin<TElem>* pi1, TNodoArbin<TElem>* pi2) const;

	 //Funcion auxiliar que hace la recursion calcular el numero de hojas de un arbol.
	 //Se le pasa un parametro adicional que se identifica con el puntero a la raiz del arbol cuyas hojas vamos a contar
	 unsigned int  numHojasAux (TNodoArbin<TElem>* p) const;

	 //Procedimiento auxiliar empleado para realizar la recursion al salvar el contenido del arbol.
	 //Se le pasa un parametro adicional: El puntero a la raiz del arbol que queremos guardar
	 void salvaAux (std::ostream &out, TNodoArbin<TElem>* p) const;

	 //Funcion auxiliar que implementa la recursion y el tratamiento de excepciones, que se lleva acabo en el proceso de carga
	 //Se devuelve un valor que representa el puntero que apunta a la raiz de una estructura de nodos (un arbol)
	 TNodoArbin<TElem>* cargaAux (std::istream &in);
};

//---------------------------------------------------------------------------
// IMPLEMENTACION
//---------------------------------------------------------------------------

  //-------------------
  // Clase de los nodos
  //-------------------
    template <class TElem>
    TNodoArbin<TElem>::TNodoArbin( const TElem& elem,
                                   TNodoArbin<TElem>* iz = 0, TNodoArbin<TElem>* dr = 0 ) :
      _elem(elem), _iz(iz), _dr(dr) {};

    template <class TElem>
    const TElem& TNodoArbin<TElem>::elem() const {
		return _elem;
    }

    template <class TElem>
    TNodoArbin<TElem>* TNodoArbin<TElem>::iz() const {
		return _iz;
    }

    template <class TElem>
    TNodoArbin<TElem>* TNodoArbin<TElem>::dr() const {
		return _dr;
    }


	//-------------------
	//Árboles
	//-------------------

  // Constructoras, destructora y operador de asignación

     template <class TElem>
     CArbol<TElem>::CArbol( ) : _ra( 0 ), _pi(0) {};

	template <class TElem>
    CArbol<TElem>::CArbol (const TElem &e) {
		_ra = new TNodoArbin<TElem> (e, 0, 0);
		_pi = _ra;
	}

     template <class TElem>
     CArbol<TElem>::CArbol( const CArbol<TElem>& arbin ) {
		copia(arbin);
     };

     template <class TElem>
     CArbol<TElem>::~CArbol( ) {
		libera();
     };

     template <class TElem>
     CArbol<TElem>&
     CArbol<TElem>::operator=( const CArbol<TElem>& arbin ) {
		if( this != &arbin ) {
			libera();
			copia(arbin);
		}
		return *this;
     };

	 template <class TElem>
	 bool  CArbol<TElem>::operator== (const CArbol &rhs) const {

		TNodoArbin<TElem>* aux = _ra;
		TNodoArbin<TElem>* tmp = rhs._ra;

		return esIgualAux (_ra, rhs._ra, _pi, rhs._pi);
	 }

	 template <class TElem>
	 bool CArbol<TElem>::esIgualAux (TNodoArbin<TElem>* p, TNodoArbin<TElem>* q, TNodoArbin<TElem>* pi1, TNodoArbin<TElem>* pi2) const {

		 if ((p == 0) && (q == 0))
			 return true;
		 if (((p == 0) && (q != 0)) || ((p != 0) && (q == 0)))
			 return false;
		 if (((p == pi1) && (q != pi2)) || ((p != pi1) && (q == pi2)))
			 return false;
		 if (p->elem() != q->elem())
			 return false;
		 else
			return (esIgualAux(p->iz(), q->iz(), pi1, pi2) && esIgualAux(p->dr(), q->dr(), pi1, pi2));


	 }

  // Operaciones de los árboles

     template <class TElem>
     CArbol<TElem> CArbol<TElem>::hijoIz ( ) const {
		 if( esVacio() )
		   throw EAccesoIndebido();
		 else
		   return CArbol<TElem>( copiaAux(_ra->iz()) );
     };

     template <class TElem>
     CArbol<TElem> CArbol<TElem>::hijoDr ( ) const {
		 if( esVacio() )
		   throw EAccesoIndebido();
		 else
		   return CArbol<TElem>( copiaAux(_ra->dr()) );
     };

     template <class TElem>
     const TElem& CArbol<TElem>::raiz( ) const {
		 if( esVacio() )
		   throw EAccesoIndebido();
		 else
		   return _ra->elem();
     };

     template <class TElem>
     bool CArbol<TElem>::esVacio( ) const {
		return _ra == 0;
     };

  // Recorrido en pre-orden
     template <class TElem>
     void preOrdAcu( TNodoArbin<TElem>* p, CSecuencia<TElem>& xs ) {
		 if ( p != 0 ) {
		   xs.inserta( p->elem() );
		   preOrdAcu( p->iz(), xs );
		   preOrdAcu( p->dr(), xs );
		 }
     };

     template <class TElem>
     CSecuencia<TElem> CArbol<TElem>::preOrd( ) const {
		 CSecuencia<TElem> r;

		 preOrdAcu( _ra, r );
		 return r;
     };

  // Recorrido en post-orden
     template <class TElem>
     void postOrdAcu( TNodoArbin<TElem>* p, CSecuencia<TElem>& xs ) {
		 if ( p != 0 ) {
		   postOrdAcu( p->iz(), xs );
		   postOrdAcu( p->dr(), xs );
		   xs.inserta( p->elem() );
		 }
     };

     template <class TElem>
     CSecuencia<TElem> CArbol<TElem>::postOrd( ) const {
		 CSecuencia<TElem> r;

		 postOrdAcu( _ra, r );
		 return r;
     };

  // Recorrido en in-orden
     template <class TElem>
     void inOrdAcu( TNodoArbin<TElem>* p, CSecuencia<TElem>& xs ) {
		 if ( p != 0 ) {
		   inOrdAcu( p->iz(), xs );
		   xs.inserta( p->elem() );
		   inOrdAcu( p->dr(), xs );
		 }
     };

     template <class TElem>
     CSecuencia<TElem> CArbol<TElem>::inOrd( ) const {
		 CSecuencia<TElem> r;

		 inOrdAcu( _ra, r );
		 return r;
     };


  // Es montículo
     template <class TElem>
     bool esHoja( TNodoArbin<TElem>* p ) {
		return (p != 0) && (p->iz() == 0) && (p->dr() == 0);
     }

     template <class TElem>
     bool CArbol<TElem>::esMont( ) const {
		bool mont = true;
		TNodoArbin<TElem>* p;
		TColaDinamica< TNodoArbin<TElem>* > cola;

		cola.ponDetras(_ra);
		while ( mont && (cola.primero() != 0 ) ) {
			p = cola.primero();
			mont = ( (p->iz()== 0) || (p->elem() < p->iz()->elem()) ) &&
				( (p->dr()== 0) || (p->elem() < p->dr()->elem()) );
			if ( mont ) {
			cola.quitaPrim();
			cola.ponDetras( p->iz() );
			cola.ponDetras( p->dr() );
			}
		}
		while ( (! cola.esVacio()) && ( cola.primero() == 0 ) )
			cola.quitaPrim();
		return cola.esVacio();
     };


  // Operaciones de entrada/salida

     template <class TElem>
     void CArbol<TElem>::escribeAux( ostream& salida, TNodoArbin<TElem>* p, string prefijo ) {
		 if ( p != 0 ) {
		   salida << ( prefijo + " : " ) << p->elem() << endl;
		   escribeAux( salida, p->iz(), prefijo + ".1" );
		   escribeAux( salida, p->dr(), prefijo + ".2" );
		 }
     }

     template <class TElem>
     void CArbol<TElem>::escribe( ostream& salida ) const {
		escribeAux( salida, _ra, "0" );
     };

  // Operaciones privadas

     // anulación
     template <class TElem>
     void CArbol<TElem>::liberaAux( TNodoArbin<TElem>* p ) {
		 if ( p != 0 ){
		   liberaAux(p->iz());
		   liberaAux(p->dr());
		   delete p;
		 }
     };

     template <class TElem>
     void CArbol<TElem>::libera() {
		 _pi = 0;
		 liberaAux( _ra );
     };

     // copia
     template <class TElem>
     TNodoArbin<TElem>* CArbol<TElem>::copiaAux( TNodoArbin<TElem>* p, TNodoArbin<TElem>* pi1, TNodoArbin<TElem>*& pi2) {

		 TNodoArbin<TElem>* r;

		 if ( p == 0 )
			r = 0;
		 else
			r = new TNodoArbin<TElem>( p->elem(), copiaAux( p->iz(), pi1, pi2 ), copiaAux( p->dr(), pi1, pi2 ) );
			if (pi1 == p)
			   pi2 = r;
		 return r;
     };

     template <class TElem>
     void CArbol<TElem>::copia(const CArbol<TElem>& arb) {
		_ra = copiaAux( arb._ra, arb._pi, _pi );
     };

  // Constructora privada para los subárboles
     template <class TElem>
     CArbol<TElem>::CArbol( TNodoArbin<TElem>* ra ) : _ra( ra ) {};

	template <class TElem>
	unsigned int  CArbol<TElem>::numHojas () const {

		return numHojasAux (_ra);
	}

	template <class TElem>
	unsigned int  CArbol<TElem>::numHojasAux (TNodoArbin<TElem>* p) const {

		if (p == 0)
			return 0;
		if ((p->iz() == 0) && (p->dr() == 0))
			return 1;
		else
			return numHojasAux (p->iz()) +  numHojasAux (p->dr());
	}

	template <class TElem>
	const TElem&  CArbol<TElem>::actual () const {

		if (_pi == 0)
			throw EAccesoIndebido();

		return _pi->elem();
	}

	template <class TElem>
	bool  CArbol<TElem>::esFin () const  {

		return (_pi == 0);
	}

	template <class TElem>
	bool CArbol<TElem>::esHojaPI () const {

		if ((_pi != 0) && (_pi->iz() == 0) && (_pi->dr() == 0))
			return true;
		else
			return false;
	}
		 
	template <class TElem>
	void  CArbol<TElem>::reinicia () {

		_pi = _ra;
	}

	template <class TElem>
	void CArbol<TElem>::bajaIzda () {

		if (_pi == 0)
			throw EAccesoIndebido();
		else
			_pi = _pi->iz();
	}

	template <class TElem>
	void CArbol<TElem>::bajaDcha () {

		if (_pi == 0)
			throw EAccesoIndebido();
		else
			_pi = _pi->dr();
	}

	template <class TElem>
	void CArbol<TElem>::cambiaActual (const TElem& e) {

		if(esFin())
			throw EAccesoIndebido();
		else
			_pi->_elem = e;
	}

	template <class TElem>
	void CArbol<TElem>::anyadeDr (const TElem& e)   {

		if ((esFin()) || (_pi->dr() != 0))
			throw EAccesoIndebido();
		else
			_pi->_dr = new TNodoArbin<TElem> (e, 0, 0);
	}

	template <class TElem>
	void CArbol<TElem>::anyadeIz (const TElem& e)   {

		if ((esFin()) || (_pi->iz() != 0))
			throw EAccesoIndebido();
		else
			_pi->_iz = new TNodoArbin<TElem> (e, 0, 0);
	}

	template <class TElem>
	void CArbol<TElem>::carga (std::istream &in) {

		TNodoArbin<TElem>* aux = 0;

		try {
		aux = cargaAux (in);
		libera();
		_ra = aux;
		}
		catch(EFormatoIncorrecto e){
			liberaAux(aux);
			throw EFormatoIncorrecto("Error de sintaxis"); 
		}
	}

	template <class TElem>
	TNodoArbin<TElem>*  CArbol<TElem>::cargaAux (std::istream &in) {

		string linea;
		getline (in, linea);

		if (linea == "Nuevo")
		return 0;
		if (linea == "Cons(") {
			TNodoArbin<TElem>* iz = 0;
			TNodoArbin<TElem>* dr = 0;

			//HIJO IZ.
			iz = cargaAux(in);

			//PRIMERA COMA
			getline (in, linea);
			if (linea != ",") {
				liberaAux(iz);
				throw EFormatoIncorrecto("Error de sintaxis");
			}

			//ELEMENTO
			TElem x;
			in >> x;
			getline (in, linea); //para que se haga el salto de línea

			//SEGUNDA COMA
			getline (in, linea);
			if (linea != ",") {
				liberaAux(iz);
				throw EFormatoIncorrecto("Error de sintaxis");
			}

			//HIJO DR.
			try{dr = cargaAux(in);}
			catch(EFormatoIncorrecto e){
				liberaAux(iz);
				throw EFormatoIncorrecto("Error de sintaxis"); 
			}

			//PARENTESIS DE FIN
			getline (in, linea);
			if (linea != ")") {
				liberaAux(iz);
				liberaAux(dr);
				throw EFormatoIncorrecto("Error de sintaxis");
			}

			return new TNodoArbin<TElem> (x , iz, dr);

		} else
			throw EFormatoIncorrecto("Error de sintaxis");
	}

	template <class TElem>
	void CArbol<TElem>::salva (std::ostream &out) const {

		salvaAux (out, _ra);
	}

	template <class TElem>
	void CArbol<TElem>::salvaAux (std::ostream &out, TNodoArbin<TElem>* p) const {

		if (p == 0)
			out << "Nuevo\n";
		else {
			out << "Cons(\n";
			salvaAux (out, p->iz());
			out << ",\n";
			out << p->elem();
			out << "\n,\n";
			salvaAux (out, p->dr());
			out << ")\n";
		}
	}

#endif
