#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
#define min(x,y) (x<y?x:y)
#define max(x,y) (x>y?x:y)
using namespace std;
int bookN,peopleN;//book people
int book[501],dp[501][501];//dp[i][j]��ʾi���˳�j������Ҫ�ĸ���ʱ��min
//����ʱ��Ϊ��дҳ����������ȥ��ʱ�䡣
int t[501];//ǰi�����ҳ������ǰ׺��
int save[501][2];
int main() {
	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	memset(dp,127/3,sizeof dp);
	scanf("%d %d",&bookN,&peopleN);
	if(bookN==0||peopleN==0)
		return 0;
	t[0]=0;
	for(int i=1; i<=bookN; i++) {
		scanf("%d",&book[i]);
		t[i]=t[i-1]+book[i];
		dp[1][i]=t[i];
	}
	for(int i=2; i<=peopleN; i++) {
		for(int j=i; j<=bookN; j++) {
			for(int k=i; k<=j; k++) { //k�Ժ�ĸ���j���˳�
				dp[i][j]=min(dp[i][j],max(dp[i-1][k-1],t[j]-t[k-1]));
			}
		}
	}
	/////////////////////
	//unknow why,,under  copyfrom net
	save[peopleN][1]=save[peopleN][0]=bookN;
	for(int i=peopleN; i>0; i--) {
		while(save[i][0]>i-1 /*������i-1�����i-1����  */&& t[save[i][1]]-t[save[i][0]-1]<=dp[peopleN][bookN]) 
		//��ʱ�䳬����ʱ���˳�ѭ�� 
			save[i][0]--;
		save[i][0]++;//����һ�� 
		save[i-1][1]=save[i-1][0]=save[i][0]-1;//��һ��βָ��ָ����һ���� 
	}
	for(int i=1; i<=peopleN; i++)
		printf("%d %d\n",save[i][0],save[i][1]);
	return 0;
}
