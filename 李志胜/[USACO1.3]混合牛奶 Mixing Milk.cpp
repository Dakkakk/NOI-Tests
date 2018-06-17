#include<cstdio>
using namespace std;
int n,m,price[5001],num[5001],bz=1,t,p;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
	  scanf("%d%d",&price[i],&num[i]);
	int k=1;  
	while(bz)
	{
		bz=0;
		for(int i=1;i<=m-k;++i)
		  {
		  	if(price[i]>price[i+1])
		  	  {
		  	  	t=price[i];p=num[i];
		  	  	price[i]=price[i+1];num[i]=num[i+1];
		  	  	price[i+1]=t;num[i+1]=p;
		  	  	bz=1;
		  	  }  
		  }
		++k;  
	}
	int sum=n,money=0,j=1,x; 
	while(sum>0)
	{
		if(num[j]<=sum)
		  {		
		    x=price[j]*num[j];
		  	sum-=num[j];
		  	money+=x;
		  }
		else
		  {
		  	money+=sum*price[j];
		  	sum=0;
		  }  
		++j;  
	} 
	printf("%d",money);
	return 0;
}
