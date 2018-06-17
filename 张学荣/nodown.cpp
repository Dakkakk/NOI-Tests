#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
struct Node{
	int value;
	int past;
	int l;
}nodes[101];
int n,maxLIndex=1;
int main(){
	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&nodes[i].value);
		nodes[i].past=0;
		nodes[i].l=1;
	}
	for(int i=n;i>0;i--){
		for(int j=i-1;j>0;j--){
			int followI=nodes[i].l+1;
			if(nodes[j].value<=nodes[i].value&&followI>nodes[j].l){
				nodes[j].l=followI;
				nodes[j].past=i;
				if(nodes[j].l>nodes[maxLIndex].l)
					maxLIndex=j;
			}
		}
	}
	printf("%d\n",nodes[maxLIndex].l);
	while(nodes[maxLIndex].past!=0){
		printf("%d ",nodes[maxLIndex].value);
		maxLIndex=nodes[maxLIndex].past;
	}
	printf("%d",nodes[maxLIndex].value);
	return 0;
}
