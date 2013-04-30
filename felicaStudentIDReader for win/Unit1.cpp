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
	char str[93]; //学籍番号格納
	uint8 data[16]; //readしたデータの受け口

	p = pasori_open(NULL);
	if (!p) return false;

	pasori_init(p); //pasoriの初期化

	f = felica_polling(p, SYSTEM_CODE, 0, 0) ;
	if (!f) return false;

	felica_read_without_encryption02(f,SERVICE_CODE,0,STUDENT_ID_BLOCK_NUM,data);

	for(int i =2;i<9;i++)sprintf(&str[i-2],"%c",data[i]); //ASCII変換
	sprintf(&str[7],"%c",NULL);

	felica_free(f);
	return str;
}

void TForm1::writedate(int i){
  TDateTime date = Date();
  TDateTime time = Time();
  String s1,s2;
  String s3;
  s1 = DateTimeToStr(date);
  s2 = time.TimeString();
  TDateTime letemagin = StrToDateTime("1:30:00");
  TDateTime early_margin = StrToDateTime("0:10:00");
  TDateTime set1,set2;

  //何時限目かを返す


	TDateTime academic_time[6];
	s3 = "0:00:00";
	academic_time[0] = StrToDateTime(s3);

	s3 = "9:00:00";
	academic_time[1] = StrToDateTime(s3);

	s3 = "10:40:00";
	academic_time[2] = StrToDateTime(s3);

	s3 = "13:10:00";
	academic_time[3] = StrToDateTime(s3);

	s3 = "14:50:00";
	academic_time[4] = StrToDateTime(s3);

	s3 = "16:30:00";
	academic_time[5] = StrToDateTime(s3);

	s3 = "18:10:00";
	academic_time[6] = StrToDateTime(s3);


  for ( int i1 = 0; i1 < 7; i1++ ) {
	set1 = ( academic_time[i1] + letemagin );
	set2 = ( early_margin + time );
	if ( set1 < set2 ) {
	  s2 = IntToStr(i1) + "時限目";
	  //ShowMessage(set1.TimeString() + " " + set2.TimeString());
	}
	if ( academic_time[6] < time ) {
	  s2 = "0";
	}
	if ( i1 == 0 ) {
      s2 = 0;
	}
  }

  Form1->StringGrid1->Cells[0][i] = i;
  Form1->StringGrid1->Cells[5][i] = s1;
  Form1->StringGrid1->Cells[6][i] = s2;
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
   int i,i1,i2,i3,i4,i5;;
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

	  if ( Form1->StringGrid2->Cells[0][i] == ( s ) ) {

		s3 = Form1->StringGrid2->Cells[1][i];
		//Caption = s3;
		Form1->Label3->Caption = s3;
		Form1->StringGrid1->Cells[2][i] = s3;

		i4 = Form1->StringGrid2->Cols[0]->IndexOf(s);
        if ( i4 != -1 ) {
		  i5 = Form1->StringGrid1->Cols[1]->IndexOf(s);
		  if ( i5 != -1 ) {
			Form1->StringGrid1->Cells[3][i5] = Form1->StringGrid2->Cells[2][i4];
			Form1->StringGrid1->Cells[4][i5] = Form1->StringGrid2->Cells[3][i4];
			//Caption = IntToStr(i4);
		  }
		}
		hitsw = true;
		break;
	  } else {
		s3 = "未登録です";
		Form1->Label3->Caption = s3;
		//Form1->StringGrid1->Cells[3][i] = s3;
		hitsw = false;
	  }
	}
	}

   if (sw == true) {

	 s = Form1->Label2->Caption;
	 if (7== s.Length()){


	   i1 = Form1->StringGrid1->Cols[1]->IndexOf(s);
	   if ( -1 == i1 ) {
		 Form1->StringGrid1->RowCount = Form1->StringGrid1->RowCount + 1;
		 i = Form1->StringGrid1->RowCount -1;
		 Form1->StringGrid1->Cells[1][i] = Form1->Label2->Caption;
		 if ( hitsw ) {
		   Form1->StringGrid1->Cells[2][i] = s3;
		 } else {
		   Form1->StringGrid1->Cells[2][i] = "";
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
  Form1->StringGrid1->Cells[1][0] = "学籍番号";
  Form1->StringGrid1->Cells[2][0] = "名前";
  Form1->StringGrid1->Cells[3][0] = "ふりがな";
  Form1->StringGrid1->Cells[4][0] = "性別";
  Form1->StringGrid1->Cells[5][0] = "出席日時";
  Form1->StringGrid1->Cells[6][0] = "出席時限";
  TStringList* alist = new TStringList(this);
  alist->LoadFromFile(ExtractFilePath( ParamStr(0) )  + "students_sample.csv");
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

   amemo->Lines->SaveToFile(ExtractFilePath( ParamStr(0) ) + "出席" + Edit1->Text + ".csv");
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




