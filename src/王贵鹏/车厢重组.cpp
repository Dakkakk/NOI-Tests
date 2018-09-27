#include<cstdio>
using namespace std;
int main(){
	int n;
	int a[10001];
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	int ans=0;
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
		if(a[i]>a[j]){
			int f=a[i];
			a[i]=a[j];
			a[j]=f;
			ans++;
		}
	printf("%d",ans);
}
