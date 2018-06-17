#include<cstdio>
#include<cstring>
#define mx(x,y) ((x>y)?x:y)
#define max(a,b,c,d) (mx(mx(a,b),mx(c,d)))
using namespace std;
int n,dp[11][11][11][11],a[11][11];
int main(){
//	freopen("write.in","r",stdin);
	scanf("%d",&n);
	memset(dp,0,sizeof(dp));
	int q,p,z;
	while(q!=0||p!=0||z!=0){
	scanf("%d%d%d",&q,&p,&z);
	a[q][p]=z;
	}
	for(int ii=1;ii<=n;ii++)
		for(int jj=1;jj<=n;jj++)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++){
				dp[ii][jj][i][j]=max(dp[ii-1][jj][i][j-1]+a[i][j]+a[ii][jj],dp[ii-1][jj][i-1][j]
					+a[i][j]+a[ii][jj],dp[ii][jj-1][i-1][j]+a[i][j]+a[ii][jj],dp[ii][jj-1][i][j-1]+a[i][j]+a[ii][jj]);
				if(ii==i&&jj==j) dp[ii][jj][i][j]-=a[i][j];
				}
	printf("%d",dp[n][n][n][n]);
}
