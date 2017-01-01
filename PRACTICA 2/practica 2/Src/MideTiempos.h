#ifndef __MIDETIEMPOS_H
#define __MIDETIEMPOS_H

#include "Algoritmo.h"
#include "Salida.h"

class CMideTiempos {
public:
	CMideTiempos (int tamIni, int tamFin, int intervalo, int numEjeIni = 1, int numEjeFin = 1); 
	~CMideTiempos();
	void  LanzaPrueba (CAlgoritmo* alg, CSalida* output1, CSalida* output2); 
protected:
	int _tamIni;
	int _tamFin;
	int _intervalo;
	int _numEjeIni;
	int _numEjeFin;
	void  LanzaPruebaAux (CAlgoritmo* alg, CSalida* output1, CSalida* output2, float numEjecuciones);
};

#endif