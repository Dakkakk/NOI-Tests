#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

long long f(long long i){
	long long res=i;
	long long t=i;
	while(t>0){
		res*=t%10;
		t/=10;
	}
	return res;
}
int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	int res=0;
	for(;a<=b;a++){
		long long t=f(a);
		if(a<=t&&t<=b)
			res++;
	}
	printf("%d",res);
	return 0;
}
