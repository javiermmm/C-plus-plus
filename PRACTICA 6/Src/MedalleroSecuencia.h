#ifndef __MEDALLEROSECUENCIA_H
#define __MEDALLEROSECUENCIA_H

#include "MedalleroAbstracto.h"
#include "Secuencia.h"
#include "Pareja.h"
#include "Deporte.h"
#include "Pais.h"
#include "Medallas.h"
#include "Atleta.h"
#include "Prueba.h"

class CMedalleroSecuencia : public CMedalleroAbstracto {
public:
	//constructor
	CMedalleroSecuencia ();

	//destructor
	virtual ~CMedalleroSecuencia ();

	//Funci�n que registra en el medallero general y el medallero por deporte los resultados
	//de una prueba deportiva a partir de la clasificaci�n final de la misma (al menos con el podio)
	//prueba[IN]: Par�metro de entrada que representa la prueba que estamos registrando
	//clasif[IN]: Par�metro de entrada que representa la clasificaci�n, con al menos, 
	//los tres primeros atletas (oro, plata y bronce en esa prueba)
	virtual void  clasificacion (const CPrueba &prueba, CSecuencia< CAtleta > &clasif);

	//Funci�n que devuelve el estado actual del medallero general
	//Se devuelve el medallero general en forma de secuencia de parejas
	//representadas por el pa�s de origen de los atletas, y las medallas
	//conseguidas hasta el momento
	virtual CSecuencia< CPareja< CPais, CMedallas > >  medallero ();

	//Funci�n que devuelve el estado actual del medallero general, esta vez,
	//de manera ordenada.
	//Se devuelve el medallero general en forma de secuencia de parejas
	//representadas por el pa�s de origen de los atletas, y las medallas
	//conseguidas hasta el momento, ordenado seg�n el criterio de los 
	//operadores implementados en la clase CMedallas
	virtual CSecuencia< CPareja< CPais, CMedallas > >  medalleroOrdenado ();

	//Funci�n que devuelve el estado actual del medallero por deporte
	//dep [IN]: Par�metro de entrada que representa el deporte cuyo medallero queremos obtener
	//Se devuelve el medallero del deporte solicitado en forma de secuencia de parejas
	//representadas por el pa�s de origen de los atletas, y las medallas
	//conseguidas hasta el momento en dicho deporte
	virtual CSecuencia< CPareja< CPais, CMedallas > >  medalleroDeporte (const CDeporte &dep);

	//Funci�n que devuelve el estado actual del medallero por deporte, esta vez, 
	//de manera ordenada
	//dep [IN]: Par�metro de entrada que representa el deporte cuyo medallero queremos obtener
	//Se devuelve el medallero del deporte solicitado en forma de secuencia de parejas
	//representadas por el pa�s de origen de los atletas, y las medallas
	//conseguidas hasta el momento en dicho deporte, despu�s de haberlo ordenado
	virtual CSecuencia< CPareja< CPais, CMedallas > >  medalleroDeporteOrdenado (const CDeporte &dep);
protected:
	//"alias"
	typedef CSecuencia< CPareja< CPais, CMedallas > > TInfoMedallero;

	//ATRIBUTOS
	TInfoMedallero _medalleroGeneral;
	CSecuencia < CPareja< CDeporte, TInfoMedallero* > > _medalleroPorDeporte;

	//--------------------
	//FUNCIONES AUXILIARES
	//--------------------

	//funci�n que dado un pais y un medallero, busca si el pais ya forma parte del medallero,
	//es decir, si ya ha ganado alguna medalla
	//info[IN]: medallero en el vamos a buscar
	//pais[IN]: pais que estamos buscando
	bool buscaPais (TInfoMedallero& info, const CPais& pais);

	//funci�n que dado un deporte y un medallero por Deporte, busca si el deporte ya forma parte del medallero,
	//es decir, si ya se han celebrado pruebas de ese deporte
	//info[IN]: medallero por deporte en el vamos a buscar
	//dep[IN]: deporte que estamos buscando
	bool buscaDeporte (CSecuencia < CPareja< CDeporte, TInfoMedallero* > >& info, const CDeporte& deporte);

	//funcion que dado un pais, una posicion en la que ha quedado
	//un atleta en una prueba, y un medallero que ser� en el que figura 
	//el pais que queremos modificar, a�ade la medalla correspondinete al pais
	//siempre y cuando este exita en el sistema
	//infoMed[IN-OUT]: medallero que se modifica con la nueva medalla
	//i [IN]: posicion en la que ha quedado el atleta
	//pais [IN]: pais cuyas medallas queremos modificar
	void modifica (TInfoMedallero& infoMed, int i, const CPais& pais);

	//funcion que dada una clasificacion de atletas y un medallero,
	//actualiza este �ltimo, sirvi�ndose de la funci�n anterior
	//teniendo en cuenta, no uno, sino a los tres primeros clasificados
	//info[IN-OUT]: medallero que se actualiza a partir de la clasificacion
	//clasif[IN]: clasificaci�n con los tres primeros atletas tras
	//la realizacion de una prueba a partir de la cual
	//actualizaremos el medallero
	void actualiza (TInfoMedallero& info, CSecuencia< CAtleta > &clasif);
};


#endif