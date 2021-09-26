//---------------------------------------------------------------------------

// v 10.4 Морданов Егор   Сортировка двухмерного массива путём
//                        Перевода в одномернный массива сортировки
//						  И перевода одномернного массива в двухмернный
#include <vcl.h>
#pragma hdrstop
#include <ctime>
#include <string>
#include <random>

#include "Unit1.h"
using namespace std;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------

void qs(long *s_arr, int first, int last)
{
	if (first < last)
	{
		int left = first, right = last, middle = s_arr[(left + right) / 2];
		while (left <= right)
		{
			while (s_arr[left] < middle) left++;
			while (s_arr[right] > middle) right--;
			if (left <= right)
			{
				int tmp = s_arr[left];
				s_arr[left] = s_arr[right];
				s_arr[right] = tmp;
				left++;
				right--;
			}
		}
		qs(s_arr, first, right);
		qs(s_arr, left, last);
	}
}

__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner){}

//---------------------------------------------------------------------------

int ar[1000][1000]; long arr[1000*1000];

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	int n,m,k;
	n = StrToInt(Edit1 -> Text), m = StrToInt(Edit2 -> Text);
	if (n > 1000 || m > 1000) {
		ShowMessage("У нас такие большие массивы не приняты, массив должен быть <1000");
		return;
	}

	mt19937 random(time(0));
	StringGrid1 -> RowCount=n;
	StringGrid2 -> RowCount=n;
	StringGrid1 -> ColCount=m;
	StringGrid2 -> ColCount=m;
	for (int i=0; i<n;i++) {
		for (int j=0; j<m;j++){
			ar[i][j] = random()% 99999+1;  // заполнение массива
			StringGrid1 -> Cells[j][i] = ar[i][j];
		}
	}


	for (int i=0; i<n;i++) {
		for (int j=0; j<m;j++){
			arr[i * m + j] = ar[i][j];
		}
	}   // Перевод в одномерный массив

	qs(arr,0,n*m-1); // сортировка одномерного массива

	for (int i=0; i<n;i++) {
		for (int j=0; j<m;j++){
			ar[i][j]=arr[i * m + j];
			StringGrid2 -> Cells[j][i] = ar[i][j];
		}
	}
		// Перевод в двухмерный массив




}
//---------------------------------------------------------------------------

