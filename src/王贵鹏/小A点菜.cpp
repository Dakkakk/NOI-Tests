#include<cstdio>
#include<cstring>
using namespace std;
int money,n;
int a[101],dp[10001];
int main(){
	//由图分析可知 1元的方案+0为2元的方案； 3元的方案为二元的方案加一元的方案； 
、、	freopen("in.in","r",stdin);
	memset(dp,0,sizeof(dp));
	dp[0]=1;//money=a[i]
	scanf("%d%d",&n,&money);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		for(int j=money;j>=a[i];j--)
		dp[j]+=dp[j-a[i]];
		printf("%d",dp[money]);
}
