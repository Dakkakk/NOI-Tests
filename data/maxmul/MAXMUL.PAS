program maxmul;
const maxn=40;
var n,k,i,j,t:integer;max1:longint;
    a:array[1..maxn]of char;
    f:array[0..maxn,0..maxn]of longint;

function num(ii,jj:integer):longint;
var 
    t1:integer; s1:longint;
begin
    s1:=0;
    for t1:=ii to jj do  s1:=s1*10+ord(a[t1])-ord('0');
    num:=s1;
end;

begin
  assign(input,'maxmul.in');assign(output,'maxmul.out');
  rewrite(output); reset(input);
  readln(n,k);
  for i:=1 to n do read(a[i]);
  close(input);
    
  for i:=2 to n do
   begin
     max1:=0;
     for j:=1 to i-1 do  if (num(1,j)*num(j+1,i))>max1 then max1:=num(1,j)*num(j+1,i);
     f[i,1]:=max1;
   end;
 
  for t:=2 to k do
   for i:=t+1 to n-k+t do
     begin
        max1:=0;
        for j:=t to i-1 do
        if f[j,t-1]*num(j+1,i)>max1 then max1:=f[j,t-1]*num(j+1,i);
        f[i,t]:=max1;
     end;
  writeln(f[n,k]);
  close(output);
end.

