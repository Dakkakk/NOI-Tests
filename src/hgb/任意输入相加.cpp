#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int sum=0,value=0;
	freopen("casual in.in","r",stdin);
	freopen("casual out.out","w",stdout);
	while(cin>>value)
	{
		sum+=value;
	}
	cout<<"The sum is"<<sum<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
