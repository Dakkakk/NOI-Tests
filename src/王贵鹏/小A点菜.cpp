#include<cstdio>
#include<cstring>
using namespace std;
int money,n;
int a[101],dp[10001];
int main(){
	//��ͼ������֪ 1Ԫ�ķ���+0Ϊ2Ԫ�ķ����� 3Ԫ�ķ���Ϊ��Ԫ�ķ�����һԪ�ķ����� 
����	freopen("in.in","r",stdin);
	memset(dp,0,sizeof(dp));
	dp[0]=1;//money=a[i]
	scanf("%d%d",&n,&money);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		for(int j=money;j>=a[i];j--)
		dp[j]+=dp[j-a[i]];
		printf("%d",dp[money]);
}
