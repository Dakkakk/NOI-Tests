#include<iostream>
#include <cstdio>
using namespace std;
int n,m,p,q,t=0;
int d[100005];
string s[100005];
int main()
{
    freopen("toy.in","r",stdin);
    freopen("toy.ans","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;++i)
    {
        cin>>d[i]>>s[i];
    }
    for(int i=0;i<m;++i)
    {
        cin>>p>>q;
        if ((d[t]==1&&p==0)||(d[t]==0&&p==1))       //À≥ ±’Î 
            t=(t+q)%n;
        else if ((d[t]==0&&p==0)||(d[t]==1&&p==1))  //ƒÊ ±’Î 
            t=(t-q+n)%n;        
    }
    cout<<s[t]<<endl; 
    return 0;
}
