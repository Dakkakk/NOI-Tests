#include<cstdio>
#include<algorithm>
using namespace std;
struct point
{
    int x,y,data;//��¼ÿ�����λ�ú���ֵ
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
    for(l=2;l<=n*2;l++)//ÿ�������ٺ������Ŷ���һ����඼��n��͵��յ�
        for(i=l-1;i>=1;i--)//��ǰ��˵��һ����������
            for(j=l-1;j>=1;j--)
            {
                a=l-i;b=l-j;//i+a=j+b=l
                f[i][j]=max(max(f[i][j],f[i-1][j-1]),max(f[i-1][j],f[i][j-1]))+map[i][a];
//�ص�˵��һ�°ɣ�����ʡ���˺ܶࡣ���i����1����˼����a-1����Ϊ��һ���׶ξ���l-1����j-1����˼����˵b����1��
                f[i][j]+=map[j][b]*(i!=j);
//���i==j����ʵ����(i==j&&a==b)����Ϊ�Ͷ���l�����߹�һ�飬�ڶ����ߵõ���ֵ����0����Ŀ��˵�ģ���
            }
    printf("%d\n",f[n][n]);
//�����˼����·������Ϊ2*n�Ľ׶Σ����鶼�ߵ�(n,n)������ֵ����Ϊ������(a=2*n-i=n,b=2*n-j=n),�����ߵ��ľ���(n,n)��λ��
    return 0;
}
