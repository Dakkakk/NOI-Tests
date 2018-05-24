#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int map[10][10];
int grids[4][4][10];//小九宫格 
int raw[10][10];//行 
int rank[10][10];//列 
int put[81][2];//未放置的点坐标 
bool putted[81];
int sign=0;//当前可以放的点的个数

//返回值a[0]表示可以放多少个 
int*getNumsCanPut(int x,int y){
	int nums[10];
	int t=1;
	for(int i=1;i<=9;i++){
		
	}
	return new int [10];
}
////////////////////////////////////////////////
int pastScore=0;
void dfs(int index){
    if(index==sign){
        int nowScore=0;
        for(int x=1;x<=9;x++){
            for(int y=1;y<=9;y++){
                nowScore+=(10-max(abs(x-5),abs(y-5)))*map[x][y];
            }
        }
        if(nowScore>pastScore){
            pastScore=max(pastScore,nowScore);
        }
        return ;
    }
    int choise=0;
//    for(int i=0;i<n;i++){
  //  	if(!putted[i]){
  //  		int past[2]=put[choise];
  //  		for(int i=1;)
//		}
//	}
    int x=put[choise][0],y=put[choise][1];
    for(int i=1;i<=9;i++){
        if(raw[x][i]==0&&rank[y][i]==0&&grids[(x+2)/3][(y+2)/3][i]==0){
            raw[x][i]=rank[y][i]=grids[(x+2)/3][(y+2)/3][i]=1;
            map[x][y]=i;
            dfs(index+1);
            raw[x][i]=rank[y][i]=grids[(x+2)/3][(y+2)/3][i]=0;
            map[x][y]=0;
        }
    }
}
int main(){
//	freopen("1074.txt","r",stdin);
    memset(grids,0,sizeof(grids));
    memset(raw,0,sizeof(raw));
    memset(rank,0,sizeof(rank));
    memset(put,0,sizeof(put));
    for(int x=1;x<=9;x++){
        for(int y=1;y<=9;y++){
            int tmp;
            cin>>tmp;
            map[x][y]=tmp;
            if(tmp==0){
                put[sign][0]=x;
                put[sign][1]=y;
                putted[sign]=false;
                sign++;
            }else//需要更新的点的坐标，值               放(1)或不放(0) 
                raw[x][tmp]=rank[y][tmp]=grids[(x+2)/3][(y+2)/3][tmp]=1;
        }
    }
    dfs(0);
    cout<<pastScore;
    return 0;
} 

