#include<cstdio>
#include<iostream>
using namespace std;
int main(){
	freopen("sum.in","r",stdin); 
	freopen("sum.out","w",stdout);
	int i;
	long long result=1;
	scanf("%d",&i);
	for(int j=1;j<=i;j++){
		result*=j;
	}
	printf("%d",result);
	return 0;
}
