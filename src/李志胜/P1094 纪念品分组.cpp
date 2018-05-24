#include<cstdio>
#include<algorithm>
using namespace std;
int w,n,s[30001],ans=0,tail;
void swap(int a)
{
	for(int i=a;i<tail;++i)
	s[i]=s[i+1];
	return;
}
int main()
{
//	freopen("b.in","r",stdin);
	scanf("%d%d",&w,&n);
	for(int i=1;i<=n;++i)
	  scanf("%d",&s[i]);
	sort(s+1,s+n+1);
	int k=n,j=1,x;tail=n;
	while(k>0)
	{
		x=s[j];
		for(int i=tail;i>j;--i)
		if(x+s[i]<=w)
		{
			k--;swap(i);tail--;break;
		}
		++j;k--;ans++;
	}
	printf("%d",ans);
	return 0;  
}
