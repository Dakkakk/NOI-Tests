#include<cstdio>
#include<iostream>
using namespace std;
int m,n,start[501]={0},end[501]={0},s[501],f[501][501],a[501][501],t,temp=0,p;
int comd(int x,int y)
{
	int ans=0;
	for(int i=x;i<=y;++i)
	  ans+=s[i];
	return ans;  
}
int main()
{
	freopen("book.in","r",stdin);
	freopen("book.out","w",stdout);
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;++i)
	  scanf("%d",&s[i]);
	for(int i=1;i<=m;++i)
	  for(int j=1;j<=n;++j)
	    f[i][j]=0x3f3f3f3f;
	for(int i=0;i<=m;++i)
	  f[i][1]=0;		    
	for(int i=1;i<=m;++i)
	  f[i][1]=f[i-1][1]+s[i];  
    for(int i=2;i<=n;++i) 
      for(int j=2;j<=m;++j)
        for(int k=1;k<j;++k)
          {
          	t=comd(k+1,j);
          	if(f[k][i-1]>t)
          	  t=f[k][i-1];
            if(t<f[j][i])
              f[j][i]=t;
          }
     int h=n;
	 p=m;     
    for(int i=m;i>=1;--i)
      {
      	if(temp>f[m][n])
      	  {
      	  	start[h]=i+1;
      	  	end[h--]=p;
      	  	p=i;
      	  	temp=0;
      	  }
      	temp+=s[i];
      }
  for(int i=1;i<=n;++i)
	  printf("%d %d\n",start[i],end[i]);
	return 0;        
}
