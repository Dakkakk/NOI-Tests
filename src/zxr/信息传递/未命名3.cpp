#include <cstdio>
#define NodeMax 200001
int a[NodeMax] , f[NodeMax] , v[NodeMax];
inline int InP()
{
    int N=0;
    char C;
    C=getchar();
    while('0' <= C && C <= '9')
    N=N*10 + (C-'0') , C=getchar();
    return N;
}
int main()
{
	freopen("cc.in","r",stdin);
    int n=InP() , p , t , x=NodeMax;
    for(int i=1 ; i <= n ; i++) a[i]=InP();
    for(int i=1 ; i <= n ; i++)
    {
        v[i]=1 , t=i , p=a[i];
        while(f[p] != i)
        {    
            if(f[p] != 0 && f[p] < i) break;        
            v[p]=v[t]+1 , f[t]=i;
            t=p , p=a[t];
        }

        if(f[p] == i && x > v[t]+1-v[p]) x=v[t]+1-v[p];
    }
    printf("%d" , x);
    return 0;
}
