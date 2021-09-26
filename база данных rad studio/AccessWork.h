//---------------------------------------------------------------------------

#ifndef AccessWorkH
#define AccessWorkH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.Dialogs.hpp>
//---------------------------------------------------------------------------
class TAccessWorkForm : public TForm
{
__published:	// IDE-managed Components
	TDBGrid *ViewTab;
	TDBNavigator *DBNavigator1;
	TMainMenu *BigMenu;
	TMenuItem *N1;
	TMenuItem *N2;
	TListBox *TableList;
	TMenuItem *N3;
	TMenuItem *SQL1;
	TMenuItem *SQL2;
	TOpenDialog *OpDi;
	TOpenDialog *OpenDialog1;
	TMenuItem *SQLexec1;
	TMenuItem *N4;
	TMenuItem *N5;
	void __fastcall N2Click(TObject *Sender);
	void __fastcall N3Click(TObject *Sender);
	void __fastcall SQL2Click(TObject *Sender);
	void __fastcall SQLexec1Click(TObject *Sender);
	void __fastcall N5Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TAccessWorkForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TAccessWorkForm *AccessWorkForm;
//---------------------------------------------------------------------------
#endif
