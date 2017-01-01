#include "SalidaWindowsForms.h"

using namespace std;

void CSalidaWindowsForms::setNumPasos (int numPasos){
     _numPasos = numPasos;
}

CSalidaWindowsForms::CSalidaWindowsForms (gcroot<System::Windows::Forms::TextBox ^> tb, gcroot<System::Windows::Forms::ProgressBar ^> barra) {

	_tb = tb;
	_barra = barra;
}

CSalidaWindowsForms::~CSalidaWindowsForms () {}

void  CSalidaWindowsForms::InitPrueba (const std::string &desc){

	string lineas = "\r\n-------------------------------------------------------\r\n";
	_tb->AppendText(System::String(desc.c_str()).ToString());
	_tb->AppendText(System::String(lineas.c_str()).ToString());
	_barra->Minimum = 0;
	_barra->Value = _barra->Minimum;
	_barra->Maximum = _numPasos;
}

void  CSalidaWindowsForms::Muestra (int tam, float tiempo){

	_tb ->AppendText(tam.ToString());

	string espacios = "               ";
	_tb->AppendText(System::String(espacios.c_str()).ToString());

	_tb->AppendText(tiempo.ToString());

	string salto = "\r\n";
	_tb->AppendText(System::String(salto.c_str()).ToString());

	_barra->Value++;
}

void  CSalidaWindowsForms::FinPrueba (){

	string fin = "-----------------------FIN DATOS-----------------------\r\n\r\n\r\n";
	_tb->AppendText(System::String(fin.c_str()).ToString());
}