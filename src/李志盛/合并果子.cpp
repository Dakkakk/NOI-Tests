#include<cstdio>
#include<queue>
using namespace std;
priority_queue<long long>a;
long long sum=0;
int n,x,t;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	  {
	    scanf("%d",&x);
		a.push(-x);	
	  }
	for(int i=1;i<n;++i)
	  {
	  	t=a.top();
	  	a.pop();
	  	t+=a.top();
	  	a.pop();
	  	sum+=-t;
	  	a.push(t);
	  }  
	printf("%lld",sum);
	return 0;  
}
