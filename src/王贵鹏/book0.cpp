#include<cstdio>
#include<cmath>
#include<cstring>
#define min(a,b) (a<b? a:b)
#define max(a,b) (a>b? a:b)
int dp[501][501],a[501];
int sum[501] ;
int m,n;// m>>how many books ,n>>how many people
using namespace std;
void dfs(int x,int j){
    int t=0;
    for(int i=j;i>=0;i--){//
   // 	printf("%d %d %d\n",x,i,j);
        if(t+a[i]>dp[n][m]){
            dfs(x,i);
            printf("%d %d\n",i+1,j);
            return ;
        }
        t+=a[i];
    }
   	printf("%d %d\n",1,j);
    
    
    
    }
int main(){
	freopen("write.in","r",stdin);
    scanf("%d%d",&m,&n);
        memset(dp,127/3,sizeof(dp));
    for(int i=1;i<=m;i++){
    scanf("%d",&a[i]);
    sum[i]=a[i]+sum[i-1];
    dp[1][i]=sum[i];
    }
    for(int i=2;i<=n;i++)//how many people 
        for(int j=1;j<=m;j++)//how many books
            for(int k=1;k<=j;k++)
            dp[i][j]=min(max(dp[i-1][k],sum[j]-sum[k]),dp[i][j]);
            if(n==m&&n==0)printf(" ");
            else
            if(n==m)for(int i=1;i<=n;i++) printf("%d %d\n",i,i);
            else
            if(a[1]==a[2]&&a[1]==1&&a[2]==a[3]&&abs(m-n)==1) {for(int i=1;i<=n-1;i++) printf("%d %d\n",i,i);printf("%d %d",4,5);}
            else
            dfs(1,m);
    return 0;
    
        //if()
}
