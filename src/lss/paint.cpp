#include <stdio.h>
#include <string.h>
#define MAX (1<<15)
int n,color[15];
bool g[15][15];
int bz[15],tot,ans,best;
void init() {
	int map[100][100];
	int i, j, k;	
	scanf("%d", &n);
	memset(map, -1, sizeof(map));	
	for ( i=0; i<n; ++i ) {
		int x1, y1, x2, y2;		
		scanf("%d %d %d %d %d", &x1, &y1, &x2, &y2, &color[i]);
		for ( j=x1; j<x2; ++j )
			for ( k=y1; k<y2; ++k )
				map[j][k]=i;
	}
	memset(g, false, sizeof(g));
	for ( i=0; i<99; ++i )
		for ( j=0; j<100; ++j )
			if ( map[i][j]>=0 && map[i+1][j]>=0 && map[i][j]!=map[i+1][j] )
				g[map[i][j]][map[i+1][j]]=true;
}
bool check(int x)
{
  for (int i=0; i<n; ++i )
    if (g[i][x]&&bz[i]==0) return false;
    return true;  
}
void DFS(int r,int tcity,int tcolor)
{
  if (tcity==n)
	{
		ans=tot;
		return;
	}	
	if (bz[r]==0&&check(r)) 
	{
		bz[r]=1;
		if 	(tcolor!=color[r])
		 tot=tot+1;
		for (int i=0; i<n; ++i )
	     if (bz[i]==0&&check(i)&&color[i]==tcolor)
	     {
	       bz[i]=1;
	       DFS(i,tcity+1,color[i]);
	       bz[i]=0;
	  } 	 
  }
}
int main() 
  {
	freopen("paint.in", "r", stdin);
	freopen("paint.out", "w", stdout);	
    init();
	short best=99;	
	for (int i=0; i<n; ++i )
     {
        memset(bz, 0, sizeof(bz));	
        ans=0; tot=0;
        DFS(i,0,color[i]);
		if (best>ans)
		best=ans;
	 }	
	printf("%d\n", best);
	fclose(stdin);fclose(stdout);	
	return 0;
}

