#include<iostream>
using namespace std;
int m,n,p,q,sum=0,total=0,ansn=0,ansp=0,f[31][31],c[31],cop[31],b[31];//sum~money   total~kind
bool check(int x){
	for(int i=1;i<=x-1;++i)
		if(f[x][i]==1&&c[i]==1)	return false;
	 return true;
}
void dfs(int k){//第k条鱼，总共花费的money 
	if(k>n||sum>m){
		if((sum<=m&&total>ansp)||(ansp==total&&sum<=m&&sum>ansn)){
			ansn=sum;
			ansp=total;
			for(int i=1;i<=30;i++)
			cop[i]=c[i];
		}
		return;
	}
	
	if(check(k)){
		c[k]=1;
		sum+=b[k];
		total+=1;
		dfs(k+1);//buy this one then search the next one
		c[k]=0;
		sum-=b[k];
		total-=1;
		dfs(k+1);//no buy this one,search the next one;
	}
	else
		dfs(k+1);
}
int main(){
	freopen("fish.in","r",stdin);
	freopen("fish.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=n;++i)
	  c[i]=0;
	for(int i=1;i<=n;++i)  
	  for(int k=1;k<=n;++k)
	    f[i][k]=0;
	    int e,ee;
	for(int i=1;i<=n;i++){
	cin>>e>>ee;
	b[e]=ee;
	}
	cin>>p>>q;
	while(p>0&&q>0){
		f[p][q]=f[q][p]=1;
		cin>>p>>q;
	}
	dfs(1);
	cout<<ansp<<" "<<ansn<<endl;//ansn~number,ansp~the max money;
	for(int i=1;i<=n;i++)
		if(cop[i]==1)
			cout<<i<<endl;
		return 0;
}
