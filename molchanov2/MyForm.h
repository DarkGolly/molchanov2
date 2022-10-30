#include "tokens.h"
#include <string>
#include <list>
#include <msclr\marshal_cppstd.h>
#pragma once

namespace molchanov2 {

	using namespace System;
	using namespace System::IO;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabControl^ tabControl1;
	protected:
	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::TabPage^ tabPage2;
	private: System::Windows::Forms::TextBox^ fileContentTextBox;

	private: System::Windows::Forms::TextBox^ filePathTextBox;

	private: System::Windows::Forms::Button^ loadFileButton;

	private: System::Windows::Forms::Button^ browseFileButton;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ number;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ form;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ val;








	private:
		System::Collections::Generic::List<int>^ selectedIndex = gcnew System::Collections::Generic::List<int>;
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->fileContentTextBox = (gcnew System::Windows::Forms::TextBox());
			this->filePathTextBox = (gcnew System::Windows::Forms::TextBox());
			this->loadFileButton = (gcnew System::Windows::Forms::Button());
			this->browseFileButton = (gcnew System::Windows::Forms::Button());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->number = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->form = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->val = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Location = System::Drawing::Point(12, 12);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(700, 535);
			this->tabControl1->TabIndex = 0;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->fileContentTextBox);
			this->tabPage1->Controls->Add(this->filePathTextBox);
			this->tabPage1->Controls->Add(this->loadFileButton);
			this->tabPage1->Controls->Add(this->browseFileButton);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(692, 509);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Исходный файл";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// fileContentTextBox
			// 
			this->fileContentTextBox->Location = System::Drawing::Point(7, 62);
			this->fileContentTextBox->Multiline = true;
			this->fileContentTextBox->Name = L"fileContentTextBox";
			this->fileContentTextBox->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->fileContentTextBox->Size = System::Drawing::Size(679, 441);
			this->fileContentTextBox->TabIndex = 3;
			this->fileContentTextBox->TextChanged += gcnew System::EventHandler(this, &MyForm::fileContentTextBox_TextChanged);
			// 
			// filePathTextBox
			// 
			this->filePathTextBox->Location = System::Drawing::Point(7, 19);
			this->filePathTextBox->Name = L"filePathTextBox";
			this->filePathTextBox->Size = System::Drawing::Size(569, 20);
			this->filePathTextBox->TabIndex = 2;
			// 
			// loadFileButton
			// 
			this->loadFileButton->Location = System::Drawing::Point(582, 33);
			this->loadFileButton->Name = L"loadFileButton";
			this->loadFileButton->Size = System::Drawing::Size(104, 23);
			this->loadFileButton->TabIndex = 1;
			this->loadFileButton->Text = L"Загрузить файл";
			this->loadFileButton->UseVisualStyleBackColor = true;
			this->loadFileButton->Click += gcnew System::EventHandler(this, &MyForm::loadFileButton_Click);
			// 
			// browseFileButton
			// 
			this->browseFileButton->Location = System::Drawing::Point(582, 4);
			this->browseFileButton->Name = L"browseFileButton";
			this->browseFileButton->Size = System::Drawing::Size(104, 23);
			this->browseFileButton->TabIndex = 0;
			this->browseFileButton->Text = L"Выбрать файл";
			this->browseFileButton->UseVisualStyleBackColor = true;
			this->browseFileButton->Click += gcnew System::EventHandler(this, &MyForm::browseFileButton_Click);
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->dataGridView1);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(692, 509);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Таблица лексем";
			this->tabPage2->UseVisualStyleBackColor = true;
			this->tabPage2->Enter += gcnew System::EventHandler(this, &MyForm::tabPage2_Enter);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->number,
					this->form, this->val
			});
			this->dataGridView1->Location = System::Drawing::Point(6, 6);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridView1->Size = System::Drawing::Size(680, 497);
			this->dataGridView1->TabIndex = 0;
			// 
			// number
			// 
			this->number->Frozen = true;
			this->number->HeaderText = L"№-п/п";
			this->number->Name = L"number";
			this->number->ReadOnly = true;
			// 
			// form
			// 
			this->form->Frozen = true;
			this->form->HeaderText = L"Форма";
			this->form->Name = L"form";
			this->form->ReadOnly = true;
			this->form->Width = 400;
			// 
			// val
			// 
			this->val->Frozen = true;
			this->val->HeaderText = L"Выражение";
			this->val->Name = L"val";
			this->val->ReadOnly = true;
			this->val->Width = 300;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(724, 559);
			this->Controls->Add(this->tabControl1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->tabPage2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void browseFileButton_Click(System::Object^ sender, System::EventArgs^ e) {
		dataGridView1->Rows->Add("1", "lex", "val");
		Stream^ myStream;
		OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog;

		openFileDialog1->InitialDirectory = "c:\\";
		openFileDialog1->Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";
		openFileDialog1->FilterIndex = 1;
		openFileDialog1->RestoreDirectory = true;

		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			if ((myStream = openFileDialog1->OpenFile()) != nullptr)
			{
				// Insert code to read the stream here.
				filePathTextBox->Text = openFileDialog1->FileName;
				myStream->Close();
			}
		}
	}
	private: System::Void loadFileButton_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ filename = filePathTextBox->Text;
		if (filename != nullptr) {
			try
			{
				StreamReader^ DataIn = File::OpenText(filename);
				String^ DataStr;
				int count = 0;
				fileContentTextBox->Text = DataIn->ReadToEnd();
			}
			catch (Exception^ e)
			{
				if (dynamic_cast<FileNotFoundException^>(e))
					MessageBox::Show("File " + filename + " not found");
			}
		}
	}
	private: System::Void print(std::vector<TokenNode> tokens) {
		DataGridView^ table = dataGridView1;
		table->Rows->Clear();
		table->ClearSelection();
		selectedIndex->Clear();
		int i = 0;
		for each (TokenNode token in tokens) {
			int rowId = table->Rows->Add();
			table->Rows[rowId]->Cells[0]->Value = i;
			table->Rows[rowId]->Cells[1]->Value = gcnew String(_toPrint(token.type).c_str());
			table->Rows[rowId]->Cells[2]->Value = gcnew String(_toPrint(token).c_str());
			if (token.type == TKN_UNKNOWN ||
				token.type == TKN_ERROR_BRACKET_DONT_CLOSE ||
				token.type == TKN_ERROR_COMMENT_NOT_CLOSED
				) {
				selectedIndex->Add(i);
			}
			i++;
		}
		table->Refresh();
	}
	private: void prnt(std::string str) {

	}
	private: System::Void fileContentTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		prnt(fileContentTextBox->Text);
		print(tokenize(msclr::interop::marshal_as<std::string>(fileContentTextBox->Text)));
	}
	private: System::Void tabPage2_Enter(System::Object^ sender, System::EventArgs^ e) {
		DataGridView^ table = dataGridView1;
		table->ClearSelection();
		for (int i = 0; i < selectedIndex->Count; i++) {
			table->Rows[selectedIndex[i]]->Selected = true;
		}
		//table->Refresh();
	}
	};
}