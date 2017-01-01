#include "TablaAbierta.h"
#include "TablaCerrada.h"
#include "MedalleroSecuencia.h"
#include "MedalleroTablaAbierta.h"
#include "MedalleroTablaCerrada.h"
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
	cout << "MideMedallero.exe [-s|-ta|-tc] [-m|-md|-c]" << endl;
	cout << "                  [nInicial] [nFinal] [incN] [repIni] [repFin]" << endl;
	cout << "Parametros:" << endl;
	cout << "        " << "-s, -ta, -tc: indica la implementación utilizada" << endl;
	cout << "        " << "              " << "(secuencias, tablas abiertas o tablas" << endl;
	cout << "        " << "              " << "cerradas)." << endl;
	cout << "        " << "-m, -md, -c: indica el método analizado (medallero," << endl;
	cout << "        " << "             " << "medallero deporte o clasificación)." << endl;
	cout << "        " << "[nInicial]: tamaño inicial de los datos." << endl;
	cout << "        " << "[nFinal]: tamaño final." << endl;
	cout << "        " << "[incN]: incremento del tamaño." << endl;
	cout << "        " << "[repIni]: numero de repeticiones para el primer tamanyo." << endl;
	cout << "        " << "[repFin]: numero de repeticiones para el ultimo tamanyo." << endl;
	cout << endl << endl;
}

int main (int argc, const char* argv[]) {

	srand(time(NULL));
	if (argc == 1)
		ayuda ();
	else {
		string param = argv [1];
		if (param == "-h")
			ayuda ();
		else {
			 if ((argc < 8) || (argc > 8))
				 ayuda ();
			 else {
				 string opciones [2];

				 opciones[0] = argv [1];
				 opciones[1] = argv [2];

				 if ((opciones[0] != "-s") && (opciones[0] != "-ta") && (opciones[0] != "-tc"))
					 ayuda();
				 else {
					 if ((opciones[1] != "-m") && (opciones[1] != "-md") && (opciones[1] != "-c"))
						ayuda();
					 else {

						 int parametros[5];
						 for (int k= 2; k< 7; ++k){
							 param = argv[k+1];
							 if (param != "0") {
								 parametros[k-2] = atoi (argv[k+1]);
								 if ( parametros [k-2] == 0) {
									 cout << "Fallo en la conversion de parametros" << endl;
									 return 0;
								 }
							 }
							 else 
								 parametros[k-2] = atoi (argv[k+1]);
						 }

						 CMideTiempos medicion (parametros[0],parametros[1],parametros[2],parametros[3],parametros[4]);

						 CAlgoritmo* algoritmos[21] = {new CAlgoritmoMedallero<CMedalleroSecuencia> (), new CAlgoritmoMedalleroOrdenado<CMedalleroSecuencia> (),
						 new CAlgoritmoMedalleroDeporteAleatorio<CMedalleroSecuencia> (), new CAlgoritmoMedalleroDeporteAleatorioOrdenado<CMedalleroSecuencia> (),
						 new CAlgoritmoClasificacionPrimero<CMedalleroSecuencia> (), new CAlgoritmoClasificacionUltimo<CMedalleroSecuencia> (), 
						 new CAlgoritmoClasificacionAleatorio<CMedalleroSecuencia> (), new CAlgoritmoMedallero<CMedalleroTAbierta> (), 
						 new CAlgoritmoMedalleroOrdenado<CMedalleroTAbierta> (), new CAlgoritmoMedalleroDeporteAleatorio<CMedalleroTAbierta> (),
						 new CAlgoritmoMedalleroDeporteAleatorioOrdenado<CMedalleroTAbierta> (), new CAlgoritmoClasificacionPrimero<CMedalleroTAbierta> (),
						 new CAlgoritmoClasificacionUltimo<CMedalleroTAbierta> (), new CAlgoritmoClasificacionAleatorio<CMedalleroTAbierta> (),
						 new CAlgoritmoMedallero<CMedalleroTCerrada> (), new CAlgoritmoMedalleroOrdenado<CMedalleroTCerrada> (),
						 new CAlgoritmoMedalleroDeporteAleatorio<CMedalleroTCerrada> (), new CAlgoritmoMedalleroDeporteAleatorioOrdenado<CMedalleroTCerrada> (),
						 new CAlgoritmoClasificacionPrimero<CMedalleroTCerrada> (), new CAlgoritmoClasificacionUltimo<CMedalleroTCerrada> (),
						 new CAlgoritmoClasificacionAleatorio<CMedalleroTCerrada> ()};

						 CSalidaGNUPlot* salidas[21] = {new CSalidaGNUPlot ("Medallero_NPaisesSecuencia.txt"), new CSalidaGNUPlot ("MedalleroOrdenado_NPaisesSecuencia.txt"), 
						 new CSalidaGNUPlot ("MedalleroDeporte_DeporteAleatorioSecuencia.txt"), new CSalidaGNUPlot ("MedalleroDeporteOrdenado_DeporteAleatorioSecuencia.txt"), 
						 new CSalidaGNUPlot ("Clasif_NPaisesPrimeroSecuencia.txt"), new CSalidaGNUPlot ("Clasif_NPaisesUltimoSecuencia.txt"), 
						 new CSalidaGNUPlot ("Clasif_NPaisesAleatorioSecuencia.txt"), new CSalidaGNUPlot ("Medallero_NPaisesTAbierta.txt"), 
						 new CSalidaGNUPlot ("MedalleroOrdenado_NPaisesTAbierta.txt"), new CSalidaGNUPlot ("MedalleroDeporte_DeporteAleatorioTAbierta.txt"), 
						 new CSalidaGNUPlot ("MedalleroDeporteOrdenado_DeporteAleatorioTAbierta.txt"), new CSalidaGNUPlot ("Clasif_NPaisesPrimeroTAbierta.txt"), 
						 new CSalidaGNUPlot ("Clasif_NPaisesUltimoTAbierta.txt"), new CSalidaGNUPlot ("Clasif_NPaisesAleatorioTAbierta.txt"), 
						 new CSalidaGNUPlot ("Medallero_NPaisesTCerrada.txt"), new CSalidaGNUPlot ("MedalleroOrdenado_NPaisesTCerrada.txt"), 
						 new CSalidaGNUPlot ("MedalleroDeporte_DeporteAleatorioTCerrada.txt"), new CSalidaGNUPlot ("MedalleroDeporteOrdenado_DeporteAleatorioTCerrada.txt"),
						 new CSalidaGNUPlot ("Clasif_NPaisesPrimeroTCerrada.txt"), new CSalidaGNUPlot ("Clasif_NPaisesUltimoTCerrada.txt"), 
						 new CSalidaGNUPlot ("Clasif_NPaisesAleatorioTCerrada.txt")};

						 int algIni, numAlgs;

						 //Tipo de Implementación
						 if (opciones[0] == "-s")
							algIni = 0;
						 if (opciones[0] == "-ta")
							algIni = 7;
						 if (opciones[0] == "-tc")
							algIni = 14;

						 //Tipo de Algoritmo
						 if (opciones[1] == "-m")
								numAlgs = 2;
						 if (opciones[1] == "-md") {
								numAlgs = 2;
								algIni += 2;
						 }
						 if (opciones[1] == "-c") {
								numAlgs = 3;
								algIni += 4;
						 }

						 CSalidaPantalla* sal2 = new CSalidaPantalla ();

						 clock_t t1 = clock ();
						 for (int j = 0; j < numAlgs; ++j) { 
							medicion.LanzaPrueba (algoritmos [algIni + j], salidas[algIni + j], sal2);
						 }
						 clock_t t2 = clock ();


						for (int i= 0; i< 21; ++i)
							delete algoritmos[i];

						for (int i= 0; i< 21; ++i)
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
		}
	}

	return 0;
}