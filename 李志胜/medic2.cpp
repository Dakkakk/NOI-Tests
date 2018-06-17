#include<cstdio>
using namespace std;
struct m
{int t,p;} m[101];
int ti,n,ans=0;
void dfs(int k,int tt,int tp)
{
	if(k>n)
	  {
	  	if(tt<=ti&&ans<tp)
	  	  ans=tp;
	  	return;  
	  }

	  	dfs(k+1,tt+m[k].t,tp+m[k].p);

	  dfs(k+1,tt,tp);  
}
int main()
{
	freopen("medic.in","r",stdin);
	freopen("medic.out","w",stdout);
	scanf("%d%d",&ti,&n);
	for(int i=1;i<=n;++i)
	  scanf("%d%d",&m[i].t,&m[i].p);
	dfs(1,0,0);
	printf("%d",ans);
	return 0;  
}
