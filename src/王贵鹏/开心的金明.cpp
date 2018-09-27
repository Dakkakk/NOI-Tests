#include<cstdio>
#include<cstring>
#define max(a,b) (a>b?a:b)
using namespace std;
int money,n;
struct aa{
	int price,heavy;
}a[26];
int dp[30001];
int main(){
	freopen("in.in","r",stdin);
	memset(dp,0,sizeof(dp));
	scanf("%d%d",&money,&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&a[i].price,&a[i].heavy);
	for(int i=1;i<=n;i++)
		for(int j=money;j>a[i].price;j--)
		dp[j]=max(dp[j],a[i].price*a[i].heavy+dp[j-a[i].price]);
		printf("%d",dp[money]);
		
}
