#pragma once
#include <string>
#include <cmath>

namespace ÊàëüêóëÿòîðËîãàðèôìîâ {


	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	int stage;

	/// <summary>
	/// Ñâîäêà äëÿ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: äîáàâüòå êîä êîíñòðóêòîðà
			//
		}

	protected:
		/// <summary>
		/// Îñâîáîäèòü âñå èñïîëüçóåìûå ðåñóðñû.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Button^ button9;
	private: System::Windows::Forms::Button^ button10;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button11;
	private: System::Windows::Forms::Button^ button12;
	private: System::Windows::Forms::Button^ button13;
	private: System::Windows::Forms::Button^ button14;
	private: System::Windows::Forms::Button^ button15;
	private: System::Windows::Forms::Button^ button16;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Button^ button17;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Button^ button18;
	private: System::Windows::Forms::Button^ button19;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::TextBox^ textBox7;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	protected:

	private:
		/// <summary>
		/// Îáÿçàòåëüíàÿ ïåðåìåííàÿ êîíñòðóêòîðà.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Òðåáóåìûé ìåòîä äëÿ ïîääåðæêè êîíñòðóêòîðà — íå èçìåíÿéòå 
		/// ñîäåðæèìîå ýòîãî ìåòîäà ñ ïîìîùüþ ðåäàêòîðà êîäà.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->button13 = (gcnew System::Windows::Forms::Button());
			this->button14 = (gcnew System::Windows::Forms::Button());
			this->button15 = (gcnew System::Windows::Forms::Button());
			this->button16 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->button17 = (gcnew System::Windows::Forms::Button());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->button18 = (gcnew System::Windows::Forms::Button());
			this->button19 = (gcnew System::Windows::Forms::Button());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->button1->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->button1->ForeColor = System::Drawing::SystemColors::ControlText;
			this->button1->Location = System::Drawing::Point(14, 147);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(30, 30);
			this->button1->TabIndex = 0;
			this->button1->Text = L"1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(14, 183);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(30, 30);
			this->button2->TabIndex = 1;
			this->button2->Text = L"4";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(14, 219);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(30, 30);
			this->button3->TabIndex = 2;
			this->button3->Text = L"7";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(50, 183);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(30, 30);
			this->button4->TabIndex = 3;
			this->button4->Text = L"5";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(86, 147);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(30, 30);
			this->button5->TabIndex = 4;
			this->button5->Text = L"3";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(86, 183);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(30, 30);
			this->button6->TabIndex = 5;
			this->button6->Text = L"6";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// button7
			// 
			this->button7->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->button7->Cursor = System::Windows::Forms::Cursors::Default;
			this->button7->ForeColor = System::Drawing::SystemColors::ControlText;
			this->button7->Location = System::Drawing::Point(50, 147);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(30, 30);
			this->button7->TabIndex = 6;
			this->button7->Text = L"2";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(50, 219);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(30, 30);
			this->button8->TabIndex = 7;
			this->button8->Text = L"8";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &MyForm::button8_Click);
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(86, 219);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(30, 30);
			this->button9->TabIndex = 8;
			this->button9->Text = L"9";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &MyForm::button9_Click);
			// 
			// button10
			// 
			this->button10->Location = System::Drawing::Point(122, 219);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(30, 30);
			this->button10->TabIndex = 9;
			this->button10->Text = L"0";
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &MyForm::button10_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(262, 48);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(102, 20);
			this->textBox1->TabIndex = 10;
			// 
			// button11
			// 
			this->button11->Location = System::Drawing::Point(166, 147);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(106, 30);
			this->button11->TabIndex = 11;
			this->button11->Text = L"^n";
			this->button11->UseVisualStyleBackColor = true;
			this->button11->Click += gcnew System::EventHandler(this, &MyForm::button11_Click);
			// 
			// button12
			// 
			this->button12->Location = System::Drawing::Point(166, 183);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(106, 30);
			this->button12->TabIndex = 12;
			this->button12->Text = L"->n";
			this->button12->UseVisualStyleBackColor = true;
			this->button12->Click += gcnew System::EventHandler(this, &MyForm::button12_Click);
			// 
			// button13
			// 
			this->button13->Location = System::Drawing::Point(222, 219);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(50, 30);
			this->button13->TabIndex = 13;
			this->button13->Text = L"/";
			this->button13->UseVisualStyleBackColor = true;
			this->button13->Click += gcnew System::EventHandler(this, &MyForm::button13_Click);
			// 
			// button14
			// 
			this->button14->Location = System::Drawing::Point(166, 219);
			this->button14->Name = L"button14";
			this->button14->Size = System::Drawing::Size(50, 30);
			this->button14->TabIndex = 14;
			this->button14->Text = L"*";
			this->button14->UseVisualStyleBackColor = true;
			this->button14->Click += gcnew System::EventHandler(this, &MyForm::button14_Click);
			// 
			// button15
			// 
			this->button15->Location = System::Drawing::Point(122, 183);
			this->button15->Name = L"button15";
			this->button15->Size = System::Drawing::Size(30, 30);
			this->button15->TabIndex = 15;
			this->button15->Text = L"-";
			this->button15->UseVisualStyleBackColor = true;
			this->button15->Click += gcnew System::EventHandler(this, &MyForm::button15_Click);
			// 
			// button16
			// 
			this->button16->Location = System::Drawing::Point(122, 147);
			this->button16->Name = L"button16";
			this->button16->Size = System::Drawing::Size(30, 30);
			this->button16->TabIndex = 16;
			this->button16->Text = L"+";
			this->button16->UseVisualStyleBackColor = true;
			this->button16->Click += gcnew System::EventHandler(this, &MyForm::button16_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(86, 27);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(110, 20);
			this->textBox2->TabIndex = 17;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(86, 61);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(110, 20);
			this->textBox3->TabIndex = 18;
			// 
			// button17
			// 
			this->button17->Location = System::Drawing::Point(290, 219);
			this->button17->Name = L"button17";
			this->button17->Size = System::Drawing::Size(88, 30);
			this->button17->TabIndex = 19;
			this->button17->Text = L"Ðåçóëüòàò";
			this->button17->UseVisualStyleBackColor = true;
			this->button17->Click += gcnew System::EventHandler(this, &MyForm::button17_Click);
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(34, 48);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(20, 20);
			this->textBox4->TabIndex = 20;
			// 
			// button18
			// 
			this->button18->Location = System::Drawing::Point(290, 147);
			this->button18->Name = L"button18";
			this->button18->Size = System::Drawing::Size(88, 29);
			this->button18->TabIndex = 21;
			this->button18->Text = L"Î÷èñòèòü";
			this->button18->UseVisualStyleBackColor = true;
			this->button18->Click += gcnew System::EventHandler(this, &MyForm::button18_Click);
			// 
			// button19
			// 
			this->button19->Location = System::Drawing::Point(290, 183);
			this->button19->Name = L"button19";
			this->button19->Size = System::Drawing::Size(88, 30);
			this->button19->TabIndex = 22;
			this->button19->Text = L"Ââîä";
			this->button19->UseVisualStyleBackColor = true;
			this->button19->Click += gcnew System::EventHandler(this, &MyForm::button19_Click);
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(202, 34);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(20, 20);
			this->textBox5->TabIndex = 23;
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(202, 68);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(20, 20);
			this->textBox6->TabIndex = 24;
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(14, 121);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(258, 20);
			this->textBox7->TabIndex = 25;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(55, 34);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(25, 13);
			this->label1->TabIndex = 26;
			this->label1->Text = L"Log";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(55, 68);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(25, 13);
			this->label2->TabIndex = 27;
			this->label2->Text = L"Log";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(237, 50);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(13, 13);
			this->label3->TabIndex = 28;
			this->label3->Text = L"=";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->ClientSize = System::Drawing::Size(390, 261);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox7);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->button19);
			this->Controls->Add(this->button18);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->button17);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->button16);
			this->Controls->Add(this->button15);
			this->Controls->Add(this->button14);
			this->Controls->Add(this->button13);
			this->Controls->Add(this->button12);
			this->Controls->Add(this->button11);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button10);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"Êàëüêóëÿòîð";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
// ñòàðò
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e)
{
	textBox1->Text = "";
	textBox2->Text = "";
	textBox3->Text = "";
	textBox4->Text = "";
	textBox5->Text = "";
	textBox6->Text = "";
	textBox7->Text = "";
	stage = 0;
	textBox7->Text = "Ââåäèòå ïåðâîå ëîãàðèôìèðóåìîå ÷èñëî";
}
// ðåçóëüòàò
private: System::Void button17_Click(System::Object^ sender, System::EventArgs^ e) {
	double a, b, c, aa, bb;
	double firstlog, secondlog;

	a = System::Convert::ToDouble(textBox2->Text);
	aa = System::Convert::ToDouble(textBox5->Text);
	if(textBox3->Text!="") b = System::Convert::ToDouble(textBox3->Text);
	if (textBox6->Text != "") bb = System::Convert::ToDouble(textBox6->Text);

	if (textBox4->Text == "^n" || textBox4->Text == "->n") {
		if (textBox4->Text == "^n") { c = log(a)/log(aa) * b; }
		else { c = log(a)/log(bb) ; }
	}
	else if (textBox3->Text == "" && textBox6->Text == "" && a > 0 && aa > 0 && a != 1)
	{
		c = log(a) / log(aa);
	}
	else
	{
		if (a <= 0 || b <= 0 || aa <= 0 || aa == 1 || bb <= 0 || bb == 1)
		{
			textBox7->Text = "Íåêîððåêòíûå ëîãàðèôìû";
		}
		else {
			if (textBox4->Text == "+" && textBox2->Text && textBox3->Text)
			{

				if (aa = bb) c = log(a * b) / log(aa);
				else c = log(a) / log(aa) + log(b) / log(bb);

			}
			if (textBox4->Text == "-" && textBox2->Text && textBox3->Text)
			{


				if (aa = bb) c = log(a / b) / log(aa);
				else c = log(a) / log(aa) - log(b) / log(bb);

			}
			if (textBox4->Text == "*" && textBox2->Text && textBox3->Text)
			{

				if (aa == b && bb == a) { c = 1; }
				else  c = log(a) / log(aa) * log(b) / log(bb);
			}
			if (textBox4->Text == "/" && textBox2->Text && textBox3->Text)
			{
				if (aa == bb) c = log(a) / log(b);
				else log(a) / log(aa) / log(b) / log(bb);
			}

			else { textBox7->Text = "Ââåäèòå ÷èñëà"; }
			
		}
	}
	textBox1->Text = System::Convert::ToString(c);
}
//î÷èñòêà
private: System::Void button18_Click(System::Object^ sender, System::EventArgs^ e)
{
	textBox1->Text = "";
	textBox2->Text = "";
	textBox3->Text = "";
	textBox4->Text = "";
	textBox5->Text = "";
	textBox6->Text = "";
	textBox7->Text = "";
	stage = 0;
	textBox7->Text = "Ââåäèòå ïåðâîå ëîãàðèôìèðóåìîå ÷èñëî";
}
//ââîä
private: System::Void button19_Click(System::Object^ sender, System::EventArgs^ e)
	{
		stage++;
		switch (stage)
		{
			
		case 1:
			
			textBox7->Text = "Ââåäèòå îñíîâàíèå ïåðâîãî ëîãîðèôìà"; break;
		case 2:
			
			textBox7->Text = "Ââåäèòå âûïîëíÿåìîå äåéñòâèå"; break;
		case 3:
			if (textBox4->Text == "^n") { textBox7->Text = "Ââåäèòå ñòåïåíü"; break; }
			else if (textBox4->Text == "->n") { textBox7->Text = "Ââåäèòå íîâîå îñíîâàíèå"; break; }
			else { textBox7->Text = "Ââåäèòå âòîðîå ëîãàðèôìèðóåìîå ÷èñëî"; break; }

		case 4:
			textBox7->Text = "Ââåäèòå îñíîâàíèå âòîðîãî ëîãàðèôìà"; break;

		case 5:
			textBox7->Text = "Íàæìèòå íà ðåçóëüòàò"; break;
		}
	
}//ââîä
// ÷èñëà
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) //1
{
	String^ one = "1";
	
	switch (stage)
	{
	case 0:
		textBox2->Text += System::Convert::ToString(one); break;
	case 1:
		textBox5->Text += System::Convert::ToString(one); break;
	case 3:
		if (textBox4->Text == "^n" || textBox4->Text == "->n")
		{
			if(textBox4->Text == "^n"){ textBox3->Text += System::Convert::ToString(one); stage = 4; break; }
			if (textBox4->Text == "->n"){textBox6->Text += System::Convert::ToString(one);  stage = 4;break; }
		}
			textBox3->Text += System::Convert::ToString(one); break;
	case 4:
		textBox6->Text += System::Convert::ToString(one); break;
	
	}
}
private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) //2
{
	String^ two = "2";
	switch (stage)
	{
	case 0:
		textBox2->Text += System::Convert::ToString(two); break;
	case 1:
		textBox5->Text += System::Convert::ToString(two); break;
	case 3:
		if (textBox4->Text == "^n" || textBox4->Text == "->n")
		{
			if (textBox4->Text == "^n") { textBox3->Text += System::Convert::ToString(two); stage = 4; break; }
			else { textBox6->Text += System::Convert::ToString(two); stage = 4; break; }
		}
		else
		textBox3->Text += System::Convert::ToString(two); break;
	case 4:
		textBox6->Text += System::Convert::ToString(two); break;
	}
}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) 
{
		   String^ three = "3";
		   switch (stage)
		   {
		   case 0:
			   textBox2->Text += System::Convert::ToString(three); break;
		   case 1:
			   textBox5->Text += System::Convert::ToString(three); break;
		   case 3:
			   if (textBox4->Text == "^n" || textBox4->Text == "->n")
			   {
				   if (textBox4->Text == "^n") { textBox3->Text += System::Convert::ToString(three);  stage = 4;break; }
				   else { textBox6->Text += System::Convert::ToString(three); stage = 4; break; }
			   }
			   else
			   textBox3->Text += System::Convert::ToString(three); break;
		   case 4:
			   textBox6->Text += System::Convert::ToString(three); break;
		   }
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ four = "4";
	switch (stage)
	{
	case 0:
		textBox2->Text += System::Convert::ToString(four); break;
	case 1:
		textBox5->Text += System::Convert::ToString(four); break;
	case 3:
		if (textBox4->Text == "^n" || textBox4->Text == "->n")
		{
			if (textBox4->Text == "^n") { textBox3->Text += System::Convert::ToString(four);  stage = 4;break; }
			else { textBox6->Text += System::Convert::ToString(four); stage = 4; break; }
		}
		else
		textBox3->Text += System::Convert::ToString(four); break;
	case 4:
		textBox6->Text += System::Convert::ToString(four); break;
	}
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ five = "5";
	
	switch (stage)
	{
	case 0:
		textBox2->Text += System::Convert::ToString(five); break;
	case 1:
		textBox5->Text += System::Convert::ToString(five); break;
	case 3:
		if (textBox4->Text == "^n" || textBox4->Text == "->n")
		{
			if (textBox4->Text == "^n") { textBox3->Text += System::Convert::ToString(five); stage = 4; break; }
			else { textBox6->Text += System::Convert::ToString(five); stage = 4; break; }
		}
		else
		textBox3->Text += System::Convert::ToString(five); break;
	case 4:
		textBox6->Text += System::Convert::ToString(five); break;
	}
}
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ six = "6";
	switch (stage)
	{
	case 0:
		textBox2->Text += System::Convert::ToString(six); break;
	case 1:
		textBox5->Text += System::Convert::ToString(six); break;
	case 3:
		if (textBox4->Text == "^n" || textBox4->Text == "->n")
		{
			if (textBox4->Text == "^n") { textBox3->Text += System::Convert::ToString(six); stage = 4; break; }
			else { textBox6->Text += System::Convert::ToString(six); stage = 4; break; }
		}
		else
		textBox3->Text += System::Convert::ToString(six); break;
	case 4:
		textBox6->Text += System::Convert::ToString(six); break;
	}
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ seven = "7";
	
	switch (stage)
	{
	case 0:
		textBox2->Text += System::Convert::ToString(seven); break;
	case 1:
		textBox5->Text += System::Convert::ToString(seven); break;
	case 3:
		if (textBox4->Text == "^n" || textBox4->Text == "->n")
		{
			if (textBox4->Text == "^n") { textBox3->Text += System::Convert::ToString(seven); stage = 4; break; }
			else { textBox6->Text += System::Convert::ToString(seven); stage = 4; break; }
		}
		else
		textBox3->Text += System::Convert::ToString(seven); break;
	case 4:
		textBox6->Text += System::Convert::ToString(seven); break;
	}
}
private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ eight = "8";
	switch (stage)
	{
	case 0:
		textBox2->Text += System::Convert::ToString(eight); break;
	case 1:
		textBox5->Text += System::Convert::ToString(eight); break;
	case 3:
		if (textBox4->Text == "^n" || textBox4->Text == "->n")
		{
			if (textBox4->Text == "^n") { textBox3->Text += System::Convert::ToString(eight); stage = 4; break; }
			else { textBox6->Text += System::Convert::ToString(eight); stage = 4; break; }
		}
		else
		textBox3->Text += System::Convert::ToString(eight); break;
	case 4:
		textBox6->Text += System::Convert::ToString(eight); break;
	}
}
private: System::Void button9_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ nine = "9";
	switch (stage)
	{
	case 0:
		textBox2->Text += System::Convert::ToString(nine); break;
	case 1:
		textBox5->Text += System::Convert::ToString(nine); break;
	case 3:
		if (textBox4->Text == "^n" || textBox4->Text == "->n")
		{
			if (textBox4->Text == "^n") { textBox3->Text += System::Convert::ToString(nine); stage = 4; break; }
			else { textBox6->Text += System::Convert::ToString(nine); stage = 4; break; }
		}
		else
		textBox3->Text += System::Convert::ToString(nine); break;
	case 4:
		textBox6->Text += System::Convert::ToString(nine); break;
	}
}
private: System::Void button10_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ null = "0";
	switch (stage)
	{
	case 0:
		textBox2->Text += System::Convert::ToString(null); break;
	case 1:
		textBox5->Text += System::Convert::ToString(null); break;
	case 3:
		if (textBox4->Text == "^n" || textBox4->Text == "->n")
		{
			if (textBox4->Text == "^n") { textBox3->Text += System::Convert::ToString(null); stage = 4; break; }
			else { textBox6->Text += System::Convert::ToString(null); stage = 4; break; }
		}
		else
		textBox3->Text += System::Convert::ToString(null); break;
	case 4:
		textBox6->Text += System::Convert::ToString(null); break;
	}

}
// çíàêè
private: System::Void button16_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ plus = "+";
	switch (stage)
	{
	
	case 2:
		textBox4->Text += System::Convert::ToString(plus); break;
	
	}
}
private: System::Void button15_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ minus = "-";
	
	switch (stage)
	{
	
	case 2:
		textBox4->Text += System::Convert::ToString(minus); break;

	}
}
private: System::Void button14_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ multiply = "*";

	switch (stage)
	{

	case 2:
		textBox4->Text += System::Convert::ToString(multiply); break;

	}
}
private: System::Void button13_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ division = "/";

	switch (stage)
	{
	case 2:
		textBox4->Text += System::Convert::ToString(division); break;
	}
}
private: System::Void button11_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ pow = "^n";

	switch (stage)
	{
	case 2:
		textBox4->Text += System::Convert::ToString(pow); break;
	}
}
private: System::Void button12_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ newbase = "->n";

	switch (stage)
	{
	case 2:
		textBox4->Text += System::Convert::ToString(newbase); break;
	}
}
};
}
