#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int people[101],dis[101][101];
int main()
{
	freopen("hospital.in","r",stdin);
	freopen("hospital.out","w",stdout);
	int n;
    cin>>n;
//    for(int i=1;i<=n;++i)
//      for(int j=1;j<=n;++j)
//        dis[i][j]=0x3f3f3f3f;
	memset(dis,0x3f3f3f,sizeof(dis));
	for(int i=1;i<=n;++i)
	  {
	  	int x,y;
	  	cin>>people[i]>>x>>y;
	  	dis[i][x]=dis[x][i]=1;
	  	dis[i][y]=dis[y][i]=1;
	  	dis[i][i]=0;
	  }
	for(int k=1;k<=n;++k)
	  for(int i=1;i<=n;++i)
	    if(i!=k)
	      for(int j=1;j<=n;++j)
		  {
		  	if(i!=j&&k!=j&&dis[i][j]>dis[i][k]+dis[k][j])
		  	  dis[i][j]=dis[i][k]+dis[k][j];
		  }
	int ans=0x7fffffff;	   
	for(int i=1;i<=n;++i)
	  {
	  	int k=0;
	  	for(int j=1;j<=n;++j)
	  	  k+=people[j]*dis[i][j];
	  	if(k<ans) ans=k;  
	  }
	printf("%d",ans);
	return 0;  	  
	  
}
