#include<cstdio>
using namespace std;
int n,a[20001],f[20001];
int main()
{
    freopen("busses.in","r",stdin);
    freopen("busses.out","w",stdout);
    for(int i=1;i<=10;++i)
       { 
         scanf("%d",&a[i]);
         f[i]=a[i];
       }
     scanf("%d",&n);
     for(int i=11;i<=n;++i)    //������memset���������ǰ�f�������帳ֵ 
       f[i]=0x3f3f3f;         //��ֵ����Ҫ������0xfffffff 
     for(int i=2;i<=n;++i)
       for(int j=0;j<=i-1;++j)
       if(j>=i-10&&f[j]+a[i-j]<f[i])
         f[i]=f[j]+a[i-j];
     printf("%d",f[n]);
     return 0;   
}
