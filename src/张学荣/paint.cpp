#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
struct Rect{
	int x0,y0;//���Ͻ� 
	int x1,y1;//���½� 
	int color;
	int dependence[16];//�þ�������ľ��εı�� 
	int signD;//�Ѵ���ľ����� 
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
int panColor=0;//��ǰpan����ɫ 
int lastColor;
int timer=0;//�����������㻻��ɫ�Ĵ��� 
void draw(int index){
	
}
////////////////////////////////////
int bestChoise=0xffffff;
/////////////////////////////////
//int debug1[20];
bool ttt=true;
void dfs(int hasPainted){
	if(hasPainted>=n){//��hasPainted����n��˵�����������о��� 
		bestChoise=min(bestChoise,timer);
		return;
	}
	for(int i=0;i<n;i++){
		
		if(!rects[i].colored&&check(i)){//���i����Ϳɫ 
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
	for(int i=0;i<n;i++){//����i��������˭ 
		for(int j=0;j<n;j++){//����j�ڲ���i���� 
			//   i��x0��x1��j����          �Ⱥ�ȡ����                                                         ��ǰj�����Լ� 
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
