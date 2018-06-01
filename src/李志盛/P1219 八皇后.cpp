#include<cstdio>
#include<ctime>
using namespace std;
int n,a[16],b[16][16],total=0,t=1;
void print()
{
	if(total<3)
	{
	for(int i=1;i<=n;++i)
	printf("%d ",a[i]);
	printf("\n");}
	
	return;
}
void search(int x,int y)
{
	int l=x,r=y;
	while(l>1&&r>1)
	{
		l--;r--;
	}
	while(l<=n&&r<=n)
	b[l++][r++]++;l=x;r=y;
	while(l>1&&r<n)
	{l--;r++;
	}
	while(l<=n&&r>=1)
	b[l++][r--]++;
	return;
}
void asearch(int x, int y)
{
	int l=x,r=y;
	while(l>1&&r>1)
	{
		l--;r--;
	}
	while(l<=n&&r<=n)
	b[l++][r++]--;l=x;r=y;
	while(l>1&&r<n)
	{
		l--;r++;
	}
	while(l<=n&&r>=1)
	b[l++][r--]--;
	return;
}
void change(int x,int y)
{
	for(int i=1;i<=n;++i)
	{
		b[x][i]++;
		b[i][y]++;
	}
	return;
}
void achange(int x,int y)
{
	for(int i=1;i<=n;++i)
	{
		b[x][i]--;
		b[i][y]--;
	}
	return;
}
void queen(int x)
{
	if(x>n)
	{
		print();++total;return;
	}
	for(int i=1;i<=n;++i)
	{
		if(!b[x][i])
		{
			search(x,i);change(x,i);b[x][i]-=3;
			a[x]=i;queen(x+1);asearch(x,i);
			achange(x,i);b[x][i]+=3;
		}
	}
	return;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		search(t,i);change(t,i);b[t][i]-=3;a[t]=i;
		queen(t+1);asearch(t,i);achange(t,i);b[t][i]+=3; 
	}
	printf("%d",total);
	    printf("\n%.2f",(double)clock()/CLOCKS_PER_SEC);
	return 0;
}
