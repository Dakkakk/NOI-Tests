#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
#define min(x,y) (x<y?x:y)
#define max(x,y) (x>y?x:y)
using namespace std;
int bookN,peopleN;//book people
int book[501],dp[501][501];//dp[i][j]表示i个人抄j本书需要的复制时间min
//复制时间为抄写页数最多的人用去的时间。
int t[501];//前i本书的页数，，前缀和
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
			for(int k=i; k<=j; k++) { //k以后的给第j个人抄
				dp[i][j]=min(dp[i][j],max(dp[i-1][k-1],t[j]-t[k-1]));
			}
		}
	}
	/////////////////////
	//unknow why,,under  copyfrom net
	save[peopleN][1]=save[peopleN][0]=bookN;
	for(int i=peopleN; i>0; i--) {
		while(save[i][0]>i-1 /*至少留i-1本书给i-1个人  */&& t[save[i][1]]-t[save[i][0]-1]<=dp[peopleN][bookN]) 
		//当时间超过的时候退出循环 
			save[i][0]--;
		save[i][0]++;//多算一个 
		save[i-1][1]=save[i-1][0]=save[i][0]-1;//下一项尾指针指向下一本书 
	}
	for(int i=1; i<=peopleN; i++)
		printf("%d %d\n",save[i][0],save[i][1]);
	return 0;
}
