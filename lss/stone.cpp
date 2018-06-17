#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int c,m,n,w[50002],mid,l,r;
bool cha(int now) {
    int flag=0,s=0;
    for(int i=1;i<=n+1;i++) {
        if(w[i]-s<now) flag++;
        else s=w[i];
    }
    return (flag>m)?false:true;
}
int main() {
	freopen("stone.in","r",stdin);
	freopen("stone.out","w",stdout);
    scanf("%d%d%d",&c,&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&w[i]);
    l=1;r=c;w[n+1]=c;
    while(l+1<r) { 
        mid=((l+r+1)/2);
        if(cha(mid)==false) r=mid;
        else l=mid;
    }
    if(cha(r)) l=r;//这行和上一行我考试时没有加,结果在m=0时被卡了一个点。
    printf("%d",l);
    return 0;
}
