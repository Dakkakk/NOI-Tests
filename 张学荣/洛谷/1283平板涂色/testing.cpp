#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
struct Point{
	int x,y;
};
struct Rect{
	Point leftup;//���Ͻ� 
	Point rightdown;//���½� 
	int color;
	int dependence[16];//�þ�������ľ��εı�� 
	int signD;//�Ѵ���ľ����� 
	bool colored;
}rects[16];
int n,painted[16];

void dfs(){
	
}

int main(){
	freopen("test.in","r",stdin);
	cin>>n;
	for(int i=0;i<n;i++){
		int a,b,c,d,e;
		cin>>a>>b>>c>>d>>e;
		rects[i].leftup.x=b;
		rects[i].leftup.y=a;
		rects[i].rightdown.x=d;
		rects[i].rightdown.y=c;
		rects[i].color=e;
		rects[i].signD=0;
		rects[i].colored=false;
	}
	for(int i=0;i<n;i++){//����i��������˭ 
		for(int j=0;j<n;j++){//����j�ڲ���i���� 
			//   i��x0��x1��j����          �Ⱥ�ȡ����                                                         ��ǰj�����Լ� 
			if(rects[i].leftup.y==rects[j].rightdown.y&&( (rects[j].leftup.x<=rects[i].leftup.x&&rects[i].leftup.x<rects[j].rightdown.x)||(rects[j].leftup.x<rects[i].rightdown.x&&rects[i].rightdown.x<=rects[j].rightdown.x) )&&i!=j){
				rects[i].dependence[rects[i].signD]=j;
				rects[i].signD++;
			}
		}
	}
	return 0;
}
