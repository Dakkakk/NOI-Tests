#include<cstdio>
using namespace std;
#define min(a,b) a<b?a:b
#define max(a,b) a>b?a:b
int limit,f[101][601],c=0;
void dfs(){
	int root=++c;
	int x,y;
	scanf("%d%d",&x,&y);
	x*=2;
	if(y!=0){
		for(int i=x;i<=limit;++i)
		f[root][i]=min((i-x)/5,y);//如果时间多到可以全部取完就选t 
	}
	else{
		int l=c+1;
		dfs();
        int r=c+1;
        dfs();
		for(int i=x;i<=limit;++i)
		for(int j=0;j<=i-x;++j)
		f[root][i]=max(f[root][i],f[l][j]+f[r][i-j-x]);
	}
}
int main(){
	freopen("gallery.in","r",stdin);
	freopen("gallery.out","w",stdout);
    scanf("%d",&limit);
	limit--;
	dfs();
	printf("%d",f[1][limit]);
	return 0;
}

