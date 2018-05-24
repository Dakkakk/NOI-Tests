#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	long long n;
	freopen("jc.in","r",stdin);
	freopen("jc.out","w",stdout);
	cin>>n;
	long long jc=1;
	for(int i=1;i<=n;++i)
	{
		jc*=i;
	}
	cout<<jc<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
