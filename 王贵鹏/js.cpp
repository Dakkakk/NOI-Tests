#include<iostream>
#include<cstdio>
using namespace std;
int js(int x){
	long long s=1;
	for(int i=1;i<=x;++i)
	s*=i;
	return s;
}
int main(){
	freopen("sum.in","r",stdin); 
    freopen("sum.out","w",stdout); 
    int n;
    cin>>n;
    cout<<js(n);
}
