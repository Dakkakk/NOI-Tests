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
	if (ti==s&&l) {                               //����ص���ʼ˵�������˻�
		ans=min(ans,l);
		return;
	}
	if (!flag[f[ti]]) {
		flag[f[ti]]=1;                                //���
		dfs(f[ti],s,l+1);
	}
}
void rmove(int ti) {                               
//ɾ��ti
	flag[ti]=1;                                    
	//���
	du[f[ti]]--;                                    
	//ti����һ���˵���ȼ�һ
	if (du[f[ti]]<=0&&!flag[f[ti]]) 
		rmove(f[ti]);
}
int main() {                      //du[i]Ϊ�� i ���˵����
	int i;
	freopen("cc.in","r",stdin);
	cin>>n;
	for (i=1; i<=n; i++) {
		cin>>f[i];
		du[f[i]]++;
	}
	for (i=1; i<=n; i++) {
		if (!du[i]&&!flag[i]) rmove(i);            
		//��� i �����Ϊ 0 �һ�δ��ɾ������ɾ��i
	}
//	for(int i=1;i<=n;i++)
//		if(du[i]==0)
//			du[f[i]]--,f[i]=0;
	for (i=1; i<=n; i++) {
		if (!flag[i]) {                               //���i��δ�ѹ���δ��ɾ�������i��ʼ����
			dfs(i,i,0);
		}
	}
	printf("%d",ans);
	return 0;
}
