#ifndef __CALGORITMOMERGESORTCRECIENTE_H
#define __CALGORITMOMERGESORTCRECIENTE_H

#include "AlgoritmoSobreVectores.h"
#include "MetodosGeneracion.h"
#include "MetodosOrdenacion.h"

class CAlgoritmoMergesortCreciente : public CAlgoritmoSobreVectores {
public:
	CAlgoritmoMergesortCreciente ();
	virtual  ~CAlgoritmoMergesortCreciente ();
	virtual std::string  getDescription ();
	virtual void  SetUp (int N);
	virtual void  Execute ();
};

#endif