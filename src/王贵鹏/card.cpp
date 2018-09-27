#include<cstdio>
using namespace std;
int n,average;
int a[101];
int main(){
	//freopen("in.in","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		average+=a[i];
	average/=n;
	int l=0,f=0;
	for(int i=1;i<=n;i++)
		a[i]-=average;
	for(int i=1;i<=n;i++){
		if(a[i]==0)
			continue;	
		a[i+1]+=a[i];//change 
		l++;
	}
	printf("%d",l);
}
