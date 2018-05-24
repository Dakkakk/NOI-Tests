program mul3;
const maxn=101;
var a:array[1..maxn]of integer;
    f:array[1..maxn,1..maxn]of longint;
    n,r,t:integer;
function calc(i,j:integer):longint;
  var k:integer;
      temp:longint;
  begin
  if i=j then begin calc:=0;exit; end;
  temp:=maxint;
  for k:=i+1 to j-1 do
   begin
     temp:=calc(i,k-1)+calc(k+1,j)+a[i]*a[k]*a[j];
     if temp<f[i,j] then f[i,j]:=temp;
     end;
  calc:=f[i,j];
  end;
begin
   assign(input,'mul.in');reset(input);
   assign(output,'mul.out');rewrite(output);
   readln(n);
   for t:=1 to n do read(a[t]);
   for t:=1 to n-2 do f[t,t+2]:=a[t]*a[t+1]*a[t+2];
   writeln(calc(1,n));
   close(input);
   close(output);
end.
