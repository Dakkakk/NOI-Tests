#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int n,al=0,b[21]={0},ans=0,t[21][21]={-1};
char star;
struct word
{
	string s;
	int l;
}a[21];
void search(int x,int y)
{
	int q=a[x].l-1,w=0,temp=0;
	while(a[x].s[q]==a[y].s[w])
	{
		q--;w++;temp++;
	}
	if(q==-1||w>=a[y].l) t[x][y]=t[y][x]=0;
	else t[x][y]=temp;
	return;  
}
void dfs(int x)
{
	for(int i=1;i<=n;++i)
	{
		if(t[x][i]==-1) search(x,i);
		if(b[i]<2&&t[x][i])
		{
			al+=a[i].l-t[x][i];b[i]++;
			dfs(i);al-=a[i].l-t[x][i];b[i]--;
		}
	}
	if(ans<al) ans=al;
	return;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	//scanf("%s",a[i].s);
	cin>>a[i].s;
	//scanf("%c",&star);
	cin>>star;
	for(int i=1;i<=n;++i)
	a[i].l=a[i].s.length();
	for(int i=1;i<=n;++i)
	if(a[i].s[0]==star)
	{
		b[i]++;al+=a[i].l;dfs(i);b[i]--;al-=a[i].l;
	}
//	for(int i=1;i<=n;++i) printf("%d ",a[i].l);
	printf("%d",ans);
	return 0;
}
