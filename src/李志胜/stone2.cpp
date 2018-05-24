#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
int l,m,n,a[50001],c[50001],ans;
int main()
{
	freopen("stone.in","r",stdin);
	freopen("stone.out","w",stdout);
	scanf("%d%d%d",&l,&m,&n);
	ans=l;
	for(int i=1;i<=m;++i)
	  {
	  	scanf("%d",&a[i]);
	  }
	int mid=l,s=0;
	while(1)
	  {
	  	int t=0;s=0;c[0]=0;
	  	memcpy(c,a,sizeof(a));
	  	for(int i=1;i<=m;++i)
	  	  {
	  	  	if((c[i]-c[t])<mid)//Òª°áµÄ 
	  	  	  {
	  	  	  	c[i]=c[t];
	  	  	  	++t;++s;
	  	  	 // 	cout<<c[i]<<" "<<c[t]<<" "<<s<<endl;
	  	  	  }
	  	  	else
			  {
			  ++t;	
			  }	  
	  	  }
	  	if(s>n)
		  mid/=2;
		if(s<n)
		  mid=3*mid/2;    
	  	if(s==n)
         {ans=mid;
		   break;
		   }		 
	  } 
     printf("%d\n",ans);  
	 return 0;  
}
