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
int timer=0;//���㻻��ɫ�Ĵ��� 
int bestChoise=0xffff;
bool check(int index){
	for(int i=0;i<rects[index].signD;i++)
		if(!rects[rects[index].dependence[i]].colored)
			return false;
	return true;
}
void dfs(int hasPainted,int panColor){
	if(hasPainted>=n)//��hasPainted����n��˵�����������о��� 
		bestChoise=min(bestChoise,timer);
	else
		for(int i=0;i<n;i++){
			if(!rects[i].colored&&check(i)){//���i����Ϳɫ 
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
	for(int i=0;i<n;i++){//����i��������˭ 
		for(int j=0;j<n;j++){//����j�ڲ���i���� 
			//   i��x0��x1��j����          �Ⱥ�ȡ����                                                         ��ǰj�����Լ� 
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
