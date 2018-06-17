#include<cstdio>
#include<algorithm>
using namespace std;
struct point
{
    int x,y,data;//记录每个点的位置和数值
}p[100];
int n,m,map[11][11],f[11][11];
int main()
{
	freopen("in.txt","r",stdin);
    int i,j,a,b,l;
    scanf("%d",&n);
    while(1)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if(!a&&!b&&!c)
            break;
        p[++m].x=a;
        p[m].y=b;
        p[m].data=c;
    }
    for(i=1;i<=m;i++)
        map[p[i].x][p[i].y]=p[i].data;
    for(l=2;l<=n*2;l++)//每个点最少横着竖着都走一格，最多都走n格就到终点
        for(i=l-1;i>=1;i--)//和前面说的一样，倒着做
            for(j=l-1;j>=1;j--)
            {
                a=l-i;b=l-j;//i+a=j+b=l
                f[i][j]=max(max(f[i][j],f[i-1][j-1]),max(f[i-1][j],f[i][j-1]))+map[i][a];
//重点说明一下吧，这里省略了很多。如果i不减1，意思就是a-1，因为上一个阶段就是l-1嘛。如果j-1，意思就是说b不减1。
                f[i][j]+=map[j][b]*(i!=j);
//如果i==j，其实就是(i==j&&a==b)，因为和都是l嘛。如果走过一遍，第二遍走得到的值就是0（题目上说的）。
            }
    printf("%d\n",f[n][n]);
//输出意思是在路径长度为2*n的阶段，两遍都走到(n,n)的最优值。因为在这里(a=2*n-i=n,b=2*n-j=n),所以走到的就是(n,n)的位置
    return 0;
}
