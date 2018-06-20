#include<cstdio>
#include<cstring>
#define min(x,y) (x<y?x:y)
using namespace std;
int num[101];
int n;
int dp[101][101];
int main(){ 
	freopen("mul.in","r",stdin);
	freopen("mul.out","w",stdout);
	scanf("%d",&n);
	memset(dp,127/3,sizeof dp);
	for(int i=1;i<=n;i++)
		scanf("%d",&num[i]),dp[i][i]=dp[i][i+1]=0;
//	for(int i=1;i<n;i++)
//	dp[i][i+1]=0;//相邻两个无法相乘 
	for(int i=n-2;i>=1;i--){//至少要三个点 
		for(int j=i+1;j<=n;j++){  //j<=n，否则dp[i,j]无法记录到最右边的解。 
			for(int k=i;k<j;k++){
				dp[i][j]=min(dp[i][j],dp[i][k]+num[i]*num[k]*num[j]+dp[k][j]);
			}
		}
	}
	printf("%d",dp[1][n]);
	return 0;
}
//
//	for(int i=n-3;i>=1;i--){
//		for(int j=i+3;j<=n;j++){  //j<=n，否则dp[i,j]无法记录到最右边的解。 
//			for(int k=i+1;k<j;k++){
//				dp[i][j]=min(dp[i][j],dp[i][k]+num[i]*num[k]*num[j]+dp[k][j]);
//			}
//		}
//	}
