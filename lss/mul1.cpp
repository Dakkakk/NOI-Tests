#include<cstdio>
#include<cstring>
using namespace std;
int n,a[101],f[101][101];
int cacl(int i,int j)
{
    if(i==j-1)return 0;
    if(j-i==2)return f[i][j];
    f[i][j]=0x3f3f3f3f;
    for(int k=i+1;k<=j-1;++k) 
      if(f[i][j]>cacl(i,k)+cacl(k,j)+a[i]*a[k]*a[j]) f[i][j]=cacl(i,k)+cacl(k,j)+a[i]*a[k]*a[j];
    return f[i][j];
}
int main()
{
    freopen("mul.in","r",stdin);
    freopen("mul.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%d",&a[i]);
    memset(f,0,sizeof(f));
    for(int i=1;i<=n-2;++i)f[i][i+2]=a[i]*a[i+1]*a[i+2];
    printf("%d\n",cacl(1,n));
    return 0;
}
