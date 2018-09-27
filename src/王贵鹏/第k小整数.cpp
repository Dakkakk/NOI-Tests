#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    int a[10001];
    for(int i=1;i<=n;i++)
    scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        if(a[i]<a[i+1]){
            k--;
            if(k==0){
            printf("%d",a[i]);
            break;
            }
        }
    if(k>0)
	printf("NO RESULT");
}

