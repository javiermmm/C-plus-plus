#ifndef __MEDALLEROABSTRACTO_H
#define __MEDALLEROABSTRACTO_H

#include "Secuencia.h"
#include "Pareja.h"
#include "Deporte.h"
#include "Pais.h"
#include "Medallas.h"
#include "Atleta.h"
#include "Prueba.h"

class CMedalleroAbstracto {
public:
	//constructor
	CMedalleroAbstracto () {};

	//destructor
	virtual ~CMedalleroAbstracto () {};

	//Funci�n que registra en el medallero general y el medallero por deporte los resultados
	//de una prueba deportiva a partir de la clasificaci�n final de la misma (al menos con el podio)
	//prueba[IN]: Par�metro de entrada que representa la prueba que estamos registrando
	//clasif[IN]: Par�metro de entrada que representa la clasificaci�n, con al menos, 
	//los tres primeros atletas (oro, plata y bronce en esa prueba)
	virtual void  clasificacion (const CPrueba &prueba, CSecuencia< CAtleta > &clasif)=0 {}

	//Funci�n que devuelve el estado actual del medallero general
	//Se devuelve el medallero general en forma de secuencia de parejas
	//representadas por el pa�s de origen de los atletas, y las medallas
	//conseguidas hasta el momento
	virtual CSecuencia< CPareja< CPais, CMedallas > >  medallero ()=0 {}

	//Funci�n que devuelve el estado actual del medallero general, esta vez,
	//de manera ordenada.
	//Se devuelve el medallero general en forma de secuencia de parejas
	//representadas por el pa�s de origen de los atletas, y las medallas
	//conseguidas hasta el momento, ordenado seg�n el criterio de los 
	//operadores implementados en la clase CMedallas
	virtual CSecuencia< CPareja< CPais, CMedallas > >  medalleroOrdenado ()=0 {}

	//Funci�n que devuelve el estado actual del medallero por deporte
	//dep [IN]: Par�metro de entrada que representa el deporte cuyo medallero queremos obtener
	//Se devuelve el medallero del deporte solicitado en forma de secuencia de parejas
	//representadas por el pa�s de origen de los atletas, y las medallas
	//conseguidas hasta el momento en dicho deporte
	virtual CSecuencia< CPareja< CPais, CMedallas > >  medalleroDeporte (const CDeporte &dep)=0 {}

	//Funci�n que devuelve el estado actual del medallero por deporte, esta vez, 
	//de manera ordenada
	//dep [IN]: Par�metro de entrada que representa el deporte cuyo medallero queremos obtener
	//Se devuelve el medallero del deporte solicitado en forma de secuencia de parejas
	//representadas por el pa�s de origen de los atletas, y las medallas
	//conseguidas hasta el momento en dicho deporte, despu�s de haberlo ordenado
	virtual CSecuencia< CPareja< CPais, CMedallas > >  medalleroDeporteOrdenado (const CDeporte &dep)=0 {}
protected:

	//--------------------
	//FUNCIONES AUXILIARES
	//--------------------

	//funci�n que dada una posici�n de un atleta en la clasificacion (1,2 � 3)
	//y las medallas obtenida por un pa�s, les suma 1 a �stas,
	//seg�n el puesto (1-oro, 2-plata, 3-bronce)
	//med[IN/OUT]: par�metro que representa las medallas acumuladas de un pais, y que se va a incrementar
	//pos [IN]: posicion del podio cuya correspondiente medalla queremos aunmentar.
	void ponMedalla (CMedallas&  med, int pos);

	//funci�n que ordena un medallero, de la siguiente manera:
	//1. - Copiamos el contenido del medallero (secuencia) en un vector
	//2. - Ordenamos dicho vector con el algoritmo quicksort, 
	//modific�ndolo para poder ordenar a partir de la segunda componente de las parejas guardadas
	//3. - Volcamos el contenido del vector ordenado en una secuencia
	//infoMed[IN]: medallero que vamos a "ordenar". En realidad no ordenamos
	//el propio param�tro, sino que se devuelve una secuencia distinta que
	//contiene los mismos elementos, pero ya ordenados
	CSecuencia< CPareja< CPais, CMedallas > >  ordenaInfoMedallero (CSecuencia< CPareja< CPais, CMedallas > >& infoMed);

	//------------------------------------------------------------
	//funciones necesarias para la implementaci�n de la ordenaci�n
	//mediante el algoritmo quicksort
	//------------------------------------------------------------
	//funci�n auxiliar que realiza la ordenaci�n propiamente dicha, efectuando las comparaciones
	void particion ( CPareja< CPais, CMedallas > v[], int a, int b, int & p );

	//funci�n auxiliar que utilizamos, para ampliar la cabecera de la funci�n
	//que usaremos y realizar la recursi�n
	void quickSort (CPareja< CPais, CMedallas > v[], int a, int b);

	//funci�n que, utilizando las dos anteriores ordena un vector con la filosof�a quicksort
	void quickSort ( CPareja< CPais, CMedallas > v[], int num );
};


#endif