#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int a[100],g[100][101];
int main()
{
	int n;
	freopen("hospital.in","r",stdin);
	freopen("hospital.out","w",stdout);
	cin>>n;
       for(int i=1; i<=n; ++i)
	 for(int j=1; j<=n; ++j)
	    g[i][j]=0x3f3f3f3f;	
       for(int i=1; i<=n; ++i)
	{
	int x,y;
        cin>>a[i]>>x>>y;
	g[i][x]=1;g[x][i]=1;
	g[i][y]=1;g[y][i]=1;
        g[i][i]=0;
	}
	
	for(int k=1; k<=n; ++k)
	for(int i=1; i<=n; ++i)
         if(i!=k)
	for(int j=1; j<=n; ++j)
        if(i!=j&&j!=k&&g[i][j]>g[i][k]+g[k][j]) g[i][j]=g[i][k]+g[k][j];  
    
    int m=0x7fffffff;
    for(int i=1; i<=n; ++i)
    {
        int t=0;
        for(int j=1; j<=n; ++j)
         t=t+g[i][j]*a[j];
        if(t<m) m=t;       
	}
	cout<<m<<endl;
	return 0;
}

