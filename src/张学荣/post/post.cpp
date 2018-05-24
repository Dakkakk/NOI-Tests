#include<cstdio>
#include<cstring>
#include<algorithm>
#define min(x,y) (x>y?y:x)
using namespace std;
int m,n;
int vpos[301];
int v[301][301],t[301][301];
int main() {
	freopen("post.in","r",stdin);
//	freopen("post.out","w",stdout);
	scanf("%d%d",&m,&n);
	for(int i=1; i<=m; i++)
		scanf("%d",&vpos[i]);
	sort(vpos,vpos+m);
	memset(v,127/3,sizeof v);
	memset(t,0,sizeof t);
	for(int i=1; i<=m; i++) {
		for(int j=i+1; j<=m; j++)
			t[i][j]=t[i][j-1]+vpos[j]-vpos[(i+j)>>1];
		v[i][i]=0;
		v[i][1]=t[1][i];
	}
	for(int j=2; j<=n; j++) //�ȱ����ٵģ�����Ļ����ٵ� ,�ʾ� 
		for(int i=j+1; i<=m; i++) //��j���ʾ֣�����Ҫ��j+1����ׯ�ź��� 
			for(int k=j-1; k<i; k++)//��kλ�÷ŵ�j���ʾ� 
				v[i][j]=min(v[i][j],v[k][j-1]+t[k+1][i]);
	printf("%d",v[m][n]);
	return 0;
}

