#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int a;
	char b;
	freopen("char.out","w",stdout);
	for(a=65;a<=90;++a)
	{
		b=a;
		cout<<a<<" "<<b<<" "<<endl;
	}
	fclose(stdout);
	return 0;
	
	
}

