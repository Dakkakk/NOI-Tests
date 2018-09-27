
#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstring>
#include<vector>
#include<string>
#define max(a,b) ((a>b)?a:b)
using namespace std;
struct num{
	inline num(){
		num(0,0);
	}
	inline num(int length,int num){
		memset(number,0,sizeof(number));
		number[0]=length;
		if(num!=0)
			for(int i=1;i<=length;i++)
				number[i]=num;
	}
	inline num cpy(){
		num n;
		memcpy(n.number,this->number,sizeof this->number);
		return n;
	}
//	private :
	int number[120];
//	public:

	inline num add(num numt){
		num n;
		int max=max(number[0],numt.number[0]);
		for(int i=1;i<=max;i++){
			n.number[i]=numt.number[i]+number[i];
			if(n.number[i]>=10){
				n.number[i]%=10;
				n.number[i+1]++;
				n.number[0]=i+1;
			}
		}
		return n;
	}
	
	
	inline num add(long numt){
		num n=this->cpy();
		long tmp=numt;
		int i=1;
		while(tmp>0){
			int t=(tmp%10);
			tmp/=10;
			n.number[i]+=t;
			if(n.number[i]>=10){
				n.number[i]%=10;
				n.number[i+1]++;
			}
			i++;
		}
		if(i>n.number[0]&&n.number[i]==0)
			n.number[0]=i-1;	
		return n;
	}
};
inline num max(num a,num b){
	int l1=a.number[0];
	if(l1>b.number[0])
		return a;
	else if(l2>b.number[0])
		return b;
	for(;l1>0;l1--){
		if(a.number[l1]>b.number[l1])
			return a;
		else if(a.number[l1]<b.number[l1])
			return b;
	}
	return a;
}

//int main(){
////	freopen("in.txt","r",stdin);
////	freopen("out.txt","w",stdout);
//	//cout<<t;
//	num n=num(10,7),h=num(8,7);
//	
//	h=n.add(677755555l);
//	cout<<0;
//	return 0;
//}

