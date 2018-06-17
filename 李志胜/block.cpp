#include<iostream>
#include<cstdio>
using namespace std;
int f[101][101],n,a[101],k,x;
int main()
{
	;freopen("block.in","r",stdin);
	freopen("block.out","w",stdout);
	cin>>n;
	for(int i=1;i<n;++i)
	  for(int j=i;j<=n;++j)
	    f[i][j]=f[j][i]=127/3;
	a[0]=0;    
	for(int i=1;i<=n;++i)
	  {
	  	cin>>x;
	  	a[i]=a[i-1]+x;
	  	f[i][i]=0;
	  }
	for(int i=n-1;i>0;--i)
	  for(int j=i+1;j<=n;++j)
	    for(int k=i;k<j;++k)
		  if(f[i][k]+f[k+1][j]+a[j]-a[i-1]<f[i][j])
		    f[i][j]=f[i][k]+f[k+1][j]+a[j]-a[i-1];
	cout<<f[1][n];
	return 0;		      
}
