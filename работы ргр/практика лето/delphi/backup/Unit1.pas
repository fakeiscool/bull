unit Unit1;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, Buttons, Grids;

type
  TForm1 = class(TForm)
    edt1: TEdit;
    edt2: TEdit;
    edt3: TEdit;
    btn1: TBitBtn;
    a: TLabel;
    lbl1: TLabel;
    Label1: TLabel;
    edt4: TEdit;
    Label2: TLabel;
    edt5: TEdit;
    lbl2: TLabel;
    lbl3: TLabel;
    strngrd1: TStringGrid;
    lbl4: TLabel;
    procedure btn1Click(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form1: TForm1;

implementation

{$R *.dfm}


procedure TForm1.btn1Click(Sender: TObject);
var a,b:real;

function roundto(x:real):real;
begin
  roundto:=round(x*10000000000)/10000000000;
end;

/////////////////////////////////////////////
function f(x:real):real;
begin
f:=x*x-1;
end;
/////////////////////////////////////////////
function rootfind(a,b:real):real;
var x1,x2,e:real; i:integer;
begin
  e:=strtofloat(edt3.text);
  i:=0;
  x1:=((a+b)/2)-e/2;
  x2:=((a+b)/2)+e/2;
  strngrd1.Cells[0,0]:='0';
  strngrd1.Cells[1,0]:=FloatToStr(roundto(a));
  strngrd1.Cells[2,0]:=FloatToStr(roundto(b));
  strngrd1.Cells[3,0]:=FloatToStr(roundto(x1));
  strngrd1.Cells[4,0]:=FloatToStr(roundto(x2));
  strngrd1.Cells[5,0]:=FloatToStr(roundto(f(x1)));
  strngrd1.Cells[6,0]:=FloatToStr(roundto(f(x2)));
  if (Abs((b-a)/2) < e) then
       strngrd1.Cells[7,i]:='Да'
    else
       strngrd1.Cells[7,i]:='Нет';
  strngrd1.Cells[8,i]:=FloatToStr(roundto(Abs((b-a)/2)));

while (abs((b-a)/2) > e) do	begin
  inc(i);
  x1:=((a+b)/2)-e/2;
  x2:=((a+b)/2)+e/2;
  if f(x1) > f(x2) then
	  a:=x1
  else
		b:=x2;
  strngrd1.Cells[0,i]:=IntToStr(i);
  strngrd1.Cells[1,i]:=FloatToStr(roundto(a));
  strngrd1.Cells[2,i]:=FloatToStr(roundto(b));
  strngrd1.Cells[3,i]:=FloatToStr(roundto(x1));
  strngrd1.Cells[4,i]:=FloatToStr(roundto(x2));
  strngrd1.Cells[5,i]:=FloatToStr(roundto(f(x1)));
  strngrd1.Cells[6,i]:=FloatToStr(roundto(f(x2)));
    if (Abs((b-a)/2) < e) then
     strngrd1.Cells[7,i]:='Да'
  else
     strngrd1.Cells[7,i]:='Нет';
  strngrd1.Cells[8,i]:=FloatToStr(roundto(Abs((b-a)/2)));
  strngrd1.RowCount:=i+1;
end;
rootfind:=(a+b)/2;
end;
//////////////////////////////////////////////
begin
  a:=strtofloat(edt1.text);
  b:=strtofloat(edt2.text);
  edt4.text:='';
  edt5.text:='';
  if a > b then
    edt4.text:='Введите корректный интервал a<b'
  else if (edt3.text[2]='.' ) then
    edt4.text:='Точность нужно вводить через запятую'
  else if (strtofloat(edt3.text) > 1) then
    edt4.text:='Введите корректную точность e < 1'
  else begin
  edt4.text:=floattostr(rootfind(a,b));
  edt5.text:=floattostr(f(rootfind(a,b)));
  end;
end;

end.
