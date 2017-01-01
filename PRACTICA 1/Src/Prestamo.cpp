#include "Prestamo.h"

//Inicializamos el estado de un prestamo, asignandole como fecha de devoluci�n la "fecha por defecto" que asignamos a una fecha al inicializarla (01/01/1900)
//p [IN-OUT]: prestamo que vamos a inicializar
void inicializaPrestamo (TInfoPrestamo &p) {
	inicializaFecha (p.fechaDev);
}

//Inicializamos el estado de un prestamo, asign�ndole como fecha de devolucion la fecha "f", y como n�mero de registro "numRegistro
//p [IN-OUT]: prestamos que vamos a inicializar.
//numRegistro [IN]: n�mero de registro, que identificar� al libro de  nuestro prestamo.
//f [IN]: fecha de devoluci�n que le asignaremos al prestamo.
void inicializaPrestamo (TInfoPrestamo &p, int numRegistro, const TFecha &f) {
	p.fechaDev = f;
	p.numRegistro = numRegistro;
}

//Comprobamos, a partir de la informaci�n de un prestamo, si el libro relacionado con ese prestamo se encuentra en la lista de libros "libros",
//y si es as�, devolvemos los datos de dicho libro mediante "infoLibroPrestado"
//p [IN]: Prestamo con la informaci�n del libro que se encontrara (o no) en la lista de libros.  Conceptualmente es un par�metro de entrada, pero lo ponemos como referencia constante por motivos de eficiencia
//libros [IN]: lista de libros en la buscaremos si el libro relacionado con el prestamo "p" est� o no.  Conceptualmente es un par�metro de entrada, pero lo ponemos como referencia constante por motivos de eficiencia
//infoLibroPrestado [OUT]: Libro que contendr� la informacion del libro que buscabamos, en caso de haberlo encontrado, y en caso contrario, no modificar� su estado.
//Devolvemos un valor booleano que indica si hemos encontrado el libro en cuesti�n o no.
bool libroPrestado (const TInfoPrestamo &p, const TListaLibros &libros, TLibro &infoLibroPrestado) {

	int i = 0;
	bool encontrado = false;
	while ((i < libros.numElems) && !encontrado) {
		TLibro li = dameElem (libros, i);
		if (li.numRegistro == p.numRegistro) {
			encontrado = true;
			infoLibroPrestado = dameElem (libros, i);
		}
		else 
			++i;
	}
	return encontrado;
}
