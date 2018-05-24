var
  s:string;
  lens,i,na,nb,nc,nd:longint;
begin
  assign(input,'charcount.in');reset(input);
  assign(output,'charcount.out');rewrite(output);
  readln(s);
  lens:=length(s);
  for i:=1 to lens do
   begin
   if (s[i]='a')or(s[i]='A') then inc(na);
   if (s[i]='b')or(s[i]='B') then inc(nb);
   if (s[i]='c')or(s[i]='C') then inc(nc);
   if (s[i]='d')or(s[i]='D') then inc(nd);
   end;
  writeln(na);
  writeln(nb);
  writeln(nc);
  writeln(nd);
  close(input);close(output);
end.
