#include <iostream>
#include <cstdio>    
#include <cstring>
using namespace std;  
int n,ans=0;  
int a[111*2];  
int f[111*2][111*2];  
inline int dp(int i,int j)
 {
    if (f[i][j]!=0) return f[i][j];  
    for (int k=i+1;k<=j-1;++k)  
      f[i][j]=max(f[i][j],dp(i,k)+dp(k+1,j)+a[i]*a[k]*a[j]);  
    return f[i][j];  
}
int main()  
{   
    freopen("energy.in","r",stdin);
    freopen("energy.ans","w",stdout);
    cin>>n;  
    for(int i=1;i<=n;i++)  
    {  
      cin>>a[i];  
      a[i+n]=a[i];   
    }  
    memset(f,0,sizeof(f));  
    for (int i=1;i<=n;++i)
      if(dp(i,i+n-1)>ans) ans=dp(i,i+n-1);
	printf("%d\n",ans);     
}  
