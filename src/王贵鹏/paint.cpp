#include<cstdio>
using namespace std;
int n,ans=0xfff,b[16],tot,color[16]={0},map[100][100]={0},boo[16][16]={0};
bool check(int i){
    for(int j=1;j<=n;j++)
    if(j!=i&&boo[j][i]&&b[j]==0) return 0;
    return 1;
}
void dfs(int k,int color1){ 
    if(k>=n||tot>ans){
        if(tot<ans)
        ans=tot;
        return ;
    }
    for(int i=1;i<=n;i++){
        if(b[i]==0&&check(i)){
            b[i]=1;
            if(color[i]!=color1)
            tot++;
            dfs(k+1,color[i]);
            b[i]=0;
            if(color[i]!=color1)
            tot--;
        }
    }	
}
int main(){
    freopen("paint.in","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        	int x1,x2,y1,y2;
            scanf("%d%d%d%d%d",&y1,&x1,&y2,&x2,&color[i]);
            b[i]=0;
            for(int k1=y1;k1<y2;k1++)
            	for(int k2=x1;k2<=x2;k2++)//k1,k2 ,map,it can make an table with all the i!
            	map[k1][k2]=i;//let a table becom i; 
        }
    for(int i=1;i<99;i++)
        for(int j=1;j<100;j++)
            if(map[i][j]>0&&map[i+1][j]>0&&map[i+1][j]!=map[i][j])
            boo[map[i][j]][map[i+1][j]]=true;
        dfs(0,0);
    printf("%d",ans);
}
