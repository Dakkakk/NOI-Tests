#include<cstdio>//首先要确定项链的顺序，
//而i小的可连i+1；当i取最大值时，连在i=1上 
#define max(a,b) (a>b? a:b)
using namespace std;
int dp[202][202],a[202],n; //dp>>k i j which to be each other;
// a>>i the table that we can do; //k>> which you use over
int main(){
	freopen("write.in","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
	scanf("%d",&a[i]);
	a[i+n]=a[i];// copy the table once 
	}
	for(int i=2*n-1;i>=1;i--)
		for(int j=i+1;j<=2*n;j++)
			for(int k=i;k<=j-1;k++){
				dp[i][j]=max(dp[i][j],dp[i][k]+dp[i][k+1]+a[k+1]*a[i]*a[j+1]);
			}
int ans=0;
	for(int i=2*n-1;i>=1;i--)
		for(int j=i+1;j<=2*n;j++)
			for(int k=i;k<=j-1;k++)
				ans=max(dp[i][j],ans);
	printf("%d",ans);
}
