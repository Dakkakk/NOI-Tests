#include<iostream>
#include<cstdio>
#define min(a,b) (a<b?a:b)
using namespace std;
//             ���
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
	flag[target]=1;//��ǣ�����
	du[f[target]]--;//��һ�ڵ����--
	//��һ�ڵ����Ϊ0��δ����ǣ���ôɾ������ 
	//                �ѱ�ǵĲ����ٱ����
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
		if(!du[i]&&!flag[i])//i�����Ϊ0����δ��� 
			rm(i);
	for(int i=1; i<=n; i++)
		if(!flag[i])
			flag[i]=1,dfs(i,f[i],1);
	cout<<mini;
	return 0;
}
