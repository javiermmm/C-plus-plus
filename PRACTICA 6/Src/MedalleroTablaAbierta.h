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

	//Función que registra en el medallero general y el medallero por deporte los resultados
	//de una prueba deportiva a partir de la clasificación final de la misma (al menos con el podio)
	//prueba[IN]: Parámetro de entrada que representa la prueba que estamos registrando
	//clasif[IN]: Parámetro de entrada que representa la clasificación, con al menos, 
	//los tres primeros atletas (oro, plata y bronce en esa prueba)
	virtual void  clasificacion (const CPrueba &prueba, CSecuencia< CAtleta > &clasif);

	//Función que devuelve el estado actual del medallero general
	//Se devuelve el medallero general en forma de secuencia de parejas
	//representadas por el país de origen de los atletas, y las medallas
	//conseguidas hasta el momento
	virtual CSecuencia< CPareja< CPais, CMedallas > >  medallero ();

	//Función que devuelve el estado actual del medallero general, esta vez,
	//de manera ordenada.
	//Se devuelve el medallero general en forma de secuencia de parejas
	//representadas por el país de origen de los atletas, y las medallas
	//conseguidas hasta el momento, ordenado según el criterio de los 
	//operadores implementados en la clase CMedallas
	virtual CSecuencia< CPareja< CPais, CMedallas > >  medalleroOrdenado ();

	//Función que devuelve el estado actual del medallero por deporte
	//dep [IN]: Parámetro de entrada que representa el deporte cuyo medallero queremos obtener
	//Se devuelve el medallero del deporte solicitado en forma de secuencia de parejas
	//representadas por el país de origen de los atletas, y las medallas
	//conseguidas hasta el momento en dicho deporte
	virtual CSecuencia< CPareja< CPais, CMedallas > >  medalleroDeporte (const CDeporte &dep);

	//Función que devuelve el estado actual del medallero por deporte, esta vez, 
	//de manera ordenada
	//dep [IN]: Parámetro de entrada que representa el deporte cuyo medallero queremos obtener
	//Se devuelve el medallero del deporte solicitado en forma de secuencia de parejas
	//representadas por el país de origen de los atletas, y las medallas
	//conseguidas hasta el momento en dicho deporte, después de haberlo ordenado
	virtual CSecuencia< CPareja< CPais, CMedallas > >  medalleroDeporteOrdenado (const CDeporte &dep);
protected:
	//"alias"
	typedef CTablaAbierta< CPais, CMedallas > TInfoMedallero;

	//ATRIBUTOS
	TInfoMedallero _medalleroGeneral;
	CTablaAbierta < CDeporte, TInfoMedallero* > _medalleroPorDeporte;
};


#endif