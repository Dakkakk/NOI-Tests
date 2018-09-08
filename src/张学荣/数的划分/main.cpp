#include<iostream>
#define min(a,b) (a<b?a:b)
using namespace std;
int n,k,ans=0;
void dfs(int index,int next,int left) {
	if(left<0)
		return;
	if(index==0) {
		if(left==0)
			ans++;
		return;
	}
	for(int i=min(left-index+1,next); i>0; i--)
		dfs(index-1,i,left-i);
}
int main() {
	cin.sync_with_stdio(0);
	cin>>n>>k;
	dfs(k,0xfffff,n);
	cout<<ans;
	return 0;
}
