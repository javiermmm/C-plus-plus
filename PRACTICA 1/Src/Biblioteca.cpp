#include "Biblioteca.h"
#include <iostream>
using namespace std;

//Función auxiliar para buscar un socio en una lista de socios y devolver la posicion en la que se encuentra (en caso de que esté).
//Hacemos una búsqueda binaria, porque los socios siempre van a estar ordenados de menor a mayor según su número de código.
//socios [IN]: lista de socios en la que buscamos. Conceptualmente es un parámetro de entrada, pero lo ponemos como referencia constante por motivos de eficiencia
//codigoSocio [IN]: codigo identificativo del socio que queremos buscar.
//pos [OUT]: posición de la lista de socios en la que se encuestra el socio buscado, si finalmente se encontrara, si no, no modificaría su valor.
//Devolvemos un bool para indicar si la operación ha tenido éxito o no.
bool buscaSocio ( const TListaSocios &socios, int codigoSocio, int &pos) {

	int primero = 0;
	int ultimo = numElems(socios)-1;
	bool encontrado = false;
	int medio;

	while (!encontrado && primero <= ultimo) {
		medio = (primero + ultimo) / 2;
		if (dameElem(socios, medio).numCodigo == codigoSocio)
			encontrado = true;
		if (dameElem(socios, medio).numCodigo < codigoSocio)
			primero = medio +1;
		if (dameElem(socios, medio).numCodigo > codigoSocio)
			ultimo = medio -1;
	}
		if (encontrado) {
			pos = medio;
			return true;
		} else 
			return false;
}

//Función auxiliar para buscar un libro en una lista de libros y devolver la posicion en la que se encuentra (en caso de que esté)
//Hacemos una búsqueda binaria, porque los libros siempre van a estar ordenados de menor a mayor según su número de registro.
//libros [IN]: lista de libros en la que buscamos. Conceptualmente es un parámetro de entrada, pero lo ponemos como referencia constante por motivos de eficiencia
//codigoLibro [IN]: codigo identificativo del libro que queremos buscar.
//pos [OUT]: posición de la lista de libros en la que se encuestra el libro buscado, si finalmente se encontrara, si no, no modificaría su valor.
//Devolvemos un bool para indicar si la operación hatenido éxito o no.
bool buscaLibro ( const TListaLibros &libros, int codigoLibro, int &pos) {

	int primero = 0;
	int ultimo = numElems(libros)-1;
	bool encontrado = false;
	int medio;

	while (!encontrado && primero <= ultimo) {
		medio = (primero + ultimo) / 2;
		if (dameElem (libros, medio).numRegistro == codigoLibro)
			encontrado = true;
		if (dameElem (libros, medio).numRegistro < codigoLibro)
			primero = medio +1;
		if (dameElem (libros, medio).numRegistro > codigoLibro)
			ultimo = medio -1;
	}
	if (encontrado) {
		pos = medio;
		return true;
	} else 
		return false;
}

//Función auxiliar para buscar un prestamo en una lista de prestamos y devolver la posicion en la que se encuentra (en caso de que esté)
//Hacemos una búsqueda secuencial, porque en nuestro caso, los prestamos no están ordenados de ninguma manera.
//prestamos [IN]: lista de prestamos en la que buscamos. Conceptualmente es un parámetro de entrada, pero lo ponemos como referencia constante por motivos de eficiencia
//codigoLibro [IN]: codigo identificativo del libro relacionado con el prestamo que queremos buscar.
//pos [OUT]: posición de la lista de prestamos en la que se encuestra el prestamo buscado, si finalmente se encontrara, si no, no modificaría su valor.
//Devolvemos un bool para indicar si la operación hatenido éxito o no.
bool buscaPrestamo ( const TListaPrestamos &prestamos, int codigoLibro, int &pos) {

	int i = 0;
	bool encontrado= false;

	while ( (i < numElems(prestamos)) && !encontrado) {
		if (dameElem(prestamos, i).numRegistro == codigoLibro)
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

//Función auxiliar que se dedica a conceder un prestamo, sin tener en cuenta ninguna restricción. 
//Se cambia el estado del libro a "Prestado" y se genera un nuevo prestamo para añadirlo a la lista de prestamos.
//b [IN-OUT]: bilbioteca en la que se lleva a cabo el prestamo
//pos [IN]: posición que ocupa el socio en la lista de socios.
//pos2 [IN]: posición que ocupa el libro en la lista de libros.
//li [IN-OUT]: libro que se presta.
//so [IN-OUT]: socio en cuya lista de prestamos se añade el nuevo prestamo.
//f [IN]: fecha de devolución que se le asigna al nuevo prestamo. Conceptualmente es un parámetro de entrada, pero lo ponemos como referencia constante por motivos de eficiencia
void procesaPrestamo (TBiblioteca &b, int pos, int pos2, TLibro &li, TSocio &so, const TFecha &f) {

	li.estado = Prestado;
	borraElemento (b.libros, pos2);
	ponElemento (b.libros, li);					
	TListaPrestamos lp = so.prestamos;
	TInfoPrestamo prestamo;
	inicializaPrestamo (prestamo, li.numRegistro, f);
	ponElemento (lp, prestamo);
	so.prestamos = lp;
	borraElemento(b.socios, pos);
	ponElemento(b.socios, so);

}

//Función auxiliar que se dedica a devolver un prestamo, sin tener en cuenta ninguna restricción. Se cambia el estado del libro a "Disponible" y se elimina el prestamo de la lista de prestamos.
//b [IN-OUT]: bilbioteca en la que se lleva a cabo la devolución
//posLibro [IN]: posición que ocupa el libro en la lista de libros.
//posSocio [IN]: posición que ocupa el socio en la lista de socios.
//posPrestamo [IN]: posición que ocupa el prestamo en la lista de prestamos.
//li [IN-OUT]: libro que se presta.
//so [IN-OUT]: socio en cuya lista de prestamos se añade el nuevo prestamo.
void procesaDevolución (TBiblioteca &b, int posLibro, int posSocio, int posPrestamo, TLibro &li, TSocio & so) {
	
	li.estado = Disponible;
	borraElemento (b.libros, posLibro);
	ponElemento (b.libros, li);		
	TListaPrestamos lp = so.prestamos;
	borraElemento (lp, posPrestamo);
	so.prestamos = lp;
	borraElemento(b.socios, posSocio);
	ponElemento(b.socios, so);
}

//Inicializamos la biblioteca, inicializando sus dos listas, y "reseteando" los codigos de libros y socios
//bib [IN-OUT]: biblioteca que vamos a inicializar.
void inicializaBiblioteca (TBiblioteca &bib){

	inicializaLista (bib.socios);
	inicializaLista (bib.libros);
	bib.contLibros = 0;
	bib.contSocios = 100;
}

//Damos de alta un nuevo libro en la biblioteca, y le asignamos su numero de regitro correspondiente.
//biblio [IN-OUT]: biblioteca a la que añadimos el nuevo libro.
//nuevoLibro [IN]: libro que queremos añadir. Conceptualmente es un parámetro de entrada, pero lo ponemos como referencia constante por motivos de eficiencia
//Devolvemos un bool para indicar si se ha podido o no, realizar la operación
bool anyadeLibro (TBiblioteca &biblio, const TLibro &nuevoLibro){

	if ((numElems(biblio.libros)) == MAX_LIBROS)
		return false;

	TLibro l = nuevoLibro;
	biblio.contLibros++;
	l.numRegistro = biblio.contLibros;
	
	if(nuevoLibro.estado == Prestado)
		l.estado = Disponible;
	else
		l.estado = nuevoLibro.estado;
	
	ponElemento (biblio.libros, l);
	return true;

}

//Buscamos un libro en la biblioteca, a partir de su número de registro, y si lo encontramos lo devolvemos, en caso contrario, "libro" no modifica su valor
//biblio [IN]: biblioteca en la que buscamos. Conceptualmente es un parámetro de entrada, pero lo ponemos como referencia constante por motivos de eficiencia
//numRegistro [IN]: numero de registro del libro que buscamos.
//libro [OUT]: libro que contendrá la información del libro buscado, en caso de encontrarlo.
//Devolvemos un valor booleano para indicar si se ha podido realizar la operacion, o no
bool buscaLibroPorRegistro (const TBiblioteca &biblio, int numRegistro, TLibro &libro){

	int pos;
	if (numElems(biblio.libros) > 0)
		if (buscaLibro (biblio.libros, numRegistro, pos)) {
			libro = dameElem(biblio.libros, pos);
			return true;
		}
		else
			return false;
	else 
		return false;
}

//Damos de baja un libro de la biblioteca, si es posible.
//biblio [IN-OUT]: biblioteca que contiene el libro que vamos a eliminar.
//numRegistro [IN]: numero de registro del libro que vamos a eliminar.
//Devolvemos un bool para indicar si hemos podido realizar la operación, o no
bool borraLibro (TBiblioteca &biblio, int numRegistro){

	int pos;
	if(numElems(biblio.libros) > 0)
		if (buscaLibro (biblio.libros, numRegistro, pos)) 
			if (dameElem(biblio.libros, pos).estado == Prestado)
				return false;
			else
				return borraElemento (biblio.libros, pos);
		else
			return false;
	else
		return false;
}

//Mostramos los libros que haya en la bilioteca actualmente.
//biblio [IN]: biblioteca cuyos libros vamos a mostrar. Conceptualmente es un parámetro de entrada, pero lo ponemos como referencia constante por motivos de eficiencia
void muestraLibros (const TBiblioteca &biblio){

	for (int i = 0; i < numElems(biblio.libros) ; ++i){
		muestraLibro (dameElem (biblio.libros, i));
		cout << endl;
	}
}

//Damos de alta un nuevo socio en la biblioteca, y le asignamos su codigo de regitro correspondiente.
//biblio [IN-OUT]: biblioteca a la que añadimos el nuevo socio.
//nuevoSocio [IN]: socio que queremos añadir. Conceptualmente es un parámetro de entrada, pero lo ponemos como referencia constante por motivos de eficiencia
//Devolvemos un bool para indicar si se ha podido o no, realizar la operación
bool anyadeSocio (TBiblioteca &biblio, const TSocio &nuevoSocio){

	if (numElems (biblio.socios) == MAX_SOCIOS)
		return false;

	TSocio s = nuevoSocio;
	biblio.contSocios++;
	s.numCodigo = biblio.contSocios;
	inicializaLista (s.prestamos);
	
	ponElemento (biblio.socios, s);

	return true;
}

//Buscamos un socio en la biblioteca, a partir de su codigo de registro, y si lo encontramos lo devolvemos, en caso contrario, "socio" no modifica su valor
//biblio [IN]: biblioteca en la que buscamos. Conceptualmente es un parámetro de entrada, pero lo ponemos como referencia constante por motivos de eficiencia
//numCodigo [IN]: codigo de registro del socio que buscamos.
//socio [OUT]: socio que contendrá la información del socio buscado, en caso de encontrarlo.
//Devolvemos un valor booleano para indicar si se ha podido realizar la operacion, o no
bool buscaSocioPorCodigo (const TBiblioteca &biblio, int numCodigo, TSocio &socio){

	int pos;
	if (buscaSocio (biblio.socios, numCodigo, pos)) {
		socio = dameElem (biblio.socios, pos);
		return true;
	} else
		return false;
}

//Damos de baja un socio de la biblioteca, si es posible.
//biblio [IN-OUT]: biblioteca que contiene el socio que vamos a eliminar.
//numCodigo [IN]: codigo de registro del socio que vamos a eliminar.
//Devolvemos un bool para indicar si hemos podido realizar la operación, o no
bool borraSocio (TBiblioteca &biblio, int numCodigo){

	int pos;
	if (buscaSocio (biblio.socios, numCodigo, pos))
		if (numElems (dameElem (biblio.socios, pos).prestamos) > 0)
			return false;
		else
			return borraElemento (biblio.socios, pos);
	else
		return false;
}

//Mostramos los socios que haya en la bilioteca actualmente.
//biblio [IN]: biblioteca cuyos socios vamos a mostrar. Conceptualmente es un parámetro de entrada, pero lo ponemos como referencia constante por motivos de eficiencia
void muestraSocios (const TBiblioteca &biblio){

	for (int i = 0; i < numElems(biblio.socios); ++i){
		muestraSocio (dameElem (biblio.socios, i), biblio.libros);
		cout << endl;
	}
}

//Prestamos un libro a un socio, atendiendo a las posibles restricciones y asignándole una fecha de devolución.
//b [IN-OUT]: biblioteca en la que se lleva a cabo el prestamo.
//codigoSocio [IN]: código identificativo del socio al que se le va a prestar el libro
//codigoLibro [IN]: número de registro, identificativo del libro, que va a ser prestado.
//f [IN]: fecha de devolución que se le asignará al prestamo. Conceptualmente es un parámetro de entrada, pero lo ponemos como referencia constante por motivos de eficiencia
//Devolvemos un bool para indicar si se ha podido realizar el prestamo, o no.
bool presta (TBiblioteca &b, int codigoSocio, int codigoLibro, const TFecha &f){

	int pos, pos2;
	if (!buscaSocio (b.socios,codigoSocio, pos))
		return false;
	if (!buscaLibro (b.libros, codigoLibro, pos2))
		return false;
	if (dameElem (b.libros, pos2).estado != Disponible)
		return false;
	if (((numElems(dameElem(b.socios, pos).prestamos) < 8) && (dameElem(b.socios, pos).tipoSocio == Profesor))
		|| ((numElems(dameElem(b.socios, pos).prestamos) < 5) && (dameElem(b.socios, pos).tipoSocio == Becario))
		|| ((numElems(dameElem(b.socios, pos).prestamos) < 3) && (dameElem(b.socios, pos).tipoSocio == Alumno)))
	{
		procesaPrestamo (b, pos, pos2, dameElem (b.libros, pos2), dameElem (b.socios, pos), f); 
		return true;
	}
	else
		return false;
}

//Devolvemos un libro a la biblioteca, si es posible.
//b [IN-OUT]: biblioteca en la que se lleva a cabo la devolución.
//codigoSocio [IN]: numero identificativo del socio que devuelve el libro.
//codigoLibro [IN]: numero de registro identificativo del libro, que es devuelto.
//Devolvemos un valor booleano para indicar si la operación se pudo llevar a cabo, o no
bool devuelve (TBiblioteca &b, int codigoSocio, int codigoLibro){

	TLibro li;		
	TSocio so;		
	int posSocio, posLibro, posPrestamo;

	if (buscaSocio(b.socios, codigoSocio, posSocio)) {
		if (buscaPrestamo(dameElem (b.socios, posSocio).prestamos, codigoLibro, posPrestamo)) {
			if (buscaLibro(b.libros, codigoLibro, posLibro)) {
				procesaDevolución (b, posLibro, posSocio, posPrestamo, dameElem(b.libros, posLibro), dameElem(b.socios, posSocio));
				return true;
			}
			else return false; 
		}
		else return false;
	} else 
		return false;
}

//Comprobamos, a partir del numero de registro de un libro, quien tiene ese libro prestado en caso de que este prestado.
//b [IN]: biblioteca en que vamos a realizar la comprobación. Conceptualmente es un parámetro de entrada, pero lo ponemos como referencia constante por motivos de eficiencia
//codigoLibro [IN]: numero de registro que identifica al libro del que nos interesa conocer a qúién está prestado (si lo está).
//s [OUT]: socio que tiene el libro prestado en caso de que se verifique esa circunstancia, en caso contrario "s" no modificará su valor.
//Devuelve un bool que indica si la operación se ha llevado a cabo o no.
bool quienTiene (const TBiblioteca &b, int codigoLibro, TSocio &s){

	inicializaSocio(s);
	int pos;
	if (buscaLibro (b.libros, codigoLibro, pos)) {
		if (dameElem(b.libros, pos).estado != Prestado)
			return false;

		int i = 0;
		bool encontrado = false;
		while ((i <  numElems (b.socios)) && !encontrado) {
			int j = 0;
			while ((j < numElems (dameElem(b.socios, i).prestamos)) && !encontrado) {
				if (dameElem(dameElem(b.socios, i).prestamos, j).numRegistro == codigoLibro) {
					encontrado = true;
					s = dameElem (b.socios, i);
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
//biblio [IN]: biblioteca cuyos prestamos vamos a mostrar. Conceptualmente es un parámetro de entrada, pero lo ponemos como referencia constante por motivos de eficiencia
void muestraPrestamos (const TBiblioteca &b){

	for (int i = 0; i < numElems (b.libros); ++i)
		if (dameElem(b.libros, i).estado == Prestado) {
			int numReg = dameElem(b.libros, i).numRegistro;
			int j =0;
			bool encontrado = false;
			while ((j < numElems (b.socios)) && !encontrado) {
				int k = 0;
				while ((k < numElems(dameElem(b.socios, j).prestamos)) && !encontrado) {
					if (dameElem(dameElem(b.socios, j).prestamos, k).numRegistro == numReg) {
						encontrado = true;
						muestraLibro (dameElem(b.libros, i));
						cout << " => Prestado a " << dameElem(b.socios, j).nombre << " " << dameElem(b.socios, j).apellidos << endl;
					}
					else
						++k;
				}
				++j;
			}
		}
}