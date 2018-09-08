#include<cstdio>
#include<algorithm>
using namespace std;
int n,ans=1;
struct aa{
	int end,begin;
}c[1001];
bool cmp(aa a,aa b){
	return a.end<b.end;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d%d",&c[i].begin,&c[i].end);
	sort(c+1,c+n+1,cmp);
	int test=c[1].end;
	for(int i=1;i<=n;i++){
		if(test<=c[i].begin){
			ans++;
			test=c[i].end;
		}
	}
	printf("%d",ans);
}
