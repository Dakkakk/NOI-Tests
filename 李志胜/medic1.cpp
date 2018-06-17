#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int a[101],t[101],m[101];
int main()
{
	freopen("medic.in","r",stdin);
	freopen("medic.out","w",stdout);
	int ti,mi;
	cin>>ti>>mi;
	int max=0;
	memset(a,0,sizeof(a));
	for(int i=1;i<=mi;++i)
	  cin>>t[i]>>m[i];
	while(a[0]!=1)
	  {
	  	int j=mi;
	  	while(a[j]==1)j--;
	  	a[j]=1;
		for(int i=j+1;i<=mi;++i) //for(int i=j+i;i<=mi;++i)
		  a[i]=0;
		int son=0,dauther=0;  
		for(int i=1;i<=mi;++i)
		  {
		  	son+=a[i]*m[i];
		  	dauther+=t[i]*a[i];
		  	if(dauther>ti) break;
		  }
		if(dauther<=ti&&max<son)
		  max=son;        
	  }
	cout<<max;  
	return 0;
}

