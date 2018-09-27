#include<cstdio>
#include<algorithm>
using namespace std;
struct aa{
	int price,heavy;
}a[2000001];
int n,m;
bool cmp(aa aaa,aa b){
	return aaa.price<b.price;
}
int main(){
	freopen("in.in","r",stdin);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	scanf("%d%d",&a[i].price,&a[i].heavy);
	sort(a+1,a+m+1,cmp);
	int ans=0;
	for(int i=1;i<=m;i++){
		if(n-a[i].heavy>=0){
		ans+=a[i].price*a[i].heavy;
		n-=a[i].heavy;
		}
		else
		if(n>0){
		ans+=n*a[i].price;break;
		}
	}
	printf("%d",ans);
	
}
