#include<cstdio>
#include<cmath>
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
struct a{//table ,res ,box;
	int table,res,box;
}b[10][10];
int ans=0,sum=0,x;
bool check(int i,int j,int k){
	if(b[i][j].table!=0) return false;
	if(k==b[i][j].table||k==b[j][i].table||(b[i][j].box==1&&k==b[i][j].table)||(b[i][j].box==2&&k==b[i][j].table)||(b[i][j].box==3&&k==b[i][j].table))
	return false;
	if((b[i][j].box==4&&k==b[i][j].table)) return false;
	if(b[i][j].box==5&&k==b[i][j].table) return false;
	if((b[i][j].box==6&&k==b[i][j].table)) return false;
	if(b[i][j].box==7&&k==b[i][j].table) return false;
	if((b[i][j].box==8&&k==b[i][j].table)) return false;
	if(b[i][j].box==9&&k==b[i][j].table) return false;
	return true;
}
void dfs(int i){
	if(x>81){
		if(sum>ans)
		ans=sum;
	return ;	
	}
	for(int j=1;j<=9;j++)	
		for(int k=1;k<=9;k++)
			if(check(i,j,k))
			{	x++;
				b[i][j].table=k;
				sum+=b[i][j].table*b[i][j].res;
				dfs(i+1);
				b[i][j].table=0;
				sum-=b[i][j].table*b[i][j].res;
			}       
}
int main(){	
	freopen("word.in","r",stdin);
	for(int i=1;i<=9;i++)
	  for(int j=1;j<=9;j++){
		scanf("%d",&b[i][j].table);
		b[i][j].res=10-max(abs(i-5),abs(j-5));//to make it look more beautiful
		b[i][j].box=(i-1)/3*3+(j-1)/3+1;
	}
		dfs(1);//don't have num;
		if(ans==0)
			printf("%d",-1);
		else	
			printf("%d",ans);
}
