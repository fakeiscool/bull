uses crt;

type tree=record
  info:record // Разделение данных безполезно по итогу оказалось ведь он по первым char`ам проверяет :( но всё равно сделал 
    fio:string;
    number:string; //даже Longint не справился с номерами, string в итоге :(
    date:string;
  end;
  left:^tree;
  right:^tree;
end;

var root:^tree; f:text; nummenu:integer; st:string;

function IsDigit(c:char):boolean;
begin
  IsDigit:=c in ['0'..'9']
end;

procedure init(var root:^tree);
begin
  root:=nil;
end;

procedure add(var root:^tree;var f:text);
var t,pp,p:^tree; c:char; buff:string;
begin
    new(t);
    repeat
      buff:=buff+c;
      read(f,c);
    until IsDigit(c);
    t^.info.fio:=buff;
    buff:='';
    repeat
      buff:=buff+c;
      read(f,c);
     until c =' ';
    t^.info.number:=buff;
    read(f,t^.info.date);
    t^.left:=nil;
    t^.right:=nil;
    if root=nil then 
      root:=t
    else begin
      p:=root;
      while p<>nil do begin
        pp:=p;
        if t^.info.fio<p^.info.fio then 
          p:=p^.left
        else p:=p^.right;
        end;
        if t^.info.fio<pp^.info.fio then 
          pp^.left:=t
        else 
          pp^.right:=t;
    end;
end;

procedure preorder(p:^tree;st:string);
begin
   if p<>nil then begin
     writeln(st,p^.info.fio, ' | ', p^.info.number, ' | ', p^.info.date);
     st:=st+'  ';
     preorder(p^.left,st);
     preorder(p^.right,st);
   end;
end;

procedure menu;
begin
    writeln('1-Чтение');
    writeln('2-Вывод');
    writeln('3-Выход');
end;

procedure readfile();
begin
  reset(f); 
  while not eof(f) do
   while not eoln(f) do begin 
    add(root,f);
    readln(f)
   end;
  writeln('Чтение завершено');
  close(f);
end;

begin
    assign(f,'text.txt');
    init(root);
    repeat
        menu;
        readln(nummenu);
        clrscr;
        case nummenu of 
        1:readfile();   
        2:preorder(root,st);
        end;
    until nummenu=3;
end.