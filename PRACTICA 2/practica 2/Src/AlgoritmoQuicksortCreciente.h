#ifndef __CALGORITMOQUICKSORTCRECIENTE_H
#define __CALGORITMOQUICKSORTCRECIENTE_H

#include "AlgoritmoSobreVectores.h"
#include "MetodosGeneracion.h"
#include "MetodosOrdenacion.h"

class CAlgoritmoQuicksortCreciente : public CAlgoritmoSobreVectores {
public:
	CAlgoritmoQuicksortCreciente ();
	virtual  ~CAlgoritmoQuicksortCreciente ();
	virtual std::string  getDescription ();
	virtual void  SetUp (int N);
	virtual void  Execute ();
};

#endif