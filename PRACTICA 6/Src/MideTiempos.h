#ifndef __MIDETIEMPOS_H
#define __MIDETIEMPOS_H

#include "Algoritmo.h"
#include "Salida.h"

class CMideTiempos {
public:
	//constructor
	CMideTiempos (int tamIni, int tamFin, int intervalo, int numEjeIni = 1, int numEjeFin = 1); 

	//Destructor
	~CMideTiempos();

	//funcion que lanza la prueba y realiza las mediciones de tiempo
	//cumpliendo las condiciones pertinentes
	//alg[IN]: Algoritmo que vamos a medir
	//output1[IN-OUT]: salida Nº 1 por la que vamos a mostrar los resultados
	//output[IN-OUT]: segunda salida por la que vamos a mostra los resultados
	void  LanzaPrueba (CAlgoritmo* alg, CSalida* output1, CSalida* output2); 
protected:
	//ATRIBUTOS
	int _tamIni;
	int _tamFin;
	int _intervalo;
	int _numEjeIni;
	int _numEjeFin;

	//Funciones Auxiliares
	//funcion auxiliar que comprueba que se cumplen las condiciones necesarias para realizar la medicion
	void  LanzaPruebaAux (CAlgoritmo* alg, CSalida* output1, CSalida* output2, float numEjecuciones);
};

#endif