var i,j,k,n,m,s:integer;
   num:array[1..200] of integer;
   ans:array[1..1000] of integer;
  procedure work;
    var i,j,s,g:integer;
      begin  ans[1000]:=1;
            for j:=1 to  m do begin
             g:=0;
             for i:=1000 downto 1  do
                 begin
                    s:=ans[i]*num[j]+g;
                    ans[i]:=s mod 10;
                    g:=s div 10
                  end;          end;
        end;
  procedure  out;
   var i,j:integer;
     begin  i:=1;
            while ans[i]=0 do inc(i);
            for j:=i to 1000 do write(ans[j]);
            close(input);
            close(output);
       end;
begin
  assign(input,'best.in');
  reset(input);
  assign(output,'best.out');
  rewrite(output);
  readln(n);
  num[1]:=2; m:=1;s:=2;
  while  s+num[m]+1<=n do
    begin  s:=s+num[m]+1;
          inc(m);
          num[m]:=num[m-1]+1;
      end;
      k:=m;
      while  s<n do
      begin  inc(s);
             inc(num[k]);
             dec(k);
             if k=0 then k:=m
        end;
     work;
     out;
    end.


