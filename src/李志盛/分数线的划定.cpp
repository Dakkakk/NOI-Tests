#include<cstdio>
#include<cstring>
using namespace std;
int x,t,n,m,a[5001],b[10000],bz=1,temp1,temp2,ans=0;
int main()
{
	freopen("a.in","r",stdin);
	freopen("a","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
	  {
	  scanf("%d%d",&a[i],&x);
	  t=a[i];b[t]=x;
	//  printf("%d %d",a[i],b[a[i]]);
     }
	int k=1;  
	while(bz)
	{
		bz=0;
		for(int i=1;i<=n-k;++i)
		  {
		  	if(b[a[i]]<b[a[i+1]])
		     {
		     	temp1=a[i];temp2=b[a[i]];
		     	a[i]=a[i+1];b[a[i]]=b[a[i+1]];
		     	a[i+1]=temp1;b[a[i+1]]=temp2;
		     	bz=1;
			 } 
		  }
		++k;  
	}
	for(int i=1;i<n;++i)
	  {
	  	x=a[i];t=a[i+1];
	  	if(b[x]==b[t]&&a[i]>a[i+1])
	  	  {
	  	  	temp1=a[i];
	  	  	a[i]=a[i+1];
	  	  	a[i+1]=temp1;
	  	  }
	  }
	m=m*3/2;
	int swap=b[a[m]];
	k=1;
	while(b[a[k]]>=swap)
	  {
	  	ans++;++k;
	  }
	printf("%d %d\n",swap,ans);  
	for(int i=1;i<=ans;++i)
	  {
	   printf("%d %d\n",a[i],b[a[i]]);
      }
	return 0;      
}
