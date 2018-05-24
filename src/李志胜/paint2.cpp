#include<cstdio>
using namespace std;
int n,a[20],c[101][101],heng[20],chang[20],zong[20],ans=99,k,t,m;
bool b[20];
void init(int n)
   {
	int x,y,z,w;
	for(int i=1;i<=n;++i){
		scanf("%d%d%d%d%d",&y,&x,&z,&w,&a[i]);
		for(int j=x;j<=w;++j)
		  c[z][j]=i;		
		heng[i]=y;chang[i]=w-x;zong[i]=x;
	}
	return;
}
bool pd(){   //判断是否 涂完 
	for(int i=1;i<=n;++i)
	  if(!b[i]) return false;
	return true;	
}
bool judge(int x){//判断该方块是否可以涂 
//	int k=heng[x];int t=zong[x];int m=chang[x]+t;
//	//if(k==0)return true;
//	do
//	{
//		int p=c[k][t];
//		if(!b[p])
//		 return false;
//	 	else
//		 t+=chang[p];
//	}
//	while(t<=m);	
	return true;
}
void dfs(int x,int ti,int color){
    if(ti>=ans) return;
	if(pd()){
		if(ti<ans) ans=ti;
		return;
	}
	for(int i=1;i<=n;++i){
		if(!b[i]&&judge(i)){
			b[i]=true;
			if(a[i]==color) dfs(i,ti,a[i]);
			 else dfs(i,ti+1,a[i]);
			b[i]=false;
		}
	}
	return ;
}
int main(){
	freopen("paint.in", "r", stdin);
	freopen("paint.out", "w", stdout);	
	scanf("%d",&n);
	init(n);
	for(int j=1;j<=n;++j) b[j]=false;
	dfs(1,1,a[1]);		
//	for(int i=1;i<=n;++i)
//    {
//	   	for(int j=1;j<=n;++j) b[j]=false;
//	  	//if(judge(i)) 
//           		
//	}
	printf("%d",ans);
    return 0;
}
