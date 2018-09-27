#include<cstdio>
#include<iostream>
#include<cstring>
#define max(a,b) (a>b?a:b)
using namespace std;
int n;
int a[101];
int b[101][101];
int c[101];
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d",&n);
	char aa;
	int f;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		while(aa=getchar()!='\n'&&scanf("%d",&f)!=EOF) {
			b[i][f]=1;
			f=0;
		}
	}
	for(int i=1;i<=n;i++)
		c[i]=a[i];
	int ans=0;
	for(int i=n;i>=1;i--){
		int max1=0;
		for(int j=i+1;j<=n;j++)
			if(b[i][j]==1)
			max1=max(c[j],max1);
		c[i]=max1+a[i];
	}	
		for(int i=1;i<=n;i++)
		ans=max(ans,c[i]);
		printf("%d",ans);	
}
