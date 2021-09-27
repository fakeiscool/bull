unit Unit1;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, math, Vcl.StdCtrls, Vcl.Grids;

type
  TForm1 = class(TForm)
    Button1: TButton;
    StringGrid1: TStringGrid;
    procedure Button1Click(Sender: TObject);
    procedure FormCreate(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form1: TForm1;   N:integer;    h:real;

implementation

{$R *.dfm}
//истинная производная
function fa(x:real):extended;
begin
  fa:=(2*arcsin(x))/(sqrt(1-sqr(x)));
end;

function f(x:real):extended;
begin
  f:=arcsin(x)*arcsin(x);

end;

function df(a,b:real):real;
var i,g:integer;
    hi,x1,x2,y:real;
begin
  x1:=f(a);
  x2:=f(b);
  y:=(x1-x2)/h;
  df:=(x1-x2)/h;
end;


procedure TForm1.Button1Click(Sender: TObject);
var x,a,b,r:real;
  c,y,e:extended;
  i: Integer;
begin
  a:=-1/2;
  b:=1/2;
  r:=a;
  h :=(b-a)/n;
  i:=0;
  c:=a+i*h;
  e := 0.0001;
  while abs(fa(c)-df(c+h,c)) > e do
  begin
    n:=n*4;
    h :=(b-a)/n;
  end;
  StringGrid1.Rowcount:=n+1;
      if abs(fa(c)-df(c+h,c))<e then
    while r < b do
    begin
      c :=a+i*h;
      StringGrid1.Cells[0,i+1]:='X'+inttostr(i)+'   ='+floattostr(c);
      y := df(c+h,c);
      StringGrid1.Cells[1,i+1]:=floattostr(y);
      StringGrid1.Cells[2,i+1]:=floattostr(fa(c ));
      inc(i);
      r := r+h;
    end;

end;

procedure TForm1.FormCreate(Sender: TObject);
begin
  n:=10;
  StringGrid1.Rowcount:=n+1;
  StringGrid1.Cells[0,0]:='Номер Х';
  StringGrid1.Cells[1,0]:='Приближенное значение производной';
  StringGrid1.Cells[2,0]:='Точный ответ';


end;

end.
