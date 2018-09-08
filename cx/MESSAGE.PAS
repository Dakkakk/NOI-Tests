const
   maxn=1000;

var
   n,m,i,j,x,y:longint;
   a:array[1..maxn,1..maxn] of boolean;
   v:array[1..maxn] of boolean;

function dfs(x,root:longint):boolean;
var
   j:longint;
   f:boolean;
begin
   v[x]:=true; f:=false;
   for j:=1 to n do begin
      if a[x,j] and not v[j] then begin
         f:=f or dfs(j,root);
         if f then begin dfs:=true; exit; end;
         end
      else if (j=root) and (a[x,j]) then begin
         dfs:=true; exit; end;
      end;
   dfs:=f;
end;

begin
   assign(input,'message.in'); reset(input);
   assign(output,'message.out'); rewrite(output);
   readln(n,m);
   fillchar(a,sizeof(a),false);
   for i:=1 to m do begin
      readln(x,y);
      a[x,y]:=true;
      end;
   for i:=1 to n do begin
      fillchar(v,sizeof(v),false);
      if dfs(i,i) then writeln('T')
      else writeln('F');
      end;
   close(input); close(output);
end.
