#include<cstdio>
#include<cstring>
using namespace std;
struct a{
	int t,price;
}f[100];
int dp[1005],k,t;//f is the table
int main(){
	freopen("write.in","r",stdin);
	memset(dp,0,sizeof(dp));
	scanf("%d%d",&t,&k);
	for(int i=1;i<=t;i++)
		scanf("%d%d",&f[i].t,&f[i].price);
	for(int i=1;i<=k;i++)
		for(int j=t;j>=f[i].t;j--)
		if(dp[j]<dp[j-f[i].t]+f[i].price)
		 dp[j]=dp[j-f[i].t]+f[i].price;
		printf("%d",dp[t]);
}

