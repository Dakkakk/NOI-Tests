#include<cstdio>
#define max(a,b) (a>b? a:b)
using namespace std;
int n,m,a[110][110],dp[101][101],ans;
inline int dfs(int x,int y){
	if(dp[x][y]!=1) return dp[x][y];
	int b=0;
    if(x>=1&&y>=1&&x<=m&&y<=n&&a[x][y]>a[x+1][y])    b=max(b,(dfs(x+1,y)+1));
    if(x>=1&&y>=1&&x<=m&&y<=n&&a[x][y]>a[x][y+1])    b=max(b,(dfs(x,y+1)+1));
    if(x>=1&&y>=1&&x<=m&&y<=n&&a[x][y]>a[x-1][y])    b=max(b,(dfs(x-1,y)+1));
    if(x>=1&&y>=1&&x<=m&&y<=n&&a[x][y]>a[x][y-1])    b=max(b,(dfs(x,y-1)+1));
    dp[x][y]=max(dp[x][y],b); 
    return dp[x][y];
}
int main(){
//	freopen("write.in","r",stdin);
	scanf("%d%d",&m,&n);//m多少行，n多少列；
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
		scanf("%d",&a[i][j]),dp[i][j]=1;//输入表格	
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
		ans=max(ans,dfs(i,j)); //记忆化搜索
	printf("%d",ans);
	
}
