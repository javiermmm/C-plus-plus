#include "ArbolDirectorios.h"
#include <sstream>
using namespace std;

//Función que devuelve el tamaño total de un directorio definido a partir de su ruta
//ruta[IN]: representa la ruta del directorio a calcular
unsigned long 	CArbolDirectorios::tamDirectorio (const string &ruta) {

	unsigned long tamTotal = 0;
	tamDirectorioAux (ruta, tamTotal);

	return tamTotal;
}

//Función que dada una ruta calcula de forma recursiva el tamaño de ese directorio
//ruta[IN]: representa la ruta del directorio cuyo tamaño calculamos
//tamTotal[IN]: tamaño total del directorio, fruto de ir acumulando los resultados parciales de la recursión
unsigned long 	CArbolDirectorios::tamDirectorioAux (const string &ruta, unsigned long& tamTotal) {

	CRecorreDirectorio rd = CRecorreDirectorio (ruta);
	string subcarpeta = "";
	string subdirectorio = "";
	while (!(rd.esFin())) {
		CRecorreDirectorio::TInfoEntrada info = rd.info();
		if (info.esFichero)
			tamTotal += info.tam;
		else {
			subcarpeta = "\\" + info.nombre;
			subdirectorio = ruta + subcarpeta;
			tamDirectorioAux (subdirectorio, tamTotal);
		}
		rd.avanza();
	}
	
	return tamTotal;
}

//Función que dada una ruta y un flujo de salida, muestra por este último, todos los directorios de la ruta en forma de árbol
//ruta[IN]: representa la ruta cuyo arbol se va a pintar
//output[IN]: flujo de salida por el que queremos mostrar el arbol
void 	CArbolDirectorios::escribeArbol (const string &ruta, ostream &output) {

	escribeArbolAux (ruta, output, ruta, 1);
}

//Función recursiva que dada una ruta muestra por pantalla el arbol de directorios de dicha ruta
//ruta[IN]: representa la ruta cuyo arbol se va a pintar
//output[IN]: flujo de salida por el que queremos mostrar el arbol
//nombrePantalla[IN]: string que representa el nombre del directorio que se debe escribir por pantalla
//numBlancos[IN]: Representa el número de grupos de 3 espacios en blanco que se debe dejar respecto del margen izquierdo.
void CArbolDirectorios::escribeArbolAux (const string &ruta, ostream &output, string nombrePantalla, int numBlancos) {

	output << nombrePantalla << endl;

	CRecorreDirectorio rd = CRecorreDirectorio (ruta);
	string subcarpeta = "";
	string subdirectorio = "";
	while (!(rd.esFin())) {
		CRecorreDirectorio::TInfoEntrada info = rd.info();
		string blancos = "   ";
		if (!(info.esFichero)) {
			for (int i= 0; i < numBlancos; ++i)
				output << blancos;
			subcarpeta = "\\" + info.nombre;
			subdirectorio = ruta + subcarpeta;
			escribeArbolAux (subdirectorio, output, info.nombre, numBlancos+1);
		}
		rd.avanza();
	}
}

//Función que muestra por pantalla el arbol de directorios que define
//la ruta proporcionada; así como los tamaños de de dichos directorios
//ruta[IN]: representa la ruta cuyo arbol se va a pintar
//output[IN]: flujo de salida por el que queremos mostrar el arbol
void 	CArbolDirectorios::escribeArbolYTam (const string &ruta, ostream &output) {

	CPila<string> pilaRes = CPila<string> ();
	unsigned long tam;
	tam = escribeArbolYTamAux (ruta, pilaRes, ruta, 0);
	//Escribir los strings almacenados en pilaRes, que es el arbol_Final
	while (!(pilaRes.empty())) {
		output << pilaRes.top();
		pilaRes.pop();
	}

}

//Función auxiliar que hace la recursión para mostrar por pantalla el arbol de directorios
//que define la ruta proporcionada; así como los tamaños de de dichos directorios
//ruta[IN]: representa la ruta cuyo arbol se va a pintar
//nombrePantalla[IN]: string que representa el nombre del directorio que se debe escribir por pantalla
//numBlancos[IN]: Representa el número de grupos de 3 espacios en blanco que se debe dejar respecto del margen izquierdo.
//pilaRes:pila que almacena lo que se debe mostrar por pantalla
unsigned long CArbolDirectorios::escribeArbolYTamAux (const string &ruta, CPila<string>& pilaRes, string nombrePantalla, int numBlancos) {

	stringstream lineaCompleta;	
	unsigned long tam = 0;
	CPila<string> pilatmp = CPila<string>();
	CRecorreDirectorio rd = CRecorreDirectorio (ruta);
	
	//Suma el tamaño de los ficheros y llena una pila temporal con el nombre del fichero
	while (!(rd.esFin())) {
		CRecorreDirectorio::TInfoEntrada info = rd.info();
		if (!(info.esFichero)) 
			pilatmp.push (info.nombre);
		else 
			tam += info.tam;
		rd.avanza();
	}

	//vaciar pilatmp
	while (!pilatmp.empty()) {
		string nombre = pilatmp.top();
		pilatmp.pop();
		string subDirectorio = ruta + "\\" + nombre;
		tam+= escribeArbolYTamAux (subDirectorio, pilaRes, nombre, numBlancos+1);
	}
	for (int i=0; i < numBlancos; ++i)
		lineaCompleta << "   ";
	lineaCompleta << nombrePantalla << " (" << tam << " bytes)" << endl;
		
	pilaRes.push (lineaCompleta.str());

	return tam;
}