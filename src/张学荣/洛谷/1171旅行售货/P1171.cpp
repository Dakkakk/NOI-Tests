#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
int n;
int dp[1100010][25];
int map[25][25];
int main() {
	cin>>n;
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= n; j ++)
			cin>>map[i][j];//�����ׯ�����
	memset(dp,63,sizeof(dp));
	dp[1][1] = 0;//״̬1��ʾ��ʱֻ��1�ŵ���ʹ�
	for(int i =0; i<=(1 << n/*��n����ׯ*/) -1; i++)
		for(int j=1; j<=n; j++)
			if( !( (1 << j-1) & i) )
				for(int k=1; k<=n; k++)
					if( ( (1 << k-1) & i) )
						dp[((1 << j-1) | i)][j] = min(dp[((1 << j-1) | i)][j],dp[i][k] + map[k][j]);//���Ĵ��룬������������
	int ans = 2147483640;
	for(int i=2; i<=n; i++) //����״̬(1<<n)-1��������ȫΪ1����Ѱ�ҵ�1��̵ĵ�
		ans=min(ans,dp[(1<<n)-1][i] + map[i][1]);
	cout<<ans;
	return 0;
}


