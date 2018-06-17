#include <iostream>
#include<cstdio>
using namespace std;
int s[20][20],ans=0,toto=0,a=1,b=1,bd[20][20]={0};
char l;
bool check(int x,int y,int q)
{
    for(int i=1;i<=9;i++)
    {
	if(y!=i) if(s[x][i]==q) return false;
    if(x!=i) if(s[i][y]==q) return false;
     }	
    return true;	
}

void dfs(int i,int j)
 {
    if(j>9)
	 {i++;j=1;
     }   	
    if(i>9)
{
	for(int x=1;x<=9;x++)	
	for(int y=1;y<=9;y++)
	if(x==1||x==9||y==1||y==9) toto+=(s[x][y]*6);
	else
	if(x==2||x==8||y==2||y==8) toto+=(s[x][y]*7);
	else
	if(x==3||x==7||y==3||y==7) toto+=(s[x][y]*8);
	else
	if(x==4||x==6||y==4||y==6) toto+=(s[x][y]*9);
	else
	if(x==5||y==5) toto+=(s[x][y]*10);	
	if(toto>ans) ans=toto;
	toto=0;
	return;
}
else
for(int q=1;q<=9;q++)
{
	if(s[i][j]==0)	
	{
		if(check(i,j,q))
	    {
	    	s[i][j]=q;
	    	dfs(i,j+1);
	    	s[i][j]=0;
		}	
	}	
}

}

int main()
{
	freopen("ans.in","r",stdin);    
    freopen("4.out","w",stdout); 
    for(int i=1;i<=9;i++)	
      for(int j=1;j<=9;j++)
          cin>>s[i][j];	
    dfs(1,1);	
    cout<<ans;		
}
