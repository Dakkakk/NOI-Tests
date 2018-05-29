#include<cstdio>
#define max(a,b) (a>b? a:b)
using namespace std;
int dp[31][31]={0},a[31],n,ans=0,find[31][31]={0};
void printer(int x,int y){
	int t=find[x][y];
	if(t!=0){
		printf("%d ",t);
		if(find[x][t-1]) printer(x,t-1);
		if(find[t+1][y]) printer(t+1,y);
	}
	return ;
}
int main(){
	freopen("write.in","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]),dp[i][i]=a[i],dp[i][i-1]=1,find[i][i]=i;//��ֹ��ʱ���ǵ� 
	for(int i=n;i>=1;i--)
		for(int j=i+1;j<=n;j++)
			for(int k=i;k<=j;k++){
			if(dp[i][j]<dp[i][k-1]*dp[k+1][j]+a[k])
				find[i][j]=k;//��¼kֵ�� 
			dp[i][j]=max(dp[i][j],dp[i][k-1]*dp[k+1][j]+a[k]);//k Ϊ����k-1 Ϊ���ӣ�k+1 Ϊ�Һ��ӣ� 
			ans=max(ans,dp[i][j]);
			}
	printf("%d\n",ans);
	printer(1,n);
}
