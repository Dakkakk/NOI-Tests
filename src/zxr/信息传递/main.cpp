#include<iostream>
#include<cstdio>
#define min(a,b) (a<b?a:b)
using namespace std;
//             入度
int f[200001],du[200001];
int flag[200001];
int n,mini=0xffffff;

void dfs(int sti,int nowi,int l) {
	if(nowi==sti) {
		//loop;
		mini=min(mini,l);
		return;
	}
	if(!flag[nowi]) {
		flag[nowi]=1;
		dfs(sti,f[nowi],l+1);
	}
}
void rm(int target) {
	flag[target]=1;//标记，不搜
	du[f[target]]--;//下一节点入度--
	//下一节点入度为0且未被标记，那么删除它吧 
	//                已标记的不用再标记了
	if(du[f[target]]<=0&&!flag[f[target]])
		rm(f[target]);
}
int main() {
	freopen("cc.in","r",stdin);
	cin.sync_with_stdio(0);
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>f[i];
		du[f[i]]++;
	}
	for(int i=1; i<=n; i++)
		if(!du[i]&&!flag[i])//i的入度为0，且未标记 
			rm(i);
	for(int i=1; i<=n; i++)
		if(!flag[i])
			flag[i]=1,dfs(i,f[i],1);
	cout<<mini;
	return 0;
}
