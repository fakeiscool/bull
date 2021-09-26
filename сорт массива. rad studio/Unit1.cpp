//---------------------------------------------------------------------------

// v 10.4 Морданов Егор
#include <vcl.h>
#pragma hdrstop
#include <ctime>
#include <string>

#include "Unit1.h"
using namespace std;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------

void qs(int *s_arr, int first, int last)
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
	: TForm(Owner){
	int ar[10000];
	int min;
	srand(time(0));
	for (int i=0; i<10000;i++) {
		ar[i] = rand()% 10000+1;
		StringGrid1 -> Cells[0][i] = ar[i];
		StringGrid1 -> RowCount=i;
	}
	min=ar[0];
	for (int i=0; i<10000;i++) {
		if (min>ar[i]) {
			min = ar[i];
		}
	}
	qs(ar,0,9999);
	for (int i=0; i<10000;i++) {
		StringGrid2 -> Cells[0][i] = ar[i];
		StringGrid2 -> RowCount=i;
	}
   /*	string str;
	for (int i = 0; i < 10000; ++i) {
		str += to_string(ar[i]) + " ";
	}
	ShowMessage(str.c_str());*/
	//ShowMessage(min);
	Edit1->Text = min;
	}




//---------------------------------------------------------------------------
