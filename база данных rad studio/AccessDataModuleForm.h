//---------------------------------------------------------------------------

#ifndef AccessDataModuleFormH
#define AccessDataModuleFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
//---------------------------------------------------------------------------
class TAccessDataModule : public TDataModule
{
__published:	// IDE-managed Components
	TADOConnection *AccessConnect;
	TADOTable *AсTab;
	TDataSource *DaS;
	TADOQuery *pQf;
private:	// User declarations
public:		// User declarations
//  программка выполн€юща€ запрос к базе и возвращающа€ только один параметр
		 AnsiString __fastcall QueryWorkOne(TADOQuery * pQ, AnsiString s);
//  программка выполн€юща€ запрос к базе и возвращающа€ число полученных записей
		 int __fastcall QueryWorkHow(TADOQuery * pQ, AnsiString s);
//  программка выполн€юща€ запрос к базе типа Update, Delete.
		 void __fastcall QueryExecHow(TADOQuery * pQ, AnsiString s);

	__fastcall TAccessDataModule(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TAccessDataModule *AccessDataModule;
//---------------------------------------------------------------------------
#endif
