#include<iostream>
using namespace std;
int a[21][21],b[21]={0},n,ts=0,ans=0xffff,f,x=1;
void dfs(int k){
	if(x==n||ts>ans)
	 {
		if(ans>ts+a[k][1])
		ans=ts+a[k][1];	
	return ;
	} 
	for(int i=2;i<=n;i++)
	if(b[i]==0){
		b[i]=1;
		ts+=a[k][i];
		x+=1;
		dfs(i);
		b[i]=0;
		ts-=a[k][i];
		x-=1;
	}
}
int main(){
	freopen("salesman.in","r",stdin);
	freopen("salesman.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	dfs(1);
	cout<<ans;
	return 0;
}
