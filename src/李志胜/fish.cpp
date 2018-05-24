#include<iostream>
#include<cstdio>
using namespace std;
int tp,n,p[31],bz[31][31],ansn=0,ansp=0,a[31],totp=0,s=0,totn,cop[31];
bool chekc(int x)
{
	for(int i=1;i<=x-1;++i)
	  if(bz[x][i]==1&&a[i]==1) return false;
	 return true;   
}
void search(int x)
{
	if(x>n||totp>tp)
	  {
	 if((totp<=tp&&totn>ansn)||(ansn==totn&&totp<=tp&&totp>ansp))
	  	  {
	  	  	ansp=totp;
	  	  	ansn=totn;
	  	  	for(int i=1;i<=30;++i) cop[i]=a[i];  
	  	  }
	  	return;  
	  }
    if(chekc(x))           //不会打架
	 {
	  	a[x]=1;
	  	totp+=p[x];
	  	totn+=1;
	  	search(x+1);     //买第x条的基础上，再搜索下一条
	    a[x]=0;
	  	totp-=p[x];
	  	totn-=1;
	  	search(x+1);   //不买第x条，直接搜索下一条
	 }
	else
	 search(x+1);  //第x条鱼会与之前已购买鱼打架，则不能买第x条，直接搜下一条
}
int main()
{
	freopen("fish.in","r",stdin);
	freopen("fish.out","w",stdout);
	cin>>tp>>n;
	int e,E;
	for(int i=1;i<=n;++i)
	  a[i]=0;
	for(int i=1;i<=n;++i)  
	  for(int k=1;k<=n;++k)
	    bz[i][k]=0;
	for(int i=1;i<=n;++i)
	  {
	  	cin>>e>>E;
	  	p[e]=E;
	  }
	int q,w;
	cin>>q>>w; 
	while(q>0&&w>0)
	  {
	  bz[q][w]=bz[w][q]=1;
	  cin>>q>>w; 
      }
    search(1);
	cout<<ansn<<" "<<ansp<<endl;
	for(int i=1;i<=n;++i)
	  if(cop[i]==1)
	    cout<<i<<endl;
	return 0;	  
}

