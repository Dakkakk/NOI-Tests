#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int n;
string s;
int main(){
	freopen("copycat.in","r",stdin);
	freopen("copycat.out","w",stdout);
	scanf("%d",&n);
	while(n>=1){
		n--;
		cin>>s;
		cout<<s<<endl;
	}
	return 0;
}
