#include<cstdio>
#include<cstring>
#define min(a,b) (a<b? a:b)
using namespace std;
//int ;
int dp[101][101],a[101],n;//���� a[101],n,dp[101][101]ʽ���� 
int main(){
    freopen("mul.in","r",stdin);
   // int n;
   // freopen("mul.out","w",stdout);
    scanf("%d",&n);
    memset(dp,127/3,sizeof(dp));
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        dp[i][i]=dp[i][i+1]=0;//����ȡ�Լ����ܳ�//ȡ��һ����̫�٣� 
    } 
    for(int i=n-2;i>=1;i--)
        for(int j=i+1;j<=n;j++){
            for(int k=i;k<j;k++){
            	dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]+a[i]*a[k]*a[j]);
        	}
    	}
    printf("%d",dp[1][n]);
    return 0;
}
