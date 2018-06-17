#include<cstdio>
#include<cstring>
using namespace std;
int a[5010],n,k;bool bz[1000001]={0};
int main()
{
	freopen("bed.in","r",stdin);
	freopen("bed.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	  scanf("%d",&a[i]);
    int s,ans=0,k,t=n-1;
    while(ans==0)
      {
      	++t;s=0;
      	memset(bz,0,sizeof(bz));
      	for(int i=0;i<n;++i)
      	  {
      	  	k=a[i]%t;
      	  	if(bz[k]==1)
      	  	  {
      	  	  	s=1;
      	  	  	break;
      	  	  }
      	  	bz[k]=1;	  
      	  }
      	if(!s)  
      	  ans=t;  
      }
	printf("%d",ans);
	return 0;       
}

