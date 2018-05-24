#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
struct Rect{
	int x0,y0;//左上角 
	int x1,y1;//右下角 
	int color;
	int dependence[16];//该矩形上面的矩形的编号 
	int signD;//已储存的矩形数 
	bool colored;
}rects[16];
int n;
int timer=0;//计算换颜色的次数 
int bestChoise=0xffff;
bool check(int index){
	for(int i=0;i<rects[index].signD;i++)
		if(!rects[rects[index].dependence[i]].colored)
			return false;
	return true;
}
void dfs(int hasPainted,int panColor){
	if(hasPainted>=n)//当hasPainted等于n，说明遍历完所有矩形 
		bestChoise=min(bestChoise,timer);
	else
		for(int i=0;i<n;i++){
			if(!rects[i].colored&&check(i)){//如果i可以涂色 
				if(rects[i].color!=panColor)
					timer++;
				rects[i].colored=true;
				dfs(hasPainted+1,rects[i].color);
				if(rects[i].color!=panColor)
					timer--;
				rects[i].colored=false;
			}
		}
}
int main(){
	freopen("test.in","r",stdin);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>rects[i].y0>>rects[i].x0>>rects[i].y1>>rects[i].x1>>rects[i].color;
		rects[i].signD=0;
		rects[i].colored=false;
	}
	for(int i=0;i<n;i++){//查找i的上面有谁 
		for(int j=0;j<n;j++){//看看j在不在i上面 
			//   i的x0或x1在j下面          等号取极限                                                         当前j不是自己 
			if(rects[i].y0==rects[j].y1&&( (rects[j].x0<=rects[i].x0&&rects[i].x0<rects[j].x1)||(rects[j].x0<rects[i].x1&&rects[i].x1<=rects[j].x1) )&&i!=j){
				rects[i].dependence[rects[i].signD]=j;
				rects[i].signD++;
			}
		}
	}
	dfs(0,0xff);
	cout<<bestChoise;
	return 0;
}
