#include "Fecha.h"
#include <iostream>
using namespace std;

//Inicializamos la fecha a 1 de enero del año 1900
//f [IN-OUT]: Es la fecha que se va a inicializar
void inicializaFecha  ( TFecha &f ) {
	f.dia = 1;
	f.mes = 1;
	f.anyo = 1970;
}

//Inicializamos la fecha utilizando el dia, mes y año que nos pasan como argumentos
//f [IN-OUT]: Es la fecha que se va a inicializar
//dia, mes, anyo [IN]: Son los datos que queremos que tenga la fecha
void inicializaFecha  ( TFecha &f,  int  dia,  int  mes,  int  anyo) {
	f.dia = dia;
	f.mes = mes;
	f.anyo = anyo;
}

//Mostramos por pantalla la fecha con el formato dd/mm/aaaa
//f [IN]: fecha que se va a mostrar. Conceptualmente es de entrada pero lo ponemos como referencia constante por motivos de eeficiencia.
void muestraFecha (const TFecha &f){
	cout<< f.dia << "/" << f.mes << "/" << f.anyo;
}

//leermos de teclado los datos de una fecha, que creamos y devolvemos
TFecha leerFecha (){
	TFecha f;
	cout<<"Introduzca el dia"<<endl;
	cin>> f.dia;
	cout<<"Introduzca el mes"<<endl;
	cin>> f.mes;
	cout<<"Introduzca el año"<<endl;
	cin>> f.anyo;

	return f;
}