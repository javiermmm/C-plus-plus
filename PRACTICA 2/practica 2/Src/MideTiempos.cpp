#include "MideTiempos.h"
#include <ctime>
#include <iostream>
using namespace std;

CMideTiempos::CMideTiempos  ( int  tamIni,int  tamFin,int  intervalo,int  numEjeIni,int  numEjeFin) 
	: _tamIni(tamIni), _tamFin(tamFin), _intervalo(intervalo), _numEjeIni(numEjeIni), _numEjeFin(numEjeFin) {}

CMideTiempos::~CMideTiempos() {}

void CMideTiempos::LanzaPruebaAux  ( CAlgoritmo*  alg, CSalida*  output1, CSalida*  output2, float diferencia) {
			
			//Inicializar la Prueba
			if (output1 != NULL)
				output1 -> InitPrueba(alg -> getDescription());
			if (output2 != NULL)
				output2 -> InitPrueba(alg -> getDescription());

			int numEjecuciones;
			if (_numEjeIni == 0)
				numEjecuciones = 1;
			else
				numEjecuciones = _numEjeIni;

			int numEjecucionesAux = numEjecuciones;
			int cont = 0;

			for (int tam = _tamIni; tam <= _tamFin  ; tam += _intervalo) {
				//Rellenar
				alg -> SetUp (tam);

				if (numEjecuciones <= 0)
					numEjecuciones = 1;

				//Ejecutar
				clock_t comienzo = clock ();
				for (int i = 0; i < numEjecuciones ; ++i)
					alg -> Execute();
				clock_t final = clock ();

				//Calcular Tiempo
				float tiempoEjecuciones = (float (final - comienzo)) / CLOCKS_PER_SEC;
				
				float tiempoIndividual = tiempoEjecuciones / numEjecuciones;

				numEjecucionesAux -= diferencia; 
				
				numEjecuciones = numEjecucionesAux;

				//Control para tiempo > 5
				if (tiempoEjecuciones > 5)
					cont++;

				if (cont > 0)
					for (int i = 0; i < cont; ++i)
						numEjecuciones /= 2;

				//Destruccion
				alg -> TearDown();

				//Volcar a Salida
				if (output1 != NULL)
					output1 -> Muestra (tam, tiempoIndividual);
				if (output2 != NULL)
					output2 -> Muestra (tam, tiempoIndividual);

			}

			//Finalizar Prueba
			if (output1 != NULL)
				output1 -> FinPrueba ();
			if (output2 != NULL)
				output2 -> FinPrueba ();
}



void CMideTiempos::LanzaPrueba  ( CAlgoritmo*  alg, CSalida*  output1, CSalida*  output2) {

	if (_tamIni > _tamFin) {
		int temp = _tamIni;
		_tamIni = _tamFin;
		_tamFin = temp;
	}
	else
		if (_tamIni == _tamFin) {
			if (_intervalo == 0) {
				_intervalo++;
			}
		}

	int denominador;
	float diferencia = 0.0;
	if (_intervalo != 0) {
		denominador = ((_tamFin - _tamIni) / _intervalo);			// Interpolación
		if (denominador != 0)
			diferencia = float ((_numEjeIni - _numEjeFin) / denominador);
	}

	LanzaPruebaAux (alg, output1, output2, diferencia);
}