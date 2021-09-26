//---------------------------------------------------------------------------

#include <vcl.h>  // Морданов Егор 10.4 Расстояние Левенштейна
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------


#include <stdio.h>

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
   int n,m;
   int d[50][50];
   UnicodeString edittext1 = Edit1 -> Text;
   UnicodeString edittext2 = Edit2 -> Text;    		 // преобразования нужные,
   string s1 = (AnsiString(edittext1).c_str()); // чтобы нормально перевести
   string s2 = (AnsiString(edittext2).c_str()); // текст из TEdit
   n = s1.length();
   m = s2.length();

   d[0][0]=0;
   for (int j = 1; j <= n; j++) {
		d[0][j]=d[0][j-1]+1;
   }
   for (int i = 1; i <= m; i++) {
		d[i][0]=d[i-1][0]+1;
		for (int j=1; j <= n; j++) {
			if (s1[i]!=s2[j]) {
				d[i][j]=min({
					d[i-1][j]+1,  //удаление
					d[i][j-1]+1,  //вставка
					d[i-1][j-1]+1 //перестановка
				}
				);
			}
			else
			d[i][j]=d[i-1][j-1];
		}
   }


   Label1 -> Caption = d[m][n];

}
//---------------------------------------------------------------------------
