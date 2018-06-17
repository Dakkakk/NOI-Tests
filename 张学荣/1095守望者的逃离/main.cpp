#include <algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#define put(t,tmp,mm) dp[t]=max(dp[t],dp[t-1]+tmp),m+=mm
using namespace std;
int dp[300001];
int m,s,t;
bool f(int st,int t){
	switch(st){
		case 1:
			if(m>=10)
				put(t,60,-10);
        	else 
				put(t,0,4);
			break;
		default:
			put(t,17,0);
			if(dp[t]>=s)
				return true;
			break;
	}
	return false;
}
int main(){
	freopen("test.in","r",stdin);
    scanf("%d %d %d",&m,&s,&t);
    memset(dp,0,sizeof(dp));
    for(int i=1;i<3;i++){
    	for(int j=1;j<=t;j++){
    		if(f(i,j)){
    			printf("Yes\n%d",j);
				return 0;
    		}
    	}
    }
	printf("No\n%d",dp[t]);//没成功，输出no
    return 0;
}

