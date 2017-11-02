#pragma once
#include "MyForm.h"
#include "Parsing.h"
#include "Station.h"
#include "RecuitVLS.h"
namespace Project2 {
	using namespace EO;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
			//
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: RecuitVLS^ problem;
	private: EO::WinForm::WebControl^  webBrowser1;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::GroupBox^  groupBox1;

	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::ComboBox^  comboBox2;
	private: System::Windows::Forms::ListBox^  listBox1;

	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::ListBox^  listBox3;
	private: System::Windows::Forms::ListBox^  listBox2;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::Windows::Forms::ListBox^  listBox4;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::Button^  button9;
	private: System::Windows::Forms::ListBox^  listBox5;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Button^  button10;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Button^  button11;
	private: System::Windows::Forms::TextBox^  textBox6;
	private: System::Windows::Forms::Button^  button12;
	private: System::Windows::Forms::ListBox^  listBox6;
	protected:

	protected:

	private:
		/// <summary>
		/// Variable nécessaire au concepteur.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			this->webBrowser1 = (gcnew EO::WinForm::WebControl());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->listBox6 = (gcnew System::Windows::Forms::ListBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->listBox4 = (gcnew System::Windows::Forms::ListBox());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->listBox5 = (gcnew System::Windows::Forms::ListBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->listBox3 = (gcnew System::Windows::Forms::ListBox());
			this->listBox2 = (gcnew System::Windows::Forms::ListBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// webBrowser1
			// 
			this->webBrowser1->BackColor = System::Drawing::Color::White;
			this->webBrowser1->Location = System::Drawing::Point(183, 12);
			this->webBrowser1->MinimumSize = System::Drawing::Size(20, 20);
			this->webBrowser1->Name = L"webBrowser1";
			this->webBrowser1->Size = System::Drawing::Size(492, 367);
			this->webBrowser1->TabIndex = 1;
			this->webBrowser1->WebView = gcnew EO::WebBrowser::WebView();
			this->webBrowser1->WebView->Url = System::IO::Directory::GetCurrentDirectory() + "/Connector.html";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Mode", L"Stochastique", L"Déterministe" });
			this->comboBox1->SelectedIndex = 0;
			this->comboBox1->Location = System::Drawing::Point(7, 7);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(89, 21);
			this->comboBox1->TabIndex = 2;
			this->comboBox1->SelectionChangeCommitted += gcnew System::EventHandler(this, &MyForm::ModeSwitch);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->button11);
			this->groupBox1->Controls->Add(this->textBox6);
			this->groupBox1->Controls->Add(this->button12);
			this->groupBox1->Controls->Add(this->listBox6);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->button8);
			this->groupBox1->Controls->Add(this->button6);
			this->groupBox1->Controls->Add(this->textBox4);
			this->groupBox1->Controls->Add(this->textBox5);
			this->groupBox1->Controls->Add(this->button7);
			this->groupBox1->Controls->Add(this->listBox4);
			this->groupBox1->Controls->Add(this->button9);
			this->groupBox1->Controls->Add(this->button4);
			this->groupBox1->Controls->Add(this->listBox5);
			this->groupBox1->Controls->Add(this->textBox3);
			this->groupBox1->Controls->Add(this->button5);
			this->groupBox1->Controls->Add(this->button3);
			this->groupBox1->Controls->Add(this->textBox2);
			this->groupBox1->Controls->Add(this->button2);
			this->groupBox1->Controls->Add(this->listBox3);
			this->groupBox1->Controls->Add(this->listBox2);
			this->groupBox1->Enabled = false;
			this->groupBox1->Location = System::Drawing::Point(7, 29);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(170, 340);
			this->groupBox1->TabIndex = 3;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Paramètres déterministes";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(6, 342);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(53, 13);
			this->label6->TabIndex = 24;
			this->label6->Text = L"Demande";
			// 
			// button11
			// 
			this->button11->Location = System::Drawing::Point(131, 403);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(33, 23);
			this->button11->TabIndex = 23;
			this->button11->Text = L"→";
			this->button11->UseVisualStyleBackColor = true;
			this->button12->Click += gcnew System::EventHandler(this, &MyForm::button12_Click);
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(45, 405);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(81, 20);
			this->textBox6->TabIndex = 22;
			// 
			// button12
			// 
			this->button12->Enabled = false;
			this->button12->Location = System::Drawing::Point(6, 403);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(33, 23);
			this->button12->TabIndex = 21;
			this->button12->Text = L"←";
			this->button12->UseVisualStyleBackColor = true;
			this->button12->Click += gcnew System::EventHandler(this, &MyForm::button12_Click);
			// 
			// listBox6
			// 
			this->listBox6->FormattingEnabled = true;
			this->listBox6->Location = System::Drawing::Point(7, 356);
			this->listBox6->Name = L"listBox6";
			this->listBox6->Size = System::Drawing::Size(157, 43);
			this->listBox6->TabIndex = 20;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(6, 255);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(92, 13);
			this->label5->TabIndex = 19;
			this->label5->Text = L"Capacité en velos";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(6, 173);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(164, 13);
			this->label4->TabIndex = 18;
			this->label4->Text = L"Cout lié au manque de place (Wi)";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(6, 92);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(154, 13);
			this->label3->TabIndex = 17;
			this->label3->Text = L"Cout lié au manque de velo (Vi)";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(6, 11);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(103, 13);
			this->label2->TabIndex = 16;
			this->label2->Text = L"Prix d\'acquisition (Ci)";
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(131, 316);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(33, 23);
			this->button8->TabIndex = 15;
			this->button8->Text = L"→";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &MyForm::button8_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(131, 233);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(33, 23);
			this->button6->TabIndex = 11;
			this->button6->Text = L"→";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(45, 235);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(81, 20);
			this->textBox4->TabIndex = 10;
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(45, 318);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(81, 20);
			this->textBox5->TabIndex = 14;
			// 
			// button7
			// 
			this->button7->Enabled = false;
			this->button7->Location = System::Drawing::Point(6, 233);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(33, 23);
			this->button7->TabIndex = 9;
			this->button7->Text = L"←";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			// 
			// listBox4
			// 
			this->listBox4->FormattingEnabled = true;
			this->listBox4->Location = System::Drawing::Point(7, 186);
			this->listBox4->Name = L"listBox4";
			this->listBox4->Size = System::Drawing::Size(157, 43);
			this->listBox4->TabIndex = 8;
			// 
			// button9
			// 
			this->button9->Enabled = false;
			this->button9->Location = System::Drawing::Point(6, 316);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(33, 23);
			this->button9->TabIndex = 13;
			this->button9->Text = L"←";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &MyForm::button9_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(131, 150);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(33, 23);
			this->button4->TabIndex = 7;
			this->button4->Text = L"→";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// listBox5
			// 
			this->listBox5->FormattingEnabled = true;
			this->listBox5->Location = System::Drawing::Point(7, 269);
			this->listBox5->Name = L"listBox5";
			this->listBox5->Size = System::Drawing::Size(157, 43);
			this->listBox5->TabIndex = 12;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(45, 152);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(81, 20);
			this->textBox3->TabIndex = 6;
			// 
			// button5
			// 
			this->button5->Enabled = false;
			this->button5->Location = System::Drawing::Point(6, 150);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(33, 23);
			this->button5->TabIndex = 5;
			this->button5->Text = L"←";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(131, 68);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(33, 23);
			this->button3->TabIndex = 4;
			this->button3->Text = L"→";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(45, 70);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(81, 20);
			this->textBox2->TabIndex = 3;
			// 
			// button2
			// 
			this->button2->Enabled = false;
			this->button2->Location = System::Drawing::Point(6, 68);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(33, 23);
			this->button2->TabIndex = 2;
			this->button2->Text = L"←";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// listBox3
			// 
			this->listBox3->FormattingEnabled = true;
			this->listBox3->Location = System::Drawing::Point(7, 105);
			this->listBox3->Name = L"listBox3";
			this->listBox3->Size = System::Drawing::Size(157, 43);
			this->listBox3->TabIndex = 1;
			// 
			// listBox2
			// 
			this->listBox2->FormattingEnabled = true;
			this->listBox2->Location = System::Drawing::Point(7, 24);
			this->listBox2->Name = L"listBox2";
			this->listBox2->Size = System::Drawing::Size(157, 43);
			this->listBox2->TabIndex = 0;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->listBox1);
			this->groupBox2->Controls->Add(this->comboBox2);
			this->groupBox2->Location = System::Drawing::Point(7, 371);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(170, 118);
			this->groupBox2->TabIndex = 5;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Demande";
			this->groupBox2->Visible = false;
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(7, 46);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(157, 69);
			this->listBox1->TabIndex = 6;
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(1) { L"Scenario" });
			this->comboBox2->Location = System::Drawing::Point(6, 19);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(138, 21);
			this->comboBox2->TabIndex = 6;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(116, 497);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 6;
			this->button1->Text = L"Lancer";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::ButtonClick);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(13, 500);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(97, 20);
			this->textBox1->TabIndex = 7;
			this->textBox1->Text = "1000";
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::setIter);
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(183, 385);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(492, 99);
			this->richTextBox1->TabIndex = 4;
			this->richTextBox1->Text = L"";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 486);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(97, 13);
			this->label1->TabIndex = 8;
			this->label1->Text = L"Nombre d\'itérations";
			// 
			// button10
			// 
			this->button10->Location = System::Drawing::Point(102, 5);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(75, 23);
			this->button10->TabIndex = 9;
			this->button10->Text = L"Randomiser";
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &MyForm::Rand_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(681, 523);
			this->Controls->Add(this->button10);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->webBrowser1);
			this->Name = L"MyForm";
			this->Text = L"Projet Stochastique";
			this->problem = gcnew RecuitVLS(TEMPERATURE_INITIALE, 1000, 12);
			for each(Station^ stat in problem->getProb()->getStations())
			{
				this->listBox2->Items->Add(stat->getCost());
				this->listBox3->Items->Add(stat->getLessCost());
				this->listBox4->Items->Add(stat->getOverCost());
				this->listBox5->Items->Add(stat->getBikeStands());
				this->comboBox2->Items->Add(stat->getId());
			}
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		System::Void ModeSwitch(System::Object^  sender, System::EventArgs^  e)
		{
			this->groupBox2->Visible = this->comboBox1->SelectedItem->Equals("Stochastique");
			this->groupBox1->Enabled = this->comboBox1->SelectedIndex;

			this->button1->Enabled = !this->comboBox1->SelectedItem->Equals("Mode");
			this->textBox1->Enabled = !this->comboBox1->SelectedItem->Equals("Mode");
			this->richTextBox1->Enabled = !this->comboBox1->SelectedItem->Equals("Mode");
			if ((String^)this->comboBox1->SelectedItem == "Déterministe")
			{
				this->groupBox1->Size = System::Drawing::Size(170, 455);
				this->problem->getProb()->generateDemandes(false);
				for each(Trajet ^tej in this->problem->getProb()->getTrajets())
					this->listBox6->Items->Add(tej);
			}
			else
			{
				this->groupBox1->Size = System::Drawing::Size(170, 340);
				this->problem->getProb()->generateDemandes(true);
			}
		}
		System::Void FilterAsk(System::Object^  sender, System::EventArgs^  e)
		{
			for each(Trajet ^traj in problem->getProb()->getTrajets())
			{
				if (this->comboBox2->SelectedItem != NULL && traj->getIdDepart() == (int)comboBox2->SelectedItem)
					listBox1->Items->Add(traj);
				else if (this->comboBox2->SelectedItem == NULL)
					this->listBox1->Items->Add(traj);
			}
		}
		System::Void ButtonClick(System::Object^ sender, System::EventArgs^ e)
		{
			this->richTextBox1->Text += "LApatapata\n";
			this->webBrowser1->Refresh();
		}

		void PopDelBut() { this->button10->Enabled = true; this->button10->Visible = true; }
		void DepopDelBut() { this->button10->Enabled = false; this->button10->Visible = false; }

		System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			((Station^)this->problem->getProb()->getStations()[this->listBox2->SelectedIndex])->setCost(int::Parse(this->textBox2->Text));
			this->listBox2->Items[this->listBox2->SelectedIndex] = ((Station^)this->problem->getProb()->getStations()[this->listBox2->SelectedIndex])->getCost();
			this->listBox2->SelectedIndex--;
			this->textBox2->Text = "" + this->listBox2->SelectedItem;
			this->button2->Enabled = this->listBox2->SelectedIndex != 0 || this->listBox2->SelectedIndex != -1;
		}

		System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			if (this->listBox2->Items->Count == 0) {

			}
			else if (this->listBox2->SelectedIndex == -1) {
				this->listBox2->SelectedIndex = 0;
				this->textBox2->Text = "" + this->listBox2->SelectedItem;
			}
			else {
				((Station^)this->problem->getProb()->getStations()[this->listBox2->SelectedIndex])->setCost(int::Parse(this->textBox2->Text));
				this->listBox2->Items[this->listBox2->SelectedIndex] = ((Station^)this->problem->getProb()->getStations()[this->listBox2->SelectedIndex])->getCost();
				this->listBox2->SelectedIndex++;
				this->textBox2->Text = "" + this->listBox2->SelectedItem;
			}
			this->button2->Enabled = this->listBox2->SelectedIndex != 0 || this->listBox2->SelectedIndex != -1;
		}

		System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
			if (this->listBox3->Items->Count == 0) {

			}
			else if (this->listBox3->SelectedIndex == -1) {
				this->listBox3->SelectedIndex = 0;
				this->textBox3->Text = "" + this->listBox3->SelectedItem;
			}
			else {
				((Station^)this->problem->getProb()->getStations()[this->listBox3->SelectedIndex])->setLessCost(int::Parse(this->textBox3->Text));
				this->listBox3->Items[this->listBox3->SelectedIndex] = ((Station^)this->problem->getProb()->getStations()[this->listBox3->SelectedIndex])->getLessCost();
				this->listBox3->SelectedIndex++;
				this->textBox3->Text = "" + this->listBox3->SelectedItem;
			}
			this->button5->Enabled = this->listBox3->SelectedIndex != 0 || this->listBox3->SelectedIndex != -1;

		}

		System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
			((Station^)this->problem->getProb()->getStations()[this->listBox3->SelectedIndex])->setCost(int::Parse(this->textBox3->Text));
			this->listBox3->Items[this->listBox3->SelectedIndex] = ((Station^)this->problem->getProb()->getStations()[this->listBox3->SelectedIndex])->getCost();
			this->listBox3->SelectedIndex--;
			this->textBox3->Text = "" + this->listBox3->SelectedItem;
			this->button5->Enabled = this->listBox3->SelectedIndex != 0 || this->listBox3->SelectedIndex != -1;
		}

		System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
			if (this->listBox4->Items->Count == 0) {

			}
			else if (this->listBox4->SelectedIndex == -1) {
				this->listBox4->SelectedIndex = 0;
				this->textBox4->Text = "" + this->listBox4->SelectedItem;
			}
			else {
				((Station^)this->problem->getProb()->getStations()[this->listBox4->SelectedIndex])->setOverCost(int::Parse(this->textBox4->Text));
				this->listBox4->Items[this->listBox4->SelectedIndex] = ((Station^)this->problem->getProb()->getStations()[this->listBox4->SelectedIndex])->getOverCost();
				this->listBox4->SelectedIndex++;
				this->textBox4->Text = "" + this->listBox4->SelectedItem;
			}
			this->button7->Enabled = this->listBox4->SelectedIndex != 0 || this->listBox4->SelectedIndex != -1;

		}

		System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
			((Station^)this->problem->getProb()->getStations()[this->listBox4->SelectedIndex])->setCost(int::Parse(this->textBox4->Text));
			this->listBox4->Items[this->listBox4->SelectedIndex] = ((Station^)this->problem->getProb()->getStations()[this->listBox4->SelectedIndex])->getCost();
			this->listBox4->SelectedIndex--;
			this->textBox4->Text = "" + this->listBox4->SelectedItem;
			this->button7->Enabled = this->listBox4->SelectedIndex != 0 || this->listBox4->SelectedIndex != -1;
		}

		System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) {
			if (this->listBox5->Items->Count == 0) {

			}
			else if (this->listBox5->SelectedIndex == -1) {
				this->listBox5->SelectedIndex = 0;
				this->textBox5->Text = "" + this->listBox5->SelectedItem;
			}
			else {
				((Station^)this->problem->getProb()->getStations()[this->listBox5->SelectedIndex])->setBikeStands(int::Parse(this->textBox5->Text));
				this->listBox5->Items[this->listBox5->SelectedIndex] = ((Station^)this->problem->getProb()->getStations()[this->listBox5->SelectedIndex])->getBikeStands();
				this->listBox5->SelectedIndex++;
				this->textBox5->Text = "" + this->listBox5->SelectedItem;
			}
			this->button9->Enabled = this->listBox5->SelectedIndex != 0 || this->listBox5->SelectedIndex != -1;
		}

		System::Void button9_Click(System::Object^  sender, System::EventArgs^  e) {
			((Station^)this->problem->getProb()->getStations()[this->listBox5->SelectedIndex])->setCost(int::Parse(this->textBox5->Text));
			this->listBox5->Items[this->listBox5->SelectedIndex] = ((Station^)this->problem->getProb()->getStations()[this->listBox5->SelectedIndex])->getCost();
			this->listBox5->SelectedIndex--;
			this->textBox5->Text = "" + this->listBox5->SelectedItem;
			this->button9->Enabled = this->listBox5->SelectedIndex != 0 || this->listBox5->SelectedIndex != -1;
		}

		System::Void button12_Click(System::Object^  sender, System::EventArgs^  e) {
			if (this->listBox6->Items->Count == 0) {

			}
			else if (this->listBox6->SelectedIndex == -1) {
				this->listBox6->SelectedIndex = 0;
				this->textBox6->Text = "" + this->listBox6->SelectedItem;
			}
			else {
				((Trajet^)this->problem->getProb()->getTrajets()[this->listBox6->SelectedIndex])->setDemande(int::Parse(this->textBox6->Text));
				this->listBox6->Items[this->listBox6->SelectedIndex] = ((Trajet^)this->problem->getProb()->getTrajets()[this->listBox6->SelectedIndex])->getDemande();
				this->listBox6->SelectedIndex++;
				this->textBox6->Text = "" + this->listBox6->SelectedItem;
			}
			this->button12->Enabled = this->listBox6->SelectedIndex != 0 || this->listBox6->SelectedIndex != -1;
		}

		System::Void button11_Click(System::Object^  sender, System::EventArgs^  e) {
			((Trajet^)this->problem->getProb()->getTrajets()[this->listBox6->SelectedIndex])->setDemande(int::Parse(this->textBox6->Text));
			this->listBox6->Items[this->listBox6->SelectedIndex] = ((Trajet^)this->problem->getProb()->getTrajets()[this->listBox6->SelectedIndex])->getDemande();
			this->listBox6->SelectedIndex--;
			this->textBox6->Text = "" + this->listBox6->SelectedItem;
			this->button12->Enabled = this->listBox6->SelectedIndex != 0 || this->listBox6->SelectedIndex != -1;
		}
		System::Void Rand_Click(System::Object^  sender, System::EventArgs^  e) {
			this->problem->getProb()->randomizeStations();
		}
		System::Void setIter(System::Object^  sender, System::EventArgs^  e) {
			if (int::Parse(this->textBox1->Text) < 1000)
				this->textBox1->Text = "1000";
			else
				this->problem->setIter(int::Parse(this->textBox1->Text));
		}
	};
}
