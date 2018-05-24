#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
struct Pos{
	int x,y;
};
struct Node{
	Pos pos;
	int step;
};
int direction[4][2]={
	{0,1},{1,0},{0,-1},{-1,0}
};
int n,m;
queue<Node>q;
bool mapB[51][51];
int map[51][51];
Pos target;
#define checkIsOutOfRange(x,y,m,n) (1<=x&&x<=n&&1<=y&&y<=m)
#define checkIsRock(x,y) (map[x][y]==0)
#define checkHasBeen(x,y) (mapB[x][y])
#define check(x,y,m,n) checkIsOutOfRange(x,y,m,n)&&!checkIsRock(x,y)&&!checkHasBeen(x,y)
int main(){
	freopen("in.txt","r",stdin);
	memset(mapB,false,sizeof(mapB));
	memset(map,0,sizeof(map));
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>map[i][j];
	Pos p;
	cin>>p.x>>p.y>>target.x>>target.y;
	Node node;
	node.pos=p;
	node.step=0;
	mapB[p.x][p.y]=true;
	int flag=0;
	q.push(node);
	while(!q.empty()){
		for(int i=0;i<4;i++){
			Pos tPos;
			tPos.x=q.front().pos.x+direction[i][0];
			tPos.y=q.front().pos.y+direction[i][1];
			if(check(tPos.x,tPos.y,m,n)){
				mapB[tPos.x][tPos.y]=true;
				Node nd;
				nd.pos=tPos;
				nd.step=q.front().step+1;
				q.push(nd);
			}
			if(tPos.x==target.x&&tPos.y==target.y){
				flag=1;
				break;
			}
		}
		
		if(flag==1)break;
		q.pop();
	}
	cout<<q.back().step;
	return 0;
}
