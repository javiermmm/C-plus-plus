#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <ctime>
#include "MideTiempos.h"
#include "SalidaPantalla.h"
#include "SalidaGNUPlot.h"
#include "AlgoritmoBurbujaAleatorio.h"
#include "AlgoritmoBurbujaCreciente.h"
#include "AlgoritmoBurbujaDecreciente.h"
#include "AlgoritmoInsercionAleatorio.h"
#include "AlgoritmoInsercionCreciente.h"
#include "AlgoritmoInsercionDecreciente.h"
#include "AlgoritmoMergesortAleatorio.h"
#include "AlgoritmoMergesortCreciente.h"
#include "AlgoritmoMergesortDecreciente.h"
#include "AlgoritmoQuicksortAleatorio.h"
#include "AlgoritmoQuicksortCreciente.h"
#include "AlgoritmoQuicksortDecreciente.h"
#include "AlgoritmoSeleccionAleatorio.h"
#include "AlgoritmoSeleccionCreciente.h"
#include "AlgoritmoSeleccionDecreciente.h"
#include <vld.h>
using namespace std;

void ayuda () {

	cout << endl << endl;
	cout << "CronoOrdenaciones.exe -h" << endl;
	cout << "        Muestra esta ayuda." << endl << endl;
	cout << "CronoOrdenaciones.exe [nInicial] [nFinal] [incN] [repIni] [repFin]" << endl;
	cout << "Parametros:" << endl;
	cout << "        " << "[nInicial]: tamaño inicial de los datos." << endl;
	cout << "        " << "[nFinal]: tamaño final." << endl;
	cout << "        " << "[incN]: incremento del tamaño." << endl;
	cout << "        " << "[repIni]: numero de repeticiones para el primer tamanyo." << endl;
	cout << "        " << "[repFin]: numero de repeticiones para el ultimo tamanyo." << endl;
	cout << endl << endl;
}

int main (int argc, const char* argv[]) {

	if (argc == 1)
		ayuda ();
	else {
		string param = argv [1];
		if (param == "-h")
			ayuda ();
		else {
			 if (argc < 6)
				 ayuda ();
			 else {
				 int parametros[5];

				 for (int k= 0; k< 5; ++k){
					 param = argv[k+1];
					 if (param != "0") {
						 parametros[k] = atoi (argv[k+1]);
						 if ( parametros [k] == 0) {
							 cout << "Fallo en la conversion de parametros" << endl;
							 return 0;
						 }
					 }
					 else 
						 parametros[k] = atoi (argv[k+1]);
				 }

				 CMideTiempos medicion (parametros[0],parametros[1],parametros[2],parametros[3],parametros[4]);

				 CAlgoritmo* algoritmos[15] = { new CAlgoritmoSeleccionAleatorio (), new CAlgoritmoSeleccionCreciente (),
					 new CAlgoritmoSeleccionDecreciente (), new CAlgoritmoInsercionAleatorio (), new CAlgoritmoInsercionCreciente (), 
					 new CAlgoritmoInsercionDecreciente (), new CAlgoritmoBurbujaAleatorio (), new CAlgoritmoBurbujaCreciente (), 
					 new CAlgoritmoBurbujaDecreciente (), new CAlgoritmoQuicksortAleatorio (), new CAlgoritmoQuicksortCreciente (), 
					 new CAlgoritmoQuicksortDecreciente (), new CAlgoritmoMergesortAleatorio (), new CAlgoritmoMergesortCreciente (), 
					 new CAlgoritmoMergesortDecreciente () };

				CSalidaGNUPlot* salidas[15] = { new CSalidaGNUPlot ("seleccionAleatorio.txt"), new CSalidaGNUPlot ("seleccionCreciente.txt"), 
					new CSalidaGNUPlot ("seleccionDecreciente.txt"), new CSalidaGNUPlot ("insercionAleatorio.txt"), new CSalidaGNUPlot ("insercionCreciente.txt"), 
					new CSalidaGNUPlot ("insercionDecreciente.txt"), new CSalidaGNUPlot ("burbujaAleatorio.txt"), new CSalidaGNUPlot ("burbujaCreciente.txt"), 
					new CSalidaGNUPlot ("burbujaDecreciente.txt"), new CSalidaGNUPlot ("quicksortAleatorio.txt"), new CSalidaGNUPlot ("quickSortCreciente.txt"), 
					new CSalidaGNUPlot ("quicksortDecreciente.txt"), new CSalidaGNUPlot ("mezclaAleatorio.txt"), new CSalidaGNUPlot ("mezclaCreciente.txt"), 
					new CSalidaGNUPlot ("mezclaDecreciente.txt") };

				 CSalidaPantalla* sal2 = new CSalidaPantalla ();

				 clock_t t1 = clock ();
				 for (int j = 0; j < 15; ++j) { 
					medicion.LanzaPrueba (algoritmos [j], salidas[j], sal2);
				 }
				 clock_t t2 = clock ();

				for (int i= 0; i< 15; ++i)
					delete algoritmos[i];

				for (int i= 0; i< 15; ++i)
					delete salidas[i];
			 
				 delete sal2;

			 
				//Mostrar el tiempo total de las ejecuciones en formato HH:MM:SS
			 float tiempo =  (float(t2-t1) / CLOCKS_PER_SEC);
			 float horas = 0;
			 float minutos = 0;
			 float segundos = tiempo;
			 if (tiempo > 1){
				float horas = ((tiempo / 3600));
				float minutos = float (((int(tiempo) % 3600) / 60));
				float segundos = float (((int(tiempo) % 3600) % 60));
			 }
				cout << endl << endl << "El tiempo total empleado ha sido de ";
				if (horas < 10)
					cout << "0" << horas;
				else
					cout << horas;
				cout << ":";
				if (minutos < 10)
					cout << "0" << minutos;
				else
					cout << minutos;
				cout << ":";
				if (segundos < 10)
					cout << "0" << segundos << endl;
				else
					cout << segundos << endl;

			}
		}
	}

	return 0;
}