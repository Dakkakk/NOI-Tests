#include<cstdio>
#define max(a,b) (a>b? a:b)
using namespace std;
int time,n;
int a[31],f[20001];
int main(){
	freopen("in.in","r",stdin);
	scanf("%d%d",&time,&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		for(int j=time;j>=a[i];j--)
			f[j]=max(f[j],f[j-a[i]]+a[i]);
	printf("%d",time-f[time]);
}
