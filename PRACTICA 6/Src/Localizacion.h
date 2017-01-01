#ifndef __LOCALIZACION_H
#define __LOCALIZACION_H

#include <string>

template <class TClave>
int num ( const TClave &clave ) {
  return clave.num();
}

int num (int n);

int num (char ch);

int num (std::string cad);


#endif