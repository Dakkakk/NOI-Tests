#include<cstdio>
#include<cstring>
#define min(a,b) ((a)<(b)?(a):(b))
int f[101][101],a[101],n,x;
int main()
{
	freopen("unite.in","r",stdin);
    freopen("unite.out","w",stdout);
    scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
	 scanf("%d",&x);
	 a[i]=a[i-1]+x;
   }
	a[0]=0;
	memset(f,127/3,sizeof(f));
	for (int i=1;i<=n;i++) f[i][i]=0;
	for (int i=n-1;i>=1;i--)
	  for (int j=i+1;j<=n;j++)
		for (int k=i;k<=j-1;k++)
			f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]+a[j]-a[i-1]);
	printf("%d\n",f[1][n]);
	return 0;
}



