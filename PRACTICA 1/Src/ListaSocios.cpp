#include "ListaSocios.h"

//Inicializamos la lista poniendo su longitud a cero
//lista [IN-OUT]: lista que inicializamos.
void inicializaLista (TListaSocios &lista) {

	lista.numSocios = 0;
}

//Añadimos el elemento "elto" (un socio) a la lista de socios "lista", realizando inserción ordenada.
//lista [IN-OUT]: lista de socios en la que insertamos el nuevo socio.
//elto [IN]: Nuevo socio que tratamos de añadir. Conceptualmente es un parámetro de entrada, pero lo ponemos como referencia constante por motivos de eficiencia
//Devolvemos un valor booleano que indica si la operación se ha podido realizar o no.
bool ponElemento (TListaSocios &lista, const TSocio &elto) {

	if (lista.numSocios == MAX_SOCIOS)
		return false;
	else {
		int i = 0;
		bool encontrado = false;
		while (( i < lista.numSocios) && !encontrado) {
			if (lista.socios[i].numCodigo > elto.numCodigo)
				encontrado = true;
			else ++i;
		}

		for (int j = lista.numSocios-1; j >= i; --j)
			lista.socios[j+1] = lista.socios[j];

		lista.socios[i] = elto;
		++lista.numSocios;
		return true;
	}
}

//Eliminamos el elemento (un socio) ubicado en la posicion "pos" de la lista de socios "lista"
//lista [IN-OUT]: lista de socios de la que pretendemos eliminar el elemento.
//pos [IN]: posición que ocupa el elemento (el socio) que queremos borrar en la lista.
// Devolvemos un valor booleano que indica si la operción se ha podido realizar o no.
bool borraElemento (TListaSocios &lista, int pos) {

	if ((pos < 0) || (pos > lista.numSocios-1))
		return false;
	else { 
		if (pos < lista.numSocios-1) {
			for (int i = pos; i < lista.numSocios-1; ++i)
				lista.socios[i] = lista.socios[i+1];
		 }
		--lista.numSocios;
		return true;
	}
}

//Consultamos el número de elementos de la lista.
//lista [IN]: lista cuyo número de elementos queremos consultar. Conceptualmente es un parámetro de entrada, pero lo ponemos como referencia constante por motivos de eficiencia.
//Devolvemos un entero correspondiente a la longitud de la lista.
int numElems (const TListaSocios &lista) {

	return lista.numSocios;
}

//Accedemos al elemento (socio) que ocupa la posicion "i" en la lista "lista" y lo devolvemos.
//lista [IN]: lista donde se encuentra el elemento que queremos recuperar. Conceptualmente es un parámetro de entrada, pero lo ponemos como referencia constante por motivos de eficiencia
//i [IN]: Posición en la que se encuentra el elemento que vamos a recuperar.
//Devolvemos el socio que ocupa la posición "i" en la lista "lista".
TSocio  dameElem (const TListaSocios &lista, int i) {

	TSocio so;

	if ((i >= 0) && (i < lista.numSocios))
		so = lista.socios[i];

	return so;
}
