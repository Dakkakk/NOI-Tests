#include<cstdio>
#include<cstring>
using namespace std;
int n,dis[41][41],tots=0,bz[41],ans=0xfffffff,s,temp;
void search(int x,int y)
{
	if(tots>ans)
	  return;
	bz[x]=1;
	if(y==n)
	  {
	  	tots+=dis[x][temp];
	  	if(tots<ans)
	  	  ans=tots;
	  	tots-=dis[x][temp];  
	  }
	for(int i=1;i<=n;++i)
	  if(bz[i]==0)
	    {
	    	tots+=dis[x][i];
	    	search(i,y+1);
	    	tots-=dis[x][i];
	    	bz[i]=0;
	    }   
}
int main()
{
	freopen("salesman.in","r",stdin);
	freopen("salesman.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	  for(int j=1;j<=n;++j)
	    scanf("%d",&dis[i][j]);  
	printf("%d",ans);
	return 0;      
}

