//---------------------------------------------------------------------------
//     ���������� ������ � Access
//       27.10.2020   �.�. �����
#include <vcl.h>
#include <stdio.h>
#pragma hdrstop

#include "AccessWork.h"
#include "AccessDataModuleForm.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

FILE * ASQL;  //  ���� ��� ���������� SQL

char buf[12000];   //   ������ ��� ����� ������
int lbuf = 12000;   //   ����� ����� �������

//     ������� ���������� ��� �����
//      ������� ��������� ����
bool openMyFile(FILE *, AnsiString);

TAccessWorkForm *AccessWorkForm;
//---------------------------------------------------------------------------
__fastcall TAccessWorkForm::TAccessWorkForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TAccessWorkForm::N2Click(TObject *Sender)
{
TStrings *SL = new TStringList;

		 AccessDataModule -> AccessConnect -> Connected = true;

		 AccessDataModule -> AccessConnect -> GetTableNames(SL, false);
		 for (int index = 0; index < SL -> Count; index++)
				TableList -> Items -> Add (SL->Strings[index]);


		 AccessDataModule -> A�Tab -> Open();


		 MessageDlg("����������� � ����� ������",
		     mtInformation, TMsgDlgButtons() << mbOK, NULL);

}
//---------------------------------------------------------------------------

void __fastcall TAccessWorkForm::N3Click(TObject *Sender)
{
	AnsiString str;
	str = TableList->Items->Strings[TableList->ItemIndex];

	AccessDataModule->A�Tab->Active = false;

	AccessDataModule->A�Tab->TableName = str;

    AccessDataModule->A�Tab->Active = true;
}
//---------------------------------------------------------------------------
//     ��������� ������ ���� "��������� SQL"
void __fastcall TAccessWorkForm::SQL2Click(TObject *Sender)
{
AnsiString nfm;
AnsiString sqltext = "select * from ";
AnsiString tbl = "prepod";
AnsiString sql;

//		 nfm = mygetFileName("������� ���� � SQL - �������������.");
		 if (nfm == "") return;
		 ASQL = fopen(nfm.c_str(), "r");
		 while (!feof(ASQL)) {

			 }




int n;   //   ����� ������� � ��������
		 sql = sqltext + tbl;
try {
		 n = AccessDataModule -> QueryWorkHow(AccessDataModule ->pQf, sql);
		 MessageDlg("����� ������� � �������� " + IntToStr(n),
			mtInformation, TMsgDlgButtons() << mbOK, NULL);
} catch (...) {
		 MessageDlg("������� ��� ���������� SQL",
			mtError, TMsgDlgButtons() << mbOK, NULL);
}
}
//---------------------------------------------------------------------------
//      ������� ��������� ����
bool openMyFile(FILE * af, AnsiString tit)
{
AnsiString nm;
		 AccessWorkForm -> OpDi -> Title = tit;
		 if (!AccessWorkForm -> OpDi -> Execute()) {
				   MessageDlg("�� ������� ��� �����.",
					   mtError, TMsgDlgButtons() << mbOK, NULL);
				   return false;
			 }
		 nm = AccessWorkForm -> OpDi -> FileName;
		 ASQL = NULL;
		 ASQL = fopen (nm.c_str(),"r");
		 if (ASQL == NULL) {
		   MessageDlg("�� ������� ������� ���� \"" + nm + "\"",
					   mtError, TMsgDlgButtons() << mbOK, NULL);
		   return false;
		 }
		 return true;
}
//    ��������� ������ ���� "��������� SQL - exec"
void __fastcall TAccessWorkForm::SQLexec1Click(TObject *Sender)
{
AnsiString u;
AnsiString sql;
int i;
		 if (!openMyFile(ASQL, "������� ���� � SQL - �������������.")) return;
		 fgets(buf, lbuf, ASQL);
		 sql = buf;
		 while (!feof(ASQL)) {
			   for (i = 0; i < lbuf; i++) buf[i] = 0x00;
			   fgets(buf, lbuf, ASQL);
			   u = buf;
			   sql = sql + u;
			}
		 MessageDlg(sql,
			mtInformation, TMsgDlgButtons() << mbOK, NULL);

//try {
		 AccessDataModule -> QueryExecHow(AccessDataModule -> pQf, sql);
		 MessageDlg("��������� SQL = exec ",
			mtInformation, TMsgDlgButtons() << mbOK, NULL);
//} catch (...) {
//		 MessageDlg("������� ��� ���������� SQL",
//			mtError, TMsgDlgButtons() << mbOK, NULL);
//}

}
//---------------------------------------------------------------------------
// ��������� ������ ���� ��������� �������
void __fastcall TAccessWorkForm::N5Click(TObject *Sender)
{
AnsiString tblname,u;
int n,r;
	if (!AccessDataModule->AccessConnect->Connected) {
		MessageDlg("������ ��� ���������� SQL",
		mtError, TMsgDlgButtons() << mbOK, NULL);
		return;
	}
	AccessDataModule->A�Tab->Open();
	tblname = AccessDataModule->A�Tab->TableName;
	MessageDlg("��� ������� "+tblname,mtInformation, TMsgDlgButtons() << mbOK, NULL);
	r = AccessDataModule->A�Tab->RecordCount;
	MessageDlg("����� ������� ������� "+IntToStr(r),mtInformation, TMsgDlgButtons() << mbOK, NULL);
	n = AccessDataModule->A�Tab->FieldCount;
	MessageDlg("����� ����� � ������� "+IntToStr(n),mtInformation, TMsgDlgButtons() << mbOK, NULL);
	for (int i = 0; i < n; i++) {
	  //	u=AccessDataModule->A�Tab->Fields->Fields[i]->FieldName;
	   //	MessageDlg("��� ���� ����� "+IntToStr(i)+" "+u,mtInformation, TMsgDlgButtons() << mbOK, NULL);
	   //	MessageDlg("��� ���� ����� "+IntToStr(i)+" "+IntToStr(AccessDataModule->A�Tab->Fields->Fields[i]->DataType),mtInformation, TMsgDlgButtons() << mbOK, NULL);
	   //	MessageDlg("������ ���� ����� "+IntToStr(i)+" "+IntToStr(AccessDataModule->A�Tab->Fields->Fields[i]->DataSize),mtInformation, TMsgDlgButtons() << mbOK, NULL);
	   ;
	}
	AccessDataModule->A�Tab->First();
	for (int j=0; j < r; j++,AccessDataModule->A�Tab->Next()) {
		for (int i=0; i < n; i++) {
		try {
			u=AccessDataModule->A�Tab->Fields->Fields[i]->Value;
		} catch (...) {
			u="Null";
		}
			MessageDlg("�������� ���� "+u,mtInformation, TMsgDlgButtons() << mbOK, NULL);
		}
	}
}
//---------------------------------------------------------------------------

