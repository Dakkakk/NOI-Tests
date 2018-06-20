#include<cstdio>
#define max(a,b) (a>b?a:b)
#define getH(x,y) (map[x][y])
using namespace std;
int r,c;
int val[101][101];
int map[101][101];
int direction[4][2]={
	{0,1},{0,-1},{1,0},{-1,0},
};
inline int dfs(int x,int y) {
	if(val[x][y]!=1)
		return val[x][y];
	int tmp=1;
	for(int i=0;i<4;i++){
		int tx=x+direction[i][0],ty=y+direction[i][1];
		if(1<=tx&&tx<=r&&1<=ty&&ty<=c&&getH(x,y)<getH(tx,ty)){
			tmp=max(dfs(tx,ty)+1,tmp);
		}
	}
	val[x][y]=tmp;
	return val[x][y];
}
int main() {
	freopen("in.txt","r",stdin);
	scanf("%d%d",&r,&c);
	for(int i=1;i<=r;i++){
		for(int j=1;j<=c;j++){
			scanf("%d",&map[i][j]);
			val[i][j]=1;
		}
	}
	int max=0;
	for(int i=1;i<=r;i++){
		for(int j=1;j<=c;j++){
			max=max(max,dfs(i,j));
		}
	}
	printf("%d",max);
	return 0;
}

