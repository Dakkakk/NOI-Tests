#include<cstdio>
using namespace std;
int n,m;//n point ,m side;
int d[5001];
int vst[5001]={0};
int a[5001][5001];
int main(){
//a	freopen("in.in","r",stdin);
	scanf("%d%d",&n,&m);
	int q,w,e;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		a[i][j]=8388607;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&q,&w,&e);
		if(a[q][w]>e){
		a[q][w]=e;
		a[w][q]=e;
		}
	}//read map
  	int ans=0,k=0;
	for(int i=1;i<=n;i++) d[i]=8388607;
	d[1]=0;
	int minn;
	for(int i=1;i<=n;i++){//point
		minn=8388607;
		for(int j=1;j<=n;j++)
			if(vst[j]==0&&minn>d[j]){
				minn=d[j];
				k=j;
			}
		ans+=d[k];//add side
		vst[k]=1;//have searched ,add
		for(int j=1;j<=n;j++)
			if(vst[j]==0&&d[j]>a[k][j])
			d[j]=a[k][j];
		
	}
	printf("%d",ans);
		
	
}
