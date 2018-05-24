#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	freopen("sum.in","r",stdin); 
    freopen("sum.out","w",stdout); 
	int a,b;
	cin>>a>>b;
	if((a<1000000000)&&(b<1000000000)){
		int sum=a+b;
	cout<<sum;
	}
	else
	cout<<a+b;
	return 0;
}
