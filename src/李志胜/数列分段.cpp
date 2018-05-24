#include<cstdio>
using namespace std;
long long n,m,a[100001],sum=0,t=0;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
	  {
	  	scanf("%d",&a[i]);
	  }
	int j=1;  
	for(int i=1;i<=n;++i)
	  {
	  	t+=a[i];
	  	if(t>m)
	  	  {
	  	  	t=a[i];
	  	  	sum++;
	  	  }
	  }
	printf("%d",sum+1);
	return 0;    
}

