#ifndef __MEDALLERO_H
#define __MEDALLERO_H

#include "Secuencia.h"
#include "Pareja.h"
#include "Deporte.h"
#include "Pais.h"
#include "Medallas.h"
#include "Atleta.h"
#include "Prueba.h"

class CMedallero {
public:
	//constructor
	CMedallero ();

	//destructor
	~CMedallero ();

	//Función que registra en el medallero general y el medallero por deporte los resultados
	//de una prueba deportiva a partir de la clasificación final de la misma (al menos con el podio)
	//prueba[IN]: Parámetro de entrada que representa la prueba que estamos registrando
	//clasif[IN]: Parámetro de entrada que representa la clasificación, con al menos, 
	//los tres primeros atletas (oro, plata y bronce en esa prueba)
	void  clasificacion (const CPrueba &prueba, CSecuencia< CAtleta > &clasif);

	//Función que devuelve el estado actual del medallero general
	//Se devuelve el medallero general en forma de secuencia de parejas
	//representadas por el país de origen de los atletas, y las medallas
	//conseguidas hasta el momento
	CSecuencia< CPareja< CPais, CMedallas > >  medallero ();

	//Función que devuelve el estado actual del medallero general, esta vez,
	//de manera ordenada.
	//Se devuelve el medallero general en forma de secuencia de parejas
	//representadas por el país de origen de los atletas, y las medallas
	//conseguidas hasta el momento, ordenado según el criterio de los 
	//operadores implementados en la clase CMedallas
	CSecuencia< CPareja< CPais, CMedallas > >  medalleroOrdenado ();

	//Función que devuelve el estado actual del medallero por deporte
	//dep [IN]: Parámetro de entrada que representa el deporte cuyo medallero queremos obtener
	//Se devuelve el medallero del deporte solicitado en forma de secuencia de parejas
	//representadas por el país de origen de los atletas, y las medallas
	//conseguidas hasta el momento en dicho deporte
	CSecuencia< CPareja< CPais, CMedallas > >  medalleroDeporte (const CDeporte &dep);

	//Función que devuelve el estado actual del medallero por deporte, esta vez, 
	//de manera ordenada
	//dep [IN]: Parámetro de entrada que representa el deporte cuyo medallero queremos obtener
	//Se devuelve el medallero del deporte solicitado en forma de secuencia de parejas
	//representadas por el país de origen de los atletas, y las medallas
	//conseguidas hasta el momento en dicho deporte, después de haberlo ordenado
	CSecuencia< CPareja< CPais, CMedallas > >  medalleroDeporteOrdenado (const CDeporte &dep);
protected:
	//"alias"
	typedef CSecuencia< CPareja< CPais, CMedallas > > TInfoMedallas;

	//ATRIBUTOS
	TInfoMedallas _medalleroGeneral;
	CSecuencia < CPareja< CDeporte, TInfoMedallas* > > _medalleroPorDeporte;

	//--------------------
	//FUNCIONES AUXILIARES
	//--------------------

	//función que dada una posición de un atleta en la clasificacion (1,2 ó 3)
	//y las medallas obtenida por un país, les suma 1 a éstas,
	//según el puesto (1-oro, 2-plata, 3-bronce)
	//med[IN/OUT]: parámetro que representa las medallas acumuladas de un pais, y que se va a incrementar
	//pos [IN]: posicion del podio cuya correspondiente medalla queremos aunmentar.
	void ponMedalla (CMedallas&  med, int pos);

	//función que dado un pais y un medallero, busca si el pais ya forma parte del medallero,
	//es decir, si ya ha ganado alguna medalla
	//info[IN]: medallero en el vamos a buscar
	//pais[IN]: pais que estamos buscando
	bool buscaPais (TInfoMedallas& info, const CPais& pais);

	//función que dado un deporte y un medallero por Deporte, busca si el deporte ya forma parte del medallero,
	//es decir, si ya se han celebrado pruebas de ese deporte
	//info[IN]: medallero por deporte en el vamos a buscar
	//dep[IN]: deporte que estamos buscando
	bool buscaDeporte (CSecuencia < CPareja< CDeporte, TInfoMedallas* > >& info, const CDeporte& deporte);

	//función que ordena un medallero, de la siguiente manera:
	//1. - Copiamos el contenido del medallero (secuencia) en un vector
	//2. - Ordenamos dicho vector con el algoritmo quicksort, 
	//modificándolo para poder ordenar a partir de la segunda componente de las parejas guardadas
	//3. - Volcamos el contenido del vector ordenado en una secuencia
	//infoMed[IN]: medallero que vamos a "ordenar". En realidad no ordenamos
	//el propio paramétro, sino que se devuelve una secuencia distinta que
	//contiene los mismos elementos, pero ya ordenados
	CSecuencia< CPareja< CPais, CMedallas > >  ordenaInfoMedallas (TInfoMedallas& infoMed);

	//funcion que dado un pais, una posicion en la que ha quedado
	//un atleta en una prueba, y un medallero que será en el que figura 
	//el pais que queremos modificar, añade la medalla correspondinete al pais
	//siempre y cuando este exita en el sistema
	//infoMed[IN-OUT]: medallero que se modifica con la nueva medalla
	//i [IN]: posicion en la que ha quedado el atleta
	//pais [IN]: pais cuyas medallas queremos modificar
	void modifica (TInfoMedallas& infoMed, int i, const CPais& pais);

	//funcion que dada una clasificacion de atletas y un medallero,
	//actualiza este último, sirviéndose de la función anterior
	//teniendo en cuenta, no uno, sino a los tres primeros clasificados
	//info[IN-OUT]: medallero que se actualiza a partir de la clasificacion
	//clasif[IN]: clasificación con los tres primeros atletas tras
	//la realizacion de una prueba a partir de la cual
	//actualizaremos el medallero
	void actualiza (TInfoMedallas& info, CSecuencia< CAtleta > &clasif);

	//------------------------------------------------------------
	//funciones necesarias para la implementación de la ordenación
	//mediante el algoritmo quicksort
	//------------------------------------------------------------
	//función auxiliar que realiza la ordenación propiamente dicha, efectuando las comparaciones
	void particion ( CPareja< CPais, CMedallas > v[], int a, int b, int & p );

	//función auxiliar que utilizamos, para ampliar la cabecera de la función
	//que usaremos y realizar la recursión
	void quickSort (CPareja< CPais, CMedallas > v[], int a, int b);

	//función que, utilizando las dos anteriores ordena un vector con la filosofía quicksort
	void quickSort ( CPareja< CPais, CMedallas > v[], int num );
};


#endif