#include "ListaLibros.h"
#include <iostream>
#include <string>
using namespace std;

//Inicializamos la lista poniendo su longitud a cero
//lista [IN-OUT]: lista que inicializamos.
void inicializaLista (TListaLibros &lista) {

	lista.numElems = 0;
}

//Añadimos el elemento "elto" (un libro) a la lista de libros "lista", realizando inserción ordenada.
//lista [IN-OUT]: lista de libros en la que insertamos el nuevo libro.
//elto [IN]: Nuevo libro que tratamos de añadir. Conceptualmente es un parámetro de entrada, pero lo ponemos como referencia constante por motivos de eficiencia
//Devolvemos un valor booleano que indica si la operación se ha podido realizar o no.
bool ponElemento (TListaLibros &lista, const TLibro &elto) { 

	if (lista.numElems == MAX_LIBROS)
		return false;
	else {
		int i = 0;
		bool encontrado = false;
		while (( i < lista.numElems) && !encontrado) {
			if (lista.libros[i].numRegistro > elto.numRegistro)
				encontrado = true;
			else ++i;
		}

		for (int j = lista.numElems-1; j >= i; --j)
			lista.libros[j+1] = lista.libros[j];

		lista.libros[i] = elto;
		++lista.numElems;
		return true;
	}
}

//Eliminamos el elemento (un libro) ubicado en la posicion "pos" de la lista de libros "lista"
//lista [IN-OUT]: lista de libros de la que pretendemos eliminar el elemento.
//pos [IN]: posición que ocupa el elemento (el libro) que queremos borrar en la lista.
// Devolvemos un valor booleano que indica si la operción se ha podido realizar o no.
bool borraElemento (TListaLibros &lista, int pos) {

	if ((pos < 0) || (pos > lista.numElems-1))
		return false;
	else { 
		if (pos < lista.numElems-1) {
			for (int i = pos; i < lista.numElems-1; ++i)
				lista.libros[i] = lista.libros[i+1];
		 }
		--lista.numElems;
		return true;
	}
}

//Consultamos el número de elementos de la lista.
//lista [IN]: lista cuyo número de elementos queremos consultar. Conceptualmente es un parámetro de entrada, pero lo ponemos como referencia constante por motivos de eficiencia.
//Devolvemos un entero correspondiente a la longitud de la lista.
int numElems (const TListaLibros &lista) {

	return lista.numElems;
}

//Accedemos al elemento (libro) que ocupa la posicion "i" en la lista "lista" y lo devolvemos.
//lista [IN]: lista donde se encuentra el elemento que queremos recuperar. Conceptualmente es un parámetro de entrada, pero lo ponemos como referencia constante por motivos de eficiencia
//i [IN]: Posición en la que se encuentra el elemento que vamos a recuperar.
//Devolvemos el libro que ocupa la posición "i" en la lista "lista".
TLibro dameElem (const TListaLibros &lista, int i) {

	TLibro li;

	if ((i >= 0) && (i < lista.numElems))
		li = lista.libros[i];

	return li;
}
