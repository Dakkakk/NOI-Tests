#include<cstdio>
#include<algorithm>
using namespace std;
int n,ans=0;
struct data{
	int a;
	int b;
}m[1000001];
int comp(data x,data y)
{
	return x.b<y.b;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	scanf("%d%d",&m[i].a,&m[i].b);
	sort(m+1,m+n+1,comp);
	int t=m[1].b;ans++;
	for(int i=2;i<=n;++i)
		if(m[i].a>=t)
		{
			ans++;
			t=m[i].b;
		}
	printf("%d",ans);
	return 0;	
}
