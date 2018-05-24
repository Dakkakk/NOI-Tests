#include<cstdio>
using namespace std;
int n,c,p,dis[801][801],m[801],ans=0xfffffff;
int main()
{
	freopen("butter.in","r",stdin);
	freopen("butter.out","w",stdout);
	scanf("%d%d%d",&n,&p,&c);
	for(int i=1;i<=p;++i)
	  for(int j=1;j<=p;++j)
	    dis[i][j]=0x3f3f3f3f;
	int q,w,e;
	for(int i=1;i<=p;++i)
	  {
	  	m[i]=0;
	  	dis[i][i]=0;
	  }
	for(int i=1;i<=n;++i)
	  {
	  	scanf("%d",&q);
	  	m[q]+=1;
	  }
	for(int i=1;i<=c;++i)
	  {
	  	scanf("%d%d%d",&q,&w,&e);
	  	dis[q][w]=dis[w][q]=e;
	  }
	 for(int k=1;k<=p;++k)
	   for(int i=1;i<=p;++i)
	     if(i!=k)
	 	   for(int j=1;j<=p;++j)
	 	     if(i!=j&&k!=j&&dis[i][k]+dis[k][j]<dis[i][j])
	 		   dis[i][j]=dis[j][i]=dis[i][k]+dis[k][j];
	 int temp=0;		   
	 for(int i=1;i<=p;++i)
	  {
	  	temp=0;
	    for(int j=1;j<=p;++j)
	      temp+=dis[i][j]*m[j];
	    if(temp<ans)
		  ans=temp;  
      }
	  	 
	  printf("%d",ans);
	  return 0;	       
}
