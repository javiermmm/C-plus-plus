#ifndef _JUEGO__H
#define _JUEGO__H

#include "Arbol.h"
#include "Secuencia.h"
#include <string>

class CJuego {
public:
	//Con este constructor, cada vez que creemos un objeto de clase CJuego,
	//los arboles se construir�n con los valores por defecto
	CJuego();

	//Jugar una partida
	void jugar();

	//Salvar el estado de la base de conocimiento
	void grabar();

	//Cargar una base de conocimiento ya existente.
	void cargar();

	//Reproducir la ultima partida. Seg�n se va jugando la partida, se va guardando el intercambio de
	//mensajes usuario-aplicaci�n, para despu�s mostrarlos de uno en uno, con un formato determinado,
	//al usar esta funci�n
	void reproducir();
private:
	typedef CArbol<string> TConocimiento;

	//Atributos
	TConocimiento _animales;
	TConocimiento _vegetales;
	TConocimiento _minerales;
	CSecuencia<string> _ultPartida;

	//FUNCIONES PRIVADAS
	//------------------

	//Esta funci�n muestra el "submenu" en el que el usuario elegir� la categor�a
	//en la que quiere jugar (animal, vegetal, mineral)
	//RETURN: Se devuelve el entero con la opcion introducida por el usuario;
	int elegirCategoria();

	//Funci�n que implementa la partida propiamente dicha, es decir, 
	//el proceso de pregunta/respuesta entre el usuario y la aplicaci�n
	//arbol[IN-OUT]: arbol por el que se desciende para adivinar la eleccion del usuario,
	//			  y que se actualizar�, a�adiendo dicha eleccion si la apuesta hecha es err�nea
	//tipo[IN]: Cadena que se mostrar� cuando la aplicaci�n se comunique con el usuario y que 
	//			representa el tipo de arbol elegido (animales, vegetales, o minerales)
	void comienzaPartida(TConocimiento& arbol, const string& tipo);

	//Comprobaci�n de si la respuesta proporcionada por el usuario es un "si" o un "no", 
	//y ninguna otra cosa
	//respuesta[IN]: respuesta de la vamos a evaluar su correci�n
	//RETURN: Un valor bool que indica si la comprobaci�n fue correcta (True), 
	//o se detect� fallida (False)
	bool respuestaValida(const string& respuesta);

	//Funcionalidad referente al momento en el que la aplicaci�n hace su apuesta particular
	//(se llega a una hoja en el arbol) y se espera la respuesta del usuario para saber si acert� o no.
	//tipo[IN]: cadena que se utiliza en el amistoso discurso de la aplicaci�n,para mostrar por pantalla 
	//el tipo de arbol elegido (animal, vegetal, mineral)
	//arbol[IN]: arbol con la informacion de la base de conocimiento que se utiliza para mostrar
	//la apuesta realizada (el nodo hoja al que se ha llegado).
	//respuesta[OUT]: respuesta que proporciona el usuario, cuando el sistema le pregunta si acert� o no
	void hacerApuesta(const string& tipo, const TConocimiento& arbol, string& respuesta);

	//Esta funci�n se encarga de:
	//1.- Recoger los nuevos datos del animal, vegetall o mineral que el usuario pens�,
	//y que la aplicaci�n debe aprender
	//2.- Actualizar el arbol a�adiendo la nueva pregunta y el nuevo dato, 
	//y recolocando el dato relativo a la apuesta err�nea.
	//arbol[IN-OUT]: arbol que se va a actualizar
	//tipo[IN]: cadena que representa la cateor�a del arbol usado (animal, vegetal, mineral)
	void aprender(TConocimiento& arbol, const string& tipo);

	//Muestra las estad�sticas sobre el n�mero de animales, vegetales y minerales, 
	//que tiene el juego en su base de conocimiento
	//animales[IN]: arbol de animales. Se contar� el n�mero de hojas
	//para conocer cu�ntos animales conoce la aplicaci�n
	//vegetales[IN]: arbol de vegetales. Se contar� el n�mero de hojas
	//para conocer cu�ntos vegetales conoce la aplicaci�n
	//minerales[IN]: arbol de minerales. Se contar� el n�mero de hojas
	//para conocer cu�ntos minerales conoce la aplicaci�n
	void mostrarEstadisticas (const TConocimiento& animales, const TConocimiento& vegetales, const TConocimiento& minerales);
};



#endif