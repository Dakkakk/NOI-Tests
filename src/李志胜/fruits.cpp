#include<cstdio>
using namespace std;
int a[10010],hold[5005],h=1;
void abc(int son,int tr)
{
	for(int i=tr;i>=1;--i)//tr表示用来排序的指针头; 
	  {
	  	if(son>hold[tr])
	  	  {
	  	  	hold[i+1]=hold[i];
	  	  }
	  	else
	  	{
		  hold[i+1]=son;
	      return; 
	    }
	    if(tr==0) hold[tr+1]=son;
		return;     
	  }
}
int main()
{
//	freopen("fruits.in","r",stdin);
//	freopen("fruits.out","w",stdout);
	int x;
	scanf("%d",&x);
	for(int i=1;i<=x;++i)
	  scanf("%d",&a[i]);
	int y;
	for(int i=1;i<x;++i)
	  for(int j=1;j<=x-i;++j)
	    if(a[j+1]<a[j])
		  {
		  	y=a[j];
		  	a[j]=a[j+1];
		  	a[j+1]=y;
		  }
	int mouse=3,ans=0,son;
	hold[1]=a[1]+a[2];
	for(int i=2;i<x;++i)
	  {
	  	if(a[mouse]>hold[h]&&h>1)
	  	  {
	  	  	son=a[h-1]+a[h];
	  	  	abc(son,h-2);
	  	  	ans+=son;
	  	  	h--;continue;
	  	  }
	  	if(a[mouse+1]>hold[h])
		  {
		  	son=a[mouse++]+hold[h];
		  	abc(son,h-1);
		  	ans+=son;
		  	continue;
		  }
		if(hold[h]>a[mouse+1])
		  {
		  	son=a[mouse]+a[mouse+1];
		  	abc(son,h);
		  	ans+=son;
		  	mouse+=2;
		  	h++;continue;
		  }
		if(mouse>x)
		  {
		  	son=a[h-1]+a[h];
	  	  	abc(son,h-2);
	  	  	ans+=son;
	  	  	h--;continue;
		  }        
	  }	
	printf("%d",ans);
	return 0;      
}
