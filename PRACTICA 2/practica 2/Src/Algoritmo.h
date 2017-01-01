#ifndef __CALGORITMO_H
#define __CALGORITMO_H

#include <string>

class CAlgoritmo {
public:
	CAlgoritmo () {}
	virtual  ~CAlgoritmo () {}
	virtual std::string  getDescription ()=0 {}
	virtual void  SetUp (int N)=0 {}
	virtual void  Execute ()=0 {}
	virtual void  TearDown ()=0 {}
};



#endif