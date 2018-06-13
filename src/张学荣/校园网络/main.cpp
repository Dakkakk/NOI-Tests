#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
int n;
int map[100][100];
int main(){
	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&map[i][j]);
		}
	}
	
	return 0;
}
