#include<iostream>
#include<cstdio>
#include <cstring>
using namespace std;
int tp,n,p[31],bz[31][31],ansn=0,ansp=0,v[31],totp=0,s=0,totn,cop[31],buy[31];
void search(int k)
{
    int b[31];
	if(k>n||totp>tp){
		 if((totp<=tp&&totn>ansn)||(ansn==totn&&totp<=tp&&totp>ansp))
	  	  {
	  	  	ansp=totp;
	  	  	ansn=totn;
	  	  	memcpy(cop,buy,sizeof(cop)); 
	  	  }
	 return;  
    }
	if ((v[k]==0)&&(totp+p[k]<=tp))         //能买  
	 {
	  	v[k]=1;
	  	totp+=p[k];
	  	totn+=1;
	  	buy[totn]=k;
	  	memcpy(b, v,sizeof(b)); 
	  	for(int i=1;i<=n;++i)
	  	  if(bz[k][i]==1) v[i]=1;
	  	search(k+1);     
	  	memcpy(v, b,sizeof(v)); 
	        v[k]=0;
	  	totp-=p[k];
	  	totn-=1;	  	
	 }
         search(k+1); //不买，直接搜索下一条
}
int main()
{
	freopen("fish.in","r",stdin);
	freopen("fish.out","w",stdout);
	cin>>tp>>n;
	int e,E;
	for(int i=1;i<=n;++i) v[i]=0;
	for(int i=1;i<=n;++i)  
	  for(int j=1;j<=n;++j)
	    bz[i][j]=0;
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
	for(int i=1;i<=ansn;++i)
	  cout<<cop[i]<<endl;
	return 0;	  
}

