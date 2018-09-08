var a,b,c:array[1..200] of longint;
    i,j,k,n,i1,i2,i3,t:integer; p:boolean; tem,s:longint;
 function   fj(n,k:integer):longint;
       var    x:array[1..20] of integer;
          i,j,m:integer;s,s1,s2:longint;
        begin  i:=0; fillchar(x,sizeof(x),0);s:=0;
               while  n<>0 do
                 begin  i:=i+1;
                       x[i]:=n mod 10;
                        n:=n div 10
                   end;
                   for j:=1 to i do
                     begin   s1:=1;
                         for  m:=1 to  k do
                              s1:=s1*x[j];
                           s:=s+s1;
                      end;
                  fj:=s
           end;
 begin
  assign(input,'ghillie.in');
  reset(input);
  assign(output,'ghillie.out');
  rewrite(output);
  readln(n);
        j:=0;
       while not eof do
        begin   j:=j+1;
              read(a[j]);
          end;
   for i:=2 to n+1 do
    begin  i2:=0;i3:=0;
      fillchar(b,sizeof(b),0);
      fillchar(c,sizeof(c),0);
     for  k:=1  to j do
        begin   s:=fj(a[k],i);
                i2:=i2+1;
                b[i2]:=s;
          end;
      for k:=1 to j do
      begin
              p:=true;
           for t:=1 to j do
            if a[k]=b[t] then p:=false;
           if p then begin  i3:=i3+1;
                             c[i3]:=a[k];
                       end;
        end;
            j:=i3;
            a:=c;
   end;
   for i:=1 to  j-1 do
     for  k:=i+1 to j do
       if a[i]>a[k] then begin
               tem:=a[i];
               a[i]:=a[k];
               a[k]:=tem
                       end;
      for i:=1 to j do
        write(a[i],' ');
   close(input);
 close(output);
 end.
