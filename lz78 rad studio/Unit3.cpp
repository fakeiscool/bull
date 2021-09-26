//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
		for (int i=0; i < 3; i++) {
			StringGrid1 -> Cols[i]->Clear();
			StringGrid1 -> Rows[i]->Clear();
		}
}
//---------------------------------------------------------------------------
