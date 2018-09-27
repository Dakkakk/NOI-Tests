#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;
int n,f[200050],flag[200050],ans=1000000000,du[200050];

void dfs(int ti,int s,int l) {
	if (ti==s&&l) {                               //如果回到开始说明连成了环
		ans=min(ans,l);
		return;
	}
	if (!flag[f[ti]]) {
		flag[f[ti]]=1;                                //标记
		dfs(f[ti],s,l+1);
	}
}
void rmove(int ti) {                               
//删除ti
	flag[ti]=1;                                    
	//标记
	du[f[ti]]--;                                    
	//ti的下一个人的入度减一
	if (du[f[ti]]<=0&&!flag[f[ti]]) 
		rmove(f[ti]);
}
int main() {                      //du[i]为第 i 个人的入度
	int i;
	freopen("cc.in","r",stdin);
	cin>>n;
	for (i=1; i<=n; i++) {
		cin>>f[i];
		du[f[i]]++;
	}
	for (i=1; i<=n; i++) {
		if (!du[i]&&!flag[i]) rmove(i);            
		//如果 i 的入度为 0 且还未被删除，则删除i
	}
//	for(int i=1;i<=n;i++)
//		if(du[i]==0)
//			du[f[i]]--,f[i]=0;
	for (i=1; i<=n; i++) {
		if (!flag[i]) {                               //如果i还未搜过且未被删除，则从i开始搜索
			dfs(i,i,0);
		}
	}
	printf("%d",ans);
	return 0;
}
