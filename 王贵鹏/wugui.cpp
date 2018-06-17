#include<cstdio>
#include<cstring>
#include<iostream>
//#define mx(a,b) (a>b?a:b)
//#define mmax(a,b,c,d,e) (mx(mx(mx(a,b),mx(c,d)),e))
using namespace std;
int n,m,dp[41][41][41][41],table[351],g[5];
int main(){
	freopen("write.in","r",stdin);
//	memset(dp,0,sizeof(dp));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&table[i]);
	int x;
	for(int i=1;i<=m;i++){
		scanf("%d",&x);
		g[x]++;
	}
	int r;
	dp[0][0][0][0]=table[1];
	for(int a=1;a<=g[1]+1;a++)
        for(int b=1;b<=g[2]+1;b++)
            for(int c=1;c<=g[3]+1;c++)
                for(int d=1;d<=g[4]+1;d++)
                {
                    r=1+(a-1)+(b-1)*2+(c-1)*3+(d-1)*4;
                    dp[a][b][c][d]=max(dp[a][b][c][d],dp[a-1][b][c][d]+table[r]);
                    dp[a][b][c][d]=max(dp[a][b][c][d],dp[a][b-1][c][d]+table[r]);
                    dp[a][b][c][d]=max(dp[a][b][c][d],dp[a][b][c-1][d]+table[r]);
                    dp[a][b][c][d]=max(dp[a][b][c][d],dp[a][b][c][d-1]+table[r]);
                }   
		printf("%d",dp[g[1]+1][g[2]+1][g[3]+1][g[4]+1]);
		return 0;
}
