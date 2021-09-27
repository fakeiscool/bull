unit module;
interface 
var num:integer;
type f = record
  placeofarrival:string[50];
  flightnum:integer;
  fio:string[50];
  departuredate:string[50];
end;

var fil:f; t: file of f;

type uk=^elem;
  elem=record
    placeofarrival:string[50];
    flightnum:integer;
    fio:string[50];
    departuredate:string[50];
   next:uk;
 end;
var start,findhelp:uk; c:uk; flag:boolean; waytofind:boolean; waytofinddelete:boolean;

procedure init(var start:uk);

procedure print(var beg:uk);

function find():uk;

procedure deletefind();

procedure delete(var start:uk);

implementation

procedure init(var start:uk);
begin
  start:=nil;
end;

procedure print(var beg:uk);
var p:uk;
begin
  p:=beg;
  while p<>nil do begin
   writeln(p^.fio,'   ',p^.flightnum,'   ',p^.departuredate,'   ',p^.placeofarrival);
   p:=p^.next;
  end;
end;

function find():uk;
var p:uk; waypick,a:integer; s:string;
begin
 p:=start;
 flag:=false;
 
 if not waytofinddelete then begin
   writeln('Введите цифру: ');
   writeln('1 - Чтобы искать по номеру полёта');
   writeln('2 - Чтобы искать по дате отбытия');
   readln(waypick);
   case waypick of
  			1: begin waytofind:=true; readln(a); end;
  			2: begin waytofind:=false; readln(s); end;
   end;	
 end;
 
 if waytofind and not waytofinddelete then 
  while (p<>nil) do begin
    if (p^.flightnum=a) then begin
      writeln('Результаты поиска ',p^.fio,'   ',p^.flightnum,'   ',p^.departuredate,'   ',p^.placeofarrival);
      flag:=true;
    end;
    findhelp:=p;
    p:=p^.next;
  end;

 if not waytofind and not waytofinddelete then 
  while (p<>nil) do begin
    if (p^.departuredate=s) then begin
      writeln('Результаты поиска ',p^.fio,'   ',p^.flightnum,'   ',p^.departuredate,'   ',p^.placeofarrival);
      flag:=true;
    end;
    findhelp:=p;
    p:=p^.next;
  end;
  
 if waytofinddelete then begin
  writeln('Введите ФИО для удаления данных');
  readln(s);
  while (p<>nil) and (p^.fio<>s) do begin
    findhelp:=p;
    p:=p^.next;
  end;
  if (p<>nil) and (p^.fio=s) then begin
   flag:=true;
   writeln('Элемент удалён');
  end;
 end;
 find:=p;
 if not flag then begin
  writeln('Элемент не найден');
  flag:=false;
  findhelp:=nil;
 end;
 waytofinddelete:=false;
 
end;
 
procedure delete(var start:uk);
begin
  start:=start^.next;
end;

procedure deletefind();
begin
find();
if findhelp <> nil then begin
  c:=findhelp;
  c^.next:=c^.next^.next;
 end
 else if flag then
  delete(start)
end;
  

end.
