#ifndef _JUEGO__H
#define _JUEGO__H

#include "Arbol.h"
#include "Secuencia.h"
#include <string>

class CJuego {
public:
	//Con este constructor, cada vez que creemos un objeto de clase CJuego,
	//los arboles se construirán con los valores por defecto
	CJuego();

	//Jugar una partida
	void jugar();

	//Salvar el estado de la base de conocimiento
	void grabar();

	//Cargar una base de conocimiento ya existente.
	void cargar();

	//Reproducir la ultima partida. Según se va jugando la partida, se va guardando el intercambio de
	//mensajes usuario-aplicación, para después mostrarlos de uno en uno, con un formato determinado,
	//al usar esta función
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

	//Esta función muestra el "submenu" en el que el usuario elegirá la categoría
	//en la que quiere jugar (animal, vegetal, mineral)
	//RETURN: Se devuelve el entero con la opcion introducida por el usuario;
	int elegirCategoria();

	//Función que implementa la partida propiamente dicha, es decir, 
	//el proceso de pregunta/respuesta entre el usuario y la aplicación
	//arbol[IN-OUT]: arbol por el que se desciende para adivinar la eleccion del usuario,
	//			  y que se actualizará, añadiendo dicha eleccion si la apuesta hecha es errónea
	//tipo[IN]: Cadena que se mostrará cuando la aplicación se comunique con el usuario y que 
	//			representa el tipo de arbol elegido (animales, vegetales, o minerales)
	void comienzaPartida(TConocimiento& arbol, const string& tipo);

	//Comprobación de si la respuesta proporcionada por el usuario es un "si" o un "no", 
	//y ninguna otra cosa
	//respuesta[IN]: respuesta de la vamos a evaluar su correción
	//RETURN: Un valor bool que indica si la comprobación fue correcta (True), 
	//o se detectó fallida (False)
	bool respuestaValida(const string& respuesta);

	//Funcionalidad referente al momento en el que la aplicación hace su apuesta particular
	//(se llega a una hoja en el arbol) y se espera la respuesta del usuario para saber si acertó o no.
	//tipo[IN]: cadena que se utiliza en el amistoso discurso de la aplicación,para mostrar por pantalla 
	//el tipo de arbol elegido (animal, vegetal, mineral)
	//arbol[IN]: arbol con la informacion de la base de conocimiento que se utiliza para mostrar
	//la apuesta realizada (el nodo hoja al que se ha llegado).
	//respuesta[OUT]: respuesta que proporciona el usuario, cuando el sistema le pregunta si acertó o no
	void hacerApuesta(const string& tipo, const TConocimiento& arbol, string& respuesta);

	//Esta función se encarga de:
	//1.- Recoger los nuevos datos del animal, vegetall o mineral que el usuario pensó,
	//y que la aplicación debe aprender
	//2.- Actualizar el arbol añadiendo la nueva pregunta y el nuevo dato, 
	//y recolocando el dato relativo a la apuesta errónea.
	//arbol[IN-OUT]: arbol que se va a actualizar
	//tipo[IN]: cadena que representa la cateoría del arbol usado (animal, vegetal, mineral)
	void aprender(TConocimiento& arbol, const string& tipo);

	//Muestra las estadísticas sobre el número de animales, vegetales y minerales, 
	//que tiene el juego en su base de conocimiento
	//animales[IN]: arbol de animales. Se contará el número de hojas
	//para conocer cuántos animales conoce la aplicación
	//vegetales[IN]: arbol de vegetales. Se contará el número de hojas
	//para conocer cuántos vegetales conoce la aplicación
	//minerales[IN]: arbol de minerales. Se contará el número de hojas
	//para conocer cuántos minerales conoce la aplicación
	void mostrarEstadisticas (const TConocimiento& animales, const TConocimiento& vegetales, const TConocimiento& minerales);
};



#endif