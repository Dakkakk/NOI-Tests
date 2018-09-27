#include<cstdio>
using namespace std;
int a[1001][1001],b[1001],c[1001];//b cout c cin
int n,m;
char s[1001];
int main(){
	freopen("message.in","r",stdin);
	//freopen("message.out","w",stdout);
	scanf("%d%d",&n,&m);
	int a1,b1;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&a1,&b1);
		a[a1][b1]=1;
		b[a1]++;
		c[b1]++;
	}
	for(int i=1;i<=n;i++)
		if(c[i]==0||b[i]==0) {
		s[i]='F';
		for(int ii=1;ii<=n;ii++)
			if(a[i][ii]==1){
			c[ii]--;
			a[i][ii]=0;
			}
		}
	for(int i=1;i<=n;i++)
		if(s[i]=='F')
		printf("%c\n",s[i]);
		else
		printf("T\n");		
}
