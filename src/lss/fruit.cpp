#include<iostream>
#include<cstdio>
using namespace std;
int a[10010];
int n,i;
int ans;
int find(int x)
{
    int minx=0x7fffffff;
    int k;
    for(int i=x;i<=n;i++)
     {
       if (a[i]<minx)
         {
         k=i;
         minx=a[i];
         }
    }
    int t=a[x];
    a[x]=a[k];
    a[k]=t;
    return a[x];
}
int main()
{
    freopen("fruit.in","r",stdin);
    freopen("fruit.ans","w",stdout);
    cin>>n;
    for(i=1;i<=n;i++)
      cin>>a[i];
    find(1);
    find(2);
    for(i=2;i<=n;i++)
      {
      a[i]=a[i]+a[i-1];
      ans=ans+a[i];
      find(i);
      find(i+1);  
      }
    cout<<ans<<endl;
  
    return 0;      
}
