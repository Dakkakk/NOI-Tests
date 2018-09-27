#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define gety(id) ((id-1)/5+1)
#define getx(id) (id-(gety(id)-1)*5)
using namespace std;
typedef unsigned long ul;
struct index {
	int id[5];
	ul idl;
	index ad() {
		bool s=true;
		for(int i=0; i<5; i++) {
			if(s)
				++id[i],s=false;
			if(id[i]>9)
				id[i]-=10,id[i+1]++;
		}
		idl++;
		return *this;
	}
	index& operator =(const ul a) {
		ul t=a;
		int iid=0;
		while(t>0) {
			id[iid++]=t%10;
			t/=10;
		}
		idl=a;
		return *this;
	}
	bool operator <=(const ul b) {
		if(idl<=b)
			return true;
		return false;
	}
} ind;
const int size=99998;
bool prime[11][11][11][11][11];
int zhishu[size/2];
void work() {
	zhishu[1]=2;
	long long k=2;
	for(ind=3; ind<=size; ind.ad()) {
		bool isprime=true;
		for(long long j=1; j<k; j++) {
			if(ind.idl%zhishu[j]==0) {
				isprime=!isprime;
				break;
			}
		}
		if(isprime) {
			zhishu[k]=ind.idl;
			prime[ind.id[4]][ind.id[3]][ind.id[2]][ind.id[1]][ind.id[0]]=true;
			k++;
		}
	}
}
int maxn,fst;
//   x      y       hv vh
int lie[6],hang[6],ll,rr;
int martex[6][6],box[4]= {1,3,7,9};
void dfs(int id) {
	int x=getx(id),y=gety(id);
	if(id==26) {
		if((!prime[martex[1][1]][martex[2][2]][martex[3][3]][martex[4][4]][martex[5][5]])
			||!prime[martex[5][1]][martex[4][2]][martex[3][3]][martex[2][4]][martex[1][5]])
				return;
		cout<<"lalalalalala\n";
		return;
	}
	bool hv=(x==y),vh=(x+y==6);
	if(x!=5&&y!=5) {
		for(int i=0; i<=9; i++) {
			if(lie[x]-i<1||hang[y]-i<1||(hv&&ll-i<1)||(vh&&rr-i<1))
				break;
			martex[x][y]=i;
			lie[x]-=i;
			hang[y]-=i;
			ll=(hv?ll-i:ll);
			rr=(vh?rr-i:rr);
			dfs(id+1);
			martex[x][y]=0;
			lie[x]+=i;
			hang[y]+=i;
			ll=(hv?ll+i:ll);
			rr=(vh?rr+i:rr);
		}
	} else {
		for(int i=0; i<4; i++) {
			int tmp=box[i];
			if(x==5&&(!prime[martex[1][y]][martex[2][y]][martex[3][y]][martex[4][y]][box[i]]))
				continue;
			if(y==5&&(!prime[martex[x][1]][martex[x][2]][martex[x][3]][martex[x][4]][box[i]]))
				continue;
			if((hv&&ll==box[i])||!hv)
				if((vh&&rr==box[i])||!vh)
					if((x==5&&hang[y]==box[i])||x!=5)
						if((y==5&&lie[x]==box[i])||y!=5) {
							martex[x][y]=box[i];
							lie[x]-=box[i];
							hang[y]-=box[i];
							ll=(hv?ll-box[i]:ll);
							rr=(vh?rr-box[i]:rr);
							dfs(id+1);
							martex[x][y]=0;
							lie[x]+=box[i];
							hang[y]+=box[i];
							ll=(hv?ll+box[i]:ll);
							rr=(vh?rr+box[i]:rr);
						}
		}
	}
}
int main() {
	cin.sync_with_stdio(0);
	freopen("in.txt","r",stdin);
	cin>>maxn>>fst;
	for(int i=1; i<=5; i++)
		lie[i]=hang[i]=maxn;
	rr=maxn;
	martex[1][1]=fst;
	ll=lie[1]=hang[1]=maxn-fst;

	work();
	dfs(2);
//	ind=1000;
//
//	for(int i=1; i<=1100; i++) {
//		cout<<"i="<<i<<' '<<(ind<=i)<<endl;
//	}
	return 0;
}



