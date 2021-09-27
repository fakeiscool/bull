unit UMet;

interface

  uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.StdCtrls, Vcl.ExtCtrls, math;


  function method_trapezoids(a1,b1,e:real; var u:real):real;
  function met_Simp(a1,b1,e:real; var u:real):real;


implementation

function f(x:real):real;
begin
  f:=sqrt(3-x)/(3-x);
end;

function MT(a1,b1,n:real):real;
var i:integer; high,s:extended;
begin
  high := (b1 - a1)/n;                //Высота трапеции
  i:=1;
  s := 0;

  while i <= n-1 do
   begin
     S := S + f((a1+high*i));
     inc(i);
   end;

   S := high*((f(a1) + f(b1))/2+S);

  result:=s;

end;

function method_trapezoids(a1,b1,e:real; var u:real):real;       //Метод трапеций
var x,           //Оператор функции
    high,       //Высота трапеции
    n1,n2,          //Кол-во шагов(трапеций)
    j:real;

    i:integer;
    S1,s2:real;

begin
  n1 := 5;
  n2 := 10;
  S1:=0; s2:=0;
  repeat
    s1 := Mt(a1,b1,n1);
    s2 := MT(a1,b1,n2);
    n1 := n2;
    n2 := n2*2;
  until abs(s1-s2) < e;
  result := s2;                                 //Результат метода трапеций
  u :=n2;

end;

function simp(a1,b1,n:real):real;
var i:integer; high,s,s1,s2:extended;
begin
  high := (b1 - a1)/(n);                //Высота трапеции
  i:=1;
  s := 0;
  s1:=0;
  s2:=0;

   while i <= n-1 do
   begin
      if i mod 2 = 0 then
        S1 := S1 + f((a1+high*i))
      else
        s2 := s2 + f((a1+high*i));
     inc(i);
   end;

   S := (high/3)*(f(a1) + f(b1) + 4*S2 + 2*s1);

  result:=s;
end;

function met_Simp(a1,b1,e:real; var u:real):real;
var x,           //Оператор функции
    high,       //Высота трапеции
    n1,n2,          //Кол-во шагов(трапеций)
    j:real;

    i:integer;
    S1,s2:real;
begin
  n1 := 4;
  n2 := 8;
  S1:=0;
  s2:=0;
  repeat
    s1 := simp(a1,b1,n1);
    s2 := simp(a1,b1,n2);
    n1 := n2;
    n2 := n2*2;
  until abs(s1-s2) < e;
  result := s2;                                 //Результат метода трапеций
  u :=n2;
end;

end.
