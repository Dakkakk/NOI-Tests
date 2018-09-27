#include<iostream>
#include<cstdio>
#include<cstring>
#define mn(a,b) (a<b?a:b)
#define min(a,b,c) (mn(a,mn(c,b)))
using namespace std;
//                          \ /
#define is(x,y) ((x+y)%2==0?1:0)

int m,n;
int map[501][501];
int dp[510][510];
char cc[501];
int main() {
	cin.sync_with_stdio(0);
	freopen("in.txt","r",stdin);
	cin>>n>>m;
	if(!is(n,m))
		cout<<"NO SOLUTION";
	else {
		memset(dp,127/3,sizeof dp);
		for(int i=1; i<=n; i++) {
			cin>>cc;
			for(int j=1; j<=m; j++)
				map[i][j]=(cc[j-1]=='/'?0:1);
		}
		dp[1][1]=(map[1][1]==1?0:1);
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=m; j++) {
				if(i==1&&j==1)
					continue;
				dp[i][j]=(map[i][j]==is(i,j)?0:1)+min(dp[i-1][j],dp[i][j-1],(is(i,j)?dp[i-1][j-1]:dp[i+1][j-1]));
			}
		}

		cout<<dp[n][m];
	}

	return 0;

}
