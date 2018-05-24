#include<cstdio>
#include<iostream>
#include <cmath>
using namespace std;
int v,p,a[301],c[31],f[31][301],w[301][301];
int main(){
	scanf("%d%d",&v,&p);
	for(int i=1;i<=v;++i){
		scanf("%d",&a[i]);
//		f[0][i]=0;
	}
	for(int i=1;i<=p;++i)
	for(int j=1;j<=v;++j){
		f[i][j]=0x3f3f3f;
	}
	for(int i=1;i<=v;++i)
	for(int j=1;j<=v;++j){
		int r=(i+j)/2,t=0;
		for(int k=i;k<=j;++k) t+=abs(a[r]-a[k]);
		w[i][j]=t;
	}
	for(int i=1;i<=v;++i) f[1][i]=w[1][i];
	for(int i=2;i<=p;++i)
	for(int j=i;j<=v-p+i;++j)
	for(int k=i;k<=j;++k){
		if(f[i-1][k-1]+w[k][j]<f[i][j]){
			f[i][j]=f[i-1][k-1]+w[k][j];
			c[i]=(k+j)/2;
		}
	}
	printf("%d\n",f[p][v]);
	for(int i=1;i<=p;++i) printf("%d ",c[i]);
	return 0;
}

