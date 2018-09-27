#include<cstdio>
#include<algorithm>
using namespace std;
struct aa{
	int num,ii;
}c[20001];
bool cmp(aa a,aa b){
	if(a.num==b.num) return a.ii<b.ii;
	return a.num>b.num;
}
int a[12];
int n,k;
int main(){
//	freopen("in.in","r",stdin);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=10;i++)
	scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
	scanf("%d",&c[i].num);
	c[i].ii=i;
	}
	sort(c+1,c+n+1,cmp);
	for(int i=1;i<=n;i++)
		c[i].num+=a[(i-1)%10+1];
	sort(c+1,c+n+1,cmp);
	for(int i=1;i<=k;i++)
	printf("%d ",c[i].ii);
}
