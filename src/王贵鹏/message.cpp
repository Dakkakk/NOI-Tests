#include<cstdio>
#include<cstring>
#define mx(x,y) ((x>y)?x:y)
#define max(a,b,c,d) (mx(mx(a,b),mx(c,d)))
using namespace std;
int n,dp[51][51][51][51],a[51][51],m;
int main(){
	freopen("write.in","r",stdin);
	scanf("%d%d",&m,&n);
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	for(int ii=1;ii<=m;ii++)
		for(int jj=1;jj<=n;jj++)
			for(int i=1;i<=m;i++)
				for(int j=1;j<=n;j++){
					dp[ii][jj][i][j]=max(dp[ii-1][jj][i][j-1],dp[ii-1][jj][i-1][j],
										dp[ii][jj-1][i-1][j],dp[ii][jj-1][i][j-1])
										+a[i][j]+a[ii][jj];
					if(ii==i&&jj==j) dp[ii][jj][i][j]-=a[i][j];
				}
	printf("%d",dp[m][n][m][n]);
	
}
