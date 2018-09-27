#include<cstdio>
#include<algorithm>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int n;
int i;
int inline squr(int a,int q){
	int s=a;
	for(int ii=1;ii<=q;ii++)
	s*=a;
	return s;
}
int a[256],b[256];
void dfs(){
	for(int q=1;q<=n;q++){
		int bb=0;
		for(int ii=1;ii<=i;ii++)
			if(a[ii]!=-1)
			if(a[ii]>=100)
				b[ii]+=squr(a[ii]%10,q)+squr((a[ii]%100-a[ii]%10)/10,q)+squr((a[ii]%1000-a[ii]%100)/100,q);
			else if(a[ii]<100&&a[ii]>=10) b[ii]+=squr(a[ii]%10,q)+squr((a[ii]%100-a[ii]%10)/10,q);
			else b[ii]+=squr(a[ii],q);
			
		for(int ii=1;ii<=i;ii++)
			for(int j=1;j<=i;j++)
			if(b[ii]==a[j]&&a[j]!=-1)
			a[j]=-1,bb++;
			else if(b[ii]<=a[j]) continue;
		
		for(int ii=1;ii<=i;ii++)
			b[ii]=0;
	}
}
int main(){
	freopen("ghillie.in","r",stdin);
	freopen("ghillie.out","w",stdout);
	scanf("%d",&n);
	i=1;
	while(scanf("%d",&a[i])!=EOF){
		b[i]=0;
	//	printf("%d %d ",a[i],b[i]);
		i++;
	}
	
	i--;
	sort(a+1,a+i+1);
	dfs();
	
	for(int ii=1;ii<=i;ii++)
	if(a[ii]!=-1)
	printf("%d ",a[ii]);
}
