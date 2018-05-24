#include<iostream>
using namespace std;
int a[11],s;
int dp[20002];
int main(){
	freopen("busses.in","r",stdin);
	freopen("busses.out","w",stdout);
	for(int i=1;i<=10;i++)
	cin>>a[i];
	cin>>s;
	for(int i=1;i<=s;i++){
		dp[i]=99999999;
		for(int j=1;j<=10;j++)
		if(i>=j)
		if(dp[i-j]+a[j]<dp[i])
		dp[i]=dp[i-j]+a[j];
	}cout<<dp[s];
	return 0;
}
