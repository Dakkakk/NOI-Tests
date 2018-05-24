#include<cstdio>
#include<cstring>
using namespace std;
struct migong{
	int x,y;
}a[10000];
int m,n,step,xx,yy,lx,ly,flad,next[5][3];//table
bool boo[51][51];
void change(){
	next[1][1]=1,next[1][2]=0,next[2][1]=-1,next[2][2]=0,next[3][1]=0,next[3][2]=1,next[4][2]=0,next[4][2]=-1;
}
void bfs(){
	yy=1;
	int head=0,tail=1,bbx,bby;
	a[tail].x=xx;
	a[tail].y=yy;
	step=0;
	boo[xx][yy]=false;
	do{
		head++;
		for(int i=1;i<=4;i++){
			bbx=a[head].x+next[i][1];
			bby=a[head].y+next[i][2];
			if(bbx>0&&bbx<=n&&bby>0&&bby<=m&&boo[bbx][bby]){
			tail++;
			step++;
			a[tail].x=bbx;
			a[tail].y=bby;
			boo[bbx][bby]=false;
			if(bbx==lx&&bby==ly){
			printf("%d",step);
			flad==1;
			}
			} 
		}
	}while(head<tail);
}
int main(){
	freopen("search.in","r",stdin);
	memset(boo,true,sizeof(boo));
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
		scanf("%d%d",&boo[i][j]);
		scanf("%d%d",&xx,&yy);
		scanf("%d%d",&lx,&ly);
		change();
		bfs();
		if(flad!=1)
		printf("No Way!");
}
