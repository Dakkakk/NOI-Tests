#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>    //直接应用min函数
using namespace std;
int i,j,k,n,m;
int num[110],f[110][110];
using namespace std;
int main()
{
    freopen("mul.in","r",stdin);
    freopen("mul.out","w",stdout);	
    scanf("%d",&n);
	memset(f,0x3f,sizeof(f));
	for (i=1;i<=n;i++)
	 {
	  scanf("%d",&num[i]);
	  f[i][i]=num[i];
     }
    for (i=1;i<=n-1;i++)
     f[i][i+1]=0;
  for (i=1;i<=n-2;i++)
   f[i][i+2]=num[i]*num[i+1]*num[i+2];
    for (i=n-3;i>=1;--i)
	 {
	    for (j=i+3;j<=n;++j)
	     {
	     	for (k=i+1;k<=j-1;++k)
	     	 f[i][j]=min(f[i][j],f[i][k]+f[k][j]+num[i]*num[k]*num[j]);
	     }
	 }
    printf("%d",f[1][n]);
	return 0;
}
