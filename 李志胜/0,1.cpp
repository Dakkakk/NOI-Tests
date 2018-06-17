#include<iostream>
#include<cstring>
using namespace std;
int a[101];
int main()
{
	int n;
	cin>>n;
	memset(a,0,sizeof(a));
	while(a[0]!=1)
	  {
	  	for(int i=1;i<=n;++i)
	  	  cout<<a[i];
	  	cout<<endl;
		int j=n;
		while(a[j]==1)
		  j--;
		a[j]=1;
		for(int i=j+1;i<=n;++i)
		  a[i]=0;      
	  }
	return 0;  
}
