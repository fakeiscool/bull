unit Unit1;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.StdCtrls, Vcl.ExtCtrls, math, UMet,
  Vcl.Buttons, Vcl.Imaging.pngimage;

type
  TForm1 = class(TForm)
    Panel1: TPanel;
    LabeledEdit1: TLabeledEdit;
    LabeledEdit2: TLabeledEdit;
    LabeledEdit4: TLabeledEdit;
    Button1: TButton;
    Panel2: TPanel;
    LabeledEdit3: TLabeledEdit;
    BitBtn1: TBitBtn;
    BitBtn3: TBitBtn;
    BitBtn4: TBitBtn;
    BitBtn2: TBitBtn;
    BitBtn5: TBitBtn;
    Panel3: TPanel;
    procedure Button1Click(Sender: TObject);
    procedure BitBtn2Click(Sender: TObject);
    procedure BitBtn3Click(Sender: TObject);
    procedure BitBtn4Click(Sender: TObject);
    procedure BitBtn5Click(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form1: TForm1;  
  
  str:string;               //?????? ? ????????

  a,b,eps:real;               //????????
  
  locker:real;    
  
  sl:Tstringlist;

  N:real;

implementation

uses unit2;

{$R *.dfm}

procedure TForm1.BitBtn2Click(Sender: TObject);
begin
LabeledEdit3.Text := 'x/(x^2+1)';
end;

procedure TForm1.BitBtn3Click(Sender: TObject);
begin
labelededit3.Text := '((3-x)^(1/2))/(3-x)';
end;

procedure TForm1.BitBtn4Click(Sender: TObject);
begin
 labelededit3.Text := 'ln(x)';
end;

procedure TForm1.BitBtn5Click(Sender: TObject);
begin
labelededit3.Text := 'cos(x)';
end;

procedure TForm1.Button1Click(Sender: TObject);
var ss:string; i:integer;   lk:string;
begin
  str:=LabeledEdit3.Text;
  a := strtofloat(labelededit1.text);
  b := strtofloat(labelededit2.Text);
  eps := strtofloat(labelededit4.Text);
  N := 0;
  if a < b  then
    begin
    //locker := method_trapezoids(head,tail,a,b,eps,N);
      locker :=  met_Simp(a,b,eps,N);
      Form2.show;
      Form2.Panel1.Caption := '?????: '+floattostr(locker);
      Form2.Panel2.Caption := '???-?? ?????: '+ floattostr(N);
    end
  else
    begin
      showmessage('a > b?');
      exit;
    end;

end;

end.
