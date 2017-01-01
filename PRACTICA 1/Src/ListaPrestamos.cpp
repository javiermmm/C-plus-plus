#include "ListaPrestamos.h"

//Inicializamos la lista poniendo su longitud a cero
//lista [IN-OUT]: lista que inicializamos.
void inicializaLista (TListaPrestamos &lista) {

	lista.numPrestamos = 0;
}

//Añadimos el elemento "elto" (un prestamo) a la lista de prestamos "lista", colocándolo por el final.
//lista [IN-OUT]: lista de prestamos en la que insertamos el nuevo prestamo.
//elto [IN]: Nuevo prestamo que tratamos de añadir. Conceptualmente es un parámetro de entrada, pero lo ponemos como referencia constante por motivos de eficiencia
//Devolvemos un valor booleano que indica si la operación se ha podido realizar o no.
bool ponElemento (TListaPrestamos &lista, const TInfoPrestamo &elto) {

	if (lista.numPrestamos == MAX_PRESTAMOS)
		return false;
	else{
		lista.prestamos[lista.numPrestamos] = elto;
		++lista.numPrestamos;
		return true;
	}
}

//Eliminamos el elemento (un prestamo) ubicado en la posicion "pos" de la lista de prestamos "lista"
//lista [IN-OUT]: lista de prestamos de la que pretendemos eliminar el elemento.
//pos [IN]: posición que ocupa el elemento (el prestamo) que queremos borrar en la lista.
// Devolvemos un valor booleano que indica si la operción se ha podido realizar o no.
bool borraElemento (TListaPrestamos &lista, int pos) {

	if ((pos < 0) || (pos > lista.numPrestamos-1))
		return false;
	else { 
		for (int i = pos; i < lista.numPrestamos-1; ++i)
			lista.prestamos[i] = lista.prestamos[i+1];
		 
		--lista.numPrestamos;
		return true;
	}
}

//Consultamos el número de elementos de la lista.
//lista [IN]: lista cuyo número de elementos queremos consultar. Conceptualmente es un parámetro de entrada, pero lo ponemos como referencia constante por motivos de eficiencia.
//Devolvemos un entero correspondiente a la longitud de la lista.
int numElems (const TListaPrestamos &lista) {

	return lista.numPrestamos;
}

//Accedemos al elemento (prestamo) que ocupa la posicion "i" en la lista "lista" y lo devolvemos.
//lista [IN]: lista donde se encuentra el elemento que queremos recuperar. Conceptualmente es un parámetro de entrada, pero lo ponemos como referencia constante por motivos de eficiencia
//i [IN]: Posición en la que se encuentra el elemento que vamos a recuperar.
//Devolvemos el prestamo que ocupa la posición "i" en la lista "lista".
TInfoPrestamo dameElem (const TListaPrestamos &lista, int i) {

	TInfoPrestamo info;
	inicializaPrestamo (info);
	if ((i >= 0) && (i < lista.numPrestamos))
		info = lista.prestamos[i];

	return info;
}
