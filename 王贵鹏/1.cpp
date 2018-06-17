#include<cstdio>
#include<cstring>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
using namespace std;
int s[202],dp1[202][202],dp2[202][202],a[202],m,amin=99999999,amax=0;
int main(){
	freopen("in.txt","r",stdin);
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d",&a[i]);
		a[m+i]=a[i];
	}
	for(int i=1;i<=2*m;i++)
		a[i]+=a[i-1];
		
	for(int i=2*m-1;i>0;i--)
		for(int j=i+1;j<=m*2;j++){
			dp1[i][j]=9999999;
			for(int k=i;k<=j-1;k++){
			dp1[i][j]=min(dp1[i][j],dp1[i][k]+dp1[k+1][j]+a[j]-a[i-1]);
			dp2[i][j]=max(dp2[i][j],dp2[i][k]+dp2[k+1][j]+a[j]-a[i-1]);
			}
		}
	for(int i=1;i<=m-1;i++){
		amin=min(amin,dp1[i][i+m-1]);
		amax=max(amax,dp2[i][i+m-1]);
	}
	printf("%d\n%d",amin,amax);
}	
