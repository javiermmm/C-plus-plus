#include "Medallas.h"

CMedallas::CMedallas () : _oros(0), _platas(0), _bronces(0) {}

CMedallas::CMedallas (int oro, int plata, int bronce) {
	_oros = oro;
	_platas = plata;
	_bronces = bronce;
}

bool  CMedallas::operator< (const CMedallas &rhs) const {
	if (_oros < rhs._oros)
		return true;
	if ((_oros == rhs._oros) && (_platas < rhs._platas))
		return true;
	if ((_oros == rhs._oros) && (_platas == rhs._platas) && (_bronces < rhs._bronces))
		return true;

	return false;
}

bool  CMedallas::operator== (const CMedallas &rhs) const {
	if ((_oros == rhs._oros) && (_platas == rhs._platas) && (_bronces == rhs._bronces))
		return true;
	else
		return false;
}

bool  CMedallas::operator> (const CMedallas &rhs) const {

	if (_oros > rhs._oros)
		return true;
	if ((_oros == rhs._oros) && (_platas > rhs._platas))
		return true;
	if ((_oros == rhs._oros) && (_platas == rhs._platas) && (_bronces > rhs._bronces))
		return true;

	return false;
}

int  CMedallas::getOros () const {
	return _oros;
}

int  CMedallas::getPlatas () const {
	return _platas;
}

int  CMedallas::getBronces () const {
	return _bronces;
}

void CMedallas::setOros (int oros) {
	_oros = oros;
}

void CMedallas::setPlatas (int platas) {
	_platas = platas;
}

void CMedallas::setBronces (int bronces) {
	_bronces = bronces;
}
