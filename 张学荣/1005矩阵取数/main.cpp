#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
int m,n;
int map[82][82];
/*
	map[i][0]��i��ǰָ��
	map[i][81]��i�к�ָ�� 
*/
long long dp[81][81];
int main(){
	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&map[i][j]);
	for(int i=1;i<=m;i++){//��i�� 
		for(int j=1;j<=n;j++){//��j��ȡ�� 
			dp[i][j]=
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			
		}
		
	}
	return 0;
}
