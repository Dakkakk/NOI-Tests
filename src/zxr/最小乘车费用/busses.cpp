#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int bus[11];
int s[20001];
int n;
////¶¯¹é 
int main(){
	freopen("busses.in","r",stdin);
	freopen("busses.out","w",stdout);
	memset(s,10000,sizeof(s));
	s[0]=0;
	for(int i=1;i<=10;i++)
		cin>>bus[i];
	cin>>n;
	for(int i=1;i<=10;i++)
		for(int j=1;j<=n;j++)
			if(j>=i)
				s[j]=min(s[j],s[j-i]+bus[i]);
	cout<<s[n];
	return 0;
}




