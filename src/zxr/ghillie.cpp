#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define getn (pep[0])
using namespace std;

int pep[201],n;
int pmp[201];
int wc(int resourse,int pows){
	int rst=0,res=resourse;
	while(res>0){
		int t=res%10;
		rst+=pow(t,pows);
		res/=10;
	}
	return rst;
}
int main(){
	freopen("ghillie.in","r",stdin);
	freopen("ghillie.out","w",stdout);
	cin.sync_with_stdio(0);
	cin>>n;
	memset(pep,127/3,sizeof pep);
	getn=0;
	while(!cin.eof())
		cin>>pep[++getn];
	for(int tt=2;tt<=n+1;tt++){
		for(int i=1;i<=getn;i++)
			pmp[i]=(pep[i]==0x2a2a2a2a)?0x2a2a2a2a:wc(pep[i],tt);
		for(int i=1;i<=getn;i++)
			for(int j=1;j<=getn;j++)
				if(pep[j]==pmp[i])
					pep[j]=0x2a2a2a2a;
	}
	sort(pep+1,pep+getn+1);
	for(int i=1;i<getn;i++)
		if(pep[i]!=0x2a2a2a2a)
			cout<<pep[i]<<' ';
	return 0;

}



