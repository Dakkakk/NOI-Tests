#include<algorithm>
#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
struct bnum{
	int nn[100],l;
	bnum& operator =(const long long a){
		long long t=a;
		l=0;
		while(t>0){
			nn[l++]=t%10;
			t/=10;
		}
		return *this;
	}
	bnum& operator +=(const bnum a){
		
	}
}dp[21][21];
ostream&operator <<(ostream &o,const bnum b){
	
	return o;
}
int sx,sy,px,py;
int map[100][100];
int cant[8][2]={
	{-1,-2},{1,-2},{-2,-1},{-2,1},{-1,2},{1,2},{2,1},{2,-1},
};

int main(){
	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	cin>>sx>>sy>>px>>py;
	map[px][py]=-1;
	for(int i=0;i<8;i++){
		int x=px+cant[i][0],y=py+cant[i][1];
		if(0<=x&&0<=y)
			map[x][y]=-1;
	}
	dp[1][1]=1;
	for(int i=0;i<=sy;i++)
		for(int j=0;j<=sx;j++)
			if(map[i][j]!=-1){
				if(i!=0)
					dp[i][j]+=dp[i-1][j];
				if(j!=0)
					dp[i][j]+=dp[i][j-1];
			}
	cout<<dp[sx][sy];
	return 0;
}
