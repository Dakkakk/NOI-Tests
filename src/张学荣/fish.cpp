#include<iostream>
using namespace std;
int P,N;//资金， 鱼的种类
int fishPrice[31];
int map[31][31];
int tPrice=0,fishNum=0;
int fishsHasBought[31];
int priceN=0,numN,function[31];
bool checking(int id){
	for(int i=1;i<=30;i++)
		if(function[i]==1&&map[i][id]==1)
			return false;
	return true;
}
void dfs(int idN){
	if(idN==N+1||priceN>P){//当鱼遍历完成 当价钱超过
		if((numN>fishNum||(numN==fishNum&&priceN>tPrice))&&priceN<=P){
			tPrice=priceN;
			fishNum=numN;
			for(int i=1;i<=N;i++)
				fishsHasBought[i]=function[i];
		}
	}else if(checking(idN)){
		function[idN]=1;
		priceN+=fishPrice[idN];
		numN++;
		dfs(idN+1);
		function[idN]=0;
		priceN-=fishPrice[idN];
		numN--;
		dfs(idN+1);
	}else
		dfs(idN+1);
}
int main(){
	freopen("fish.in","r",stdin);
	freopen("fish.out","w",stdout);
	cin>>P>>N;
	for(int i=1;i<=N;i++){
		int id,price;
		cin>>id>>price;
		fishPrice[id]=price;
	}
	int fish1,fish2;
	cin>>fish1>>fish2;
	while(fish1>0&&fish2>0){
		map[fish1][fish2]=map[fish2][fish1]=1;
		cin>>fish1>>fish2;
	}
	///////////////////////////DFS///////////////////////
	dfs(1);
	/////////////////////////OUTPUT//////////////////////
	cout<<fishNum<<' '<<tPrice<<'\n';
	for(int i=1;i<=N;i++)
		if(fishsHasBought[i]==1)
			cout<<i<<'\n';
	return 0;
}

