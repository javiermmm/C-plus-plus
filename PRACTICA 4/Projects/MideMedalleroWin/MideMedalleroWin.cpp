// MideMedalleroWin.cpp: archivo de proyecto principal.

#include "Form1.h"

using namespace MideMedalleroWin;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Habilitar los efectos visuales de Windows XP antes de crear ning�n control
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Crear la ventana principal y ejecutarla
	Application::Run(gcnew Form1());
	return 0;
}
