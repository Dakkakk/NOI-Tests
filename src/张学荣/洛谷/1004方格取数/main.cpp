//#include<algorithm>
#include<cstdio>
//#include<cmath>
//#include<cstring>
#define mx(x,y) ((x>y)?x:y)
#define max(a,b,c,d) (mx(mx(a,b),mx(c,d)))
int map[10][10];
int n;
int dp[10][10][10][10];
int main(){
	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	//////////////////////////////////
	{//inputLoop
		int i,j,k;
		scanf("%d",&n);
		scanf("%d %d %d",&i,&j,&k);
		while(i!=0&&j!=0&&k!=0){
			map[i][j]=k;
			scanf("%d %d %d",&i,&j,&k);
		}
	}//////////////D  P////////////////////
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				int l=i+j-k;
				if(l<0)
					continue;
				dp[i][j][k][l]=max(dp[i-1][j][k-1][l],dp[i][j-1][k][l-1],
								dp[i][j-1][k-1][l],dp[i-1][j][k][l-1]);
				dp[i][j][k][l]+=(i!=k&&j!=l)?map[i][j]+map[k][l]:map[i][j];				
			}
		}
	}
	printf("%d",dp[n][n][n][n]);
	return 0;
}
