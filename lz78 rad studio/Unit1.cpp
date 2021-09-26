//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>


#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
using namespace std;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TForm1 *Form1;
struct node {
	int pos;
	wchar_t next;
};

bool bettercompression(false),darktheme(false),limitdictionary(false);


vector<node> lz78(wstring s, int sz = 0) {
    vector<node>ans;    // закодированная строка
    int i = 0;
    while(i < s.size()) {
		wstring buffer;
        map<wstring, int>m; // используется для создания пар
        for (; i < s.size(); ++i) {
            if (m.count(buffer + s[i])) // m.count смотрит по первому параметру и возвращает 1
                buffer += s[i];         // если эта строка есть и 0 если её нет
            else {
                ans.push_back({ m[buffer],s[i] }); // добавляет в ans буффер + след символ
				m[buffer + s[i]] = m.size();       // распределяет "номера" в таблице
                buffer.clear();                    // очищает буффер
                if (sz > 0 && sz == m.size()) {
                    ++i;
                    break;
                }
            }
        }
        if (!buffer.empty()) { // если в буфере остались буквы после того как обработали всю строку
			wchar_t l = buffer.back(); // берем посл. букву и кладём её в вектор ans
            buffer.pop_back();
            ans.push_back({ m[buffer], l });
		}
        if (sz > 0 && sz == m.size())
            ans.push_back({7, 7});
    }
	return ans;
}

wstring decode(vector<node> enc) {
	wstring ans;         // декодируемая строка
	int i = 0;
	while(i < enc.size()) {
		vector<wstring>v(1); // создает на 0 позиции пустой элемент чтобы не сдох вектор при его самой первой иницилизации
		for (; i < enc.size(); i++) {
			if (enc[i].pos == 7 && enc[i].next == 7)
				break;
			wstring word = v[enc[i].pos] + enc[i].next; // обращается по позиции + добавляет символ (поэтому и нужен 0 позиции с пустым элементом чтобы он добавил ""+"a"
			ans += word; // декодируемая строка
			v.push_back(word);	//создает "словарь" по ходу действия
			Form3->StringGrid1 -> Cells[i][0] = v.size()-1;
			Form3->StringGrid1 -> Cells[i][1] = v.back().c_str();
		}
		++i;
	}
	return ans;
}
//------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

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


void __fastcall TForm1::Button1Click(TObject *Sender)
{
	int limit = numconvert(AnsiString(Edit1 -> Text).c_str())+1;
	if (limit > 0)
		limitdictionary = true;
	else
		limitdictionary = false;

	for (int i=0; i < 3; i++) {
		StringGrid1 -> Cols[i]->Clear();
		StringGrid1 -> Rows[i]->Clear();
	}

	int counter;
	wstring memobuffer;
	counter=0;
	Memo2 -> Text="";
	vector <node> ans = lz78(Memo1 -> Text.c_str(), limit);
	string val;
	wstring wval;
	for (int i=0;i < ans.size(); i++)
	{
		StringGrid1 -> Cells[0][counter] = i+1;
		StringGrid1 -> Cells[1][counter] = ans[i].pos;
		StringGrid1 -> Cells[2][counter] = ans[i].next;

		if (bettercompression){
			memobuffer+=wchar_t(ans[i].pos+1);// 0 для строки в c++ считается концом ввода поэтому +1
			memobuffer+=ans[i].next;          // так же кодируем цифры наподобие 13 в один символ для еще большего сжатия
		}
		else{
			val = to_string(ans[i].pos);
			wval = wstring(val.begin(),val.end());
			memobuffer += wval;
			memobuffer +=L" ";
			memobuffer +=ans[i].next;
		}
		counter++;
	}
	Memo2 -> Text=memobuffer.c_str();
	decode(ans);


}


//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{

	if (bettercompression) {
		wstring s = Memo2 -> Text.c_str(); // берем закодированную строку из 2 панели
		vector<node>a; // создаем массив для декодирования
		for (int i = 0; i < s.size(); i += 2) // заполняем массив
			a.push_back({ s[i]-1, s[i + 1] }); // -1 для того чтобы исправить костыль с 0 в строке c++ берем символ позиции и следующим символ строки

		Memo3 -> Text =decode(a).c_str(); // выводим декодированную строку на 3 панель
	}
	else {
		wstring s = Memo2 -> Text.c_str();
		vector<node>a;
		int i = 0;
		while (i < s.size()) {
			int cv = 0;
			while(i < s.size() && s[i] >= L'0' && s[i] <= L'9')
				cv *= 10, cv += s[i] - L'0', ++i;
			++i;
			a.push_back({ cv, s[i] });
			++i;
		}

		Memo3 -> Text =decode(a).c_str();
	}

}
//---------------------------------------------------------------------------



void __fastcall TForm1::Debug1Click(TObject *Sender)
{
	Form3->Visible = true;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::N1Click(TObject *Sender)
{

	Button1->Visible = true;
	Button2->Visible = false;
	Label1->Visible = true;
	Label2->Visible = true;
	Label3->Visible = false;
	Label4->Visible = true;
	Label5->Visible = true;
	Label6->Visible = true;
	Label7->Visible = true;
	Memo1->Visible = true;
	Memo2->Visible = true;
	Memo3->Visible = false;
	StringGrid1->Visible = true;
	Button2->Top = 259;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::N2Click(TObject *Sender)
{

	Button1->Visible = false;
	Button2->Visible = true;
	Label1->Visible = false;
	Label2->Visible = true;
	Label3->Visible = true;
	Label4->Visible = false;
	Label5->Visible = false;
	Label6->Visible = false;
	Label7->Visible = false;
	Memo1->Visible = false;
	Memo2->Visible = true;
	Memo3->Visible = true;
	StringGrid1->Visible = false;
	Button2->Top = 259;

	if (Button2->Visible and bettercompression) {
	   wstring s = Memo2 -> Text.c_str();
	   Label10->Caption=s.size()*2;
	}
	if (Button2->Visible and !bettercompression) {
	   wstring s = Memo2 -> Text.c_str();
	   int i=0,j = 0;
	   while (i <s.size())  {
			int cv = 0;
			while(i < s.size() && s[i] >= L'0' && s[i] <= L'9')
				cv *= 10, cv += s[i] - L'0', ++i;
			++i;
			++i;
			j++;
	   }
	   Label10->Caption=j;
	}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::N3Click(TObject *Sender)
{
	Form2->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N4Click(TObject *Sender)
{
	if  (bettercompression)
		{bettercompression = false;
		N4->Caption="Более лучшее сжатие(Вкл)";}
	else{
		bettercompression = true;
		N4->Caption="Более лучшее сжатие(Выкл)";}
		//
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------


void __fastcall TForm1::N6Click(TObject *Sender)
{
  if  (darktheme)
		{darktheme = false;
		N6->Caption="Темная тема(Вкл)";
		Form1->Color=clWhite;
		Label1->Font->Color=clBlack;
		Label2->Font->Color=clBlack;
		Label3->Font->Color=clBlack;
		Label4->Font->Color=clBlack;
		Label5->Font->Color=clBlack;
		Label6->Font->Color=clBlack;
		Label7->Font->Color=clBlack;
		Label8->Font->Color=clBlack;}
	else{
		darktheme = true;
		N6->Caption="Темная тема(Выкл)";
		Form1->Color=cl3DDkShadow;
		Label1->Font->Color=clWhite;
		Label2->Font->Color=clWhite;
		Label3->Font->Color=clWhite;
		Label4->Font->Color=clWhite;
		Label5->Font->Color=clWhite;
		Label6->Font->Color=clWhite;
		Label7->Font->Color=clWhite;
		Label8->Font->Color=clWhite;}
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
	 if (Button1->Visible) {
		int limit = numconvert(AnsiString(Edit1 -> Text).c_str());
		if (limit > 0)
			limitdictionary = true;
		else
			limitdictionary = false;

		for (int i=0; i < 3; i++) {
			StringGrid1 -> Cols[i]->Clear();
			StringGrid1 -> Rows[i]->Clear();
		}
		int step = numconvert(AnsiString(Edit2 -> Text).c_str());
		int counter;
		wstring memobuffer;
		counter=0;
		Memo2 -> Text="";
		vector <node> ans = lz78(Memo1 -> Text.c_str(), limit);
		string val;
		wstring wval;
		if (step<=ans.size()) {
			for (int i=0;i < step; i++)
			{
				StringGrid1 -> Cells[0][counter] = i+1;
				StringGrid1 -> Cells[1][counter] = ans[i].pos;
				StringGrid1 -> Cells[2][counter] = ans[i].next;
				if (bettercompression){
					memobuffer+=wchar_t(ans[i].pos+1);// 0 для строки в c++ считается концом ввода поэтому +1
					memobuffer+=ans[i].next;          // так же кодируем цифры наподобие 13 в один символ для еще большего сжатия
				}
				else{
					val = to_string(ans[i].pos);
					wval = wstring(val.begin(),val.end());
					memobuffer += wval;
					memobuffer +=L" ";
					memobuffer +=ans[i].next;
				}
				counter++;
			}
			Memo2 -> Text=memobuffer.c_str();
		}
		else{ShowMessage("Количество шагов указано больше чем их может быть");}

	 }
	 /////////////////
	 if (Button2->Visible) {
		if (bettercompression) {
			int step = numconvert(AnsiString(Edit2 -> Text).c_str())*2;
			wstring s = Memo2 -> Text.c_str(); // берем закодированную строку из 2 панели
			vector<node>a; // создаем массив для декодирования

			for (int i = 0; i < min(step,(int)s.size()); i += 2) // заполняем массив
				a.push_back({ s[i]-1, s[i + 1] }); // -1 для того чтобы исправить костыль с 0 в строке c++ берем символ позиции и следующим символ строки

			Memo3 -> Text =decode(a).c_str(); // выводим декодированную строку на 3 панель



		}
		else {
			wstring s = Memo2 -> Text.c_str();
			vector<node>a;
			int i=0,j = 0;
			int step = numconvert(AnsiString(Edit2 -> Text).c_str());
			while (i <s.size() and j<step)  {
				int cv = 0;
				while(i < s.size() && s[i] >= L'0' && s[i] <= L'9')
					cv *= 10, cv += s[i] - L'0', ++i;
				++i;
				a.push_back({ cv, s[i] });
				++i;
				j++;
			}

			Memo3 -> Text =decode(a).c_str();
		}


     }


}
//---------------------------------------------------------------------------

void __fastcall TForm1::Memo1Change(TObject *Sender)
{
	if (Button1->Visible) {
		vector <node> ans = lz78(Memo1 -> Text.c_str());
		Label10->Caption=ans.size();
	}
	wstring ss = Memo1 -> Text.c_str();
	Label13->Caption=ss.size();

	if (Label13->Caption != 0 and Label14->Caption != 0) {
	   Label16->Caption=Label13->Caption/Label14->Caption;
	}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Memo2Change(TObject *Sender)
{
	if (Button2->Visible and bettercompression) {
	   wstring s = Memo2 -> Text.c_str();
	   Label10->Caption=s.size()*2;
	}
	if (Button2->Visible and !bettercompression) {
	   wstring s = Memo2 -> Text.c_str();
	   int i=0,j = 0;
	   while (i <s.size())  {
			int cv = 0;
			while(i < s.size() && s[i] >= L'0' && s[i] <= L'9')
				cv *= 10, cv += s[i] - L'0', ++i;
			++i;
			++i;
			j++;
	   }
	   Label10->Caption=j;
	}

	wstring ss = Memo2 -> Text.c_str();
	Label14->Caption=ss.size();
	if (Label13->Caption != 0 and Label14->Caption != 0) {
	   Label16->Caption=Label13->Caption/Label14->Caption;
	}
}
//---------------------------------------------------------------------------

AnsiString getfilename(AnsiString filename){
	AnsiString nm;
	Form1->OpenDialog1 -> Title = filename;
	if (!Form1->OpenDialog1->Execute()) {
		ShowMessage("Не указан файл");
		return "";
	}
	nm = Form1->OpenDialog1 -> FileName;
	return nm;
}

void __fastcall TForm1::N7Click(TObject *Sender)
{
	AnsiString nfm;
	nfm = getfilename("Укажите файл с SQL - утверждением");
	if (nfm == "") return;
	string line;
	ifstream in(nfm.c_str());
	if (in.is_open())
	{
		while (getline(in, line)){
		Memo1-> Lines -> Add(line.c_str());
		}
	}
}
//---------------------------------------------------------------------------

