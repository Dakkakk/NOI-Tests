#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<queue>
using namespace std;
struct pos{
	int x,y;
};
int n;
int map[30][30];
bool mapb[30][30];
int dir[4][2]={
	{0,1},{0,-1},{1,0},{-1,0},
};
queue<pos>q;

int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			int t;
			cin>>t;
			if(t==1)
				map[i][j]=1;
			else
				map[i][j]=2;
			mapb[i][j]=false;
		}
	for(int i=0;i<n;i++){
		if(map[0][i]==2&&!mapb[0][i]){
			pos p;
			p.x=0;
			p.y=i;
			q.push(p);
			mapb[0][i]=true;
			map[0][i]=0;
		}if(map[n-1][i]==2&&!mapb[n-1][i]){
			pos p;
			p.x=n-1;
			p.y=i;
			q.push(p);
			mapb[n-1][i]=true;
			map[n-1][i]=0;
		}if(map[i][0]==2&&!mapb[i][0]){
			pos p;
			p.x=i;
			p.y=0;
			q.push(p);
			mapb[i][0]=true;
			map[i][0]=0;
		}if(map[i][n-1]==2&&!mapb[i][n-1]){
			pos p;
			p.x=i;
			p.y=n-1;
			q.push(p);
			mapb[i][n-1]=true;
			map[i][n-1]=0;
		}
	}
	while(!q.empty()){
		for(int i=0;i<4;i++){
			int tx=q.front().x+dir[i][0],ty=q.front().y+dir[i][1];
			if(0<=tx&&tx<n&&0<=ty&&ty<n&&!mapb[tx][ty]&&map[tx][ty]!=1){
				pos p;
				p.x=tx;
				p.y=ty;
				q.push(p);
				mapb[tx][ty]=true;
				map[tx][ty]=0;
			}
		}
		q.pop();
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf(map[i][j]+" ");
		}
		printf("\n");
	}
	return 0;
}

