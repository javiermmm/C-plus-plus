#include "Form1.h"
using namespace std;
using namespace System::Runtime::InteropServices;

namespace MideMedalleroWin {

	void Form1::vaciarResultados() {

		this->cbAlgoritmo->SelectedIndex = -1;
		this->cbAlgoritmo->Text = L"Algoritmo...";
		this->tbResultados->Clear();
		this->pbProgreso->Value = 0;
		delete pbImagen->Image;
	}

	void Form1::restaurar () {

		vaciarResultados();
		this->tbRuta->Text = System::Environment::CurrentDirectory;
		this->tbTamIni->Text = L"100";
		this->tbTamFin->Text = L"5000";
		this->tbIncremento->Text = L"100";
		this->tbRepeticionesIni->Text = L"5000";
		this->tbRepeticionesFin->Text = L"5000";
		this->pbImagen->Image = System::Drawing::Image::FromFile("logo.png");
	}

	void Form1::muestraGrafica (const string& nombre) {

		std::string rutaAux = (char*)(void*)Marshal::StringToHGlobalAnsi(this->tbRuta->Text);
		string orden1 = rutaAux + "\\wgnuplot.exe -e \"set terminal png; set output \\\"file.png\\\"; plot \\\"";
		orden1 += nombre;
		orden1 += "\\\" with lines lw 2\"";
		if (system (orden1.c_str()) != 0 )
			System::Windows::Forms::MessageBox::Show("          ERROR: No se pudo generar la gráfica.\nRevise la configuración de la prueba y vuelva a intentarlo.", "GRAFICA NO GENERADA");
		delete pbImagen->Image;
		this->pbImagen->Image = System::Drawing::Image::FromFile("file.png");
	}

	System::Void Form1::bLimpiar_Click(System::Object^  sender, System::EventArgs^  e) {
	
		restaurar();

	}

	System::Void Form1::bCambiar_Click(System::Object^  sender, System::EventArgs^  e) {

		this->folderCambiar->SelectedPath = this->tbRuta->Text;
		if (this->folderCambiar->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			if (System::IO::File::Exists(this->folderCambiar->SelectedPath + "\\wgnuplot.exe"))
				this->tbRuta->Text = this->folderCambiar->SelectedPath;
			else
				System::Windows::Forms::MessageBox::Show("ERROR: el fichero wgnuplot.exe no se encuentra en la ruta especificada", "ARCHIVO NO ENCONTRADO");
	}

	System::Void Form1::bComenzar_Click(System::Object^  sender, System::EventArgs^  e) {

			delete pbImagen->Image;
			this->pbImagen->Image = System::Drawing::Image::FromFile("logo.png");
			tbResultados->Clear();			
			this->Refresh();

			
			if (this->cbAlgoritmo->SelectedIndex == -1)
				System::Windows::Forms::MessageBox::Show("ERROR: No puede lanzar una prueba sin seleccionar un algoritmo", "ALGORITMO INCORRECTO");
			else {
				if (! System::IO::File::Exists(this->tbRuta->Text + "\\wgnuplot.exe"))
					System::Windows::Forms::MessageBox::Show("ERROR: Recuerde cambiar la ruta", "RUTA INCORRECTA");
				else {

					 CSalidaWindowsForms* salida = new CSalidaWindowsForms (this->tbResultados, this->pbProgreso);
					 salida->setNumPasos (((System::Convert::ToInt32(tbTamFin->Text)) - (System::Convert::ToInt32(tbTamIni->Text))) / (System::Convert::ToInt32(tbIncremento->Text)) +1);

					 if ((this->tbTamIni->Text != "") && (this->tbTamFin->Text != "") && (this->tbIncremento->Text != "") && (this->tbRepeticionesIni->Text != "") && (this->tbRepeticionesFin->Text != "")) {

						 CMideTiempos medicion (System::Convert::ToInt32(this->tbTamIni->Text), System::Convert::ToInt32(this->tbTamFin->Text), System::Convert::ToInt32(this->tbIncremento->Text), System::Convert::ToInt32(this->tbRepeticionesIni->Text), System::Convert::ToInt32(this->tbRepeticionesFin->Text));
			 
						 CAlgoritmo* alg;
						 std::string nombre;
						 std::string nomFichero;
						 if (this->cbAlgoritmo->SelectedIndex != -1){
								 switch (this->cbAlgoritmo->SelectedIndex) {
									case 0:  {alg = new CAlgoritmoMedallero();
											  nombre = "Medallero_NPaises.txt";
											  nomFichero = "Medallero_NPaises.png";
											  break;
											 }

									case 1: {alg = new CAlgoritmoMedalleroOrdenado();
											 nombre = "MedalleroOrdenado_NPaises.txt";
											 nomFichero = "MedalleroOrdenado_NPaises.png";
											 break;
											}

									case 2: {alg = new CAlgoritmoMedalleroDeporteAleatorio();
											 nombre = "MedalleroDeporte_DeporteAleatorio.txt";
											 nomFichero = "MedalleroDeporte_DeporteAleatorio.png";
											 break;
											}
									
									case 3: {alg = new CAlgoritmoMedalleroDeporteAleatorioOrdenado();
											 nombre = "MedalleroDeporteOrdenado_DeporteAleatorio.txt";
											 nomFichero = "MedalleroDeporteOrdenado_DeporteAleatorio.png";
											 break;
											}
									 
									case 4: {alg = new CAlgoritmoClasificacionPrimero();
											 nombre = "Clasif_NPaisesPrimero.txt";
											 nomFichero = "Clasif_NPaisesPrimero.png";
											 break;
											}

									case 5: {alg = new CAlgoritmoClasificacionUltimo;
											 nombre = "Clasif_NPaisesUltimo.txt";
											 nomFichero = "Clasif_NPaisesUltimo.png";
											 break;
											}

									case 6: {alg = new CAlgoritmoClasificacionAleatorio();
											 nombre = "Clasif_NPaisesAleatorio.txt";
											 nomFichero = "Clasif_NPaisesAleatorio.png";
											 break;
											}
								}
				 
				 
							 CSalidaGNUPlot* salida2 = NULL;
					
							 salida2 = new CSalidaGNUPlot (nombre);
			 
							 //Mostrar el tiempo total de las ejecuciones en formato HH:MM:SS
							 clock_t t1 = clock ();
							 medicion.LanzaPrueba(alg,salida,salida2);
							 clock_t t2 = clock ();
							 float tiempo =  (float(t2-t1) / CLOCKS_PER_SEC);

							 int horas = 0;
							 int minutos = 0;
							 float segundos = tiempo;
							 if (tiempo > 1){
								horas = ((tiempo / 3600));
								minutos = (((int(tiempo) % 3600) / 60));
								segundos = float (((int(tiempo) % 3600) % 60));
							 }
								std::string ttotal = "\r\n\r\n El tiempo total empleado ha sido de ";
								std::string cero = "0";
								std::string puntos = ":";
								tbResultados->AppendText(System::String(ttotal.c_str()).ToString()); 
								if (horas < 10)
									tbResultados->AppendText(System::String(cero.c_str()).ToString());	

								tbResultados->AppendText(horas.ToString());

								tbResultados->AppendText(System::String(puntos.c_str()).ToString());	
								if (minutos < 10)
									tbResultados->AppendText(System::String(cero.c_str()).ToString());	

								tbResultados->AppendText(minutos.ToString());

								tbResultados->AppendText(System::String(puntos.c_str()).ToString());	
								if (segundos < 10)
									tbResultados->AppendText(System::String(cero.c_str()).ToString());
				
								tbResultados->AppendText(segundos.ToString());

							//Borrado de recursos
							 delete alg;
							 delete salida;
							 delete salida2;

							 //Invocar GNUPlot						 
							 muestraGrafica(nombre);
							  
						}
					}
				}
			}
}

}