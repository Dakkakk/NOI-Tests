#include<cstdio>
#include<algorithm>
using namespace std;
int a[30001];
int main()
{
	freopen("group.in","r",stdin);
	freopen("group.out","w",stdout);
	int w,n;
	scanf("%d%d",&w,&n);
	for(int i=1;i<=n;++i)
	  scanf("%d",&a[i]);
	sort(a+1,a+n+1);   
	int h=1,t=n,ans=0;
	while(h<=t)
	  {
	  	if(a[h]+a[t]<=w)
	  	  {
	  	//  	a[h]=0;
	  	//  	a[t]=0;
	  	  	++h;--t;
	  	  	ans+=1;

	  	  }
	  	else
		  {
		  //	a[t]=0;
		  	--t;
		  	ans+=1;

		  }    
	  }  
	printf("%d",ans);
	return 0;  
}
