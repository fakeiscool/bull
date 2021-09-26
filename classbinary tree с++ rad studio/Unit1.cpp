//---------------------------------------------------------------------------
/* Бинарное дерево поиск Binary Search Tree
   Морданов Егор */
#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "tree.h"
#include <random>
#include <ctime>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
using namespace std;
TForm1 *Form1;

int numconvert(string s) {
    int ans = 0;
	for (int i = 0; i < s.size(); ++i) {
        if (s[i] >= '0' && s[i] <= '9') {
            ans *= 10;
			ans += s[i] - '0';
		}
		else
			return 0;
	}
	return ans;
}
binarytree *tree = nullptr;
void showtrees();
//---------------------------------------------------------------------------


__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	if (tree == nullptr)
		tree= new binarytree(numconvert(AnsiString(Edit1 -> Text).c_str()));
	else
		tree->add(numconvert(AnsiString(Edit1 -> Text).c_str()));
	showtrees();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	bool check = tree->search(numconvert(AnsiString(Edit1 -> Text).c_str()));
	if (check)
		ShowMessage("Число существует в дереве");
	else
		ShowMessage("Число отсутствует в дереве");
}
//---------------------------------------------------------------------------


void showtrees(){
	vector<vector<int>>ar = tree->showtree();

	Form1->StringGrid1 -> ColCount = ar[0].size();
	Form1->StringGrid1 -> RowCount = ar.size();


	for (int i=0; i < ar[0].size(); i++) {
		Form1->StringGrid1 -> Rows[i]->Clear();
	}

	for (int i=0; i < min(int(ar.size()), 999); i++) {  // при очень большом дереве
		for (int j=0; j < min(int(ar[0].size()), 999); j++){  //stringgrid не выдерживает
			if (ar[i][j]!=0x3f3f3f3f)                        //за то красивое отображение
				Form1->StringGrid1 -> Cells[j][i] = ar[i][j];
		}
	}

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
	delete tree;

	Form1->StringGrid1 -> ColCount = 0;
	Form1->StringGrid1 -> RowCount = 0;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
	mt19937 r(time(0));
    delete tree;
	tree = new binarytree(r() % 50+25);
	for (int i = 0; i < 8; ++i)
		tree->add(r() % 100);
	showtrees();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{
	tree->deleteNode(numconvert(AnsiString(Edit1 -> Text).c_str()));
	showtrees();
}
//---------------------------------------------------------------------------
