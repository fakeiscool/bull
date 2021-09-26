unit Unit1;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, Grids, StdCtrls;

type
  TForm1 = class(TForm)
    Edit1: TEdit;
    Button1: TButton;
    StringGrid1: TStringGrid;
    Edit2: TEdit;
    Label1: TLabel;
    Label2: TLabel;
    Label3: TLabel;
    Label4: TLabel;
    Label5: TLabel;
    procedure Button1Click(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form1: TForm1;

implementation

{$R *.dfm}
var s:string;
    x,i,sum:integer;
    entropy,a:real;
    abc: array [0..255] of integer;
procedure TForm1.Button1Click(Sender: TObject);
begin
  for x:=1 to 255 do abc[x]:=0;
  StringGrid1.RowCount:=0;
  s:=Edit1.Text;
  for x:=1 to length(s) do begin
    if ((s[x]>='а') and (s[x]<='я')) then
      abc[ord(s[x])]:=abc[ord(s[x])]+1;
  end;
  i:=0;
  sum:=0;
  for x:=30 to 255 do if abc[x]>0 then begin
    StringGrid1.RowCount:=i;
    StringGrid1.Cells[0,i]:= chr(x);
    StringGrid1.Cells[1,i]:= IntToStr(abc[x]);
    sum:=sum+StrToInt(StringGrid1.Cells[1,i]);
    inc(i);
  end;
  StringGrid1.RowCount:=i+1;
  StringGrid1.Cells[0,i]:= 'Кол-во';
  StringGrid1.Cells[1,i]:= IntToStr(sum);
  for i:=0 to StringGrid1.RowCount-2 do  begin
    a:=StrToFloat(StringGrid1.Cells[1,i])/StrToFloat(StringGrid1.Cells[1,StringGrid1.RowCount-1]);
    StringGrid1.Cells[2,i]:=FloatToStr(a);
  end;
  for i:=0 to StringGrid1.RowCount-2 do  begin
    entropy:=entropy+(StrToFloat(StringGrid1.Cells[2,i])*(ln(StrToFloat(StringGrid1.Cells[2,i]))/ln(2)));
    Edit2.Text:=FloatToStr(abs(entropy));
  end;


end;

end.
