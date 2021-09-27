var a,b,sigma:real;

function f(x:real):real;
begin
f:=x*x-1;
end;

function rootfind(a,b:real):real;
var x1,x2:real;
begin
while (abs(b-a)/2) > sigma do	begin
  x1:=((a+b)/2)-sigma/2;
  x2:=((a+b)/2)+sigma/2;
  if f(x1) > f(x2) then   
	  a:=x1
  else
		b:=x2;
end;
rootfind:=(a+b)/2;
end;

begin
write('Введите левый интервал, a = ');readln(a);
write('Введите правый интервал, b = ');readln(b); 
write('Введите точность, sigma = ');readln(sigma);
writeln('Минимум равен, х = ', rootfind(a,b):10:10); 
writeln('Значение функции, func = ', f(rootfind(a,b)):10:10);
end.