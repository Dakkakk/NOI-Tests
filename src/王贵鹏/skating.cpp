#include<cstdio>
#define max(a,b) (a>b? a:b)
using namespace std;
int n,m,a[110][110],dp[101][101],ans,move[4][2]={
{1,0,},{-1,0,},{0,1,},{0,-1,},};
bool prove(int xx,int yy) {
	if(xx>=1&&xx<=m&&yy>=1&&yy<=n)
		return 1;
	return 0;
}
inline int dfs(int x,int y) {
	if(dp[x][y]!=1) return dp[x][y];
	for(int i=0; i<4; i++) {
		int xx=x+move[i][0];
		int yy=y+move[i][1];
		if(prove(xx,yy)&&a[x][y]>a[xx][yy])
		dp[x][y]=max(dfs(xx,yy)+1,dp[x][y]);//xx yy为到的点，xy原来的点，或，xxyy 原来的点，四周到中间的点； 
	}//后者代码： 在前需定义一个 aa=1，后再将xy周围点的值算出，遍历；
	//int aa;……< aa=max(a,dfs(xx,yy)+1); 
	return dp[x][y];
}

int main() {
	freopen("write.in","r",stdin);
	scanf("%d%d",&m,&n);//m多少行，n多少列；
	for(int i=1; i<=m; i++)
		for(int j=1; j<=n; j++)
			scanf("%d",&a[i][j]),dp[i][j]=1;//输入表格
	for(int i=1; i<=m; i++)
		for(int j=1; j<=n; j++)
			ans=max(ans,dfs(i,j)); //记忆化搜索
	printf("%d",ans);
}
