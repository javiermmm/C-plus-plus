#include "Form1.h"
using namespace std;
using namespace System::Runtime::InteropServices;

namespace TreeWindowsForms {

	//Función que dado el nombre completo del fichero te devuelve la extensión,si tiene
	//nombreFichero[IN] : cadena que representa el nombre completo del fichero
	//Devolvemos una cadena con la extrensión
	string Form1::dameExtension (string nombreFichero) {
	
		int posPunto = nombreFichero.find('.', 0);
		if (posPunto == std::string::npos)
			return "";
		string ret = nombreFichero.substr (posPunto, (nombreFichero.length() - posPunto));
		return ret;
	}


	//Función que dado el nobre del fichero nos devuelve el color con el que se va a pintar
	//nombreFichero[IN] : cadena que representa el nombre completo del fichero
	//Devolvemos una "Brocha" con un color asignado, que usaremos para pintar en la ventana
	System::Drawing::Brush^ Form1::ponColor (string nombreFichero) {

		//Ficheros ejecutables o de código objeto (Azul)
		if (dameExtension(nombreFichero) == ".exe")
			return System::Drawing::Brushes::Blue;
		if (dameExtension(nombreFichero) == ".obj")
			return System::Drawing::Brushes::Blue;
		if (dameExtension(nombreFichero) == ".dll")
			return System::Drawing::Brushes::Blue;
		if (dameExtension(nombreFichero) == ".lib")
			return System::Drawing::Brushes::Blue;

		//cheros de código fuente y relacionados con Visual Studio (Rojo)
		if (dameExtension(nombreFichero) == ".h")
			return System::Drawing::Brushes::Red;
		if (dameExtension(nombreFichero) == ".cpp")
			return System::Drawing::Brushes::Red;
		if (dameExtension(nombreFichero) == ".vcproj")
			return System::Drawing::Brushes::Red;
		if (dameExtension(nombreFichero) == ".sln")
			return System::Drawing::Brushes::Red;

		//Los cheros de imágenes (Verde)
		if (dameExtension(nombreFichero) == ".jpg")
			return System::Drawing::Brushes::DarkGreen;
		if (dameExtension(nombreFichero) == ".bmp")
			return System::Drawing::Brushes::DarkGreen;
		if (dameExtension(nombreFichero) == ".png")
			return System::Drawing::Brushes::DarkGreen;
		if (dameExtension(nombreFichero) == ".ico")
			return System::Drawing::Brushes::DarkGreen;

		//documentos (Naranja)
		if (dameExtension(nombreFichero) == ".txt")
			return System::Drawing::Brushes::Orange;
		if (dameExtension(nombreFichero) == ".doc")
			return System::Drawing::Brushes::Orange;
		if (dameExtension(nombreFichero) == ".htm")
			return System::Drawing::Brushes::Orange;
		if (dameExtension(nombreFichero) == ".html")
			return System::Drawing::Brushes::Orange;
		if (dameExtension(nombreFichero) == ".tex")
			return System::Drawing::Brushes::Orange;
		
		//Para el resto (Marrón)
		return System::Drawing::Brushes::Brown;
	}

	//Función auxiliar que realiza la recursion para pintar los directorios (primero los ficheros y luego los subdirectorios).
	//ruta[IN]: representa la ruta del directorio a calcular
	//tamDirectorio[IN]: almacena el tamaño del directorio que vamos a pintar
	//recuadro[IN]: representa el objeto a partir del cual podemos pintar en el panel
	//x[IN]: representa la coordenada x
	//y[IN]: representa la coordenada y
	//alto[IN]:  representa el alto del área del recuadro 
	//ancho[IN]: representa el ancho del área del recuadro
	//partirEnVertical[IN]: indica si las líneas se hacen en vertical (True), o en horizontal (false)
	void Form1::pintaRecur (string ruta, unsigned long tamDirectorio, Graphics^ recuadro, float esqX, float esqY, float altoInicial, float anchoInicial, bool partirEnVertical) {
		
		CArbolDirectorios ad;
		CRecorreDirectorio* rd = new CRecorreDirectorio (ruta);

		float x = esqX;
		float y = esqY;
		float ancho = anchoInicial;
		float alto = altoInicial;
		float xInicial = x;
		float yInicial = y;

		//Pintamos los Ficheros que haya en el directorio indicado en la ruta
		while (!rd->esFin()) {
			CRecorreDirectorio::TInfoEntrada info = rd->info();
			if (info.esFichero) {
				unsigned long tamFichero = info.tam;
				double tamProporcional = (double) tamFichero / tamDirectorio;
				if (partirEnVertical) 
					ancho = tamProporcional * anchoInicial;
				else 
					alto = tamProporcional * altoInicial;
				
				System::Drawing::Brush ^ brush;
				brush = ponColor (info.nombre);
				recuadro->FillRectangle (brush, x, y, ancho, alto);
				System::Drawing::Pen ^ pencil;
				pencil = System::Drawing::Pens::White;
				recuadro->DrawRectangle (pencil, x, y, ancho, alto);
				
				
				if (partirEnVertical)
					x += ancho; 
				else
					y += alto; 
			}
			rd->avanza();
		}
		delete rd;

		//Pintamos recursivamente las carpetas que estén al mismo nivel
		rd = new CRecorreDirectorio (ruta);
		while (!rd->esFin()) {
			CRecorreDirectorio::TInfoEntrada info = rd->info();
			if (!info.esFichero) {
				unsigned long tamSubCarpeta = ad.tamDirectorio (ruta + "\\" + info.nombre);
				double tamProporcional = (double) tamSubCarpeta / tamDirectorio;
				if (partirEnVertical) 
					ancho = tamProporcional * anchoInicial;
				else 
					alto = tamProporcional * altoInicial;
					
				if(ancho * alto >= 25)
						pintaRecur (ruta + "\\" + info.nombre, tamSubCarpeta, recuadro, x, y, alto , ancho, !partirEnVertical);
				else {
					System::Drawing::Brush ^ penBlack;
					penBlack = System::Drawing::Brushes::Black;
					recuadro->FillRectangle (penBlack, x, y, ancho, alto);
				}
				
				if(partirEnVertical)
					x += ancho ;
				else
					y += alto ;
					
			}
			rd->avanza();
		}
		delete rd;
	} 
	
	//Función que a partir del area del recuadro en el que se muestra la escala,
	//traduce el tamaño proporcional en bytes, Kb, Mb, o Gb
	//escala[IN]: representa la escala en bytes 
	void Form1::traducirTamaño (float escala) {

		if (escala < 1024)
			this->lTamEscala->Text = escala.ToString() + " bytes";
		else {
			int escKb = escala / 1024;
			if (escKb < 1024)
				this->lTamEscala->Text = escKb.ToString() + "Kb";
			else {
				int escMb = escKb / 1024;
				if (escMb < 1024)
					this->lTamEscala->Text = escMb.ToString() + "Mb";
				else {
					int escGb = escMb / 1024;
					if (escGb < 1024)
						this->lTamEscala->Text = escGb.ToString() + "Gb";
				}
			}
		}
	}

	//Función que pinta el directorio indicado por la ruta, en el panel definido 
	//por el objeto recuadro, sus medidas y las cordenadas de uno de sus vértices
	//ruta[IN]: representa la ruta del directorio a calcular
	//tamDirectorio[IN]: almacena el tamaño del directorio que vamos a pintar
	//recuadro[IN]: representa el objeto a partir del cual podemos pintar en el panel
	//x[IN]: representa la coordenada x
	//y[IN]: representa la coordenada y
	//alto[IN]:  representa el alto del área del recuadro 
	//ancho[IN]: representa el ancho del área del recuadro
	void Form1::pinta (string ruta, Graphics^ recuadro, int x, int y, int alto, int ancho){
	
		//Inicializaciones e invocacion a la funcion recursiva
		bool partirEnVertical = true;
		CArbolDirectorios ad;
		unsigned long tamañoDirectorio = ad.tamDirectorio (ruta);
		pintaRecur(ruta, tamañoDirectorio, recuadro, x, y, alto, ancho, partirEnVertical);

		//Poner la escala usada
		int altoPeque = this->panelEscala->Size.Height;
		int anchoPeque = this->panelEscala->Size.Width;
		float escala = (tamañoDirectorio * float (anchoPeque * altoPeque)) / (ancho * alto);
		traducirTamaño (escala);
	}

	//Función que implementa el evento que se desencadena cuando el usuario pulsa en el boton Dibujar
	System::Void Form1::bDibujar_Click(System::Object^  sender, System::EventArgs^  e) {

		Graphics^ recuadro = this->panelDibujo->CreateGraphics();
		String^ rutaCLR = this->lRuta->Text;
		string ruta = (char*)(void*)Marshal::StringToHGlobalAnsi(rutaCLR);
		int alto = this->panelDibujo->Size.Height;
		int ancho = this->panelDibujo->Size.Width;
		
		//Pintar de amarillo
		System::Drawing::Pen ^ pencil;
		pencil = System::Drawing::Pens::Yellow;
		recuadro->FillRectangle(pencil->Brush, 0, 0, ancho-1, alto-1);
		Graphics^ cuadrito = this->panelEscala->CreateGraphics();
		cuadrito->FillRectangle(pencil->Brush, 0, 0, ancho, alto);

		//Borrar la escala
		this->lTamEscala->Text = "";
		
		pinta (ruta, recuadro, 0, 0, alto, ancho);

		//Pintar cuadrito
		pencil = System::Drawing::Pens::Brown;
		cuadrito->FillRectangle(pencil->Brush, 0, 0, ancho, alto);

	}

	//Función que implementa el evento que se desencadena cuando el usuario pulsa en el boton Cambiar
	System::Void Form1::bCambiar_Click(System::Object^  sender, System::EventArgs^  e) {

		if (this->folderCambiar->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			this->lRuta->Text = this->folderCambiar->SelectedPath;
	}

	//Función que implementa el evento que se desencadena cuando se abre la ventana por primera vez
	System::Void Form1::Form1_Load(System::Object^  sender, System::EventArgs^  e) {
		lRuta->Text = System::Environment::CurrentDirectory;
	}

}