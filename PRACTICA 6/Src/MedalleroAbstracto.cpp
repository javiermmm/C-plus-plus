#include "MedalleroAbstracto.h"


void CMedalleroAbstracto::particion ( CPareja< CPais, CMedallas > v[], int a, int b, int & p ) {

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

void  CMedalleroAbstracto::quickSort (CPareja< CPais, CMedallas > v[], int a, int b) {

	int p;
	if ( a <= b ) {
		particion(v, a, b, p);
		quickSort(v, a, p - 1);
		quickSort(v, p+1, b);
	}

}

void CMedalleroAbstracto::quickSort ( CPareja< CPais, CMedallas > v[], int num ) {

	quickSort(v, 0, num-1);

}

void CMedalleroAbstracto::ponMedalla (CMedallas&  med, int pos) {

	if (pos == 1)
		med.setOros(med.getOros() + 1);
	if (pos == 2)
		med.setPlatas(med.getPlatas() + 1);
	if (pos == 3)
		med.setBronces(med.getBronces() + 1);
}

CSecuencia< CPareja< CPais, CMedallas > >  CMedalleroAbstracto::ordenaInfoMedallero (CSecuencia< CPareja< CPais, CMedallas > >& infoMed) {

	
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