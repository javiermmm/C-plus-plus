#include "MetodosOrdenacion.h"

//Este m�todo ordena un vector de enteros con el algoritmo de Inserci�n
//v[] [IN]: puntero al vector que se rellena
//num [IN]: Longitud m�xima del vector
void  ordenaInsercion (int v[], int num) {

	int i, j, x;
	for ( i = 1; i < num; i++ ) {
		x = v[i];
		j = i-1;
		while ( (j >= 0 ) && (v[j] > x) ){
			v[j+1] = v[j];
			j = j-1;
		}
		v[j+1] = x;
	}
}

//Este m�todo ordena un vector de enteros con el algoritmo de Selecci�n
//v[] [IN]: puntero al vector que se rellena
//num [IN]: Longitud m�xima del vector
void  ordenaSeleccion (int v[], int num) {

	int i, j, menor, aux;
	for ( i = 0; i < num; i++ ) {
		menor = i;
		for ( j = i+1; j < num; j++ )
			if ( v[j] < v[menor] )
				menor = j;
		if ( i != menor ) {
			aux = v[i];
			v[i] = v[menor];
			v[menor] = aux;
		}
	}
}
 
//Este m�todo ordena un vector de enteros con el algoritmo de Burbuja
//v[] [IN]: puntero al vector que se rellena
//num [IN]: Longitud m�xima del vector
void  ordenaBurbuja (int v[], int num) {

	int i, j, aux;
	bool modificado;
	i = 0;
	modificado = true;
	while ( (i < num-1) && modificado ) {
		modificado = false;
		for ( j = num-1; j > i; j-- )
			if ( v[j] < v[j-1] ) {
				aux = v[j];
				v[j] = v[j-1];
				v[j-1] = aux;
				modificado = true;
			}
			i++;
	}
}

//M�todo auxiliar que realiza la ordenaci�n propiamente dicha de un vector de enteros con el algoritmo de QuickSort
//v[] [IN]: puntero al vector que se rellena
//a [IN]: posicion de inico del subvector
//b [IN]: posicion de fin del subvector
//p [OUT]: posicion final del pivote
void particion ( int v[], int a, int b, int & p ) {

	int i, j;
	int aux;
	i = a+1;
	j = b;
	while ( i <= j ) {
		if ( (v[i] > v[a]) && (v[j] < v[a]) ) {
			aux = v[i]; 
			v[i] = v[j]; 
			v[j] = aux;
			i = i + 1; 
			j = j - 1;
		}
		else {
			if ( v[i] <= v[a] ) 
				i = i + 1;
			if ( v[j] >= v[a] ) 
				j = j-1;
		}
	}
	p = j;
	aux = v[a]; 
	v[a] = v[p]; 
	v[p] = aux;
}

//M�todo auxiliar para modificar la cabecera del QuickSort
//a [IN]: posicion de inico del subvector
//b [IN]: posicion de fin del subvector
void  quickSort (int v[], int a, int b) {

	int p;
	if ( a <= b ) {
		particion(v, a, b, p);
		quickSort(v, a, p - 1);
		quickSort(v, p+1, b);
	}

}

//Este m�todo ordena un vector de enteros con el algoritmo de QuickSort
//v[] [IN]: puntero al vector que se rellena
//num [IN]: Longitud m�xima del vector
void quickSort ( int v[], int num ) {

	quickSort(v, 0, num-1);

}

//M�todo auxiliar que realiza la ordenaci�n propiamente dicha de un vector de enteros con el algoritmo de MergeSort
//v[] [IN]: puntero al vector que se rellena
//a [IN]: posicion de inico del subvector
//b [IN]: posicion de fin del subvector
//m [OUT]: posicion divisoria del subvector
void mezcla( int v[], int a, int m, int b ) {

	int *u = new int [b-a+1];
	int i, j, k;
	for ( k = a; k <= b; k++ )
		u[k-a] = v[k];
	i = 0;
	j = m-a+1;
	k = a;
	while ( (i <= m-a) && (j <= b-a) ) {
		if ( u[i] <= u[j] ){
			v[k] = u[i];
			i = i + 1;
		} else {
			v[k] = u[j];
			j = j + 1;
		}
		k = k + 1;
	}
	while ( i <= m-a ) {
		v[k] = u[i];
		i = i+1;
		k = k+1;
	}
	while ( j <= b-a ) {
		v[k] = u[j];
		j = j+1;
		k = k+1;
	}

	delete[] u;
}

//M�todo auxiliar para modificar la cabecera del MergeSort
//a [IN]: posicion de inico del subvector
//b [IN]: posicion de fin del subvector
void mergeSort( int v[], int a, int b ) {

	int m;
	if ( a < b ) {
		m = (a+b) / 2;
		mergeSort( v, a, m );
		mergeSort( v, m+1, b );
		mezcla( v, a, m, b );
	}
}

//Este m�todo ordena un vector de enteros con el algoritmo de MergeSort
//v[] [IN]: puntero al vector que se rellena
//num [IN]: Longitud m�xima del vector
void mergeSort ( int v[], int num ) {

	mergeSort(v, 0, num-1);

}

