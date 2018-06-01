#include<cstdio>
#include<algorithm>
using namespace std;
long long a[10001],sum=0;
int n;
void swap(int x)
{
	int j=x+1;
	while(a[x]>a[j])
	  {
	  	a[j-1]=a[j];
	  	++j;
	  }
	a[j-1]=a[x];
	return;  
}
int main()
{
//	freopen("a.in","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	  scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=2;i<=n;++i)
	  {
	  	a[i]+=a[i-1];
	  	sum+=a[i];
	  	swap(i);
	  }  
	printf("%lld",sum);
	return 0;  
}
