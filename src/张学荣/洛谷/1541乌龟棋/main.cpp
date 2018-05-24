#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
int n,m;//num  cardNum
int grid[351];
int card[5];
int dp[351][41][41][41][41];
int main(){
	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&grid[i]);
	for(int i=1,t=0;i<=m;i++){
		scanf("%d",&t);
		card[t]++;
	}
	dp[n][0][0][0][0]=grid[n];
	for(int i=n;i>=0;i--){
		for(int j=0;j<=card[1];j++){
			for(int k=0;j<=card[2];k++){
				for(int l=0;l<=card[3];l++){
					for(int p=0;p<=card[4];p++){
						dp[i][j][k][l][p]=
					}
				}
			}
		}
	}
	return 0;
}
