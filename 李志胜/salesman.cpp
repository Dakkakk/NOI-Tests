#include<cstdio>
#include<iostream>
using namespace std;
int w[21][21],f[21][21],ans=0xfffffff,a[21][21][21],n;
void first(int x){
	for(int i=1;i<=x;++i)for(int j=1;j<=x;++j){
		w[i][j]=0;f[i][j]=888;
	}
	for(int i=1;i<=x;++i)
	for(int j=1;j<=x;++j)
	for(int k=1;k<=x;++k)
	  a[i][j][k]=0;
	return;  
}
int main(){
	freopen("salesman.in","r",stdin);
	freopen("salesman.out","w",stdout);
	scanf("%d",&n);
	first(n);
	for(int i=1;i<=n;++i)
	  for(int j=1;j<=n;++j)
	    scanf("%d",&w[i][j]);	  
	f[1][1]=0;
	a[1][1][1]=1;
	for(int i=2;i<=n;++i)
    {
		f[2][i]=w[1][i]+f[1][1];
		a[2][i][1]=1;
		a[2][i][i]=1;
	}   
	for(int i=3;i<=n;++i)
	for(int k=2;k<=n;++k){
	   int t=0;
	   for(int j=2;j<=n;++j)
	   if((j!=k)&&(a[i-1][j][k]==0)&&(f[i-1][j]+w[j][k]<f[i][k]))
	   {
		  f[i][k]=f[i-1][j]+w[j][k];
		  t=j;	
       }
	  for(int h=2;h<=n;++h)
	   if(a[i-1][t][h]==1) a[i][k][h]=1;
	  a[i][k][k]=1;
      }
//	for(int i=2;i<=n;++i)
//	if(f[n][i]+w[i][1]<ans) ans=f[n][i]+w[i][1];
//	printf("%d",ans);
//    printf("\n");
	for (int i=1;i<=n;++i)
	{
	
	  for(int j=1;j<=n;++j)
	     cout<<f[i][j]<<" ";
	     cout<<endl;
}
	  return 0;
}
