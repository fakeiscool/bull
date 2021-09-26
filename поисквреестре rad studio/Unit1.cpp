//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include <string>
#include <windows.h>
#include <iostream>



#define TCHAR char
#define BUFF_SIZE 1600
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

using namespace std;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
int counter;

void searchKeys(HKEY rootKey, string subKeyPath, string searchedName) {
	HKEY subKey;
	DWORD subKeyCount, buffSize;
	char subKeyBuff[BUFF_SIZE] = {};

	const char* subKeyName;
	subKeyName = subKeyPath.c_str();


	DWORD output = RegOpenKeyExA(rootKey, subKeyName, NULL, KEY_ALL_ACCESS, &subKey);
	if (output != ERROR_SUCCESS) return;

	RegQueryInfoKeyA(subKey, NULL, NULL, NULL, &subKeyCount, NULL, NULL, NULL, NULL, NULL, NULL, NULL);

	for (DWORD i = 0; i < subKeyCount; i++) {
		buffSize = sizeof(subKeyBuff);
		RegEnumKeyExA(subKey, i, subKeyBuff, &buffSize, NULL, NULL, NULL, NULL);

		string keyName = subKeyPath;
		int p = 0;
		while(subKeyBuff[p] != 0)
			keyName+=subKeyBuff[p++];
		keyName += "\\";
		string key(subKeyBuff);
		DWORD paramfind = RegGetValueA(rootKey, keyName.c_str(), searchedName.c_str(), RRF_RT_ANY, NULL, NULL, NULL);
		if (paramfind == ERROR_SUCCESS)
		{
			string strr = keyName + searchedName;
			Form1->StringGrid1->Cells[0][counter++]=strr.c_str();
		}
		if (key.find(searchedName) != -1) {
			Form1->StringGrid1->Cells[0][counter++]=keyName.c_str();
		}
		p = 0;
		while(subKeyBuff[p] != 0)
			subKeyBuff[p] = 0, p++;
		RegOpenKeyExA(rootKey, subKeyName, NULL, KEY_ALL_ACCESS, &subKey);
		RegQueryInfoKeyA(subKey, NULL, NULL, NULL, &subKeyCount, NULL, NULL, NULL, NULL, NULL, NULL, NULL); //get subKeyCount

		if (subKeyCount)
			searchKeys(rootKey, keyName, searchedName);
	}
}

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	Form1->StringGrid1 -> Cols[0]->Clear();
	HKEY rootKey= HKEY_CLASSES_ROOT;
	int keyMenu;
	string searchedName;

	switch (RadioGroup1->ItemIndex){
		case 0:rootKey = HKEY_CLASSES_ROOT;
			break;
		case 1:rootKey = HKEY_CURRENT_USER;
			break;
		case 2:rootKey = HKEY_LOCAL_MACHINE;
			break;
		case 3:rootKey = HKEY_USERS;
			break;
		case 4:rootKey = HKEY_CURRENT_CONFIG;
			break;
	}
	wstring pog = Edit1->Text.c_str();
	searchedName = string(pog.begin(),pog.end());
	string subKeyPath = "";
	counter=0;
	searchKeys(rootKey, subKeyPath, searchedName);
}
//---------------------------------------------------------------------------

