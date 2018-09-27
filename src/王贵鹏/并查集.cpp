#include<cstdio>
using namespace std;
int father[20001];
int m,n;
int find(int x){
	if(father[x]!=x) return father[x]=find(father[x]);
		return father[x];
}
int main(){
	//freopen("in.in","r",stdin);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		father[i]=i;
	int z,x,y;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&z,&x,&y);
		if(z==1)
			if(find(x)!=find(y)) father[find(y)]=find(x);;
		if(z==2){
			if(find(x)==find(y)) printf("Y\n");
			else printf("N\n");
		}
	}
}
