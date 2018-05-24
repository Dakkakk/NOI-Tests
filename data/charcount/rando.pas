var
  n,i,na,nb,nc,nd:longint;
begin
  assign(output,'charcount.in');rewrite(output);
  readln(n);
  randomize;
  for i:=1 to n do write(chr(60+random(50)));
  close(output);
end.
