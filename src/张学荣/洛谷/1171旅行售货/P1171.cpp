#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
int n;
int dp[1100010][25];
int map[25][25];
int main() {
	cin>>n;
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= n; j ++)
			cin>>map[i][j];//读入村庄间距离
	memset(dp,63,sizeof(dp));
	dp[1][1] = 0;//状态1表示此时只有1号点访问过
	for(int i =0; i<=(1 << n/*第n个村庄*/) -1; i++)
		for(int j=1; j<=n; j++)
			if( !( (1 << j-1) & i) )
				for(int k=1; k<=n; k++)
					if( ( (1 << k-1) & i) )
						dp[((1 << j-1) | i)][j] = min(dp[((1 << j-1) | i)][j],dp[i][k] + map[k][j]);//核心代码，解释如上所述
	int ans = 2147483640;
	for(int i=2; i<=n; i++) //最后从状态(1<<n)-1（二进制全为1）中寻找到1最短的点
		ans=min(ans,dp[(1<<n)-1][i] + map[i][1]);
	cout<<ans;
	return 0;
}


