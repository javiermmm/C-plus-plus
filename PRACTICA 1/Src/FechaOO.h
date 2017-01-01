#ifndef __FECHAOO_H
#define __FECHAOO_H


class CFecha {
public:
	//FCO
	CFecha (int  dia = 1,  int  mes = 1,  int  anyo = 1970);
	CFecha  (const CFecha &f);
	CFecha& operator= (const CFecha &f);
	~CFecha ();

	//FUNCIONES
	void muestraFecha () const;
	static CFecha leerFecha ();
protected:
	int _dia;
	int _mes;
	int _anyo;
};

#endif