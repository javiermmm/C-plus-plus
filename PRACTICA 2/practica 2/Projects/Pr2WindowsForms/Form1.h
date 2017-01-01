#include <string>
#include <ctime>
#include "MideTiempos.h"
#include "SalidaWindowsForms.h"
#include "SalidaGNUPlot.h"
#include "AlgoritmoBurbujaAleatorio.h"
#include "AlgoritmoBurbujaCreciente.h"
#include "AlgoritmoBurbujaDecreciente.h"
#include "AlgoritmoInsercionAleatorio.h"
#include "AlgoritmoInsercionCreciente.h"
#include "AlgoritmoInsercionDecreciente.h"
#include "AlgoritmoMergesortAleatorio.h"
#include "AlgoritmoMergesortCreciente.h"
#include "AlgoritmoMergesortDecreciente.h"
#include "AlgoritmoQuicksortAleatorio.h"
#include "AlgoritmoQuicksortCreciente.h"
#include "AlgoritmoQuicksortDecreciente.h"
#include "AlgoritmoSeleccionAleatorio.h"
#include "AlgoritmoSeleccionCreciente.h"
#include "AlgoritmoSeleccionDecreciente.h"
#pragma once

namespace Pr2WindowsForms {

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
	private: System::Windows::Forms::Button^  bComenzar;
	protected: 
	private: System::Windows::Forms::Button^  bLimpiar;
	private: System::Windows::Forms::Label^  lTamIni;
	private: System::Windows::Forms::Label^  lTamFin;
	private: System::Windows::Forms::Label^  lIncremento;
	private: System::Windows::Forms::Label^  lRepeticionesIni;
	private: System::Windows::Forms::Label^  lRepeticionesFin;
	private: System::Windows::Forms::CheckBox^  checkGNUPlot;
	private: System::Windows::Forms::ComboBox^  cbAlgoritmo;
	private: System::Windows::Forms::ComboBox^  cbDatos;
	private: System::Windows::Forms::TextBox^  tbTamIni;
	private: System::Windows::Forms::TextBox^  tbTamFin;
	private: System::Windows::Forms::TextBox^  tbIncremento;
	private: System::Windows::Forms::TextBox^  tbRepeticionesIni;
	private: System::Windows::Forms::TextBox^  tbRepeticionesFin;
	private: System::Windows::Forms::TextBox^  tbResultados;

	protected: 


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
			this->bComenzar = (gcnew System::Windows::Forms::Button());
			this->bLimpiar = (gcnew System::Windows::Forms::Button());
			this->lTamIni = (gcnew System::Windows::Forms::Label());
			this->lTamFin = (gcnew System::Windows::Forms::Label());
			this->lIncremento = (gcnew System::Windows::Forms::Label());
			this->lRepeticionesIni = (gcnew System::Windows::Forms::Label());
			this->lRepeticionesFin = (gcnew System::Windows::Forms::Label());
			this->checkGNUPlot = (gcnew System::Windows::Forms::CheckBox());
			this->cbAlgoritmo = (gcnew System::Windows::Forms::ComboBox());
			this->cbDatos = (gcnew System::Windows::Forms::ComboBox());
			this->tbTamIni = (gcnew System::Windows::Forms::TextBox());
			this->tbTamFin = (gcnew System::Windows::Forms::TextBox());
			this->tbIncremento = (gcnew System::Windows::Forms::TextBox());
			this->tbRepeticionesIni = (gcnew System::Windows::Forms::TextBox());
			this->tbRepeticionesFin = (gcnew System::Windows::Forms::TextBox());
			this->tbResultados = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// bComenzar
			// 
			this->bComenzar->Location = System::Drawing::Point(39, 165);
			this->bComenzar->Name = L"bComenzar";
			this->bComenzar->Size = System::Drawing::Size(132, 45);
			this->bComenzar->TabIndex = 0;
			this->bComenzar->Text = L"&Comenzar Pruebas";
			this->bComenzar->UseVisualStyleBackColor = true;
			this->bComenzar->Click += gcnew System::EventHandler(this, &Form1::bComenzar_Click);
			// 
			// bLimpiar
			// 
			this->bLimpiar->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->bLimpiar->Location = System::Drawing::Point(277, 165);
			this->bLimpiar->Name = L"bLimpiar";
			this->bLimpiar->Size = System::Drawing::Size(130, 44);
			this->bLimpiar->TabIndex = 1;
			this->bLimpiar->Text = L"&Limpiar";
			this->bLimpiar->UseVisualStyleBackColor = true;
			this->bLimpiar->Click += gcnew System::EventHandler(this, &Form1::bLimpiar_Click);
			// 
			// lTamIni
			// 
			this->lTamIni->AutoSize = true;
			this->lTamIni->Location = System::Drawing::Point(36, 25);
			this->lTamIni->Name = L"lTamIni";
			this->lTamIni->Size = System::Drawing::Size(78, 13);
			this->lTamIni->TabIndex = 2;
			this->lTamIni->Text = L"Longitud Inicial";
			// 
			// lTamFin
			// 
			this->lTamFin->AutoSize = true;
			this->lTamFin->Location = System::Drawing::Point(43, 51);
			this->lTamFin->Name = L"lTamFin";
			this->lTamFin->Size = System::Drawing::Size(71, 13);
			this->lTamFin->TabIndex = 3;
			this->lTamFin->Text = L"Longtud Final";
			// 
			// lIncremento
			// 
			this->lIncremento->AutoSize = true;
			this->lIncremento->Location = System::Drawing::Point(10, 79);
			this->lIncremento->Name = L"lIncremento";
			this->lIncremento->Size = System::Drawing::Size(104, 13);
			this->lIncremento->TabIndex = 4;
			this->lIncremento->Text = L"Incremento Longitud";
			// 
			// lRepeticionesIni
			// 
			this->lRepeticionesIni->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->lRepeticionesIni->AutoSize = true;
			this->lRepeticionesIni->Location = System::Drawing::Point(258, 23);
			this->lRepeticionesIni->Name = L"lRepeticionesIni";
			this->lRepeticionesIni->Size = System::Drawing::Size(69, 13);
			this->lRepeticionesIni->TabIndex = 5;
			this->lRepeticionesIni->Text = L"Repeticiones";
			// 
			// lRepeticionesFin
			// 
			this->lRepeticionesFin->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->lRepeticionesFin->AutoSize = true;
			this->lRepeticionesFin->Location = System::Drawing::Point(258, 51);
			this->lRepeticionesFin->Name = L"lRepeticionesFin";
			this->lRepeticionesFin->Size = System::Drawing::Size(69, 13);
			this->lRepeticionesFin->TabIndex = 6;
			this->lRepeticionesFin->Text = L"Repeticiones";
			// 
			// checkGNUPlot
			// 
			this->checkGNUPlot->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->checkGNUPlot->AutoSize = true;
			this->checkGNUPlot->Location = System::Drawing::Point(261, 74);
			this->checkGNUPlot->Name = L"checkGNUPlot";
			this->checkGNUPlot->Size = System::Drawing::Size(68, 17);
			this->checkGNUPlot->TabIndex = 7;
			this->checkGNUPlot->Text = L"GNUPlot";
			this->checkGNUPlot->UseVisualStyleBackColor = true;
			// 
			// cbAlgoritmo
			// 
			this->cbAlgoritmo->FormattingEnabled = true;
			this->cbAlgoritmo->Items->AddRange(gcnew cli::array< System::Object^  >(5) {L"Inserción", L"Selección", L"Burbuja", L"Quicksort", 
				L"Mergesort"});
			this->cbAlgoritmo->Location = System::Drawing::Point(50, 128);
			this->cbAlgoritmo->Name = L"cbAlgoritmo";
			this->cbAlgoritmo->Size = System::Drawing::Size(121, 21);
			this->cbAlgoritmo->TabIndex = 8;
			this->cbAlgoritmo->Text = L"Algoritmo...";
			// 
			// cbDatos
			// 
			this->cbDatos->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->cbDatos->FormattingEnabled = true;
			this->cbDatos->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"Creciente", L"Decreciente", L"Aleatorio"});
			this->cbDatos->Location = System::Drawing::Point(277, 128);
			this->cbDatos->Name = L"cbDatos";
			this->cbDatos->Size = System::Drawing::Size(121, 21);
			this->cbDatos->TabIndex = 9;
			this->cbDatos->Text = L"Datos...";
			// 
			// tbTamIni
			// 
			this->tbTamIni->Location = System::Drawing::Point(120, 18);
			this->tbTamIni->Name = L"tbTamIni";
			this->tbTamIni->Size = System::Drawing::Size(100, 20);
			this->tbTamIni->TabIndex = 10;
			// 
			// tbTamFin
			// 
			this->tbTamFin->Location = System::Drawing::Point(120, 44);
			this->tbTamFin->Name = L"tbTamFin";
			this->tbTamFin->Size = System::Drawing::Size(100, 20);
			this->tbTamFin->TabIndex = 11;
			// 
			// tbIncremento
			// 
			this->tbIncremento->Location = System::Drawing::Point(120, 72);
			this->tbIncremento->Name = L"tbIncremento";
			this->tbIncremento->Size = System::Drawing::Size(100, 20);
			this->tbIncremento->TabIndex = 12;
			// 
			// tbRepeticionesIni
			// 
			this->tbRepeticionesIni->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->tbRepeticionesIni->Location = System::Drawing::Point(342, 20);
			this->tbRepeticionesIni->Name = L"tbRepeticionesIni";
			this->tbRepeticionesIni->Size = System::Drawing::Size(100, 20);
			this->tbRepeticionesIni->TabIndex = 13;
			// 
			// tbRepeticionesFin
			// 
			this->tbRepeticionesFin->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->tbRepeticionesFin->Location = System::Drawing::Point(342, 46);
			this->tbRepeticionesFin->Name = L"tbRepeticionesFin";
			this->tbRepeticionesFin->Size = System::Drawing::Size(100, 20);
			this->tbRepeticionesFin->TabIndex = 14;
			// 
			// tbResultados
			// 
			this->tbResultados->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->tbResultados->Location = System::Drawing::Point(12, 216);
			this->tbResultados->Multiline = true;
			this->tbResultados->Name = L"tbResultados";
			this->tbResultados->ReadOnly = true;
			this->tbResultados->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->tbResultados->Size = System::Drawing::Size(448, 243);
			this->tbResultados->TabIndex = 15;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(472, 471);
			this->Controls->Add(this->tbResultados);
			this->Controls->Add(this->tbRepeticionesFin);
			this->Controls->Add(this->tbRepeticionesIni);
			this->Controls->Add(this->tbIncremento);
			this->Controls->Add(this->tbTamFin);
			this->Controls->Add(this->tbTamIni);
			this->Controls->Add(this->cbDatos);
			this->Controls->Add(this->cbAlgoritmo);
			this->Controls->Add(this->checkGNUPlot);
			this->Controls->Add(this->lRepeticionesFin);
			this->Controls->Add(this->lRepeticionesIni);
			this->Controls->Add(this->lIncremento);
			this->Controls->Add(this->lTamFin);
			this->Controls->Add(this->lTamIni);
			this->Controls->Add(this->bLimpiar);
			this->Controls->Add(this->bComenzar);
			this->Name = L"Form1";
			this->Text = L"Practica 2";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void bLimpiar_Click(System::Object^  sender, System::EventArgs^  e);

private: System::Void bComenzar_Click(System::Object^  sender, System::EventArgs^  e);

};
}

