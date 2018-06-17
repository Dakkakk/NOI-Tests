#include<iostream>
using namespace std;
int a[20][20];
int n;
int minL=40000;
int f[20];
int L=0;
int n0=1;
void dfs(int index){
    if(L>=minL)
        return;
    else if(n0>=n){
        L+=a[index][0];
        if(minL>L)
            minL=L;
        L-=a[index][0];
        return;
    }
    for(int i=1;i<n;i++){
        if(f[i]==0){
            L+=a[index][i];
            f[i]=1;
            n0++;
            dfs(i);
            f[i]=0;
            L-=a[index][i];
            n0--;
        }
    }
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    f[0]=1;
    dfs(0);
    cout<<minL;
    return 0;
}
