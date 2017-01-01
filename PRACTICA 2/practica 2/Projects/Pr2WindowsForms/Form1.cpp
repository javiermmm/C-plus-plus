#include "Form1.h"

namespace Pr2WindowsForms {

System::Void Form1::bLimpiar_Click(System::Object^  sender, System::EventArgs^  e) {

	tbResultados->Clear();		 
}

System::Void Form1::bComenzar_Click(System::Object^  sender, System::EventArgs^  e) {

			 CSalidaWindowsForms* salida = new CSalidaWindowsForms (this->tbResultados);

			 CMideTiempos medicion (System::Convert::ToInt32(this->tbTamIni->Text), System::Convert::ToInt32(this->tbTamFin->Text), System::Convert::ToInt32(this->tbIncremento->Text), System::Convert::ToInt32(this->tbRepeticionesIni->Text), System::Convert::ToInt32(this->tbRepeticionesFin->Text));
			 
			 CAlgoritmo* alg;
			 std::string nombre;
			 if (this->cbAlgoritmo->SelectedIndex != -1){
				 switch (this->cbAlgoritmo->SelectedIndex) {
					case 0: if (this->cbDatos->SelectedIndex != -1)
							 switch (this->cbDatos->SelectedIndex) { 
								 case 0: {alg = new CAlgoritmoInsercionCreciente();
										  nombre = "insercionCreciente.txt";
										  break;
										 }
								 case 1: {alg = new CAlgoritmoInsercionDecreciente();
										  nombre = "insercionDecreciente.txt";
										  break;
										 }
								 case 2: {alg = new CAlgoritmoInsercionAleatorio();
										  nombre = "insercionAleatorio.txt";
										  break;
										 }
							 }
							 break;
					case 1: if (this->cbDatos->SelectedIndex != -1)
							 switch (this->cbDatos->SelectedIndex) { 
								 case 0: {alg = new CAlgoritmoSeleccionCreciente();
										  nombre = "seleccionCreciente.txt";
										  break;
										 }
								 case 1: {alg = new CAlgoritmoInsercionDecreciente();
										  nombre = "seleccionDecreciente.txt";
										  break;
										 }
								 case 2: {alg = new CAlgoritmoInsercionAleatorio();
										  nombre = "seleccionAleatorio.txt";
										  break;
										 }
							 }
							 break;
					case 2: if (this->cbDatos->SelectedIndex != -1)
							 switch (this->cbDatos->SelectedIndex) { 
								 case 0: {alg = new CAlgoritmoBurbujaCreciente();
										  nombre = "burbujaCreciente.txt";
										  break;
										 }
								 case 1: {alg = new CAlgoritmoBurbujaDecreciente();
										  nombre = "burbujaDecreciente.txt";
										  break;
										 }
								 case 2: {alg = new CAlgoritmoBurbujaAleatorio();
										  nombre = "burbujaAleatorio.txt";
										  break;
										 }
							 }
							 break;
					case 3: if (this->cbDatos->SelectedIndex != -1)
							 switch (this->cbDatos->SelectedIndex) { 
								 case 0: {alg = new CAlgoritmoQuicksortCreciente();
										  nombre = "quicksortCreciente.txt";
										  break;
										 }
								 case 1: {alg = new CAlgoritmoQuicksortDecreciente();
										  nombre = "quicksortDecreciente.txt";
										  break;
										 }
								 case 2: {alg = new CAlgoritmoQuicksortAleatorio();
										  nombre = "quicksortAleatorio.txt";
										  break;
										 }
							 }
							 break;
					case 4: if (this->cbDatos->SelectedIndex != -1)
							 switch (this->cbDatos->SelectedIndex) { 
								 case 0: {alg = new CAlgoritmoMergesortCreciente();
										  nombre = "mezclaCreciente.txt";
										  break;
										 }
								 case 1: {alg = new CAlgoritmoMergesortDecreciente();
										  nombre = "mezclaDecreciente.txt";
										  break;
										 }
								 case 2: {alg = new CAlgoritmoMergesortAleatorio();
										  nombre = "mezclaAleatorio.txt";
										  break;
										 }
							 }
							 break;
				}
			 }
				 
			 CSalidaGNUPlot* salida2 = NULL;
			 if (this->checkGNUPlot->Checked)
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
				int horas = ((tiempo / 3600));
				int minutos = (((int(tiempo) % 3600) / 60));
				float segundos = float (((int(tiempo) % 3600) % 60));
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
			 if (this->checkGNUPlot->Checked)
				 delete salida2;
}

}