unit Unit2;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.ExtCtrls, Vcl.Grids, Vcl.StdCtrls, UMet;

type
  TForm2 = class(TForm)
    Panel1: TPanel;
    Panel2: TPanel;
    procedure Button1Click(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form2: TForm2;

implementation

uses unit1;
{$R *.dfm}


procedure TForm2.Button1Click(Sender: TObject);
var x0, y0, dx, dy, h, w, x, y: integer;
    lx, ly: integer; dlx, dly,mx,my: integer;
begin
  {dx := 40;
  dy := 40; // шаг координатной сетки 40 пикселей
  dlx := 1; // Отметки на оси X
  dly := 1; // Отметки на по оси Y

   }

end;

end.
