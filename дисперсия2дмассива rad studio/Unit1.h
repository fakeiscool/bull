//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
class Tv : public TForm
{
__published:	// IDE-managed Components
	TStringGrid *StringGrid1;
	TEdit *Edit1;
	TEdit *Edit2;
	TButton *Button1;
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall Tv(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tv *v;
//---------------------------------------------------------------------------
#endif
