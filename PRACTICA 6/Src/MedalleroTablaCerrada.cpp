#include "MedalleroTablaCerrada.h"

CMedalleroTCerrada::CMedalleroTCerrada () : _medalleroGeneral(TInfoMedallero()), _medalleroPorDeporte(CTablaCerrada < CDeporte, TInfoMedallero* > ()) {}

CMedalleroTCerrada::~CMedalleroTCerrada () {

	CSecuencia < CPareja < CDeporte, TInfoMedallero* > > enu = _medalleroPorDeporte.enumera();
	enu.reinicia();
	while (!enu.esFin()) {
		TInfoMedallero* ptr = _medalleroPorDeporte.consulta(enu.actual().v1());
		delete ptr;
		enu.avanza();
	}
}

void  CMedalleroTCerrada::clasificacion (const CPrueba &prueba, CSecuencia< CAtleta > &clasif) {

	CDeporte dep = prueba.getDeporte();
	
	//Actualizamos el medallero General
	clasif.reinicia();
	for (int i= 1; i < 4; ++i) {
		CPais pais = clasif.actual().getPais();
		if (!_medalleroGeneral.esta(pais))
			_medalleroGeneral.inserta (pais, CMedallas());

		CMedallas med = _medalleroGeneral.consulta(pais);
		ponMedalla(med, i);
		_medalleroGeneral.inserta(pais, med);

		clasif.avanza();
	}

	//Actualizamos el medallero por Deporte
	TInfoMedallero* infomed;
	if (!_medalleroPorDeporte.esta(dep)) {
		infomed = new TInfoMedallero();
		_medalleroPorDeporte.inserta(dep, infomed);
	}

	infomed = _medalleroPorDeporte.consulta(dep);
	clasif.reinicia();
	for (int i = 1; i < 4 ; i++) {
		CPais pais = clasif.actual().getPais();
		if (!infomed->esta(pais))
			infomed->inserta(pais, CMedallas());

		CMedallas med = infomed->consulta(pais);
		ponMedalla(med, i);
		infomed->inserta(pais, med);

		clasif.avanza();
	} //CÓDIGO REPETIDO.ENCAPSULAR. OBVIAR ACTUALIZA, MODIFICA Y DEMAS OPERACIONES "IMPORTADAS"
}

CSecuencia< CPareja< CPais, CMedallas > >  CMedalleroTCerrada::medallero () {

	CSecuencia < CPareja < CPais, CMedallas > > res = _medalleroGeneral.enumera();

	return res;
}

CSecuencia< CPareja< CPais, CMedallas > >  CMedalleroTCerrada::medalleroOrdenado () {

	CSecuencia < CPareja < CPais, CMedallas > > res = _medalleroGeneral.enumera();

	return ordenaInfoMedallero(res);
}

CSecuencia< CPareja< CPais, CMedallas > >  CMedalleroTCerrada::medalleroDeporte (const CDeporte &dep) {
	
	if (!_medalleroPorDeporte.esta(dep))
			return CSecuencia< CPareja< CPais, CMedallas > > ();

	TInfoMedallero* infomed = _medalleroPorDeporte.consulta(dep);
	CSecuencia < CPareja < CPais, CMedallas > > res = infomed->enumera();

	return res;
}

CSecuencia< CPareja< CPais, CMedallas > >  CMedalleroTCerrada::medalleroDeporteOrdenado (const CDeporte &dep) {

	if (!_medalleroPorDeporte.esta(dep))
			return CSecuencia< CPareja< CPais, CMedallas > > ();

	TInfoMedallero* infomed = _medalleroPorDeporte.consulta(dep);
	CSecuencia < CPareja < CPais, CMedallas > > res = infomed->enumera();

	return ordenaInfoMedallero(res);

}