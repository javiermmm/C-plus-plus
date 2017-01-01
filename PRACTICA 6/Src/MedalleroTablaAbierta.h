#ifndef __MEDALLEROTABLAABIERTA_H
#define __MEDALLEROTABLAABIERTA_H

#include "MedalleroAbstracto.h"
#include "TablaAbierta.h"
#include "Secuencia.h"
#include "Pareja.h"
#include "Deporte.h"
#include "Pais.h"
#include "Medallas.h"
#include "Atleta.h"
#include "Prueba.h"

class CMedalleroTAbierta : public CMedalleroAbstracto {
public:
	//constructor
	CMedalleroTAbierta ();

	//destructor
	virtual ~CMedalleroTAbierta ();

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
	typedef CTablaAbierta< CPais, CMedallas > TInfoMedallero;

	//ATRIBUTOS
	TInfoMedallero _medalleroGeneral;
	CTablaAbierta < CDeporte, TInfoMedallero* > _medalleroPorDeporte;
};


#endif