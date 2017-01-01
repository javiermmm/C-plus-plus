#include "MedalleroSecuencia.h"

bool CMedalleroSecuencia::buscaPais (TInfoMedallero& info, const CPais& pais) {

	bool encontrado = false;
	while ((!info.esFin()) && !encontrado) {
		if (info.actual().v1() != pais)
			info.avanza();
		else
			encontrado = true;
	}
	return encontrado;
}

bool CMedalleroSecuencia::buscaDeporte (CSecuencia < CPareja< CDeporte, TInfoMedallero* > >& info, const CDeporte& deporte) {

	bool encontrado = false;
	while ((!info.esFin()) && !encontrado) {
		if (info.actual().v1() != deporte)
			info.avanza();
		else
			encontrado = true;
	}
	return encontrado;
}

void CMedalleroSecuencia::modifica (TInfoMedallero& infoMed, int i, const CPais& pais) {

	infoMed.reinicia();
	CMedallas med = CMedallas ();

	if (buscaPais (infoMed, pais)) {
		med = infoMed.actual().v2();
		infoMed.borra();
		ponMedalla (med, i);
		infoMed.inserta(CPareja< CPais, CMedallas > (pais, med));
	}
}

void CMedalleroSecuencia::actualiza (TInfoMedallero& info, CSecuencia< CAtleta > &clasif) {

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

CMedalleroSecuencia::CMedalleroSecuencia () : _medalleroGeneral(TInfoMedallero()), _medalleroPorDeporte(CSecuencia < CPareja< CDeporte, TInfoMedallero* > > ()) {}

CMedalleroSecuencia::~CMedalleroSecuencia () {

	_medalleroPorDeporte.reinicia();
	while (!_medalleroPorDeporte.esFin()) {
		TInfoMedallero* ptr;
		ptr = _medalleroPorDeporte.actual().v2();
		delete ptr;
		_medalleroPorDeporte.avanza();
	}
}

void  CMedalleroSecuencia::clasificacion (const CPrueba &prueba, CSecuencia< CAtleta > &clasif) {

	CDeporte dep = prueba.getDeporte();

	//Actualizamos el medalleroGeneral
	actualiza (_medalleroGeneral, clasif);
	
	//Actualizamos el medallero por Deporte
	_medalleroPorDeporte.reinicia();
	if (!_medalleroPorDeporte.esVacio()) {
		TInfoMedallero* infomed;
		if (!buscaDeporte (_medalleroPorDeporte, dep)) {
			infomed = new TInfoMedallero();
			_medalleroPorDeporte.inserta(CPareja< CDeporte, TInfoMedallero* > (dep, infomed));
		} else
			infomed = _medalleroPorDeporte.actual().v2();

		actualiza (*infomed, clasif);
	} else {
		TInfoMedallero* infomed = new TInfoMedallero();
		_medalleroPorDeporte.inserta(CPareja< CDeporte, TInfoMedallero* > (dep, infomed));
		actualiza (*infomed, clasif);
	}
}

CSecuencia< CPareja< CPais, CMedallas > >  CMedalleroSecuencia::medallero () {

	return _medalleroGeneral;
}

CSecuencia< CPareja< CPais, CMedallas > >  CMedalleroSecuencia::medalleroOrdenado () {

	return ordenaInfoMedallero(_medalleroGeneral);
}

CSecuencia< CPareja< CPais, CMedallas > >  CMedalleroSecuencia::medalleroDeporte (const CDeporte &dep) {
	
	_medalleroPorDeporte.reinicia();
	if (!_medalleroPorDeporte.esVacio()){
		if (!buscaDeporte (_medalleroPorDeporte, dep))
			return CSecuencia< CPareja< CPais, CMedallas > > ();

		return *_medalleroPorDeporte.actual().v2();
	} else
		return CSecuencia< CPareja< CPais, CMedallas > > ();
}

CSecuencia< CPareja< CPais, CMedallas > >  CMedalleroSecuencia::medalleroDeporteOrdenado (const CDeporte &dep) {

	_medalleroPorDeporte.reinicia();
	if (!_medalleroPorDeporte.esVacio()){
		if (!buscaDeporte (_medalleroPorDeporte, dep))
			return CSecuencia< CPareja< CPais, CMedallas > > ();

		TInfoMedallero* infomed = _medalleroPorDeporte.actual().v2();

		return ordenaInfoMedallero(*infomed);
	} else 
		return CSecuencia< CPareja< CPais, CMedallas > > ();

}
