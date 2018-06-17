#include<iostream>
using namespace std;
int a[11],n;
int main()
{
    freopen("busses.in","r",stdin);
    freopen("busses.out","w",stdout);
	for(int i=1;i<=10;++i)
		cin>>a[i];
	cin>>n;
	int dp[n];dp[0]=0;
	for(int j=1;j<=n;++j)
	{
	        dp[j]=99999999;
			for(int i=1;i<=10;++i)
	{
		
		if(j>=i)
		if(dp[j-i]+a[i]<dp[j])dp[j]=dp[j-i]+a[i];
	}
	}
	cout<<dp[n];
	return 0;
}
