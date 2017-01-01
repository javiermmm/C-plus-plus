#ifndef __PAREJA_H
#define __PAREJA_H

template <class T1, class T2>
class CPareja {
public:
	//constructores
	CPareja ();
	CPareja (const T1& v1, const T2& v2);

	//operador de asignación
	CPareja <T1, T2>& operator= (const CPareja<T1, T2>& p);

	//accedente para la primera componente de la pareja
	const T1& v1 () const;

	//accedente para la seginda componente de la pareja
	const T2& v2 () const;

	//mutador para la primera componete de la pareja
	void ponV1 (const T1& v1);

	//mutador para la segunda componete de la pareja
	void ponV2 (const T2& v2);
private:
	T1 _v1;
	T2 _v2;
};


//---------------------------------------------------------------------------
// IMPLEMENTACION
//---------------------------------------------------------------------------

template <class T1, class T2>
CPareja<T1,T2>::CPareja () {
	_v1 = T1();
	_v2 = T2(); 
};

template <class T1, class T2>
CPareja<T1,T2>::CPareja (const T1& v1, const T2& v2) : _v1(v1), _v2(v2) {};

template <class T1, class T2>
CPareja <T1, T2>& CPareja<T1,T2>::operator= (const CPareja<T1, T2>& p) {
	_v1 = p._v1;
	_v2 = p._v2;
	return *this;
}

template <class T1, class T2>
const T1& CPareja<T1,T2>::v1 () const { 
	return _v1; 
};

template <class T1, class T2>
const T2& CPareja<T1,T2>::v2 () const {
	return _v2;
};

template <class T1, class T2>
void CPareja<T1,T2>::ponV1 (const T1& v1) { 
	_v1 = v1;
};

template <class T1, class T2>
void CPareja<T1,T2>::ponV2 (const T2& v2) { 
	_v2 = v2;
};

#endif