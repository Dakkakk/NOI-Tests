#include<iostream>
using namespace std;
int a[20][20];
int n,tot;
int minL=40000;
int f[20];
int L=0;
void dfs(int index)
{
	if(tot>=n)
	{
	    if(minL>L+a[index][1])
	 	minL=L+a[index][1];
		return;
	}
	for(int i=2;i<=n;i++)
	{
		if(f[i]==0){
			L+=a[index][i];
			f[i]=1;
			tot++;
			if(L<minL)dfs(i);
			f[i]=0;
			tot--;
			L-=a[index][i];
		}
	}
}
int main(){
	freopen("Salesman.in","r",stdin);
	freopen("Salesman.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
	  for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	f[1]=1;
	tot=1;
	dfs(1);
	cout<<minL;
	return 0;
}
