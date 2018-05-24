#include<cstdio>
#include<cstring>
using namespace std;
int dp[20001],b[11],n;
int main(){
	freopen("busses.in","r",stdin);
	freopen("busses.out","w",stdout);
	memset(dp,0x7f,sizeof(dp));
	for(int i=1;i<=10;i++)scanf("%d",&b[i]);
	scanf("%d",&n);
	for(int i=1;i<=10;i++)dp[i]=b[i];
	
	
	for(int i=1;i<=10;i++)//½×¶Î 
		for(int j=1;j<=n;j++)//×´Ì¬ 
		if((j-i>0)&&(dp[j]>dp[j-i]+b[i]))
	    	dp[j]=dp[j-i]+b[i];
		printf("%d",dp[n]);
	
}
