#include<cstdio>
#include<cstring>
using namespace std;
int n,k,s[501],f[501][501],a[501][501]={0},x,y,b[501][501]={0};
int main()
{
//	freopen("house.in","r",stdin);
//	freopen("house.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)
	  scanf("%d",&s[i]);
	for(int i=1;i<=n;++i)
	  for(int j=i;j<=n;++j)
	    {
	    	if(s[j]) 
			{
	    	  a[i][j]=a[i][j-1]+1;
	    	  b[i][j]=b[i][j-1];
	        }
	    	else 
			{
			  b[i][j]=b[i][j-1]+1;
			  a[i][j]=a[i][j-1];//注意保持不变:-D  ^_^
		    }
	    	//printf("%d %d\n",a[i][j],b[i][j]);
	    }
	for(int i=1;i<=n;++i)
	  for(int j=2;j<=k;++j)
	    f[i][j]=0x3f3f3f3f;    
	for(int i=1;i<=n;++i)
	  f[i][1]=a[1][i]*b[1][i];
	for(int i=2;i<=k;++i)
	  for(int j=i;j<=n;++j)
	    for(int k=1;k<j;++k)
		  {
		  	if(f[k][i-1]+a[k+1][j]<f[j][i])
		  	  f[j][i]=f[k][i-1]+a[k+1][j]*b[k+1][j];//后面的状态是后面的马棚的不愉快系数 
		  //	printf("%d\n",f[i][j])  ;
		  }      
	printf("%d",f[n][k]);
	return 0;	  
}
