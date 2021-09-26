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

//  ���������� ����������� ������ � ���� � ������������ ������ ���� ��������
//       ����� �.�.   28.01.2005
//    ����������� �� BigProject    27.05.2011     ����� �.�.
//     ��������������     27.05.2011
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

//  ���������� ����������� ������ � ���� � ������������ ����� ���������� �������
//       ����� �.�.   14.05.2005 �������� ������������ QueryWorkOne
//    ����������� �� BigProject    27.05.2011     ����� �.�.
int __fastcall TAccessDataModule::QueryWorkHow(TADOQuery * pQ, AnsiString s)
{
		 pQ -> Close();
		 pQ -> SQL -> Clear();
		 pQ -> SQL -> Add(s);
		 pQ -> Open();
		 pQ -> First();
		 return pQ -> RecordCount;
}

//  ���������� ����������� ������ � ���� ���� Update, Delete.
//       ����� �.�.   13.02.2006
//    ����������� �� BigProject    27.05.2011     ����� �.�.
void __fastcall TAccessDataModule::QueryExecHow(TADOQuery * pQ, AnsiString s)
{
		 pQ -> Close();
		 pQ -> SQL -> Clear();
		 pQ -> SQL -> Add(s);
		 pQ -> ExecSQL();
}


