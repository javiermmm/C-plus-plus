#include "Localizacion.h"
using namespace std;

int num( int n ) {
  return n;
}

int num( char ch ) {
  return ch;
}

int num( string cad ) {
  int res = 0;
  for ( int i = 0; i < cad.length(); i++ )
    res += cad[i];
  return res;
}

/*
using namespace std;

template<>
int num<string*>( string* puntero ) {
  return int(puntero);
}
*/