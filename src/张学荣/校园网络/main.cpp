#include<algorithm>
#include<cstdio>
#include<cmath>
#define min(x,y) (x<y?x:y)
using namespace std;
int n;
int map[100][100];
int main(){
	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	memset(map,127/3,sizeof map);
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&map[i][j]);
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
				map[j][k]=min(map[j][k],map[j][i]+map[i][k]);
	
	
	return 0;
}
