//---------------------------------------------------------------------------
//     программка работы с Access
//       27.10.2020   Г.Н. Гатин
#include <vcl.h>
#include <stdio.h>
#pragma hdrstop

#include "AccessWork.h"
#include "AccessDataModuleForm.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

FILE * ASQL;  //  фалй для считывания SQL

char buf[12000];   //   массив для ввода строки
int lbuf = 12000;   //   длина этого массива

//     функция фозвращает имя файла
//      функция открывает файл
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


		 AccessDataModule -> AсTab -> Open();


		 MessageDlg("Соединились с базой данных",
		     mtInformation, TMsgDlgButtons() << mbOK, NULL);

}
//---------------------------------------------------------------------------

void __fastcall TAccessWorkForm::N3Click(TObject *Sender)
{
	AnsiString str;
	str = TableList->Items->Strings[TableList->ItemIndex];

	AccessDataModule->AсTab->Active = false;

	AccessDataModule->AсTab->TableName = str;

    AccessDataModule->AсTab->Active = true;
}
//---------------------------------------------------------------------------
//     обработка пункта меню "Выполнить SQL"
void __fastcall TAccessWorkForm::SQL2Click(TObject *Sender)
{
AnsiString nfm;
AnsiString sqltext = "select * from ";
AnsiString tbl = "prepod";
AnsiString sql;

//		 nfm = mygetFileName("Укажите файд с SQL - утверждениями.");
		 if (nfm == "") return;
		 ASQL = fopen(nfm.c_str(), "r");
		 while (!feof(ASQL)) {

			 }




int n;   //   число записей в табличке
		 sql = sqltext + tbl;
try {
		 n = AccessDataModule -> QueryWorkHow(AccessDataModule ->pQf, sql);
		 MessageDlg("Число записей в табличке " + IntToStr(n),
			mtInformation, TMsgDlgButtons() << mbOK, NULL);
} catch (...) {
		 MessageDlg("Оишибка при выполнении SQL",
			mtError, TMsgDlgButtons() << mbOK, NULL);
}
}
//---------------------------------------------------------------------------
//      функция открывает файл
bool openMyFile(FILE * af, AnsiString tit)
{
AnsiString nm;
		 AccessWorkForm -> OpDi -> Title = tit;
		 if (!AccessWorkForm -> OpDi -> Execute()) {
				   MessageDlg("Не введено имя файла.",
					   mtError, TMsgDlgButtons() << mbOK, NULL);
				   return false;
			 }
		 nm = AccessWorkForm -> OpDi -> FileName;
		 ASQL = NULL;
		 ASQL = fopen (nm.c_str(),"r");
		 if (ASQL == NULL) {
		   MessageDlg("Не удалось открыть файл \"" + nm + "\"",
					   mtError, TMsgDlgButtons() << mbOK, NULL);
		   return false;
		 }
		 return true;
}
//    обработка пункта меню "Выполнить SQL - exec"
void __fastcall TAccessWorkForm::SQLexec1Click(TObject *Sender)
{
AnsiString u;
AnsiString sql;
int i;
		 if (!openMyFile(ASQL, "Укажите файд с SQL - утверждениями.")) return;
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
		 MessageDlg("Выполнили SQL = exec ",
			mtInformation, TMsgDlgButtons() << mbOK, NULL);
//} catch (...) {
//		 MessageDlg("Оишибка при выполнении SQL",
//			mtError, TMsgDlgButtons() << mbOK, NULL);
//}

}
//---------------------------------------------------------------------------
// обработка пункта меню структура таблицы
void __fastcall TAccessWorkForm::N5Click(TObject *Sender)
{
AnsiString tblname,u;
int n,r;
	if (!AccessDataModule->AccessConnect->Connected) {
		MessageDlg("Ошибка при выполнении SQL",
		mtError, TMsgDlgButtons() << mbOK, NULL);
		return;
	}
	AccessDataModule->AсTab->Open();
	tblname = AccessDataModule->AсTab->TableName;
	MessageDlg("Имя таблицы "+tblname,mtInformation, TMsgDlgButtons() << mbOK, NULL);
	r = AccessDataModule->AсTab->RecordCount;
	MessageDlg("Число записей таблицы "+IntToStr(r),mtInformation, TMsgDlgButtons() << mbOK, NULL);
	n = AccessDataModule->AсTab->FieldCount;
	MessageDlg("Число полей в таблице "+IntToStr(n),mtInformation, TMsgDlgButtons() << mbOK, NULL);
	for (int i = 0; i < n; i++) {
	  //	u=AccessDataModule->AсTab->Fields->Fields[i]->FieldName;
	   //	MessageDlg("Имя поля номер "+IntToStr(i)+" "+u,mtInformation, TMsgDlgButtons() << mbOK, NULL);
	   //	MessageDlg("Тип поля номер "+IntToStr(i)+" "+IntToStr(AccessDataModule->AсTab->Fields->Fields[i]->DataType),mtInformation, TMsgDlgButtons() << mbOK, NULL);
	   //	MessageDlg("Размер поля номер "+IntToStr(i)+" "+IntToStr(AccessDataModule->AсTab->Fields->Fields[i]->DataSize),mtInformation, TMsgDlgButtons() << mbOK, NULL);
	   ;
	}
	AccessDataModule->AсTab->First();
	for (int j=0; j < r; j++,AccessDataModule->AсTab->Next()) {
		for (int i=0; i < n; i++) {
		try {
			u=AccessDataModule->AсTab->Fields->Fields[i]->Value;
		} catch (...) {
			u="Null";
		}
			MessageDlg("Значение поле "+u,mtInformation, TMsgDlgButtons() << mbOK, NULL);
		}
	}
}
//---------------------------------------------------------------------------

