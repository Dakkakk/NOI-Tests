#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
using namespace std;
struct pos{
	int x,y;
};
queue<pos>q;
int n,m;
int map[401][401];
bool mapb[401][401];
int direction[8][2]={
	{1,2},{1,-2},{-1,2},{-1,-2},
	{2,-1},{2,1},{-2,1},{-2,-1},
};
bool check(pos p){
	if(1<=p.x&&p.x<=n&&1<=p.y&&p.y<=m&&!mapb[p.x][p.y])
		return true;
	return false;
}
void bfs(){
	while(!q.empty()){
		pos p=q.front();
		for(int i=0;i<8;i++){
			pos tp;
			tp.x=p.x+direction[i][0];
			tp.y=p.y+direction[i][1];
			if(check(tp)){
				q.push(tp);
				map[tp.x][tp.y]=map[p.x][p.y]+1;
				mapb[tp.x][tp.y]=true;
			}
		}
		q.pop();
	}
}
int main(){
	memset(map,-1,sizeof(map));
	memset(mapb,false,sizeof(mapb));
	cin>>n>>m;
	pos p;
	cin>>p.x>>p.y;//可能导致错误,反转
	map[p.x][p.y]=0;
	mapb[p.x][p.y]=true;
	q.push(p);
	bfs();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			printf("%-5d",map[i][j]);
		}
		cout<<'\n';
	}
	return 0;
}

