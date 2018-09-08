var a,b:array[1..100] of longint;
    g:array[1..100,1..100] of 0..1;
   n,i,j,k:integer;
   procedure  init;
    var i,j,x:integer;
      begin
         assign(input,'tree.in');
         reset(input);
         assign(output,'tree.out');
         rewrite(output);
         readln(n);
         for i:=1 to  n do
          begin  read(x); a[i]:=x;
          while not eoln do
            begin read(x);
                 g[i,x]:=1;
             end;
              readln;
          end;
    end;
  procedure work;
    var  i,j:longint; max:longint;
     begin
       b[n]:=a[n];
       for i:=n-1 downto 1  do
         begin  max:=0;
                for j:=i+1 to n do
                 if (g[i,j]=1) and (b[j]>max) then max:=b[j];
                 b[i]:=max+a[i];
          end;
     end;
  procedure print;
    var i:integer; max:longint;
     begin    max:=0;
       for   i:=1 to n do
         if b[i]>max then max:=b[i];
         writeln(max);
         close(input);
         close(output);
      end;
          begin
      init;
      work;
      print;
      end.
