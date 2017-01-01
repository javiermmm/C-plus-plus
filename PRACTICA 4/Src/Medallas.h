#ifndef __MEDALLAS_H
#define __MEDALLAS_H

class CMedallas {
public:
	//Constructores
	CMedallas ();
	CMedallas (int oro, int plata, int bronce);

	//operadores de comparaci�n
	bool  operator< (const CMedallas &rhs) const;
	bool  operator== (const CMedallas &rhs) const;
	bool  operator> (const CMedallas &rhs) const;

	//accedentes
	//cada funci�n devuelve el valor del respectivo atributo
	int  getOros () const;
	int  getPlatas () const;
	int  getBronces () const;

	//mutadores
	//cada funci�n sirve para modificar su respectivo atributo
	//cada funci�n recibe el nuevo valor a implantar
	void setOros (int oros);
	void setPlatas (int platas);
	void setBronces (int bronces);
protected:
	int _oros;
	int _platas;
	int _bronces;
};


#endif