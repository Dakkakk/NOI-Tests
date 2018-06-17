#include<iostream>
#include<cstdio>
int a[30100],w,n,ans=0;
using namespace std;
int main()
{
	freopen("group.in","r",stdin);
    freopen("group.out","w",stdout);
 	cin>>w>>n;
	for (int i=1;i<=n;++i) cin>>a[i];
	for(int i=1;i<=n;++i)
	{
      int k=0;
      if(a[i]!=0)
      { 
       for(int j=i+1;j<=n;++j)
         if(a[j]<=w-a[i]&&a[j]>a[k]) k=j;
	   a[i]=0;
       a[k]=0;
       ans++;	 
      }      
    }
    cout<<ans;
	return 0;
}

