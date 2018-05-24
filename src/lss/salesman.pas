program salesman;
var data:array[1..40,1..40] of byte;
    p:array[1..40] of 0..1;
    step:array[1..40] of byte;
    n,ii,jj:byte;min,m :longint;

procedure road(k:byte);
var i,j,t:byte;
begin
  if k>n then
      if m+data[step[k-1],1]<min  then min:=m+data[step[k-1],1]
      else
  else
 
 for i:=2 to n do
     if p[i]=0 then
       begin
         step[k]:=i;
         p[i]:=1;
         m:=m+data[step[k-1],i];
         if m<min then road(k+1);
         step[k]:=0;
         p[i]:=0;
         m:=m-data[step[k-1],i];
      end;
end;
begin
   assign(input,'salesman.in'); assign(output,'salesman.out');
   reset(input);rewrite(output);
   readln(n);
   for ii:=1 to n do for jj:=1 to n do read(data[ii,jj]);
   fillchar(p,sizeof(p),0);
   fillchar(step,sizeof(step),0);
   min:=99999999;
   m:=0; p[1]:=1;step[1]:=1;
   road(2);
 writeln(min); close(input); close(output);
end.
