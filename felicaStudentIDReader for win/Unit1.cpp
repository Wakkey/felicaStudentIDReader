//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include <stdio.h>
#include <stdlib.h>
#include <System.DateUtils.hpp>
#include "felicalib.h"

#define SYSTEM_CODE 0x88B4
#define SERVICE_CODE 0x000B
#define STUDENT_ID_BLOCK_NUM 0x8004

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
soundinfo sounds[] = {
						{"Standard", 0xFFFFFF, "0xFFFFFF"},
						{"Asterisk", MB_ICONASTERISK, "MB_ICONASTERISK"},
						{"Exclamation", MB_ICONEXCLAMATION, "MB_ICONEXCLAMATION"},
						{"Hand", MB_ICONHAND, "MB_ICONHAND"},
						{"Question", MB_ICONQUESTION, "MB_ICONQUESTION"},
						{"Default", MB_OK, "MB_OK"}
					 };
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
__declspec(dllexport) char* __stdcall ReadStudentID(){
	pasori *p;
	felica *f;
	char str[93]; //�w�Дԍ��i�[
	uint8 data[16]; //read�����f�[�^�̎󂯌�

	p = pasori_open(NULL);
	if (!p) return false;

	pasori_init(p); //pasori�̏�����

	f = felica_polling(p, SYSTEM_CODE, 0, 0) ;
	if (!f) return false;

	felica_read_without_encryption02(f,SERVICE_CODE,0,STUDENT_ID_BLOCK_NUM,data);

	for(int i =2;i<9;i++)sprintf(&str[i-2],"%c",data[i]); //ASCII�ϊ�
	sprintf(&str[7],"%c",NULL);

	felica_free(f);
	return str;
}












void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
   char* ret = ReadStudentID();
   TStringList *alist;
   alist = new TStringList;
   alist->Clear();
   String s,s1,s2;
   int i,i1,i2;
   bool sw = false;
   s1 = "abcdefghijklmnopqrstuwxyz1234567890";
   s = ret;
   if ( 6 < s.Length() ){
	 for (i = 1; i < s1.Length();i++){
	   if ( s[7] == s1[i] ){
		 sw = true;
	   }
	 }
   }
   Form1->Label2->Caption = s;

   if ( Form1->Label2->Caption == "" ) {

   } else
   {
	 if (sw == true) {


	 s = Form1->Label2->Caption;
	 if (7== s.Length()){
	   i1 = Form1->StringGrid1->Cols[2]->IndexOf(s);
	   if ( -1 == i1 ) {
		 //Form1->ListBox1->Items->Add(Form1->Label2->Caption);
		 //alist->Add(Form1->Label2->Caption);
		 Form1->StringGrid1->RowCount = Form1->StringGrid1->RowCount + 1;
		 i = Form1->StringGrid1->RowCount -1;
		 //if (Form1->RadioGroup1->ItemIndex == 0 ) {
		   Form1->StringGrid1->Cells[2][i] = Form1->Label2->Caption;

		   TDateTime date = Date();
		   TDateTime time = Time();
		   String s,s1;
		   s1 = DateTimeToStr(date);
		   s2 = time.TimeString();

		   Form1->StringGrid1->Cells[0][i] = i;
		   Form1->StringGrid1->Cells[1][i] = "�����C�o��";
		   Form1->StringGrid1->Cells[4][i] = s1;//s[1] +s[2] +s[3] +s[4] +s[5] +s[6] +s[7] +s[8] +s[9] +s[10];
		   Form1->StringGrid1->Cells[5][i] = s2;//s[11] +s[12] +s[13] +s[14] +s[15] +s[16] +s[17] +s[18];

		   //Form1->ListBox2->Items->Add(s);
		   MessageBeep(sounds[5].value);
		   Button1Click(Sender);
		 //}
	   } else {
		 //if (Form1->RadioGroup1->ItemIndex == 1 ) {
		   //Form1->StringGrid1->Cells[2][i] = Form1->Label2->Caption;

		   TDateTime date = Date();
		   TDateTime time = Time();
		   String s,s1;
		   s1 = DateTimeToStr(date);
		   s2 = time.TimeString();

		   //Form1->StringGrid1->Cells[0][i] = i;
		   Form1->StringGrid1->Cells[1][i] = "�o��";
		   Form1->StringGrid1->Cells[4][i] = s1;//s[1] +s[2] +s[3] +s[4] +s[5] +s[6] +s[7] +s[8] +s[9] +s[10];
		   Form1->StringGrid1->Cells[5][i] = s2;//s[11] +s[12] +s[13] +s[14] +s[15] +s[16] +s[17] +s[18];

		   //Form1->ListBox2->Items->Add(s);
		   MessageBeep(sounds[5].value);
		   Button1Click(Sender);
		 }
	   }
	 }
   //}
}


}
//---------------------------------------------------------------------------




void __fastcall TForm1::FormCloseQuery(TObject *Sender, bool &CanClose)
{
			 Button1Click(Sender);
   }
//---------------------------------------------------------------------------



void __fastcall TForm1::FormCreate(TObject *Sender)
{
  Form1->StringGrid1->Cells[1][0] = "�o�ȉ�";
  Form1->StringGrid1->Cells[2][0] = "�w�Дԍ�";
  Form1->StringGrid1->Cells[3][0] = "���O";
  Form1->StringGrid1->Cells[4][0] = "�o�ȓ��t";
  Form1->StringGrid1->Cells[5][0] = "�o�Ȏ���";
  //Form1->StringGrid1->Cells[6][0] = "�ސȎ���";

}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button1Click(TObject *Sender)
{
   //String s,s1;
   TMemo* amemo = new TMemo(this);
   amemo->Parent = Form1->Button1;
   amemo->Visible = false;
   //TImage* image = new TImage(this);
   //amemo = new TMemo;
   //TDateTime time = Now();

   amemo->Lines->Clear();
   for (int i=0; i < Form1->StringGrid1->RowCount; i++) {
	 //s = alist->Strings[i];
	 //s1 = Form1->ListBox2->Items->Strings[i];
	 //alist->Add(s + "," + s1);
	 //Form1->Caption = s + s1;
	 //alist->Add(Form1->StringGrid1->Rows[i]->Text);
	 Caption = Form1->StringGrid1->Rows[i]->CommaText;
	 amemo->Lines->Add(Form1->StringGrid1->Rows[i]->CommaText);
   }
   //alist->SaveToFile(ExtractFilePath( ParamStr(0) ) + "�o��.csv");
   //Form1->StringGrid1->Rows[1]->SaveToFile(ExtractFilePath( ParamStr(0) ) + "�o��.csv");
   Button2Click(Sender);
   amemo->Lines->SaveToFile(ExtractFilePath( ParamStr(0) ) + "�o��" + Edit1->Text + ".csv");
   amemo->Free();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
  TDateTime date = Now();
  //2013/04/26
  //2013_04/26
  //2:47:53
  String s,s1,s2;
  String c = L"_";
  s = date.DateString();
  s1 = HourOf(date);
  s2 = MinuteOf(date);
  s[5] = c[1];
  s[8] = c[1];
  Form1->Edit1->Text = s + c + s1 + c + s2;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioGroup1Click(TObject *Sender)
{
  /*TMemo *amemo;
  amemo = new TMemo(this);
  amemo->Parent = Form1;
  amemo->Visible = false;
  amemo->Lines->Clear();

  if ( Form1->RadioGroup1->ItemIndex == 0 )	{
	  Form1->StringGrid1->ColCount = 6;
	  amemo->Lines->LoadFromFile(ExtractFilePath( ParamStr(0) ) + "����.csv");
	  for (int i=0; i < amemo->Lines->Count-1; i++ ){
		Form1->StringGrid1->Rows[i]->CommaText = amemo->Lines[i].Text;
		Form1->StringGrid1->RowCount = Form1->StringGrid1->RowCount + 1;
	  }
  } else {
	  if ( Edit2->Text != "" ) {
		Button2Click(Sender);
		Edit2->Text = Edit1->Text;
	  }
	  Form1->StringGrid1->ColCount = 5;
	  amemo->Lines->LoadFromFile(ExtractFilePath( ParamStr(0) ) + Edit2->Text + ".csv");
	  for (int i=0; i < amemo->Lines->Count-1; i++ ){
		Form1->StringGrid1->Rows[i]->CommaText = amemo->Lines[i].Text;
		Form1->StringGrid1->RowCount = Form1->StringGrid1->RowCount + 1;
	  }
	}
  amemo->Free(); */
}
//---------------------------------------------------------------------------

