#pragma once
#include "Student.h"
#include "AdditionalFunctions.h"
#include "Libraries.h"
#include "resource.h"
#include "resource1.h"

namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Collections::Generic;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem2;
	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem3;
	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem4;
	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem5;
	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem6;
	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button7;
	private: String^ fileName = "";
	private: String^ goodStudents;
	private: String^ badStudents;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem3 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem4 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem5 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem6 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(24, 24);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->toolStripMenuItem1,
					this->toolStripMenuItem6
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(978, 33);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// toolStripMenuItem1
			// 
			this->toolStripMenuItem1->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->toolStripMenuItem2,
					this->toolStripMenuItem3, this->toolStripMenuItem4, this->toolStripMenuItem5
			});
			this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
			this->toolStripMenuItem1->Size = System::Drawing::Size(129, 29);
			this->toolStripMenuItem1->Text = L"Dokumentas";
			// 
			// toolStripMenuItem2
			// 
			this->toolStripMenuItem2->Name = L"toolStripMenuItem2";
			this->toolStripMenuItem2->Size = System::Drawing::Size(236, 34);
			this->toolStripMenuItem2->Text = L"Atverti";
			this->toolStripMenuItem2->Click += gcnew System::EventHandler(this, &Form1::toolStripMenuItem2_Click);
			// 
			// toolStripMenuItem3
			// 
			this->toolStripMenuItem3->Name = L"toolStripMenuItem3";
			this->toolStripMenuItem3->Size = System::Drawing::Size(236, 34);
			this->toolStripMenuItem3->Text = L"Išsaugoti";
			this->toolStripMenuItem3->Click += gcnew System::EventHandler(this, &Form1::toolStripMenuItem3_Click);
			// 
			// toolStripMenuItem4
			// 
			this->toolStripMenuItem4->Name = L"toolStripMenuItem4";
			this->toolStripMenuItem4->Size = System::Drawing::Size(236, 34);
			this->toolStripMenuItem4->Text = L"Išsaugoti kaip...";
			this->toolStripMenuItem4->Click += gcnew System::EventHandler(this, &Form1::toolStripMenuItem4_Click);
			// 
			// toolStripMenuItem5
			// 
			this->toolStripMenuItem5->Name = L"toolStripMenuItem5";
			this->toolStripMenuItem5->Size = System::Drawing::Size(236, 34);
			this->toolStripMenuItem5->Text = L"Uždaryti";
			this->toolStripMenuItem5->Click += gcnew System::EventHandler(this, &Form1::toolStripMenuItem5_Click);
			// 
			// toolStripMenuItem6
			// 
			this->toolStripMenuItem6->Name = L"toolStripMenuItem6";
			this->toolStripMenuItem6->Size = System::Drawing::Size(64, 29);
			this->toolStripMenuItem6->Text = L"Apie";
			this->toolStripMenuItem6->Click += gcnew System::EventHandler(this, &Form1::toolStripMenuItem6_Click);
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(12, 55);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(650, 500);
			this->richTextBox1->TabIndex = 1;
			this->richTextBox1->Text = L"";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(728, 55);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(156, 40);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Pasirinkti skaičiavimo\r\nmetodiką";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Vidurkis", L"Mediana" });
			this->comboBox1->Location = System::Drawing::Point(732, 111);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 28);
			this->comboBox1->TabIndex = 3;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBox1_SelectedIndexChanged);
			// 
			// button1
			// 
			this->button1->AutoSize = true;
			this->button1->Location = System::Drawing::Point(732, 218);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(194, 30);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Nuskaityti iš dokumento";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->AutoSize = true;
			this->button2->Location = System::Drawing::Point(732, 430);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(194, 30);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Išsaugoti";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button3
			// 
			this->button3->AutoSize = true;
			this->button3->Location = System::Drawing::Point(732, 160);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(194, 30);
			this->button3->TabIndex = 6;
			this->button3->Text = L"Skaičiuoti";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// button4
			// 
			this->button4->AutoSize = true;
			this->button4->Location = System::Drawing::Point(732, 543);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(194, 30);
			this->button4->TabIndex = 7;
			this->button4->Text = L"Uždaryti";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// button5
			// 
			this->button5->AutoSize = true;
			this->button5->Location = System::Drawing::Point(732, 490);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(194, 30);
			this->button5->TabIndex = 8;
			this->button5->Text = L"Išvalyti";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
			// 
			// button6
			// 
			this->button6->AutoSize = true;
			this->button6->Location = System::Drawing::Point(732, 272);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(194, 50);
			this->button6->TabIndex = 9;
			this->button6->Text = L"Išvesti gerų studentų\r\nduomenis\r\n";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &Form1::button6_Click);
			// 
			// button7
			// 
			this->button7->AutoSize = true;
			this->button7->Location = System::Drawing::Point(732, 353);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(194, 50);
			this->button7->TabIndex = 10;
			this->button7->Text = L"Išvesti prastų studentų \r\nduomenis";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &Form1::button7_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(978, 594);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->menuStrip1);
			
			this->Name = L"Form1";
			this->Text = L"Galutinio pažymio skaičiuoklė";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
		

	}

	private: void MarshalString(String^ s, std::wstring& os) {
		using namespace Runtime::InteropServices;
		const wchar_t* chars =
			(const wchar_t*)(Marshal::StringToHGlobalUni(s)).ToPointer();
		os = chars;
		Marshal::FreeHGlobal(IntPtr((void*)chars));
	}

	private: void MarshalString(String^ s, string& os) {
		using namespace Runtime::InteropServices;
		const char* chars =
			(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
		os = chars;
		Marshal::FreeHGlobal(IntPtr((void*)chars));
	}

	private: void DisplayInTextBox(list<Student> studentList) {
		wostringstream studentStream;
		studentList = sortList(studentList);

		if (comboBox1->SelectedIndex == 1) {
			studentStream << setw(15) << left << "Pavarde" << setw(15) << left << "Vardas" << setw(15) << left << "Galutinis (Med.)" << endl;
		}
		else {
			studentStream << setw(15) << left << "Pavarde" << setw(15) << left << "Vardas" << setw(15) << left << "Galutinis (Vid.)" << endl;
		}

		studentStream << "------------------------------------------------------------" << endl;
		for (auto const& i : studentList) {
			studentStream << i;
			studentStream << "\n";

		}
		String^ all = gcnew String(studentStream.str().c_str());

		richTextBox1->Text = all;

	}

	private: String^ WriteToString(list<Student> studentList) {
		std::wostringstream studentStream;
		if (comboBox1->SelectedIndex == 1) {
			studentStream << setw(15) << left << "Pavarde" << setw(15) << left << "Vardas" << setw(15) << left << "Galutinis (Med.)" << endl;
		}
		else {
			studentStream << setw(15) << left << "Pavarde" << setw(15) << left << "Vardas" << setw(15) << left << "Galutinis (Vid.)" << endl;
		}

		studentStream << "------------------------------------------------------------" << endl;
		for (auto const& i : studentList) {
			studentStream << i;
			studentStream << "\n";

		}
		String^ graded = gcnew String(studentStream.str().c_str());
		return graded;
	}

	private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		if (comboBox1->SelectedIndex == 0) {
			Student::setCountingMethod('v');
		}
		else {
			Student::setCountingMethod('m');
		}
	}

	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		array<String^>^ lines = richTextBox1->Lines;
		int count = lines->Length;
		for (int i = 0; i < lines->Length; i++) {
			if (lines[i] == "") {
				count--;
			}
		}

		String^ appendedLine;
		wstring line;
		list<Student> studentList2(count);
		std::wistringstream inputStream;
		list<Student>::iterator iter;
		int it = 0;
		for (iter = studentList2.begin(); iter != studentList2.end(); iter++)
		{
			if (lines[it] != "") {
				appendedLine = lines[it] + " 0";
				MarshalString(appendedLine, line);
				std::wistringstream inputStream(line);
				inputStream >> *iter;
				it++;
			}


		}
		DisplayInTextBox(studentList2);
		vector <list<Student>> gradedStudents;
		gradedStudents = sortStudentsByGradeList(studentList2);
		goodStudents = WriteToString(gradedStudents[0]);
		badStudents = WriteToString(gradedStudents[1]);
	}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		openFileDialog1->InitialDirectory = "..\\";
		openFileDialog1->Filter = "txt files (*.txt)|*.txt";
		openFileDialog1->InitialDirectory = "..\\";

		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			StreamReader^ reader = gcnew StreamReader(openFileDialog1->FileName);
			richTextBox1->Text = (reader->ReadToEnd());
			fileName = openFileDialog1->FileName;
			string stdString;
			MarshalString(fileName, stdString);
			list<Student> studentList1;
			studentList1 = fileInputList(stdString);
			reader->Close();
			DisplayInTextBox(studentList1);
			vector <list<Student>> gradedStudents;
			gradedStudents = sortStudentsByGradeList(studentList1);
			goodStudents = WriteToString(gradedStudents[0]);
			badStudents = WriteToString(gradedStudents[1]);
			button3->Enabled = false;
		}
	}

	private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
		richTextBox1->Text = goodStudents;
	}
	
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		Form1:Close();
	}
	
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		SaveFileDialog^ saveFileDialog1 = gcnew SaveFileDialog();
		saveFileDialog1->InitialDirectory = "..\\";
		saveFileDialog1->Filter = "txt files (*.txt)|*.txt";
		String^ boxText = richTextBox1->Text;
	rep:
		if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)

		{
			StreamWriter^ sw = gcnew StreamWriter(saveFileDialog1->FileName);
			sw->Write(boxText);
			sw->Close();
		}
		else MessageBox::Show(L"Įvyko klaida", "Klaida", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}

	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
		richTextBox1->Clear();
		button3->Enabled = true;
	}

	private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
		richTextBox1->Text = badStudents;
	}

	private: System::Void toolStripMenuItem2_Click(System::Object^ sender, System::EventArgs^ e) {
		button1_Click(sender, e);
	}

	private: System::Void toolStripMenuItem3_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ z;
		if (richTextBox1->Text == "") z = " ";
		else z = richTextBox1->Text;
		if (MessageBox::Show(L"Ar tikrai norite perrašyti dokumentą?", "Patvirtinimas", MessageBoxButtons::OKCancel, MessageBoxIcon::Question) ==
			System::Windows::Forms::DialogResult::Yes) {

			if (fileName != "")
			{
				System::IO::StreamWriter^ sw = gcnew System::IO::StreamWriter(fileName);
				sw->Write(z);
				sw->Close();
			}
		}
	}

	private: System::Void toolStripMenuItem4_Click(System::Object^ sender, System::EventArgs^ e) {
		button2_Click(sender, e);
	}

	private: System::Void toolStripMenuItem5_Click(System::Object^ sender, System::EventArgs^ e) {
		button4_Click(sender, e);
	}

	private: System::Void toolStripMenuItem6_Click(System::Object^ sender, System::EventArgs^ e) {
		MessageBox::Show(L"Programa apskaičiuoja studentų galutinį pažymį pagal nustatytą formulę. Duomenis galima įvesti teksto laukelyje arba iš failo.", L"Apie programą", MessageBoxButtons::OK, MessageBoxIcon::Information);
	
	}
};
}
