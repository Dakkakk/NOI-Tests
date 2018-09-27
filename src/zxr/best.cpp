#include<iostream>
#include<cstdio>
#include<cstring>
#define max(a,b) (a>b?a:b)
using namespace std;
struct bnum {
	int nm[61];
	int length;
	bnum (){
		memset(nm,0,sizeof nm);
		length=0;
	}
	inline bnum(const int a){
		memset(nm,0,sizeof nm);
		length=0;
		*this=a;
	}
	bnum& operator =(const int a){
		int at=a;
		while(at>0){
			nm[length++]=at%10;
			at/=10;
		}
		return *this;
	}
	bnum operator *(const bnum a) {
		bnum tmp;
		tmp.length=length+a.length;
		for(int i=0; i<length; i++) {
			for(int j=0; j<a.length; j++) {
				tmp.nm[i+j]+=nm[i]*a.nm[j];
				tmp.nm[i+j+1]+=tmp.nm[i+j]/10;
				tmp.nm[i+j]%=10;
			}
		}
		if(tmp.nm[tmp.length-1]==0)
			tmp.length--;
		return tmp;
	}
	inline void ad(){
		int p=0,si=1;
		while(si){
			nm[p]++;
			si=nm[p]/10;
			nm[p++]%=10;
		}
		if(nm[length]!=0)
			length++;
	}

}nn[1001],ans=1;
ostream& operator << (ostream &o,const bnum & t) {
	for(int i=t.length-1; i>=0; i--)
		o<<t.nm[i];
	return o;
}
int n;

void pre(const int res) {
	int at=res,tn;
	n=0;
	while(at>=n+2)
		nn[++n]=n+2,at-=n+1;
	tn=n;
	while(at>0){
		nn[tn--].ad(),at--;
		if(tn==0)
			tn=n;
	}
}
int main() {
	cin.sync_with_stdio(0);
	freopen("best.in","r",stdin);
	freopen("best.out","w",stdout);
	cin>>n;
	pre(n);
	for(int i=1;i<=n;i++)
		ans=ans*nn[i];
	cout<<ans;
	return 0;

}



