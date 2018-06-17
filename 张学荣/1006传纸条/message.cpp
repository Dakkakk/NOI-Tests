#include<algorithm>
#include<cstdio>
#include<cmath>
#define mx(x,y) (x>y?x:y)
#define max(a,b,c,d) (mx(mx(a,b),mx(c,d)))
using namespace std;
int map[51][51];//x  y
int m,n;//Xmax  Ymax
int dp[51][51][51][51];//i j k l
//i+j=k+l=stepNow
int main(){
	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&map[i][j]);
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=m;k++){
				int l=i+j-k;
				if(l<0)
					continue;
				dp[i][j][k][l]=max(dp[i-1][j][k-1][l],dp[i][j-1][k][l-1],
									dp[i][j-1][k-1][l],dp[i-1][j][k][l-1])+
									((i!=k&&j!=l)?map[i][j]+map[k][l]:map[i][j]);
			}
		}
	}
	printf("%d",dp[m][n][m][n]);
	return 0;
}
