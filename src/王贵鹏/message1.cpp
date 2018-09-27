#include<cstdio>
using namespace std;
int in[2501],out[2501],map[2501][2501],boo[2501],x[2501];
int n,ans;
void dfs(int i,int j){
	if(map[i][j]==1){
		boo[j]++;
		if(boo[j]==2)
			return;
		ans++;
		printf("%d %d ",i,j);
		dfs(j,x[j]);
	}
	
}
int main(){
	freopen("message.in","r",stdin);
	freopen("message.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&x[i]);
		in[x[i]]++;
		out[i]++;
		map[i][x[i]]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
		printf("%d ",map[i][j]);
	printf("\n");
	}
	for(int i=1;i<=n;i++)
		if(in[i]==0||out[i]==0){
			for(int ii=1;ii<=n;ii++)
				if(map[i][ii]==1){
					map[i][ii]=0;
					in[ii]--;
					out[i]--;
				}
		}
	dfs(1,x[1]);
	printf("%d\n",ans);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
		printf("%d ",map[i][j]);
	printf("\n");
	}
}
