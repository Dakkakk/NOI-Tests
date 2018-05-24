#include<iostream>
#include<cstdio>
using namespace std;
long long  jc(int x)
{	
  long long  s=1;
  for(int i=1;i<=x;++i)
    s=s*i;
   return s;  
}
int main()
{
  freopen("jc.in","r",stdin);
  freopen("jc.out","w",stdout);
  int n;
  cin>>n;
  cout<<jc(n);
  return 0; 
}


