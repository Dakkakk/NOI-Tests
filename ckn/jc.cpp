#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	long long a=1;
	int n;
	freopen("jc.in","r",stdin);
	freopen("jc.out","w",stdout);
	cin>>n;
	if(n<=20)
	{
	for(int i=1;i<=n;++i)
	a=a*i;
	cout<<a;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
