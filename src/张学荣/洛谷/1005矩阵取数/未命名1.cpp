#include <algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
#include"test.hpp"
using namespace std;

num dp[81][81];
int nums[81];
int n;
#define p(i,j,n) (nums[i-1]*pow(2,n-j+i))
int main(){
	freopen("t.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&nums[i]);
	for(int i=1;i<=n;i++){
		for(int j=n;j>=i;j--){
			//dp[i][j]为剩余[i,j]区间未计算时的已计算的数的最大值 
			num n,m;
			n=n.add(max(dp[i-1][j])).add(p(i,j,n));
			m=m.add(dp[i][j+1]).add(p(i,j,n));
			dp[i][j]=max(n,m);
		}
		dp[0][0]=max(dp[0][0],dp[i][i]+nums[i]*pow(2,n));
	}
	printf("%d",dp[0][0]);
	return 0;
}

