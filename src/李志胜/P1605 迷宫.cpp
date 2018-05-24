#include<cstdio>
using namespace std;
int b[6][6]={0},a[2][2],t,n,m,ans=0;
void dfs(int x,int y){
	if(x==a[1][0]&&y==a[1][1]){
		ans++;
		return;
	}
	b[x][y]=1;
	if(x>1&&!b[x-1][y]) dfs(x-1,y);
	if(x<n&&!b[x+1][y]) dfs(x+1,y);
	if(y>1&&!b[x][y-1]) dfs(x,y-1);
	if(y<m&&!b[x][y+1]) dfs(x,y+1);
	b[x][y]=0;
	return; 
}
int main(){
	scanf("%d%d%d%d%d%d%d",&n,&m,&t,&a[0][0],&a[0][1],&a[1][0],&a[1][1]);
	for(int i=1;i<=t;++i){
		int x,y;
		scanf("%d%d",&x,&y);
		b[x][y]=1;
	}
	dfs(a[0][0],a[0][1]);
	printf("%d",ans);
	return 0;
}
