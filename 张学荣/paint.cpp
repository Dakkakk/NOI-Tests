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
///////////////////////////////////
bool check(int index){
	Rect r=rects[index];
	for(int i=0;i<r.signD;i++){
		Rect rect=rects[r.dependence[i]];
		if(!rect.colored)
			return false;
	}
	return true;
}
////////////////////////////////////
int panColor=0;//当前pan的颜色 
int lastColor;
int timer=0;//计数器，计算换颜色的次数 
void draw(int index){
	
}
////////////////////////////////////
int bestChoise=0xffffff;
/////////////////////////////////
//int debug1[20];
bool ttt=true;
void dfs(int hasPainted){
	if(hasPainted>=n){//当hasPainted等于n，说明遍历完所有矩形 
		bestChoise=min(bestChoise,timer);
		return;
	}
	for(int i=0;i<n;i++){
		
		if(!rects[i].colored&&check(i)){//如果i可以涂色 
			lastColor=panColor;
			if(rects[i].color!=panColor)
			{
				panColor=rects[i].color;
				timer++;
			}
			rects[i].colored=true;
//			debug1[hasPainted]=i;
			dfs(hasPainted+1);
			if(rects[i].color!=panColor)
			{
				panColor=lastColor;
				timer--;
			}
			rects[i].colored=false;
//			debug1[hasPainted]=0;
		}
	}
}
///////////////////////////////////
int main(){
	freopen("paint.in","r",stdin);
		freopen("paint.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		int a,b,c,d,e;
		cin>>a>>b>>c>>d>>e;
		rects[i].	x0=b;
		rects[i].	y0=a;
		rects[i].	x1=d;
		rects[i].	y1=c;
		rects[i].color=e;
		rects[i].signD=0;
		rects[i].colored=false;
	}
	for(int i=0;i<n;i++){//查找i的上面有谁 
		for(int j=0;j<n;j++){//看看j在不在i上面 
			//   i的x0或x1在j下面          等号取极限                                                         当前j不是自己 
			if(rects[i].y0==rects[j].y1&&( (rects[j].x0<=rects[i].x0&&rects[j].x1>rects[i].x0)||(rects[j].x0<rects[i].x1&&rects[i].x1<=rects[j].x1) )&&i!=j){
				rects[i].dependence[rects[i].signD]=j;
				rects[i].signD++;
			}
		}
	}
	dfs(0);
	cout<<bestChoise;
	return 0;
}
