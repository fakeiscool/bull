//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include <string>
using namespace std;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	StringGrid1 -> RowCount = StrToInt(Edit1->Text);
	StringGrid1 -> ColCount = StrToInt(Edit1->Text)*2;
	StringGrid2 -> RowCount = StrToInt(Edit1->Text);
	StringGrid2 -> ColCount = StrToInt(Edit1->Text);
	for (int i = StrToInt(Edit1->Text); i < StringGrid1 -> ColCount; i++) {
		for (int j = 0; j < StringGrid1 -> RowCount; j++) {
		   StringGrid1->Cells[i][j]=0;
		}
	}
	for (int i = StrToInt(Edit1->Text), j = 0; i < StringGrid1 -> ColCount; i++,j++) {
	  StringGrid1->Cells[i][j]=1;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
 for (int i = 0; i < StrToInt(Edit1->Text); i++) {
		for (int j = 0; j < StrToInt(Edit1->Text); j++) {
		   StringGrid1->Cells[i][j]=rand()%10+1;
		}
	}
}
//---------------------------------------------------------------------------



//---------------------------------------------------------------------------
double mas[20][20];

void calc(int n, int m){
	for (int i=0; i < n; i++) {
		double resh;
		resh=mas[i][i];
		for (int j=0; j < n; j++) {
			if (i!=j) {
				double x;
				x=mas[j][i];
				for (int k = 0; k < m; k++) {
					mas[j][k]=mas[j][k]-((mas[i][k]*x)/resh);
				}
			}
		}
		for (int k = 0; k < m; k++) {
			mas[i][k]=mas[i][k]/resh;
		}
   /*	string str;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			str += to_string(mas[i][j]) + " ";
		}
		str +="\n";
	}
	ShowMessage(str.c_str());*/
	}
}

//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
		for (int i = 0; i < StrToFloat(Edit1->Text)*2; i++) {
			for (int j = 0; j < StrToFloat(Edit1->Text); j++) {
				mas[j][i]=StrToFloat(StringGrid1->Cells[i][j]);
			}
		}

		calc(StrToInt(Edit1->Text),StrToInt(Edit1->Text)*2);

		for (int i = StrToFloat(Edit1->Text); i < StrToFloat(Edit1->Text)*2; i++) {
			for (int j = 0; j < StrToFloat(Edit1->Text); j++) {
			   StringGrid2->Cells[i-StrToFloat(Edit1->Text)][j]=mas[j][i];
			}
		}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
	int n=StrToFloat(Edit1->Text);
	double ar1[20][20],ar2[20][20],ar3[20][20];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
		  ar1[j][i]=StrToFloat(StringGrid1->Cells[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
		  ar2[j][i]=StrToFloat(StringGrid2->Cells[i][j]);
		}
	}

	for (int i=0; i < n; i++) {
		for (int j=0; j < n; j++) {
			double sum=0;
			for (int k=0; k < n; k++) {
				sum+=ar1[i][k]*ar2[k][j];
			}
			ar3[i][j]=sum;
		}

	}

	string str;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			str += to_string(ar3[i][j]) + " ";
		}
		str +="\n";
	}
	ShowMessage(str.c_str());


}
//---------------------------------------------------------------------------

