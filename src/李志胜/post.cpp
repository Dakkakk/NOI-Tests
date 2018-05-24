#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
int v,p,w[301][301]={0},f[301][31],a[301],m,s[31],b[31][301];
void dfs(int n,int u,int m){
	if(n==0) return;
//	printf("%d ",u);
	int k=u+(m-u)/2;
	s[n]=a[k];
	m=u-1;
	u=b[n-1][m];
	dfs(n-1,u,m);
}
int main()
{
	freopen("post.in","r",stdin);
	freopen("post.out","w",stdout);
	scanf("%d%d",&v,&p);
	for(int i=1;i<=v;++i)
	  scanf("%d",&a[i]);
	for(int i=1;i<=v;++i)  
	  for(int j=1;j<=v;++j)
	    {
	    	if(i==j)
	    	  w[i][j]=0;
	    	else
			  {
			  	m=(i+j)/2;
			  	for(int k=i;k<=j;++k)
			  	  w[i][j]+=abs(a[k]-a[m]);
			  } 
	   
	    }
	 for(int i=1;i<=v;++i)
	   for(int j=1;j<=p;++j)
	     f[i][j]=0x3f3f3f3f;   
	 for(int i=1;i<=v;++i)
	  {
	   f[i][1]=w[1][i];
	   b[1][i]=1;
	 }
	 for(int i=2;i<=p;++i)
	   for(int j=i;j<=v-p+i;++j)
	     for(int k=i;k<=j;++k)
		   {
		   	if(f[k-1][i-1]+w[k][j]<f[j][i])
		   	  {
		   	  	f[j][i]=f[k-1][i-1]+w[k][j];
		   	  	b[i][j]=k;
		   	  }
		   }
	printf("%d\n",f[v][p]);
	dfs(p,b[p][v],v);
//	printf("\n");
	for(int i=1;i<=p;++i) printf("%d ",s[i]);
	return 0;  	        
} 
