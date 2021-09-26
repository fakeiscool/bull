//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <ctime>
#include <string>

#include "Unit1.h"
using namespace std;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tv *v;
//---------------------------------------------------------------------------
__fastcall Tv::Tv(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall Tv::Button1Click(TObject *Sender)
{   int ar[100][200];
	int arr[100*200];
	int n=StrToInt(Edit1 -> Text),m=StrToInt(Edit2 -> Text),sum;
	float mid,dispers;
	StringGrid1 -> RowCount=n;
	StringGrid1 -> ColCount=m;
	for (int i=0; i<n;i++) {
		for (int j=0; j<m;j++){
			ar[i][j] = rand()% 200+1;  // заполнение массива
			StringGrid1 -> Cells[j][i] = ar[i][j];
		}
	}


	for (int i=0; i<n;i++) {
		for (int j=0; j<m;j++){
			arr[i * m + j] = ar[i][j];
		}
	}
	sum=0;
	for (int i=0; i < (n*m); i++) {
		sum+=arr[i];
	}
	mid=sum/(n*m);
	ShowMessage(mid);
	dispers=0;
	for (int i=0; i < (n*m); i++) {
		dispers+=((arr[i]-mid)*(arr[i]-mid));
	}
	dispers=dispers/(n*m);
	ShowMessage(dispers);
}
//---------------------------------------------------------------------------
