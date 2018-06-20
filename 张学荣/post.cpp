#include<cstdio>
#include<cstring>
#include<algorithm>
//给定一个序列,假设我们要建一个邮局,那么一定是在这个序列的中点,所以我们可以先预处理出序列区间[l,r]之间建立
//一个邮局的最短距离和w[l][r],然后用dp[i][j]表示到i个村庄建立j个邮局的最短距离和,那么就有状态转移方程:
using namespace std;
int v[301][301],t[301][301];
int vpos[301];
int n,m;
int main(){
	freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&vpos[i]);
	for()
	return 0;
}

