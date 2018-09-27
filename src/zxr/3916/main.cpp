#include<algorithm>
#include<cstdio>
#include<cmath>
#include<iostream>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
using namespace std;
int f[100001],n,m;
int reach[100001];
int fa(int x){
	reach[x]=max(f[x],x);
	if(f[x]==x)
		return x;
	return f[x]=fa(f[x]);
}
void inline joint(int from,int to){
	f[from]=to;
}
//void inline joint(int a,int b){
//	int mn=min(fa(a),fa(b)),mx=max(fa(a),fa(b));
//	if(mn!=mx)
//		f[mn]=mx;
//}

int main(){
	cin.sync_with_stdio(0);
	freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		f[i]=reach[i]=i;
	for(int j=1,a,b;j<=m;j++){
		cin>>a>>b;
		joint(a,b);
	}
	for(int i=1;i<=n;i++)
		fa(i);
	for(int i=1;i<=n;i++)
		cout<<reach[i]<<' ';
	return 0;
}
