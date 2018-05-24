#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int fa[20001],n,a[20001];
int main()
{
	freopen("busses.in","r",stdin);
	freopen("busses.out","w",stdout);
	for(int i=1;i<=10;++i)
	  	{
	  	cin>>a[i];
	  	fa[i]=a[i];
	  }	
	cin>>n;  
	for(int i=11;i<=n;++i)
	  fa[i]=0x3f3f3f;
	for(int i=2;i<=n;++i)
	  for(int j=i-1;j>0;--j)
	    {
	    //	if(i<=19&&j<i/2)
	    //	  continue;
	    //	if(j<i-10)
	      //    continue;
	    	if(j>=i-10&&a[i-j]+fa[j]<fa[i])
	    	  fa[i]=fa[j]+a[i-j];    
	    //	cout<<i<<" "<<j<<" "<<fa[i]<<endl;  
	    }
	cout<<fa[n];
	return 0;	  
}
