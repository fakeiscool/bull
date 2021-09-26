//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Mask.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.Dialogs.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1;
	TStringGrid *StringGrid1;
	TMemo *Memo1;
	TMemo *Memo2;
	TMemo *Memo3;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TButton *Button2;
	TMainMenu *MainMenu1;
	TMenuItem *N1;
	TMenuItem *N2;
	TMenuItem *N3;
	TMenuItem *Debug1;
	TMenuItem *N5;
	TMenuItem *N4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TMenuItem *N6;
	TEdit *Edit1;
	TLabel *Label8;
	TButton *Button3;
	TEdit *Edit2;
	TLabel *Label9;
	TLabel *Label10;
	TLabel *Label11;
	TLabel *Label12;
	TLabel *Label13;
	TLabel *Label14;
	TLabel *Label15;
	TLabel *Label16;
	TOpenDialog *OpenDialog1;
	TMenuItem *N7;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Debug1Click(TObject *Sender);
	void __fastcall N1Click(TObject *Sender);
	void __fastcall N2Click(TObject *Sender);
	void __fastcall N3Click(TObject *Sender);
	void __fastcall N4Click(TObject *Sender);
	void __fastcall N6Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Memo1Change(TObject *Sender);
	void __fastcall Memo2Change(TObject *Sender);
	void __fastcall N7Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
