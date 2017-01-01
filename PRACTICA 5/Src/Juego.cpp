#include "Juego.h"
#include <Windows.h>
using namespace std;

std::istream &operator>>(std::istream &in, std::string &cad) {

	getline(in, cad);
	in.putback('\n');
	return in;
}

int CJuego::elegirCategoria() 
{

	//opcion
	int op;

	cout << endl << endl;
	cout << "Empecemos el juego." << endl;
	cout << "Piensa en un animal, vegetal o mineral, y pulsa INTRO cuando lo hayas pensado." << endl << endl;
	cout << "Pulsa 1 si has pensado animal, 2 si has pensado vegetal y 3 si es un mineral." << endl;
	cin >> op;
	cin.ignore();
	return op;
}

bool CJuego::respuestaValida(const string& respuesta) 
{

	//Comprobamos que escriba si o no, de las formas más habituales
	if ((respuesta != "no") && (respuesta != "si") && (respuesta != "SI") && (respuesta != "NO") && (respuesta != "Si") && (respuesta != "No"))
		return false;
	else
		return true;
}


void CJuego::hacerApuesta(const string& tipo, const TConocimiento& arbol, string& respuesta) 
{

	//Se hace la apuesta
	cout << "Mmmmmm, dejame que piense....." << endl;
	//Hacemos que parezca que piensa de verdad
	Sleep(1500);
	cout << "Creo que el " << tipo << " en que estabas pensando era...: " << (char) 173 <<  arbol.actual() << "!" << endl;

	//Se actualiza la secuencia para almacenar la última partida
	_ultPartida.inserta("Con estas respuestas aposte por " + arbol.actual());

	//Se comprueba si la puesta fue correcta o no
	cout << (char) 168 << "Acerte? (Si/No)" << endl;
	do {
		cin >> respuesta;
		cin.ignore();
	} while (! respuestaValida(respuesta));
}


void CJuego::aprender(TConocimiento& arbol, const string& tipo) 
{

	//----------------------------
	//Recogida de los nuevos datos
	//----------------------------
	cout << "Vaaaya. Me rindo. Dime el " << tipo << " en el que estabas pensando." << endl;
	string nuevoDato;
	getline (cin, nuevoDato);
	
	//Actualización de la secuencia que almacena la última partida
	_ultPartida.inserta("... pero falle. La respuesta era " + nuevoDato + "  :'(");


	cout << (char) 168 << "Puedes darme una pregunta que distinga " << arbol.actual() << " de " << nuevoDato << "?" << endl;
	string nuevaPregunta;
	getline (cin, nuevaPregunta);
	cout << (char) 168 << "Y que responderias ante la pregunta si piensas en " << arbol.actual() << "? (Si/No)" << endl;
	string nuevaRespuesta;
	getline (cin, nuevaRespuesta);

	//----------------------------------
	//Proceso de actualizacion del arbol
	//----------------------------------
	string apuestaEquivocada = arbol.actual();
	arbol.cambiaActual(nuevaPregunta);
	if ((nuevaRespuesta == "si")||(nuevaRespuesta == "Si")||(nuevaRespuesta == "SI"))
	{ 
		arbol.anyadeDr(apuestaEquivocada);
		arbol.anyadeIz(nuevoDato);
	}
	if ((nuevaRespuesta == "no")||(nuevaRespuesta == "No")||(nuevaRespuesta == "NO")) 
	{
		arbol.anyadeIz(apuestaEquivocada);
		arbol.anyadeDr(nuevoDato);
	}
}

void CJuego::mostrarEstadisticas (const TConocimiento& animales, const TConocimiento& vegetales, const TConocimiento& minerales) 
{

	cout << (char) 173 << (char) 173 << "Gracias por enseñarme mas!! Hasta ahora ya se:" << endl;
	int numAnimales, numVegetales, numMinerales;
	numAnimales = animales.numHojas();
	numVegetales = vegetales.numHojas();
	numMinerales = minerales.numHojas();
	cout << numAnimales << " animales, " << numVegetales << " vegetales y " << numMinerales << " minerales." << endl;
	cout << "Creo que la proxima vez adivinare lo que pienses..." << endl;
}

void CJuego::comienzaPartida(TConocimiento& arbol, const string& tipo) 
{

	string respuesta;
	arbol.reinicia();

	//Introducción en el diálogo de reproducción de la última partida
	_ultPartida.inserta("Las preguntas fueron las siguientes:");

	while (! arbol.esHojaPI()) 
	{
		cout << arbol.actual() << endl;
		do {
			cin >> respuesta;
			cin.ignore();
		} while (! respuestaValida(respuesta)); //esperamos hasta que la respuesta sea válida
		_ultPartida.inserta(arbol.actual() + " => " + respuesta);

		//bajamos por el arbol según la respuesta recibida
		if ((respuesta == "si")||(respuesta == "Si")||(respuesta == "SI"))
			arbol.bajaDcha();
		if ((respuesta == "no")||(respuesta == "No")||(respuesta == "NO"))
			arbol.bajaIzda();
	}

	hacerApuesta(tipo, arbol, respuesta);

	//Acciones a realizar según se acierte o no
	if ((respuesta == "si") ||(respuesta == "Si")||(respuesta == "SI"))
	{
		cout << (char) 173 << "Estupendo! Gracias por jugar conmigo.";
		_ultPartida.inserta("... y ¡acerte!");
	}
	if ((respuesta == "no") ||(respuesta == "No")||(respuesta == "NO")) 
	{
		aprender(arbol, tipo);
		mostrarEstadisticas(_animales, _vegetales, _minerales);
	}

	//Dejamos el arbol preparado para la próxima partida
	arbol.reinicia();
}

CJuego::CJuego() 
{

	//Creación del árbol de animales inicial
	_animales = TConocimiento ("¿Tiene cuatro patas?");
	_animales.anyadeIz("Delfin");
	_animales.anyadeDr("Tigre");

	//Creación del árbol de vegetales inicial
	_vegetales = TConocimiento ("¿Es comestible?");
	_vegetales.anyadeIz("Pino");
	_vegetales.anyadeDr("Zanahoria");

	//Creación del árbol de minerales inicial
	_minerales = TConocimiento ("¿Es brillante?");
	_minerales.anyadeIz("Pizarra");
	_minerales.anyadeDr("Oro");

	//La reproduccion de la útima partida está vacía
	_ultPartida = CSecuencia<string> ();
}

void CJuego::jugar()
{

	//Vaciamos la secuencia de última partida, cada vez que empezamos otra nueva, 
	//y le insertamos la primera frase
	_ultPartida = CSecuencia<string> ();
	_ultPartida.inserta("La ultima partida fue asi:");

	int op = elegirCategoria();

	//Comenzamos la partida con el arbol elegido
	switch (op) 
	{
		case 1: _ultPartida.inserta("El jugador penso un animal");
				comienzaPartida(_animales, "animal");
				break;
		case 2: _ultPartida.inserta("El jugador penso un vegetal");
				comienzaPartida(_vegetales, "vegetal");
				break;
		case 3: _ultPartida.inserta("El jugador penso un mineral");
				comienzaPartida(_minerales, "mineral");
				break;
	}
}

void CJuego::grabar()
{

	cout << "Introduce el nombre del fichero donde quieres salvar la base de conocimiento." << endl;
	string nombre;
	getline(cin, nombre);
	ofstream fichero (nombre);
	if (fichero.is_open()) {
		_animales.salva(fichero);
		_vegetales.salva(fichero);
		_minerales.salva(fichero);
		fichero.close();
		cout << endl << endl << "Partida salvada" << endl << endl;
	} else
		cout << endl << endl << "ERROR AL INTENTAR SALVAR. POR FAVOR, INTENTALO DE NUEVO" << endl << endl;
}

void CJuego::cargar()
{

	cout << "Introduce el nombre del fichero desde el que quieres cargar la base de conocimiento." << endl;
	string nombre;
	getline(cin, nombre);
	ifstream fichero (nombre);
	if (!fichero.fail()) {
		try {
			TConocimiento aux1, aux2, aux3;
			aux1.carga(fichero);
			aux2.carga(fichero);
			aux3.carga(fichero);

			_animales = aux1;
			_vegetales = aux2;
			_minerales = aux3;
		} catch (EFormatoIncorrecto e){
			cout << "ERROR: Falló la carga para algun tipo de dato (animal, vegetal o mineral)" << endl;
			throw EFormatoIncorrecto ("ERROR de formato en el fichero de datos origen");
		}
		fichero.close();
		cout << "Partida cargada" << endl << endl;
	} else
		cout << endl << endl << "ERROR AL INTENTAR CARGAR. POR FAVOR, INTENTALO DE NUEVO" << endl << endl;
}

void CJuego::reproducir()
{
	if (_ultPartida.esVacio())
		cout << "¡¡¡ PRIMERO TIENES QUE JUGAR !!!" << endl << endl;
	else {
		_ultPartida.reinicia();
		while (! _ultPartida.esFin()) 
		{
			cout << _ultPartida.actual() << endl;
			_ultPartida.avanza();
		}
	}
}
