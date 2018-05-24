#include<cstdio>
using namespace std;
int n,a[31],f[31][31],root[31][31]={0},temp;
void front(int x,int y){
//	if(x>y) return;
//	if(x==y){
//		printf("%d ",x);
//		return;
//	}
//	if(x==y-1){
//		printf("%d %d ",x,y);
//		return;
//	
	int t=root[x][y];
	if(t!=0)
	{
		printf("%d ",t);
	if(root[x][t-1])	front(x,t-1);
	if(root[t+1][y]) front(t+1,y);}
	return;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	scanf("%d",&a[i]);
	for(int i=0;i<=n;++i) for(int j=0;j<=n;++j) f[i][j]=1;
	for(int i=1;i<=n;++i){
		root[i][i]=i;
		f[i][i]=a[i];
	}
	for(int len=2;len<=n;++len)
	 for(int i=1;i<=n-len+1;++i)
	  for(int j=i;j<=i+len-1;++j)
	  {
		temp=f[i][j-1]*f[j+1][i+len-1]+a[j];
		if(temp>f[i][i+len-1]){
			f[i][i+len-1]=temp;
			root[i][i+len-1]=j;
		}
	}
	printf("%d\n",f[1][n]);
	front(1,n);
	return 0;
}
