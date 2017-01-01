#include "SalidaWindowsForms.h"

using namespace std;

CSalidaWindowsForms::CSalidaWindowsForms (gcroot<System::Windows::Forms::TextBox ^> tb) {

	_tb = tb;
}

CSalidaWindowsForms::~CSalidaWindowsForms () {}

void  CSalidaWindowsForms::InitPrueba (const std::string &desc){

	string lineas = "\r\n-------------------------------------------------------\r\n";
	_tb->AppendText(System::String(desc.c_str()).ToString());
	_tb->AppendText(System::String(lineas.c_str()).ToString());
}

void  CSalidaWindowsForms::Muestra (int tam, float tiempo){

	_tb ->AppendText(tam.ToString());

	string espacios = "               ";
	_tb->AppendText(System::String(espacios.c_str()).ToString());

	_tb->AppendText(tiempo.ToString());

	string salto = "\r\n";
	_tb->AppendText(System::String(salto.c_str()).ToString());
}

void  CSalidaWindowsForms::FinPrueba (){

	string fin = "-----------------------FIN DATOS-----------------------\r\n\r\n\r\n";
	_tb->AppendText(System::String(fin.c_str()).ToString());
}