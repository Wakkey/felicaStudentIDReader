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
	char str[93]; //wΠΤi[
	uint8 data[16]; //read΅½f[^Μσ―ϋ

	p = pasori_open(NULL);
	if (!p) return false;

	pasori_init(p); //pasoriΜϊ»

	f = felica_polling(p, SYSTEM_CODE, 0, 0) ;
	if (!f) return false;

	felica_read_without_encryption02(f,SERVICE_CODE,0,STUDENT_ID_BLOCK_NUM,data);

	for(int i =2;i<9;i++)sprintf(&str[i-2],"%c",data[i]); //ASCIIΟ·
	sprintf(&str[7],"%c",NULL);

	felica_free(f);
	return str;
}

void TForm1::writedate(int i){
  TDateTime date = Date();
  TDateTime time = Time();
  String s1,s2;
  s1 = DateTimeToStr(date);
  s2 = time.TimeString();
  Form1->StringGrid1->Cells[0][i] = i;
  Form1->StringGrid1->Cells[4][i] = s1;
  Form1->StringGrid1->Cells[5][i] = s2;
  MessageBeep(sounds[5].value);
  Button1Click(Form1->Button1);
}

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
   char* ret = ReadStudentID();
   TStringList *alist;
   alist = new TStringList;
   alist->Clear();
   String s,s1,s2,s3;
   int i,i1,i2,i3;
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
    s3 = "";
	   Form1->Label3->Caption = "";
	Form1->Label2->Caption = s;
	bool hitsw = false;
	for (int i = 0; i < Form1->StringGrid2->RowCount; i++) {
	if ( s.Length() > 0 ){

	  if ( Form1->StringGrid2->Cells[1][i] == ( s ) ) {
		s3 = Form1->StringGrid2->Cells[2][i];
		Caption = s3;
		Form1->Label3->Caption = s3;
		hitsw = true;
		break;
	  } else {
		s3 = "’o^Ε·";
		Form1->Label3->Caption = s3;
		hitsw = false;
	  }
	}
	}

   if (sw == true) {

	 s = Form1->Label2->Caption;
	 if (7== s.Length()){


	   i1 = Form1->StringGrid1->Cols[2]->IndexOf(s);
	   if ( -1 == i1 ) {
		 Form1->StringGrid1->RowCount = Form1->StringGrid1->RowCount + 1;
		 i = Form1->StringGrid1->RowCount -1;
		 Form1->StringGrid1->Cells[2][i] = Form1->Label2->Caption;
		 if ( hitsw ) {
           Form1->StringGrid1->Cells[1][i] = "oΘ";
		 } else {
		   Form1->StringGrid1->Cells[1][i] = "’CoΘ";
		 }
		 writedate(i);

		 Form1->Label3->Caption =  s3;
	   }
	 }
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
  Form1->StringGrid1->Cells[1][0] = "oΘΒΫ";
  Form1->StringGrid1->Cells[2][0] = "wΠΤ";
  Form1->StringGrid1->Cells[3][0] = "ΌO";
  Form1->StringGrid1->Cells[4][0] = "oΘϊt";
  Form1->StringGrid1->Cells[5][0] = "oΘΤ";
  //Form1->StringGrid1->Cells[6][0] = "ήΘΤ";
  TStringList* alist = new TStringList(this);
  alist->LoadFromFile(ExtractFilePath( ParamStr(0) )  + "Όλ.csv");
  for (int i=0; i < alist->Count ; i++) {
   Form1->StringGrid2->Rows[i]->CommaText = alist->Strings[i];
   Form1->StringGrid2->RowCount = Form1->StringGrid2->RowCount + 1;
  }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button1Click(TObject *Sender)
{
   //String s,s1;
   TMemo* amemo = new TMemo(this);
   amemo->Parent = Form1->Button1;
   amemo->Visible = false;
   amemo->Lines->Clear();

   int i1;
   String s;

   i1 = Form1->StringGrid1->RowCount;

   for (int i=0; i < i1; i++) {
	 //Caption = Form1->StringGrid1->Rows[i]->CommaText;
	 s = Form1->StringGrid1->Rows[i]->CommaText;
	 amemo->Lines->Add( s );
   }

   Button2Click(Sender);

   amemo->Lines->SaveToFile(ExtractFilePath( ParamStr(0) ) + "oΘ" + Edit1->Text + ".csv");
   amemo->Free();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
  TDateTime date = Now();
  String s,s1,s2;
  String c = L"_";
  s = date.DateString();
  s1 = HourOf(date);
  s2 = MinuteOf(date);
  s[5] = c[1];
  s[8] = c[1];
  Form1->Edit1->Text = s + c + s1;
}
//---------------------------------------------------------------------------




