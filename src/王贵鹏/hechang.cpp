#include<cstdio>
#define max(a,b) (a>b? a:b)
using namespace std;
int n,a[105],f[2][105],ans;
int main(){
	freopen("write.in","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) 
		scanf("%d",&a[i]);
    a[0]=0;
    for(int i=1;i<=n;i++) 
    	for(int j=0;j<i;j++) 
		if(a[i]>a[j]) 
		f[0][i]=max(f[0][i],f[0][j]+1);
    a[n+1]=0;
    for(int i=n;i;i--)
    	for(int j=n+1;j>i;j--) 
		if(a[i]>a[j])
	 	f[1][i]=max(f[1][i],f[1][j]+1);
    for(int i=1;i<=n;i++)
		 ans=max(f[0][i]+f[1][i]-1,ans);
    printf("%d",n-ans);
    return 0;
}
