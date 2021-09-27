uses crt;
type tree=record
  info:record 
    fio:string[50];
    cathedra:string[50];
    scientistdegree:string[50];
    post:string[50];
    rating:integer; 
  end;
  left:^tree;
  right:^tree;
end;

var root:^tree; nummenu:integer; st:string; flag:boolean;

type inf = record
    fio:string[50];
    cathedra:string[50];
    scientistdegree:string[50];
    post:string[50];
    rating:integer; 
end;
var f: file of inf; 

procedure init(var root:^tree);
begin
  root:=nil;
end;

procedure output();
var text:inf;
begin
  reset(f);
  while not eof(f) do begin
    read(f,text);
    writeln(text.fio, ' | ', text.cathedra, ' | ', text.scientistdegree, ' | ', text.post, ' | ', text.rating);
  end;
  close(f);
end;

procedure create();
var text:inf;
begin
  reset(f);
  seek(f,filesize(f));
  writeln('Фио ');
  readln(text.fio);
  writeln('Кафедра ');
  readln(text.cathedra);
  writeln('Ученная степень ');
  readln(text.scientistdegree);
  writeln('Должность ');
  readln(text.post);
  writeln('Рейтинг ');
  readln(text.rating);
  write(f,text);
  close(f);
  output();
end;

procedure add(var root:^tree);
var t,pp,p:^tree; text:inf;
begin
    new(t);
    read(f,text);
    t^.info.fio:=text.fio;
    t^.info.cathedra:=text.cathedra;
    t^.info.scientistdegree:=text.scientistdegree;
    t^.info.post:=text.post;
    t^.info.rating:=text.rating;
    
    t^.left:=nil;
    t^.right:=nil;
    if root=nil then 
      root:=t
    else begin
      p:=root;
      while p<>nil do begin
        pp:=p;
        if t^.info.rating<p^.info.rating then 
          p:=p^.left
        else p:=p^.right;
        end;
        if t^.info.rating<pp^.info.rating then 
          pp^.left:=t
        else 
          pp^.right:=t;
    end;
end;

procedure preorder(p:^tree;st:string);
begin
   if p<>nil then begin
     preorder(p^.right,st);
     writeln(st,p^.info.fio, ' | ', p^.info.cathedra, ' | ', p^.info.scientistdegree, ' | ', p^.info.post, ' | ', p^.info.rating);
     preorder(p^.left,st);
   end;
end;



procedure readfile();
begin
  reset(f); 
  while not eof(f) and flag do begin
    add(root);
  end;
  flag:=false;
  close(f);
end;

procedure menu;
begin
    writeln('1-Добавление');
    writeln('2-Вывод из файла');
    writeln('3-Сортировка и вывод');
    writeln('4-Выход');
end;

begin
    assign(f,'text.dat');
    init(root);
    output();
    flag:=true;
    repeat
        menu;
        readln(nummenu);
        clrscr;
        case nummenu of 
        1:create();
        2:output();
        3:begin readfile(); preorder(root,st); end;
        end;
    until nummenu=4;
end.