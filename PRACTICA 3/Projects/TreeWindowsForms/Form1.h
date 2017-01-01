#include <string>
#include "RecorreDirectorio.h"
#include "ArbolDirectorios.h"

#pragma once

namespace TreeWindowsForms {

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
	private: System::Windows::Forms::Panel^  panelDibujo;
	private: System::Windows::Forms::Button^  bDibujar;
	protected: 

	protected: 

	private: System::Windows::Forms::Button^  bCambiar;
	private: System::Windows::Forms::Label^  lDirectorio;
	private: System::Windows::Forms::Label^  lEscala;



	private: System::Windows::Forms::Label^  lRuta;
	private: System::Windows::Forms::FolderBrowserDialog^  folderCambiar;
	private: System::Windows::Forms::Panel^  panelEscala;
	private: System::Windows::Forms::Label^  lTamEscala;



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
			this->panelDibujo = (gcnew System::Windows::Forms::Panel());
			this->bDibujar = (gcnew System::Windows::Forms::Button());
			this->bCambiar = (gcnew System::Windows::Forms::Button());
			this->lDirectorio = (gcnew System::Windows::Forms::Label());
			this->lEscala = (gcnew System::Windows::Forms::Label());
			this->lRuta = (gcnew System::Windows::Forms::Label());
			this->folderCambiar = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->panelEscala = (gcnew System::Windows::Forms::Panel());
			this->lTamEscala = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// panelDibujo
			// 
			this->panelDibujo->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->panelDibujo->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panelDibujo->Location = System::Drawing::Point(12, 12);
			this->panelDibujo->Name = L"panelDibujo";
			this->panelDibujo->Size = System::Drawing::Size(613, 284);
			this->panelDibujo->TabIndex = 0;
			// 
			// bDibujar
			// 
			this->bDibujar->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->bDibujar->Location = System::Drawing::Point(206, 427);
			this->bDibujar->Name = L"bDibujar";
			this->bDibujar->Size = System::Drawing::Size(230, 26);
			this->bDibujar->TabIndex = 1;
			this->bDibujar->Text = L"Dibujar";
			this->bDibujar->UseVisualStyleBackColor = true;
			this->bDibujar->Click += gcnew System::EventHandler(this, &Form1::bDibujar_Click);
			// 
			// bCambiar
			// 
			this->bCambiar->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->bCambiar->Location = System::Drawing::Point(546, 343);
			this->bCambiar->Name = L"bCambiar";
			this->bCambiar->Size = System::Drawing::Size(79, 23);
			this->bCambiar->TabIndex = 2;
			this->bCambiar->Text = L"Cambiar...";
			this->bCambiar->UseVisualStyleBackColor = true;
			this->bCambiar->Click += gcnew System::EventHandler(this, &Form1::bCambiar_Click);
			// 
			// lDirectorio
			// 
			this->lDirectorio->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->lDirectorio->AutoSize = true;
			this->lDirectorio->Location = System::Drawing::Point(9, 353);
			this->lDirectorio->Name = L"lDirectorio";
			this->lDirectorio->Size = System::Drawing::Size(88, 13);
			this->lDirectorio->TabIndex = 3;
			this->lDirectorio->Text = L"Directorio Actual:";
			// 
			// lEscala
			// 
			this->lEscala->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->lEscala->AutoSize = true;
			this->lEscala->Location = System::Drawing::Point(9, 307);
			this->lEscala->Name = L"lEscala";
			this->lEscala->Size = System::Drawing::Size(97, 13);
			this->lEscala->TabIndex = 4;
			this->lEscala->Text = L"Escala Aproximada";
			// 
			// lRuta
			// 
			this->lRuta->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->lRuta->Location = System::Drawing::Point(138, 353);
			this->lRuta->Name = L"lRuta";
			this->lRuta->Size = System::Drawing::Size(375, 13);
			this->lRuta->TabIndex = 5;
			// 
			// panelEscala
			// 
			this->panelEscala->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->panelEscala->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panelEscala->Location = System::Drawing::Point(131, 302);
			this->panelEscala->Name = L"panelEscala";
			this->panelEscala->Size = System::Drawing::Size(18, 18);
			this->panelEscala->TabIndex = 6;
			// 
			// lTamEscala
			// 
			this->lTamEscala->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->lTamEscala->AutoSize = true;
			this->lTamEscala->Location = System::Drawing::Point(171, 307);
			this->lTamEscala->Name = L"lTamEscala";
			this->lTamEscala->Size = System::Drawing::Size(0, 13);
			this->lTamEscala->TabIndex = 7;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(637, 465);
			this->Controls->Add(this->lTamEscala);
			this->Controls->Add(this->panelEscala);
			this->Controls->Add(this->lRuta);
			this->Controls->Add(this->lEscala);
			this->Controls->Add(this->lDirectorio);
			this->Controls->Add(this->bCambiar);
			this->Controls->Add(this->bDibujar);
			this->Controls->Add(this->panelDibujo);
			this->Name = L"Form1";
			this->Text = L"Practica 3";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

    //Funciones auxiliares
	std::string dameExtension (std::string nombreFichero);
	System::Drawing::Brush^ ponColor (std::string nombreFichero);
	void pinta (std::string ruta, Graphics^ recuadro, int x, int y, int alto, int ancho);
	void pintaRecur (std::string ruta, unsigned long tamDirectorio, Graphics^ brocha, float esqX, float esqY, float altoInicial, float anchoInicial, bool partirEnVertical);
	void traducirTamaño (float escala);

	//Eventos
	private: System::Void bCambiar_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void bDibujar_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e);
};
}

