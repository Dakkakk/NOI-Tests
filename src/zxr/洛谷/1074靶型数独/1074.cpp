#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int map[10][10];
int grids[4][4][10];//С�Ź���
int raw[10][10];//��
int rank[10][10];//��
int put[81][2];//δ���õĵ�����
int sign=0;//��ǰ���Էŵĵ�ĸ���
////////////////////////////////////////////////
int pastScore=0;
void dfs(int index) {
	if(index==sign) {
		int nowScore=0;
		for(int x=1; x<=9; x++) {
			for(int y=1; y<=9; y++) {
				nowScore+=(10-max(abs(x-5),abs(y-5)))*map[x][y];
			}
		}
		pastScore=max(pastScore,nowScore);
		return ;
	}
	int x=put[index][0],y=put[index][1];
		for(int i=9; i>=1; i--) {
			if(raw[x][i]==0&&rank[y][i]==0&&grids[(x+2)/3][(y+2)/3][i]==0) {
				raw[x][i]=rank[y][i]=grids[(x+2)/3][(y+2)/3][i]=1;
				map[x][y]=i;
				dfs(index+1);
				raw[x][i]=rank[y][i]=grids[(x+2)/3][(y+2)/3][i]=0;
				map[x][y]=0;
			}
		}
}
bool camp(int a[2],int b[2]) {
	return true;
}
int main() {
	freopen("1074.txt","r",stdin);
	cin.sync_with_stdio(0);
	memset(grids,0,sizeof(grids));
	memset(raw,0,sizeof(raw));
	memset(rank,0,sizeof(rank));
	memset(put,0,sizeof(put));
	for(int x=1; x<=9; x++) {
		for(int y=1; y<=9; y++) {
			int tmp;
			cin>>tmp;
			map[x][y]=tmp;
			if(tmp==0) {
				put[sign][0]=x;
				put[sign][1]=y;
				sign++;
			} else { //��Ҫ���µĵ�����ֵ꣬               ��(1)�򲻷�(0)
				raw[x][map[x][y]]=rank[y][map[x][y]]=grids[(x+2)/3][(y+2)/3][map[x][y]]=1;

			}
		}
	}
	dfs(0);
	cout<<((pastScore==0)?-1:pastScore);
	return 0;
}
