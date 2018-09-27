#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#define scan(a) scanf("%d",&a)
#define max(x,y) ((x>y)?x:y)
#define min(x,y) ((x<y)?x:y)
//#define max(a,b) (mx(a,b))
//#define min(a,b,c) (mn(a,mn(b,c)))
using namespace std;
int n;
int num[202];
int mindp[202][202];
int maxdp[202][202];
int main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	scan(n);
	for(int i=1;i<=n;i++){
		scan(num[i]);
		num[i+n]=num[i];
	}//Ç°×ººÍ 
	for(int i=1;i<=2*n;i++){
		num[i]+=num[i-1];
	}
//	memset(mindp,0x3f3f3f,sizeof(mindp));
	
	for(int i=n*2-1;i>=1;i--){
		for(int j=i+1;j<=2*n;j++){
			mindp[i][j]=0x3f3f3f;
			for(int k=i;k<=j-1;k++){
				mindp[i][j]=min(mindp[i][j],mindp[i][k]+mindp[k+1][j]+num[j]-num[i-1]);
				maxdp[i][j]=max(maxdp[i][j],maxdp[i][k]+maxdp[k+1][j]+num[j]-num[i-1]);
			}
		}
	}
	int max=-0x3f3f3f,min=0x3f3f3f;
	for(int i=1;i<=n-1;i++){
		max=max(max,maxdp[i][i+n-1]);
		min=min(min,mindp[i][i+n-1]);
	}
	printf("%d\n%d",min,max);
	return 0;
}
