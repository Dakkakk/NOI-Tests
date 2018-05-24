program scholar;
var i,j,n:integer;
    a1,a2,a3,code:integer;
    ch1,ch2:string[1];
    p,max,total:longint;
    name,maxname,s:string[50];
begin
   assign(input,'scholar.in');
   assign(output,'scholar.out');
   reset(input);
   readln(n);
   total:=0;max:=0;
   for i:=1 to n do
     begin
       readln(s);
       j:=pos(' ',s);
       name:=copy(s,1,j-1);
       delete(s,1,j);
       j:=pos(' ',s);
       val(copy(s,1,j-1),a1,code);
       delete(s,1,j);
       j:=pos(' ',s);
       val(copy(s,1,j-1),a2,code);
       delete(s,1,j);
       ch1:=copy(s,1,1);
       ch2:=copy(s,3,1);
       delete(s,1,4);
       val(s,a3,code);
       p:=0;
       if (a1>80)and(a3>=1) then p:=p+8000;
       if (a1>85)and(a2>80) then p:=p+4000;
       if a1>90 then p:=p+2000;
       if (a1>85)and(ch2='Y') then p:=p+1000;
       if (a2>80)and(ch1='Y') then p:=p+850;
       if p>max then begin max:=p;maxname:=name; end;
       total:=total+p;
       end;
     rewrite(output);
     writeln(maxname);
     writeln(max);
     writeln(total);
     close(input);close(output);
end.
