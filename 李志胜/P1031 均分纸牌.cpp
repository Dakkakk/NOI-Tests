#include<cstdio>
#pragma GCC optimize(2)
using namespace std;
int n,m=0,a[101],ans=0,b[101],t,y,f=1;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		m+=a[i];
	}
	m/=n;
	for(int i=1;i<=n;++i)
	a[i]-=m;
	for(int i=1;i<=n;++i)
	{
		if(a[i]!=0){
			a[i+1]+=a[i];ans++;a[i]=0;
		}
	}
//	m/=n;int j=1;
//	for(int i=1;i<=n;++i)
//	if(a[i]>m) b[j++]=i;b[j]=n;
////	for(int i=1;i<j;++i) printf("%d ",b[i]);
////	printf("\n");
//	for(int i=1;i<j;++i)
//	{
//		t=a[b[i]]-m;y=0;
//		for(int k=f;k<b[i];++k)
//		y+=m-a[k];ans+=b[i]-f;
//		if(y<t){
//			t-=y;
//			for(int k=b[i]+1;k<=b[i+1];++k){
//				if(t<m-a[k]){
//					ans++;f=k;break;
//				}
//				else{
//					ans+=1;t-=(m-a[k]);a[k]=m;
//				}
//				if(t==0) {
//					int yy=f;
//					for(int jj=k+1;jj<=b[i+1];++jj)
//					if(a[jj]<m) f=jj;if(f==yy) f=b[i+1];
//					break;
//				};
//			}
//		}
//	}
	printf("%d",ans);
	return 0;
}
