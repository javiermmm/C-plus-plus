#include <string>
#include <ctime>
#include "MideTiempos.h"
#include "SalidaWindowsForms.h"
#include "SalidaGNUPlot.h"
#include "MedalleroTablaAbierta.h"
#include "AlgoritmoClasificacionAleatorio.h"
#include "AlgoritmoClasificacionPrimero.h"
#include "AlgoritmoClasificacionUltimo.h"
#include "AlgoritmoMedallero.h"
#include "AlgoritmoMedalleroOrdenado.h"
#include "AlgoritmoMedalleroDeporteAleatorio.h"
#include "AlgoritmoMedalleroDeporteAleatorioOrdenado.h"

#pragma once

namespace MideMedalleroWin {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			restaurar();
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén utilizando.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  lTamIni;
	protected: 
	private: System::Windows::Forms::Label^  lTamFin;
	private: System::Windows::Forms::Label^  lIncremento;
	private: System::Windows::Forms::Label^  lRepeticionesIni;
	private: System::Windows::Forms::Label^  lRepeticionesFin;
	private: System::Windows::Forms::Label^  lRuta;



	private: System::Windows::Forms::TextBox^  tbTamIni;
	private: System::Windows::Forms::TextBox^  tbTamFin;
	private: System::Windows::Forms::TextBox^  tbIncremento;
	private: System::Windows::Forms::TextBox^  tbRepeticionesIni;
	private: System::Windows::Forms::TextBox^  tbRepeticionesFin;
	private: System::Windows::Forms::TextBox^  tbRuta;
	private: System::Windows::Forms::ComboBox^  cbAlgoritmo;
	private: System::Windows::Forms::Button^  bComenzar;
	private: System::Windows::Forms::Button^  bLimpiar;
	private: System::Windows::Forms::Button^  bCambiar;
	private: System::Windows::Forms::TextBox^  tbResultados;
	private: System::Windows::Forms::ProgressBar^  pbProgreso;

	private: System::Windows::Forms::PictureBox^  pbImagen;
	private: System::Windows::Forms::FolderBrowserDialog^  folderCambiar;




	private:
		/// <summary>
		/// Variable del diseñador requerida.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido del método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->lTamIni = (gcnew System::Windows::Forms::Label());
			this->lTamFin = (gcnew System::Windows::Forms::Label());
			this->lIncremento = (gcnew System::Windows::Forms::Label());
			this->lRepeticionesIni = (gcnew System::Windows::Forms::Label());
			this->lRepeticionesFin = (gcnew System::Windows::Forms::Label());
			this->lRuta = (gcnew System::Windows::Forms::Label());
			this->tbTamIni = (gcnew System::Windows::Forms::TextBox());
			this->tbTamFin = (gcnew System::Windows::Forms::TextBox());
			this->tbIncremento = (gcnew System::Windows::Forms::TextBox());
			this->tbRepeticionesIni = (gcnew System::Windows::Forms::TextBox());
			this->tbRepeticionesFin = (gcnew System::Windows::Forms::TextBox());
			this->tbRuta = (gcnew System::Windows::Forms::TextBox());
			this->cbAlgoritmo = (gcnew System::Windows::Forms::ComboBox());
			this->bComenzar = (gcnew System::Windows::Forms::Button());
			this->bLimpiar = (gcnew System::Windows::Forms::Button());
			this->bCambiar = (gcnew System::Windows::Forms::Button());
			this->tbResultados = (gcnew System::Windows::Forms::TextBox());
			this->pbProgreso = (gcnew System::Windows::Forms::ProgressBar());
			this->pbImagen = (gcnew System::Windows::Forms::PictureBox());
			this->folderCambiar = (gcnew System::Windows::Forms::FolderBrowserDialog());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbImagen))->BeginInit();
			this->SuspendLayout();
			// 
			// lTamIni
			// 
			this->lTamIni->AutoSize = true;
			this->lTamIni->Location = System::Drawing::Point(12, 9);
			this->lTamIni->Name = L"lTamIni";
			this->lTamIni->Size = System::Drawing::Size(78, 13);
			this->lTamIni->TabIndex = 0;
			this->lTamIni->Text = L"Longitud Inicial";
			// 
			// lTamFin
			// 
			this->lTamFin->AutoSize = true;
			this->lTamFin->Location = System::Drawing::Point(12, 35);
			this->lTamFin->Name = L"lTamFin";
			this->lTamFin->Size = System::Drawing::Size(73, 13);
			this->lTamFin->TabIndex = 1;
			this->lTamFin->Text = L"Longitud Final";
			// 
			// lIncremento
			// 
			this->lIncremento->AutoSize = true;
			this->lIncremento->Location = System::Drawing::Point(12, 63);
			this->lIncremento->Name = L"lIncremento";
			this->lIncremento->Size = System::Drawing::Size(60, 13);
			this->lIncremento->TabIndex = 2;
			this->lIncremento->Text = L"Incremento";
			// 
			// lRepeticionesIni
			// 
			this->lRepeticionesIni->AutoSize = true;
			this->lRepeticionesIni->Location = System::Drawing::Point(213, 9);
			this->lRepeticionesIni->Name = L"lRepeticionesIni";
			this->lRepeticionesIni->Size = System::Drawing::Size(69, 13);
			this->lRepeticionesIni->TabIndex = 3;
			this->lRepeticionesIni->Text = L"Repeticiones";
			// 
			// lRepeticionesFin
			// 
			this->lRepeticionesFin->AutoSize = true;
			this->lRepeticionesFin->Location = System::Drawing::Point(213, 35);
			this->lRepeticionesFin->Name = L"lRepeticionesFin";
			this->lRepeticionesFin->Size = System::Drawing::Size(69, 13);
			this->lRepeticionesFin->TabIndex = 4;
			this->lRepeticionesFin->Text = L"Repeticiones";
			// 
			// lRuta
			// 
			this->lRuta->AutoSize = true;
			this->lRuta->Location = System::Drawing::Point(213, 63);
			this->lRuta->Name = L"lRuta";
			this->lRuta->Size = System::Drawing::Size(75, 13);
			this->lRuta->TabIndex = 5;
			this->lRuta->Text = L"Ruta GNUPlot";
			// 
			// tbTamIni
			// 
			this->tbTamIni->Location = System::Drawing::Point(105, 2);
			this->tbTamIni->Name = L"tbTamIni";
			this->tbTamIni->Size = System::Drawing::Size(100, 20);
			this->tbTamIni->TabIndex = 6;
			this->tbTamIni->Text = L"100";
			// 
			// tbTamFin
			// 
			this->tbTamFin->Location = System::Drawing::Point(105, 28);
			this->tbTamFin->Name = L"tbTamFin";
			this->tbTamFin->Size = System::Drawing::Size(100, 20);
			this->tbTamFin->TabIndex = 7;
			this->tbTamFin->Text = L"5000";
			// 
			// tbIncremento
			// 
			this->tbIncremento->Location = System::Drawing::Point(105, 56);
			this->tbIncremento->Name = L"tbIncremento";
			this->tbIncremento->Size = System::Drawing::Size(100, 20);
			this->tbIncremento->TabIndex = 8;
			this->tbIncremento->Text = L"100";
			// 
			// tbRepeticionesIni
			// 
			this->tbRepeticionesIni->Location = System::Drawing::Point(302, 2);
			this->tbRepeticionesIni->Name = L"tbRepeticionesIni";
			this->tbRepeticionesIni->Size = System::Drawing::Size(100, 20);
			this->tbRepeticionesIni->TabIndex = 9;
			this->tbRepeticionesIni->Text = L"5000";
			// 
			// tbRepeticionesFin
			// 
			this->tbRepeticionesFin->Location = System::Drawing::Point(302, 28);
			this->tbRepeticionesFin->Name = L"tbRepeticionesFin";
			this->tbRepeticionesFin->Size = System::Drawing::Size(100, 20);
			this->tbRepeticionesFin->TabIndex = 10;
			this->tbRepeticionesFin->Text = L"5000";
			// 
			// tbRuta
			// 
			this->tbRuta->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->tbRuta->Location = System::Drawing::Point(302, 56);
			this->tbRuta->Name = L"tbRuta";
			this->tbRuta->Size = System::Drawing::Size(422, 20);
			this->tbRuta->TabIndex = 11;
			// 
			// cbAlgoritmo
			// 
			this->cbAlgoritmo->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->cbAlgoritmo->FormattingEnabled = true;
			this->cbAlgoritmo->Items->AddRange(gcnew cli::array< System::Object^  >(7) {L"Medallero", L"Medallero Ordenado", L"Medallero por Deporte Aleatorio", 
				L"Medallero por Deporte Aleatorio Ordenado", L"Clasificación Primero", L"Clasificación Último", L"Clasificacion Aleatorio"});
			this->cbAlgoritmo->Location = System::Drawing::Point(522, 14);
			this->cbAlgoritmo->Name = L"cbAlgoritmo";
			this->cbAlgoritmo->Size = System::Drawing::Size(267, 21);
			this->cbAlgoritmo->TabIndex = 12;
			this->cbAlgoritmo->Text = L"Algoritmo...";
			// 
			// bComenzar
			// 
			this->bComenzar->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->bComenzar->Location = System::Drawing::Point(795, 2);
			this->bComenzar->Name = L"bComenzar";
			this->bComenzar->Size = System::Drawing::Size(131, 42);
			this->bComenzar->TabIndex = 13;
			this->bComenzar->Text = L"&Comenzar Pruebas";
			this->bComenzar->UseVisualStyleBackColor = true;
			this->bComenzar->Click += gcnew System::EventHandler(this, &Form1::bComenzar_Click);
			// 
			// bLimpiar
			// 
			this->bLimpiar->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->bLimpiar->Location = System::Drawing::Point(851, 54);
			this->bLimpiar->Name = L"bLimpiar";
			this->bLimpiar->Size = System::Drawing::Size(75, 23);
			this->bLimpiar->TabIndex = 14;
			this->bLimpiar->Text = L"&Restaurar";
			this->bLimpiar->UseVisualStyleBackColor = true;
			this->bLimpiar->Click += gcnew System::EventHandler(this, &Form1::bLimpiar_Click);
			// 
			// bCambiar
			// 
			this->bCambiar->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->bCambiar->Location = System::Drawing::Point(730, 53);
			this->bCambiar->Name = L"bCambiar";
			this->bCambiar->Size = System::Drawing::Size(75, 23);
			this->bCambiar->TabIndex = 15;
			this->bCambiar->Text = L"C&ambiar";
			this->bCambiar->UseVisualStyleBackColor = true;
			this->bCambiar->Click += gcnew System::EventHandler(this, &Form1::bCambiar_Click);
			// 
			// tbResultados
			// 
			this->tbResultados->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left));
			this->tbResultados->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->tbResultados->Location = System::Drawing::Point(15, 120);
			this->tbResultados->Multiline = true;
			this->tbResultados->Name = L"tbResultados";
			this->tbResultados->ReadOnly = true;
			this->tbResultados->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->tbResultados->Size = System::Drawing::Size(212, 511);
			this->tbResultados->TabIndex = 16;
			// 
			// pbProgreso
			// 
			this->pbProgreso->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->pbProgreso->Location = System::Drawing::Point(15, 91);
			this->pbProgreso->Name = L"pbProgreso";
			this->pbProgreso->Size = System::Drawing::Size(911, 23);
			this->pbProgreso->Style = System::Windows::Forms::ProgressBarStyle::Continuous;
			this->pbProgreso->TabIndex = 17;
			// 
			// pbImagen
			// 
			this->pbImagen->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->pbImagen->ImageLocation = L"";
			this->pbImagen->Location = System::Drawing::Point(276, 135);
			this->pbImagen->Name = L"pbImagen";
			this->pbImagen->Size = System::Drawing::Size(625, 475);
			this->pbImagen->TabIndex = 18;
			this->pbImagen->TabStop = false;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(927, 643);
			this->Controls->Add(this->pbImagen);
			this->Controls->Add(this->pbProgreso);
			this->Controls->Add(this->tbResultados);
			this->Controls->Add(this->bCambiar);
			this->Controls->Add(this->bLimpiar);
			this->Controls->Add(this->bComenzar);
			this->Controls->Add(this->cbAlgoritmo);
			this->Controls->Add(this->tbRuta);
			this->Controls->Add(this->tbRepeticionesFin);
			this->Controls->Add(this->tbRepeticionesIni);
			this->Controls->Add(this->tbIncremento);
			this->Controls->Add(this->tbTamFin);
			this->Controls->Add(this->tbTamIni);
			this->Controls->Add(this->lRuta);
			this->Controls->Add(this->lRepeticionesFin);
			this->Controls->Add(this->lRepeticionesIni);
			this->Controls->Add(this->lIncremento);
			this->Controls->Add(this->lTamFin);
			this->Controls->Add(this->lTamIni);
			this->Name = L"Form1";
			this->Text = L"Mide medallero";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbImagen))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	//Eventos
	private: System::Void bLimpiar_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void bCambiar_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void bComenzar_Click(System::Object^  sender, System::EventArgs^  e);

	//Funciones Auxiliares
	void vaciarResultados();
	void restaurar();
	void muestraGrafica(const std::string& nombre);
		 
};
}

