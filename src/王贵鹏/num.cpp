#include<cstdio>
#include<cstring>
using namespace std;
int a;
int main(){
	scanf("%d",&a);
	int b[1001];
	memset(b,0,sizeof(b));
	b[1]=1;
	for(int i=2;i<=a;i++){
		b[i]=b[i-1];
		if(i%2==0)
		b[i]+=b[i/2];
	}
	printf("%d",b[a]);
}
