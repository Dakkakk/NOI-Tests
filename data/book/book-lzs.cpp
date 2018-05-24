#include<cstdio>
#include<cstring>
using namespace std;
int m,n,f[501][501],s[501],a[501][501]={0},t,sum,bz=0;
void search(int x,int y)
{
	int i=x;
	sum=0;
	if(y==1)
	  {
	  	printf("%d %d\n",1,i);
	  	bz=1;
	  }
	else  
	{
	while(1)
	  {
	  	if(sum+s[i]<=f[m][n])
	  	  	sum+=s[i--];
	  	else
		  break;  
	  }
    search(i,y-1);
	if(bz)
	  printf("%d %d\n",i+1,x);
	}
	return;    
}
int main()
{
	freopen("book.in","r",stdin);
	freopen("book.out","w",stdout);
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;++i)
	  scanf("%d",&s[i]);
	for(int i=1;i<=m;++i)
	  for(int j=i;j<=m;++j)
	    a[i][j]=a[i][j-1]+s[j];  
	for(int i=1;i<=m;i++)
	  for(int j=1;j<=n;++j)
	    f[i][j]=0x3f3f3f3f;
	f[0][1]=0;
	for(int i=1;i<=m;++i)
	  f[i][1]=f[i-1][1]+s[i];	  
	for(int i=2;i<=n;++i)
	  for(int j=i;j<=m;++j)
	    for(int k=1;k<j;++k)
		  {
		  	t=f[k][i-1]>a[k+1][j]?f[k][i-1]:a[k+1][j];
		  	if(t<f[j][i])
		  	  f[j][i]=t;
		  }
	search(m,n);	  
	return 0;	    
}
