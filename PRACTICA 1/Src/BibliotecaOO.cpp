#include "BibliotecaOO.h"
#include <iostream>
using namespace std;

//Constructor predeterminado
CBiblioteca::CBiblioteca () {
	_contLibros = 0;
	_contSocios = 100;
	_libros = CListaLibros ();
	_socios = CListaSocios ();
}

//Constructor por copia
CBiblioteca::CBiblioteca (const CBiblioteca& b) {
	_contLibros = b._contLibros;
	_contSocios = b._contSocios;
	_libros = b._libros;
	_socios = b._socios;
}

//Operador de asignaci�n
CBiblioteca& CBiblioteca::operator= (const CBiblioteca& b) {
	_contLibros = b._contLibros;
	_contSocios = b._contSocios;
	_libros = b._libros;
	_socios = b._socios;

	return *this;
}

//Destructor
CBiblioteca::~CBiblioteca () {}

//ACCEDENTES
CListaLibros CBiblioteca::dameLibros () const {
	return _libros;
}

//Funci�n auxiliar para buscar un socio en una lista de socios y devolver la posicion en la que se encuentra (en caso de que est�).
//Hacemos una b�squeda binaria, porque los socios siempre van a estar ordenados de menor a mayor seg�n su n�mero de c�digo.
//socios [IN]: lista de socios en la que buscamos. Conceptualmente es un par�metro de entrada, pero lo ponemos como referencia constante por motivos de eficiencia
//codigoSocio [IN]: codigo identificativo del socio que queremos buscar.
//pos [OUT]: posici�n de la lista de socios en la que se encuestra el socio buscado, si finalmente se encontrara, si no, no modificar�a su valor.
//Devolvemos un bool para indicar si la operaci�n ha tenido �xito o no.
bool CBiblioteca::buscaSocio ( const CListaSocios &socios, int codigoSocio, int &pos) const{

	int primero = 0;
	int ultimo = socios.numElems()-1;
	bool encontrado = false;
	int medio;

	while (!encontrado && primero <= ultimo) {
		medio = (primero + ultimo) / 2;
		if (socios.dameElem(medio).dameNumCodigo () == codigoSocio)
			encontrado = true;
		if (socios.dameElem(medio).dameNumCodigo () < codigoSocio)
			primero = medio +1;
		if (socios.dameElem(medio).dameNumCodigo () > codigoSocio)
			ultimo = medio -1;
	}
		if (encontrado) {
			pos = medio;
			return true;
		} else 
			return false;
}

//Funci�n auxiliar para buscar un libro en una lista de libros y devolver la posicion en la que se encuentra (en caso de que est�)
//Hacemos una b�squeda binaria, porque los libros siempre van a estar ordenados de menor a mayor seg�n su n�mero de registro.
//libros [IN]: lista de libros en la que buscamos. Conceptualmente es un par�metro de entrada, pero lo ponemos como referencia constante por motivos de eficiencia
//codigoLibro [IN]: codigo identificativo del libro que queremos buscar.
//pos [OUT]: posici�n de la lista de libros en la que se encuestra el libro buscado, si finalmente se encontrara, si no, no modificar�a su valor.
//Devolvemos un bool para indicar si la operaci�n hatenido �xito o no.
bool CBiblioteca::buscaLibro ( const CListaLibros &libros, int codigoLibro, int &pos) const{

	int primero = 0;
	int ultimo = libros.numElems()-1;
	bool encontrado = false;
	int medio;

	while (!encontrado && primero <= ultimo) {
		medio = (primero + ultimo) / 2;
		if (libros.dameElem(medio).dameNumRegistro () == codigoLibro)
			encontrado = true;
		if (libros.dameElem(medio).dameNumRegistro () < codigoLibro)
			primero = medio +1;
		if (libros.dameElem(medio).dameNumRegistro () > codigoLibro)
			ultimo = medio -1;
	}
	if (encontrado) {
		pos = medio;
		return true;
	} else 
		return false;
}

//Funci�n auxiliar para buscar un prestamo en una lista de prestamos y devolver la posicion en la que se encuentra (en caso de que est�)
//Hacemos una b�squeda secuencial, porque en nuestro caso, los prestamos no est�n ordenados de ninguma manera.
//prestamos [IN]: lista de prestamos en la que buscamos. Conceptualmente es un par�metro de entrada, pero lo ponemos como referencia constante por motivos de eficiencia
//codigoLibro [IN]: codigo identificativo del libro relacionado con el prestamo que queremos buscar.
//pos [OUT]: posici�n de la lista de prestamos en la que se encuestra el prestamo buscado, si finalmente se encontrara, si no, no modificar�a su valor.
//Devolvemos un bool para indicar si la operaci�n hatenido �xito o no.
bool CBiblioteca::buscaPrestamo ( const CListaPrestamos &prestamos, int codigoLibro, int &pos) const{

	int i = 0;
	bool encontrado= false;

	while ( (i < prestamos.numElems()) && !encontrado) {
		if (prestamos.dameElem(i).dameNumRegistro () == codigoLibro)
			encontrado = true;
		else
			++i;
	}
	if (encontrado) {
		pos = i;
		return true;
	} else 
		return false;
}

//Funci�n auxiliar que se dedica a conceder un prestamo, sin tener en cuenta ninguna restricci�n.
//Se cambia el estado del libro a "Prestado" y se genera un nuevo prestamo para a�adirlo a la lista de prestamos.
//pos [IN]: posici�n que ocupa el socio en la lista de socios.
//pos2 [IN]: posici�n que ocupa el libro en la lista de libros.
//li [IN-OUT]: libro que se presta.
//so [IN-OUT]: socio en cuya lista de prestamos se a�ade el nuevo prestamo.
//f [IN]: fecha de devoluci�n que se le asigna al nuevo prestamo. Conceptualmente es un par�metro de entrada, pero lo ponemos como referencia constante por motivos de eficiencia
void CBiblioteca::procesaPrestamo (int pos, int pos2, CLibro &li, CSocio & so, const CFecha &f) {
	
	li.ponEstado (CLibro::Prestado);
	_libros.borraElemento (pos2);
	_libros.ponElemento (li);					
	CListaPrestamos lp = so.damePrestamos();
	CInfoPrestamo prestamo = CInfoPrestamo (li.dameNumRegistro (), f);
	lp.ponElemento (prestamo);
	so.ponPrestamos (lp);
	_socios.borraElemento(pos);
	_socios.ponElemento(so);
}

//Funci�n auxiliar que se dedica a devolver un prestamo, sin tener en cuenta ninguna restricci�n. 
//Se cambia el estado del libro a "Disponible" y se elimina el prestamo de la lista de prestamos.
//posLibro [IN]: posici�n que ocupa el libro en la lista de libros.
//posSocio [IN]: posici�n que ocupa el socio en la lista de socios.
//posPrestamo [IN]: posici�n que ocupa el prestamo en la lista de prestamos.
//li [IN-OUT]: libro que se presta.
//so [IN-OUT]: socio en cuya lista de prestamos se a�ade el nuevo prestamo.
void CBiblioteca::procesaDevoluci�n (int posLibro, int posSocio, int posPrestamo, CLibro &li, CSocio & so) {
	
	li.ponEstado (CLibro::Disponible);
	_libros.borraElemento (posLibro);
	_libros.ponElemento (li);		
	CListaPrestamos lp = so.damePrestamos();
	lp.borraElemento (posPrestamo);
	so.ponPrestamos (lp);
	_socios.borraElemento(posSocio);
	_socios.ponElemento(so);
}

//Damos de alta un nuevo libro en la biblioteca, y le asignamos su numero de regitro correspondiente.
//nuevoLibro [IN]: libro que queremos a�adir. Conceptualmente es un par�metro de entrada, pero lo ponemos como referencia constante por motivos de eficiencia
//Devolvemos un bool para indicar si se ha podido o no, realizar la operaci�n.
bool CBiblioteca::anyadeLibro (const CLibro &nuevoLibro) {

	if ((_libros.numElems()) == CListaLibros::MAX_LIBROS)
		return false;

	CLibro l = nuevoLibro;
	_contLibros++;
	l.ponNumRegistro(_contLibros);
	
	if(nuevoLibro.dameEstado () == CLibro::Prestado)
		l.ponEstado (CLibro::Disponible);
	else
		l.ponEstado (nuevoLibro.dameEstado ());
	
	_libros.ponElemento (l);
	return true;
}

//Buscamos un libro en la biblioteca, a partir de su n�mero de registro, y si lo encontramos lo devolvemos, en caso contrario, "libro" no modifica su valor.
//numRegistro [IN]: numero de registro del libro que buscamos.
//libro [OUT]: libro que contendr� la informaci�n del libro buscado, en caso de encontrarlo.
//Devolvemos un valor booleano para indicar si se ha podido realizar la operacion, o no
bool CBiblioteca::buscaLibroPorRegistro (int numRegistro, CLibro &libro) const {

	int pos;
	if (_libros.numElems() > 0)
		if (buscaLibro (_libros, numRegistro, pos)) {
			libro = _libros.dameElem (pos);
			return true;
		}
		else
			return false;
	else 
		return false;
}

//Damos de baja un libro de la biblioteca, si es posible.
//numRegistro [IN]: numero de registro del libro que vamos a eliminar.
//Devolvemos un bool para indicar si hemos podido realizar la operaci�n, o no
bool CBiblioteca::borraLibro (int numRegistro) {

	int pos;
	if(_libros.numElems() > 0)
		if (buscaLibro (_libros, numRegistro, pos)) 
			if (_libros.dameElem(pos).dameEstado () == CLibro::Prestado)
				return false;
			else
				return _libros.borraElemento (pos);
		else
			return false;
	else
		return false;
}

//Mostramos los libros que haya en la bilioteca actualmente.
void CBiblioteca::muestraLibros () const {

	for (int i = 0; i < _libros.numElems() ; ++i){
		_libros.dameElem(i).muestraLibro ();
		cout << endl;
	}
}

//Damos de alta un nuevo socio en la biblioteca, y le asignamos su codigo de regitro correspondiente.
//nuevoSocio [IN]: socio que queremos a�adir. Conceptualmente es un par�metro de entrada, pero lo ponemos como referencia constante por motivos de eficiencia
//Devolvemos un bool para indicar si se ha podido o no, realizar la operaci�n
bool CBiblioteca::anyadeSocio (const CSocio &nuevoSocio) {

	if (_socios.numElems() == CListaSocios::MAX_SOCIOS)
		return false;

	CSocio s = nuevoSocio;
	_contSocios++;
	s.ponCodigo(_contSocios);
	s.ponPrestamos(CListaPrestamos());
	
	_socios.ponElemento (s);
	return true;
}

//Buscamos un socio en la biblioteca, a partir de su codigo de registro, y si lo encontramos lo devolvemos, en caso contrario, "socio" no modifica su valor
//numCodigo [IN]: codigo de registro del socio que buscamos.
//socio [OUT]: socio que contendr� la informaci�n del socio buscado, en caso de encontrarlo.
//Devolvemos un valor booleano para indicar si se ha podido realizar la operacion, o no
bool CBiblioteca::buscaSocioPorCodigo (int numCodigo, CSocio &socio) const {

	int pos;
	if (buscaSocio (_socios, numCodigo, pos)) {
		socio = _socios.dameElem(pos);
		return true;
	} else
		return false;
}

//Damos de baja un socio de la biblioteca, si es posible.
//numCodigo [IN]: codigo de registro del socio que vamos a eliminar.
//Devolvemos un bool para indicar si hemos podido realizar la operaci�n, o no
bool CBiblioteca::borraSocio (int numCodigo) {

	int pos;
	if (buscaSocio (_socios, numCodigo, pos))
		if (_socios.dameElem(pos).damePrestamos().numElems() > 0)
			return false;
		else
			return _socios.borraElemento(pos);
	else
		return false;
}

//Mostramos los socios que haya en la bilioteca actualmente.
void CBiblioteca::muestraSocios () const {

	for (int i = 0; i < _socios.numElems(); ++i){
		_socios.dameElem(i).muestraSocio (_libros);
		cout << endl;
	}
}

//Prestamos un libro a un socio, atendiendo a las posibles restricciones y asign�ndole una fecha de devoluci�n.
//codigoSocio [IN]: c�digo identificativo del socio al que se le va a prestar el libro
//codigoLibro [IN]: n�mero de registro, identificativo del libro, que va a ser prestado.
//f [IN]: fecha de devoluci�n que se le asignar� al prestamo. Conceptualmente es un par�metro de entrada, pero lo ponemos como referencia constante por motivos de eficiencia
//Devolvemos un bool para indicar si se ha podido realizar el prestamo, o no.
bool CBiblioteca::presta (int codigoSocio, int codigoLibro, const CFecha &f) {

	int pos, pos2;
	if (!buscaSocio (_socios,codigoSocio, pos))
		return false;
	if (!buscaLibro (_libros, codigoLibro, pos2))
		return false;
	if (_libros.dameElem(pos2).dameEstado() != CLibro::Disponible)
		return false;
	if (((_socios.dameElem(pos).damePrestamos().numElems() < 8) && (_socios.dameElem(pos).dameTipoSocio () == CSocio::Profesor))
		|| ((_socios.dameElem(pos).damePrestamos().numElems() < 5) && (_socios.dameElem(pos).dameTipoSocio () == CSocio::Becario))
		|| ((_socios.dameElem(pos).damePrestamos().numElems() < 3) && (_socios.dameElem(pos).dameTipoSocio () == CSocio::Alumno)))
	{
		procesaPrestamo (pos, pos2, _libros.dameElem(pos2), _socios.dameElem(pos), f); 
		return true;
	}
	else
		return false;
}

//Devolvemos un libro a la biblioteca, si es posible.
//codigoSocio [IN]: numero identificativo del socio que devuelve el libro.
//codigoLibro [IN]: numero de registro identificativo del libro, que es devuelto.
//Devolvemos un valor booleano para indicar si la operaci�n se pudo llevar a cabo, o no
bool CBiblioteca::devuelve (int codigoSocio, int codigoLibro) {
	
	int posSocio, posLibro, posPrestamo;

	if (buscaSocio(_socios, codigoSocio, posSocio)) {
		if (buscaPrestamo(_socios.dameElem(posSocio).damePrestamos(), codigoLibro, posPrestamo)) {
			if (buscaLibro(_libros, codigoLibro, posLibro)) {
				procesaDevoluci�n (posLibro, posSocio, posPrestamo, _libros.dameElem(posLibro), _socios.dameElem(posSocio));
				return true;
			}
			else return false; 
		}
		else return false;
	} else 
		return false;
}

//Comprobamos, a partir del numero de registro de un libro, quien tiene ese libro prestado en caso de que este prestado.
//codigoLibro [IN]: numero de registro que identifica al libro del que nos interesa conocer a q�i�n est� prestado (si lo est�).
//s [OUT]: socio que tiene el libro prestado en caso de que se verifique esa circunstancia, en caso contrario "s" no modificar� su valor.
//Devuelve un bool que indica si la operaci�n se ha llevado a cabo o no.
bool CBiblioteca::quienTiene (int codigoLibro, CSocio &s) const {

	s = CSocio();
	int pos;
	if (buscaLibro (_libros, codigoLibro, pos)) {
		if (_libros.dameElem(pos).dameEstado() != CLibro::Prestado)
			return false;

		int i = 0;
		bool encontrado = false;
		while ((i <  _socios.numElems()) && !encontrado) {
			int j = 0;
			while (j < (_socios.dameElem(i).damePrestamos().numElems()) && !encontrado) {
				if (_socios.dameElem(i).damePrestamos().dameElem(j).dameNumRegistro () == codigoLibro) {
					encontrado = true;
					s = _socios.dameElem(i);
				} else
					++j;
			}
			++i;
		}
		return true;
	} else
		return false;

}

//Mostramos los prestamos que haya en la bilioteca actualmente.
void CBiblioteca::muestraPrestamos () const {

	for (int i = 0; i < _libros.numElems(); ++i)
		if (_libros.dameElem(i).dameEstado () == CLibro::Prestado) {
			int numReg = _libros.dameElem(i).dameNumRegistro();
			int j =0;
			bool encontrado = false;
			while ((j < _socios.numElems()) && !encontrado) {
				int k = 0;
				while ((k < _socios.dameElem(j).damePrestamos().numElems()) && !encontrado) {
					if (_socios.dameElem(j).damePrestamos().dameElem(k).dameNumRegistro () == numReg) {
						encontrado = true;
						_libros.dameElem(i).muestraLibro ();
						cout << " => Prestado a " << _socios.dameElem(j).dameNombre() << " " << _socios.dameElem(j).dameApellidos () << endl;
					}
					else
						++k;
				}
				++j;
			}
		}
}