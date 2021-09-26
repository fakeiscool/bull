// v 10.4 Морданов Егор    чтение программы
#include <vcl.h>
#pragma hdrstop
#include <ctime>
#include <string>
#include <iostream>
#include <fstream>


#include "Unit1.h"
using namespace std;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------



__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
	{
		string line;
		ifstream in("Unit1.cpp");
		if (in.is_open())
		{
			while (getline(in, line)){
			Memo1-> Lines -> Add(line.c_str());
			}
		}
	}




//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

