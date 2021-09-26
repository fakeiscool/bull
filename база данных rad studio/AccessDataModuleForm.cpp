//---------------------------------------------------------------------------


#pragma hdrstop

#include "AccessDataModuleForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma classgroup "Vcl.Controls.TControl"
#pragma resource "*.dfm"
TAccessDataModule *AccessDataModule;
//---------------------------------------------------------------------------
__fastcall TAccessDataModule::TAccessDataModule(TComponent* Owner)
	: TDataModule(Owner)
{
}

//  программка выполняющая запрос к базе и возвращающая только один параметр
//       Гатин Г.Н.   28.01.2005
//    скопирована из BigProject    27.05.2011     Гатин Г.Н.
//     модифицирована     27.05.2011
AnsiString __fastcall TAccessDataModule::QueryWorkOne(TADOQuery * pQ, AnsiString s)
{
AnsiString Bs;
		 pQ -> Close();
		 pQ -> SQL -> Clear();
		 pQ -> SQL -> Add(s);
		 pQ -> Open();
		 if (pQ -> RecordCount == 0) Bs = "";
					  else Bs = pQ -> Fields -> Fields[0] -> Value;
		 return Bs;
}

//  программка выполняющая запрос к базе и возвращающая число полученных записей
//       Гатин Г.Н.   14.05.2005 получена копированием QueryWorkOne
//    скопирована из BigProject    27.05.2011     Гатин Г.Н.
int __fastcall TAccessDataModule::QueryWorkHow(TADOQuery * pQ, AnsiString s)
{
		 pQ -> Close();
		 pQ -> SQL -> Clear();
		 pQ -> SQL -> Add(s);
		 pQ -> Open();
		 pQ -> First();
		 return pQ -> RecordCount;
}

//  программка выполняющая запрос к базе типа Update, Delete.
//       Гатин Г.Н.   13.02.2006
//    скопирована из BigProject    27.05.2011     Гатин Г.Н.
void __fastcall TAccessDataModule::QueryExecHow(TADOQuery * pQ, AnsiString s)
{
		 pQ -> Close();
		 pQ -> SQL -> Clear();
		 pQ -> SQL -> Add(s);
		 pQ -> ExecSQL();
}


