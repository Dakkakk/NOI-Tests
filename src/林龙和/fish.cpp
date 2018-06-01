#include<stdio.h>
#include<iostream>
using namespace std;
int j,t,p,pp,n,m[10000]={0},x,a,b,f[100][100]={0,0},to;
int toto=0,aa[1000]={0},mon=0,ansn=0,ansp=0,cope[31];

bool check(int ttt)//判断第ttt条会不会和之前买过的某条打架 
{
	for(int i=1;i<=n;i++)
	if(aa[i]==1&&f[ttt][i]==1) return false;
	 return true;	
}

void dfs(int tt){
if(tt>n||mon>=to)	
{
   if((toto>ansn&&mon<=to)||(toto==ansn&&mon>ansp&&mon<=to))	
	{
		ansn=toto;
		ansp=mon;
		for(int i=1;i<=30;i++)
		cope[i]=aa[i];
	}
	return;
}	
	
	
if(check(tt))
{
	 aa[tt]=1;
	 mon+=m[tt];
	 toto+=1;
	 dfs(tt+1);  //可以买，也买了第tt条 
	 
	 aa[tt]=0;
	 mon-=m[tt];
	 toto-=1;
	 dfs(tt+1);//可以买，但不买第tt条 	
}	
else dfs(tt+1);//不能买第tt条 
	
	
}



int main ()
{ int i;
	freopen("fish.in","r",stdin);
    freopen("fish.out","w",stdout);
cin>>to>>n;	
for(i=1;i<=n;i++)
{   cin>>j>>x;
	m[j]=x;
}
do{
	cin>>a>>b; 	  
    f[a][b]=f[b][a]=1;
}while(a>0&&b>0);
dfs(1);	
cout<<ansn<<" "<<ansp<<endl;
for(i=1;i<=n;i++)
{
	if(cope[i]==1) cout<<i<<"\n";
	
}
return 0;	
}
