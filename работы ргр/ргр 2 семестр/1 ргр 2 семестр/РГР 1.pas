uses module,crt;

procedure create (var cur:uk);
begin
  new(cur);
  write('Фио ');
  readln(cur^.fio);
  write('Место прибытия ');
  readln(cur^.placeofarrival);
  write('Дата отбытия ');
  readln(cur^.departuredate);
  write('Номер рейса ');
  readln(cur^.flightnum);
end;

procedure add(var start,cur:uk);
begin
  if start <> nil then begin
   cur^.next:=start;
   start:=cur;
  end;
  if start = nil then begin
   start:=cur;
   start^.next:=nil
  end;
  end;
  
procedure printtofile(var beg:uk; t: file of f);
var p:uk;
begin
 p:=beg;
 assign(t, 'output.txt');
 rewrite(t);
 while (p<>nil) do begin
 fil.fio:=p^.fio;
 fil.flightnum:=p^.flightnum;
 fil.departuredate:=p^.departuredate;
 fil.placeofarrival:=p^.placeofarrival;
 write(t,fil);
 p:=p^.next;
 end;
 close(t);
end;

procedure readfromfile(var t: file of f;cur:uk);
var a,b,c:string;i:integer;
begin
 assign(t, 'output.txt');
 reset(t);
 while not eof(t) do begin
   read(t,fil);
   a:=fil.fio;
   i:=fil.flightnum;
   b:=fil.departuredate;
   c:=fil.placeofarrival;
   new(cur);
   cur^.fio:=a;
   cur^.flightnum:=i;
   cur^.departuredate:=b;
   cur^.placeofarrival:=c;
   add(start,cur);
 end;
 close(t);
end;


procedure menu;
begin
	writeln('1. Добавить');
	writeln('2. Вывод');
	writeln('3. Поиск');
	writeln('4. Вывод в файл');
	writeln('5. Считывание с файла');
	writeln('6. Удаление по ФИО');
	writeln('7. Выход');
end;

begin
  init(start);
	repeat
		menu;
		readln(num);
		case num of
			1: begin create(c);add(start,c); end;
			2: print(start);
			3: find();
			4: printtofile(start, t);
			5: readfromfile(t,start);
			6: begin waytofinddelete:=true; deletefind(); end;
		end;	
	until num=7;
end.