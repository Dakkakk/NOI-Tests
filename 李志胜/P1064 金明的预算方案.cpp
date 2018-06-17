#include<cstdio>
#include<iostream>
using namespace std;
int m,n,v1[60],p1[60],q[60],dp[300][32000],c1[60],v2[300][5],p2[300][5],c2[300][5],qq[60][5],t[60];//qq【i】【】数组用于表示每个物品i是否有附件，c数组用于存p*v 
int main(){
//	freopen("budget.in","r",stdin);
	for(int i=0;i<=n;++i) t[i]=1;
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;++i){
		scanf("%d%d%d",&v1[i],&p1[i],&q[i]);
		c1[i]=v1[i]*p1[i];
		if(q[i]){
			qq[q[i]][t[q[i]]++]=i;
		}
	}
	int tail=1,x;
	for(int i=1;i<=n;++i){
		x=1;
		if(q[i]==0){
			c2[tail][0]=c1[i];
		//	p2[tail][0]=p1[i];
			v2[tail][0]=v1[i];
			while(qq[i][x]){
				c2[tail][x]=c1[i]+c1[qq[i][x]];
				//p2[tail][x]=p1[i]+p1[qq[i][x]];
				v2[tail][x]=v1[i]+v1[qq[i][x]];
				x++;
			}
			if(t[i]>2){
				c2[tail][x]=c1[i]+c1[qq[i][1]]+c1[qq[i][2]];
				v2[tail][x]=v1[i]+v1[qq[i][1]]+v1[qq[i][2]];
			//	p2[tail][x]=p1[i]+p1[qq[i][1]]+p1[qq[i][2]];
			}
			tail++;
		}
	}
	for(int i=1;i<tail;++i)
	for(int j=1;j<=m;++j){
		x=0;
		dp[i][j]=dp[i-1][j];//不买
		while(c2[i][x]){
			if(j>=v2[i][x])
				dp[i][j]=max(dp[i][j],dp[i-1][j-v2[i][x]]+c2[i][x]);
			x++;	
		} 
	}
	printf("%d",dp[tail-1][m]);
//	printf("\n");
//	for(int i=1;i<=n;++i){
//		if(q[i]==0){
//			printf("%d ",i);
//			for(int j=1;j<=t[i];++j)
//			printf("%d ",qq[i][j]);
//			cout<<endl;
//		}
//	}
//	for(int i=1;i<tail;++i){
//		x=0;
//		while(c2[i][x]){
//			printf("%d ",c2[i][x]);
//			x++;
//		}
//	}
	return 0;
}
