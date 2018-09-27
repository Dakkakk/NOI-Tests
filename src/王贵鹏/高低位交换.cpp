#include<cstdio>
using namespace std;
int main(){
	long long x;
	scanf("%d",&x);
	x=((x&0x0000ffff)<<16)|((x&0xffff0000)>>16);//the former change x to ejz,and than move,the later the same ,but different directions,and then change the right;
		printf("%lld",x);
}
