const maxn=6;
var a:array[1..maxn]of longint;
    d:array[1..maxn,1..maxn]of longint;
    min,j,k,n,i,t,r:longint;
begin
   assign(input,'mul.in');reset(input);
   assign(output,'mul.out');rewrite(output);
   read(n);
   for i:=1 to n do read(a[i]);
   fillchar(d,sizeof(d),0);
   for i:=2 to n do
    d[i-1,i+1]:=a[i-1]*a[i]*a[i+1];
   for k:=3 to n-1 do
    for i:=1 to n-k do
     begin
      min:=maxlongint;
      for j:=i+1 to i+k-1 do
       if min>(d[i,j]+d[j,i+k]+a[i]*a[j]*a[i+k]) then
        min:=(d[i,j]+d[j,i+k]+a[i]*a[j]*a[i+k]);
      d[i,i+k]:=min;
      write(min,' ');
     end;
   writeln(d[1,n]);
   {for i:=1 to n do write(a[i],' ');writeln;
   for t:=1 to n do
    begin
    for r:=1 to n do  write(d[t,r],' ');
    writeln;end;}
   close(output);
end.
