#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
int m,n;
int map[82][82];
/*
	map[i][0]第i行前指针
	map[i][81]第i行后指针 
*/
long long dp[81][81];
int main(){
	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&map[i][j]);
	for(int i=1;i<=m;i++){//第i行 
		for(int j=1;j<=n;j++){//第j次取数 
			dp[i][j]=
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			
		}
		
	}
	return 0;
}
