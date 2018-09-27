#include<iostream>
#include<cstring>
typedef unsigned long long u;
#define usablebit 32
struct bitset{
	u bits[10];
	
	bitset(){
		memset(bits,0,sizeof bits);
	}
	#define bit(x,i) ((x>>(i-1))%2)
	int bitg(const long p){
		u pp,p0;
		pp=(p-1)/usablebit;
		p0=p-pp*usablebit;
		return bit(bits[pp],p0);
	}
	void bitp(const long p,int state){
		u pp,p0;
		pp=(p-1)/usablebit;
		p0=p-pp*usablebit;
		u t=1<<(p0-1);
		bits[pp]|=t;
	}
}bi;
using namespace std;
int idl[11]={
	1,7,9,15,36,40,44,50,61,64,75
};
int main(){
	for(int i=0;i<11;i++)
		bi.bitp(idl[i],1);
	cout<<bi.bits[0]<<' '<<bi.bits[1]<<endl;
	for(int i=0;i<11;i++)
		cout<<"p:"<<idl[i]<<"\t"<<bi.bitg(idl[i])<<endl;
	for(int i=64;i>0;i--)
		cout<<bi.bitg(i);
	cout<<endl;
	for(int i=128;i>64;i--)
		cout<<bi.bitg(i);
	return 0;
}
