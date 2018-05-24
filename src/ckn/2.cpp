#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	int n,a=1;
	freopen("jc.in","r",stdin);
	freopen("jc.out","w",stdout);
	cin>>n;
	for(n;n>0;--n)
	a=a*n;
	cout<<a;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
