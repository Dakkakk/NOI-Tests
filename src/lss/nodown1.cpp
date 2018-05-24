#include<iostream> 
using namespace std; 
int main() 
{ 
    int n,dp[5001]={0},a[5001]={0},max,best=0;
    cin>>n; 
    for(int i=1;i<=n;i++) 
        cin>>a[i]; 
    dp[1]=1; 
    for(int i=2;i<=n;i++) 
        { 
max=1; 
           for(int j=1;j<=i-1;j++) 
             if(a[j]<=a[i]) 
               if(dp[j]>=max) max=dp[j]+1; 
               dp[i]=max; 
        } 
    for(int i=1;i<=n;i++) 
        if(dp[i]>best) best=dp[i]; 
    cout<<best<<endl; 
}

