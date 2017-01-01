#include "Medallero.h"


void CMedallero::particion ( CPareja< CPais, CMedallas > v[], int a, int b, int & p ) {

	int i, j;
	CPareja< CPais, CMedallas > aux;
	i = a+1;
	j = b;
	while ( i <= j ) {
		if ( (v[i].v2() > v[a].v2()) && (v[j].v2() < v[a].v2()) ) {
			aux = v[i]; 
			v[i] = v[j]; 
			v[j] = aux;
			i = i + 1; 
			j = j - 1;
		}
		else {
			if (( v[i].v2() < v[a].v2() ) || (( v[i].v2() == v[a].v2() )))
				i = i + 1;
			if (( v[j].v2() > v[a].v2() ) || (( v[j].v2() == v[a].v2() )))
				j = j-1;
		}
	}
	p = j;
	aux = v[a]; 
	v[a] = v[p]; 
	v[p] = aux;
}

void  CMedallero::quickSort (CPareja< CPais, CMedallas > v[], int a, int b) {

	int p;
	if ( a <= b ) {
		particion(v, a, b, p);
		quickSort(v, a, p - 1);
		quickSort(v, p+1, b);
	}

}

void CMedallero::quickSort ( CPareja< CPais, CMedallas > v[], int num ) {

	quickSort(v, 0, num-1);

}

void CMedallero::ponMedalla (CMedallas&  med, int pos) {

	if (pos == 1)
		med.setOros(med.getOros() + 1);
	if (pos == 2)
		med.setPlatas(med.getPlatas() + 1);
	if (pos == 3)
		med.setBronces(med.getBronces() + 1);
}

bool CMedallero::buscaPais (TInfoMedallas& info, const CPais& pais) {

	bool encontrado = false;
	while ((!info.esFin()) && !encontrado) {
		if (info.actual().v1() != pais)
			info.avanza();
		else
			encontrado = true;
	}
	return encontrado;
}

bool CMedallero::buscaDeporte (CSecuencia < CPareja< CDeporte, TInfoMedallas* > >& info, const CDeporte& deporte) {

	bool encontrado = false;
	while ((!info.esFin()) && !encontrado) {
		if (info.actual().v1() != deporte)
			info.avanza();
		else
			encontrado = true;
	}
	return encontrado;
}

CSecuencia< CPareja< CPais, CMedallas > >  CMedallero::ordenaInfoMedallas (TInfoMedallas& infoMed) {

	
	CSecuencia< CPareja< CPais, CMedallas > > ret;
	if (!infoMed.esVacio()) {
		int NElems = infoMed.numElems();
		CPareja< CPais, CMedallas >* v = new CPareja< CPais, CMedallas >  [NElems];

		infoMed.reinicia();
		int i=0;
		while (!infoMed.esFin()) {
			CPareja< CPais, CMedallas > pareja = infoMed.actual();
			v[i] = pareja;
			infoMed.avanza();
			i++;
		}

		quickSort (v, NElems);

		for (int i=NElems-1; i>=0; --i) {
			ret.inserta(v[i]);
		}

		delete []v;
		return ret;
	}

	return CSecuencia< CPareja< CPais, CMedallas > > ();
}

void CMedallero::modifica (TInfoMedallas& infoMed, int i, const CPais& pais) {

	infoMed.reinicia();
	CMedallas med = CMedallas ();

	if (buscaPais (infoMed, pais)) {
		med = infoMed.actual().v2();
		infoMed.borra();
		ponMedalla (med, i);
		infoMed.inserta(CPareja< CPais, CMedallas > (pais, med));
	}
}

void CMedallero::actualiza (TInfoMedallas& info, CSecuencia< CAtleta > &clasif) {

	clasif.reinicia();
	for (int i=1; i < 4; ++i) {
		CPais pais = clasif.actual().getPais();
		info.reinicia();
		if (!info.esVacio()) {
			if (!buscaPais(info, pais))
				info.inserta(CPareja< CPais, CMedallas > (pais, CMedallas()));
		} else 
			info.inserta(CPareja< CPais, CMedallas > (pais, CMedallas()));
		
		modifica (info, i, pais);
		clasif.avanza();
	}
}

CMedallero::CMedallero () : _medalleroGeneral(TInfoMedallas()), _medalleroPorDeporte(CSecuencia < CPareja< CDeporte, TInfoMedallas* > > ()) {}

CMedallero::~CMedallero () {

	_medalleroPorDeporte.reinicia();
	while (!_medalleroPorDeporte.esFin()) {
		TInfoMedallas* ptr;
		ptr = _medalleroPorDeporte.actual().v2();
		delete ptr;
		_medalleroPorDeporte.avanza();
	}
}

void  CMedallero::clasificacion (const CPrueba &prueba, CSecuencia< CAtleta > &clasif) {

	CDeporte dep = prueba.getDeporte();

	//Actualizamos el medalleroGeneral
	actualiza (_medalleroGeneral, clasif);
	
	//Actualizamos el medallero por Deporte
	_medalleroPorDeporte.reinicia();
	if (!_medalleroPorDeporte.esVacio()) {
		TInfoMedallas* infomed;
		if (!buscaDeporte (_medalleroPorDeporte, dep)) {
			infomed = new TInfoMedallas();
			_medalleroPorDeporte.inserta(CPareja< CDeporte, TInfoMedallas* > (dep, infomed));
		} else
			infomed = _medalleroPorDeporte.actual().v2();

		actualiza (*infomed, clasif);
	} else {
		TInfoMedallas* infomed = new TInfoMedallas();
		_medalleroPorDeporte.inserta(CPareja< CDeporte, TInfoMedallas* > (dep, infomed));
		actualiza (*infomed, clasif);
	}
}

CSecuencia< CPareja< CPais, CMedallas > >  CMedallero::medallero () {

	return _medalleroGeneral;
}

CSecuencia< CPareja< CPais, CMedallas > >  CMedallero::medalleroOrdenado () {

	return ordenaInfoMedallas(_medalleroGeneral);
}

CSecuencia< CPareja< CPais, CMedallas > >  CMedallero::medalleroDeporte (const CDeporte &dep) {
	
	_medalleroPorDeporte.reinicia();
	if (!_medalleroPorDeporte.esVacio()){
		if (!buscaDeporte (_medalleroPorDeporte, dep))
			return CSecuencia< CPareja< CPais, CMedallas > > ();

		return *_medalleroPorDeporte.actual().v2();
	} else
		return CSecuencia< CPareja< CPais, CMedallas > > ();
}

CSecuencia< CPareja< CPais, CMedallas > >  CMedallero::medalleroDeporteOrdenado (const CDeporte &dep) {

	_medalleroPorDeporte.reinicia();
	if (!_medalleroPorDeporte.esVacio()){
		if (!buscaDeporte (_medalleroPorDeporte, dep))
			return CSecuencia< CPareja< CPais, CMedallas > > ();

		TInfoMedallas* infomed = _medalleroPorDeporte.actual().v2();

		return ordenaInfoMedallas(*infomed);
	} else 
		return CSecuencia< CPareja< CPais, CMedallas > > ();

}
