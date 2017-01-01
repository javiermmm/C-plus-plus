#include "Medallero.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <ctime>
#include "MideTiempos.h"
#include "SalidaPantalla.h"
#include "SalidaGNUPlot.h"
#include "AlgoritmoMedallero.h"
#include "AlgoritmoMedalleroOrdenado.h"
#include "AlgoritmoMedalleroDeporteAleatorio.h"
#include "AlgoritmoMedalleroDeporteAleatorioOrdenado.h"
#include "AlgoritmoClasificacionPrimero.h"
#include "AlgoritmoClasificacionUltimo.h"
#include "AlgoritmoClasificacionAleatorio.h"
#include <vld.h>

using namespace std;

void ayuda () {

	cout << endl << endl;
	cout << "MideMedallero.exe -h" << endl;
	cout << "        Muestra esta ayuda." << endl << endl;
	cout << "MideMedallero.exe [nInicial] [nFinal] [incN] [repIni] [repFin]" << endl;
	cout << "Parametros:" << endl;
	cout << "        " << "[nInicial]: tamaño inicial de los datos." << endl;
	cout << "        " << "[nFinal]: tamaño final." << endl;
	cout << "        " << "[incN]: incremento del tamaño." << endl;
	cout << "        " << "[repIni]: numero de repeticiones para el primer tamanyo." << endl;
	cout << "        " << "[repFin]: numero de repeticiones para el ultimo tamanyo." << endl;
	cout << endl << endl;
}

int main (int argc, const char* argv[]) {

	srand(time(0));
	if (argc == 1)
		ayuda ();
	else {
		string param = argv [1];
		if (param == "-h")
			ayuda ();
		else {
			 if ((argc < 6) || (argc > 6))
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

				 CAlgoritmo* algoritmos[7] = { new CAlgoritmoMedallero (), new CAlgoritmoMedalleroOrdenado (),
					 new CAlgoritmoMedalleroDeporteAleatorio (), new CAlgoritmoMedalleroDeporteAleatorioOrdenado (), new CAlgoritmoClasificacionPrimero (), 
					 new CAlgoritmoClasificacionUltimo (), new CAlgoritmoClasificacionAleatorio ()};

				CSalidaGNUPlot* salidas[7] = { new CSalidaGNUPlot ("Medallero_NPaises.txt"), new CSalidaGNUPlot ("MedalleroOrdenado_NPaises.txt"), 
					new CSalidaGNUPlot ("MedalleroDeporte_DeporteAleatorio.txt"), new CSalidaGNUPlot ("MedalleroDeporteOrdenado_DeporteAleatorio.txt"), new CSalidaGNUPlot ("Clasif_NPaisesPrimero.txt"), 
					new CSalidaGNUPlot ("Clasif_NPaisesUltimo.txt"), new CSalidaGNUPlot ("Clasif_NPaisesAleatorio.txt")};

				 CSalidaPantalla* sal2 = new CSalidaPantalla ();

				 clock_t t1 = clock ();
				 for (int j = 0; j < 7; ++j) { 
					medicion.LanzaPrueba (algoritmos [j], salidas[j], sal2);
				 }
				 clock_t t2 = clock ();

				for (int i= 0; i< 7; ++i)
					delete algoritmos[i];

				for (int i= 0; i< 7; ++i)
					delete salidas[i];
			 
				 delete sal2;

			 
			//Mostrar el tiempo total de las ejecuciones en formato HH:MM:SS
			 float tiempo =  (float(t2-t1) / CLOCKS_PER_SEC);
			 int horas = 0;
			 int minutos = 0;
			 float segundos = tiempo;
			 if (tiempo > 1){
				horas = (int(tiempo / 3600));
				minutos = (((int(tiempo) % 3600) / 60));
				segundos = float (((int(tiempo) % 3600) % 60));
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