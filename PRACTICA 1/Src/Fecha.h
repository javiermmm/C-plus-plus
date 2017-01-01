#ifndef __FECHA_H
#define __FECHA_H

struct TFecha {
	int dia;
	int mes;
	int anyo;
};

//FUNCIONES
void inicializaFecha  ( TFecha &f );
void inicializaFecha  ( TFecha &f,  int  dia,  int  mes,  int  anyo);
void muestraFecha (const TFecha &f);
TFecha leerFecha ();

#endif