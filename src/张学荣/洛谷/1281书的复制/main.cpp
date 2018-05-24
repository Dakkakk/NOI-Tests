#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
#define min(x,y) (x<y?x:y)
#define max(x,y) (x>y?x:y)
using namespace std;
int m,n;//book people
int book[501],dp[501][501];//dp[i][j]��ʾi���˳�j������Ҫ�ĸ���ʱ��min
//����ʱ��Ϊ��дҳ����������ȥ��ʱ�䡣
int t[501];//ǰi�����ҳ������ǰ׺��
#define maxPages (dp[n][m])
struct print{
	int a,b;
}pp[501];
int sign=1;
void work(int l,int r) { //��ӡ��ǰ���ұ߽��ڵĲ���
	int ss=0;
	for(int i=r; i>=l; i--) {
		if(ss+book[i]>dp[n][m]) {
			work(l,i);
			pp[sign].a=i+1;
			pp[sign].b=r;
			sign++;
			return ;
		}
		ss+=book[i];
	}
	pp[sign].a=1;
	pp[sign].b=r;
	sign++;
}
int main() {
	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	memset(dp,127/3,sizeof dp);
	scanf("%d%d",&m,&n);
	t[0]=0;
	for(int i=1; i<=m; i++) {
		scanf("%d",&book[i]);
		t[i]=t[i-1]+book[i];
		dp[1][i]=t[i];
	}
	for(int i=2; i<=n; i++) {
		for(int j=i; j<=m; j++) {
			for(int k=i; k<=j; k++) { //k�Ժ�ĸ���j���˳�
				dp[i][j]=min(dp[i][j],max(dp[i-1][k-1],t[j]-t[k-1]));
			}
		}
	}
	work(n,m);
	for(int i=1;i<sign;i++)
		printf("%d %d\n",pp[i].a,pp[i].b);
	return 0;
}
