#include<algorithm>
#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;
int n,m;
struct ppp {
	int x1,x2,time;
} path[100001];
bool cmp(ppp a,ppp b) {
	return a.time<b.time;
}
int f[100001];
int F(int x) {
	if(f[x]==x)
		return x;
	return f[x]=F(f[x]);
}
void cbine(int x,int y) {
	if(f[x]!=x)
		f[y]=F(x);
	else
		f[x]=F(y);
}
bool is(int x,int y) {
	return F(x)==F(y);
}

int main() {
	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1; i<=m; i++)
		scanf("%d%d%d",&path[i].x1,&path[i].x2,&path[i].time);
	sort(path+1,path+m,&cmp);
	for(int i=1; i<=n; i++)
		f[i]=i;
	int ctime=path[1].time;
	cbine(path[1].x1,path[1].x2);
	for(int i=2; i<=m; i++)
		cbine(path[i].x1,path[i].x2);
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			if(i!=j&&!is(i,j))
				ctime=-1;
	printf("%d",ctime);

	return 0;
}
