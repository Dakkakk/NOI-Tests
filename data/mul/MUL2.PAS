program mul;
const maxn=101;
var a:array[0..maxn]of longint;
    d:array[1..maxn,1..maxn]of longint;
    min,j,k,n,i:longint;
begin
   assign(input,'mul.in');reset(input);
   assign(output,'mul.out');rewrite(output);
   read(n);
   for i:=1 to n do read(a[i]);
   close(input);
   for i:=1 to n-2 do d[i,i+2]:=a[i]*a[i+1]*a[i+2];
   for i:=n-3 downto 1 do
     for j:=i+3 to n do
      begin
       min:=maxlongint;
       for k:=i+1 to j-1 do
         if (d[i,k]+d[k,j]+a[i]*a[k]*a[j])<min
         then  min:=d[i,k]+d[k,j]+a[i]*a[k]*a[j] ;
       d[i,j]:=min;
     end;
    writeln(d[1,n]);
    close(output);
end.
