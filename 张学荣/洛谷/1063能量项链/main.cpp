#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
#define mx(a,b) ((a>b)?a:b)
#define max(a,b,c) mx(a,mx(b,c))
#undef mx(a,b)
using namespace std;
struct num{
	int start,end;
}nums[101];
int n;
int val[202][202];//[i,j]'s max value
int main(){
	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&nums[i].start);
		nums[i-1].end=nums[i].start;
	}
	memset(val,0,sizeof val);
	nums[n].end=nums[1].start;
	for(int i=2*n-1;i>=1;i--){
		for(int j=i+1;j<=2*n;j++){//p：得到第i个num的参数 
			val[i][j]=max(val[i][j],,)
		}
	}
	return 0;
}
