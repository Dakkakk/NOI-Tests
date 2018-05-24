#include<iostream>
#include<cstdio>
using namespace std;
int ansn=0,sum=0,book[50],bz[40][40],a[40],price[40],money,n;//sum is "ansp",,,money is "tp"
int totn=0,totp=0;
bool check(int x)
{
	for(int i=1;i<=x-1;i++)
		if(bz[x][i]==1&&a[i]==1)
		return false;
		return true;
}
void dfs(int x)
{
	if(x>n||totp>money)
	{
	if((totp<=money&&totn>ansn)||(ansn==totn&&totp<=money&&totp>sum))
	{
		sum=totp;ansn=totn;
		for(int i=1;i<=30;i++)book[i]=a[i];
	}
	return;
	}
	if(check(x))
	{
			a[x]=1;
			totp+=price[x];
			totn+=1;
			dfs(x+1);
			a[x]=0;
			totp-=price[x];
			totn-=1;
			dfs(x+1);
	}
	else 
	dfs(x+1);
}
int main()
{
	freopen("fish.in","r",stdin);
	freopen("fish.out","w",stdout);
	cin>>money>>n;
    int num,val;
    for(int i=1;i<=n;i++)a[i]=0;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)bz[i][j]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>num>>val;
		price[num]=val;
	}
	for(int i=1;i<=n;i++)
	cout<<price[i];
	int m,p;
	cin>>m>>p;
	while(m>0&&p>0)
	{
		bz[m][p]=bz[p][m]=1;
		cin>>m>>p;
	}
	dfs(1);
	cout<<ansn<<" "<<sum<<endl;
	for(int i=1;i<=n;i++)
	{
		if(book[i]==1)
		cout<<i<<endl;
	}
	return 0;
}
