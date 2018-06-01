#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,s[1004],a[1004],b[1004];
double sum=0,t=0;
void swap()
{
	sort(a+1,a+n+1);
	for(int i=1;i<n;++i)  
	  {
	  	t+=(double)a[i]/n; 
	  	sum+=t;
	  }
	return;  
}
int main()
{
//	freopen("a.in","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	  scanf("%d",&s[i]);
	memset(b,0,sizeof(b));  
	memcpy(a,s,sizeof(s));  
	swap();  
	for(int i=1;i<=n;++i)
	  for(int j=1;j<=n;++j)
	    if(s[j]==a[i]&&!b[j])
	      {
	      	printf("%d ",j);
	      	b[j]=1;
	      	break;
	      }
	printf("\n");      
	printf("%.2f",sum);
	return 0;  
}
