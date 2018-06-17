#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
using namespace std;
int m,n,p[31],a[31],bz[31][31],cop[31];
int main()
{
	freopen("fish.in","r",stdin);
	freopen("fish.out","w",stdout);
	cin>>m>>n;
	int x,y;
	for(int i=1;i<=n;++i)
	   {
	   	cin>>x>>y;
	   	p[x]=y;
	   }
	memset(a,0,sizeof(a));
	int q,w;
	for(int i=1;i<=n;++i)
	  for(int j=1;j<=n;++j)
	    bz[i][j]=0;
	cin>>q>>w;
	while(q>0&&w>0)
	  {
	  bz[q][w]=bz[w][q]=1;
	  cin>>q>>w;
      }
	int ans=0,s,tp,ts=0,ss=0;//tp为买的鱼的钱数，s为鱼的条数的计量数,ts为买的鱼  
	while(a[0]!=1)
	  {
	  	int j=n;
	  	while(a[j]==1)
	  	  --j;
	  	a[j]=1;
		for(int i=j+1;i<=n;++i)
		  a[i]=0;
		s=0;tp=0;ss=0;
    	for(int i=1;i<n;++i)
		   for(int k=i+1;k<=n;++k)
		    if(bz[i][k]==1&&a[i]==1&&a[k]==1)
		      ss=1;
		if(ss==1)
		  continue;      
		for(int i=1;i<=n;++i)
		  {
		  	tp+=a[i]*p[i];
		  	if(a[i])
		  	  ++s;
		  }  
		if((ts<s&&tp<=m)||(tp<=m&&ts==s&&ans<tp))
		  {
		  	ans=tp;
		  	ts=s;
		    for(int i=1;i<=n;++i)
		      cop[i]=a[i];
		  }  
	  }
	cout<<ts<<" "<<ans<<endl;
	for(int i=1;i<=n;++i)
	  if(cop[i]==1)
	    cout<<i<<endl;
	return 0;	   
}
