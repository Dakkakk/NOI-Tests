#include<cstdio>
using namespace std;
int triangle[1001][1001],n,dp[1001][2];
void change(){
	for(int i=1;i<=1000;i++)
	for(int j=1;j<=100;j++)
	triangle[i][j]=0;
}
int main(){
freopen("write.in","r",stdin);
	scanf("%d",&n);
	change();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
		scanf("%d",&triangle[i][j]);
	for(int i=2;i<=n;i++)
		for(int j=1;j<=i;j++)
		if(triangle[i-1][j-1]<triangle[i-1][j])
		triangle[i][j]=triangle[i][j]+triangle[i-1][j];
		else
		triangle[i][j]=triangle[i][j]+triangle[i-1][j-1];
		int x=0;
		for(int i=1;i<=n;i++)
		if(x<triangle[n][i])
		x=triangle[n][i];
		printf("%d",x);
}
