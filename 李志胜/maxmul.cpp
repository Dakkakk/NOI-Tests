#include<cstdio>
using namespace std;
char s[41];
long long a[41][41],n,k,b[41],tans=0,f[41][11];
int main()
{
	freopen("maxmul.in","r",stdin);
	freopen("maxmul.out","w",stdout);
	scanf("%d%d",&n,&k);
	scanf("%s",s);
	for(int i=1;i<=n;++i)
	  b[i]=s[i-1]-'0';
	for(int i=1;i<=n;++i)
	  a[i][i]=b[i];  
	for(int i=1;i<n;++i)
	  for(int j=i+1;j<=n;++j)
	    a[i][j]=a[i][j-1]*10+b[j];//³õÊ¼»¯Êý×Ö
	for(int i=1;i<=n;++i)
	  for(int j=1;j<=k;++j)
	    f[i][j]=0;
	for(int i=1;i<=n;++i)
	  f[i][0]=a[1][i];		  
	for(int i=1;i<=k;++i)
	  for(int j=i+1;j<=n-k+i;++j)
	    {
	    	tans=0;
	    	for(int t=i;t<=j-1;++t)
	    	  {
	    	  	if(f[t][i-1]*a[t+1][j]>tans)
	    	  	  tans=f[t][i-1]*a[t+1][j];
	    	  	f[j][i]=tans;  
	    	  }
	    }  
	printf("%d",f[n][k]);
	return 0;  
}
