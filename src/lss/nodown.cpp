#include<iostream> 
using namespace std; 
int main() 
{ 
    int n,a[5001]={0},f[5001]={0},max,best=0;
    cin>>n; 
    for(int i=1;i<=n;i++) 
        cin>>a[i]; 
    f[1]=1; 
    for(int i=2;i<=n;i++) 
        { 
            max=1; 
            for(int j=1;j<=i-1;j++) 
                if(a[j]<=a[i]) 
                    if(f[j]>=max) max=f[j]+1; 
                    f[i]=max; 
        } 
    for(int i=1;i<=n;i++) 
        if(f[i]>best) best=f[i]; 
    cout<<best<<endl;  
}
