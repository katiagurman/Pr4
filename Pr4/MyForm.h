#pragma once
#include <cstdlib>
#include <ctime>
namespace Pr4 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;
	private: System::Windows::Forms::Button^ button1;



	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::Label^ label1;


	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(45, 328);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(436, 75);
			this->button1->TabIndex = 3;
			this->button1->Text = L"�������� ������ � ����\'������ ���������� �������������";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(45, 140);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(436, 173);
			this->richTextBox1->TabIndex = 6;
			this->richTextBox1->Text = L"";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(24, 64);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(505, 48);
			this->label1->TabIndex = 7;
			this->label1->Text = resources->GetString(L"label1.Text");
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(576, 443);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"Pr4";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		// ������������ ������������ ���������� ���������� �����
		srand(time(0));

		const int size = 20; // ����� ������
		int array[size];     // ���������� ������
		double sum = 0;      // ����� ��� ���������� ���� ��������
		int count = 0;       // ����� ��� ���������� ������� �������� � ������� ���������

		// ���������� ������ ����������� ������� � �������� [-50;50]
		for (int i = 0; i < size; ++i) {
			array[i] = rand() % 101 - 50; // �������� ����� �� -50 �� 50
		}

		// ���������� ���� �������� � ������� ��������� �� �� �������
		for (int i = 0; i < size; i += 2) {
			sum += array[i];
			count++;
		}

		// ���������� ���������� �������������
		double average = count ? sum / count : 0;

		// ��������� ������ �� ���������� ������������� � richTextBox1
		for (int i = 0; i < size; ++i) {
			richTextBox1->AppendText(array[i].ToString() + "\n");
		}
		richTextBox1->AppendText("C����� ����������� �������� ������������ ������, � ������� ���������: " + average.ToString() + "\n");
	}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
