#include<cstdio>
#include<iostream>
using namespace std;
const int maxn=10000;
struct player{
	int x,y;
	int w;
}pls[maxn];
int n;
int main(){
	cin.sync_with_stdio(0);
	freopen("ball.in","r",stdin);
//	freopen("ball.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>pls[i].w;
	for(int i=1;i<=n;i++)
		cin>>pls[i].x>>pls[i].y;
		
	return 0;
}
