#include<cstdio>
#include<cstring>
using namespace std;
int len,m,f[1001][50],a[1001][1001]={0},t;
char s[1001];
int main()
{
	freopen("minmax.in","r",stdin);
	freopen("minmax.out","w",stdout);
	scanf("%s%d",s,&m);
	len=strlen(s);
	for(int i=1;i<=len;++i)
	  for(int j=0;j<m;++j)
	    f[i][j]=0x3f3f3f3f;
	for(int i=1;i<=len;++i)
	  for(int j=i;j<=len;++j)
	    {
	      a[i][j]=(a[i][j-1]*10+s[j-1]-'0')%m;
	    }    
	for(int i=1;i<=len;++i)
	  f[i][a[1][i]]=0;
	for(int i=1;i<len;++i)
	  for(int j=0;j<m;++j)
	    if(f[i][j]<1001)
	      for(int k=i+1;k<=len;++k)
		    {
		    	t=(a[i+1][k]*j)%m;
		    	if(f[i][j]+1<f[k][t])
		    	  f[k][t]=f[i][j]+1;
		    }
	 for(int j=0;j<m;++j)		 
	  {
	  	if(f[len][j]<1001)
	  	  {
	  	  printf("%d %d ",j,f[len][j]);
	  	  break;
	      }
	  }	
	for(int i=m-1;i>=0;--i)
	  if(f[len][i]<1001)
	    {printf("%d %d ",i,f[len][i]);
	    break;
	    }  	
	return 0;	     
}
