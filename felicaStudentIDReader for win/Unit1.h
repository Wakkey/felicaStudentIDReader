//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
struct soundinfo
{
    char *name;
    UINT value;
	char *param;
};
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE �ŊǗ������R���|�[�l���g
	TTimer *Timer1;
	TLabel *Label2;
	TPanel *Panel1;
	TPanel *Panel2;
	TStringGrid *StringGrid1;
	TPanel *Panel3;
	TStringGrid *StringGrid2;
	TPanel *Panel4;
	TPanel *Panel5;
	TPanel *Panel6;
	TLabel *Label3;
	TLabel *Label1;
	TEdit *Edit1;
	TButton *Button1;
	TButton *Button2;
	TLabel *Label4;
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
private:	// ���[�U�[�錾
  void writedate(int);
public:		// ���[�U�[�錾
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
