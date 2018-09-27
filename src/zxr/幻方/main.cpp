#include<iostream>
#define high(a) (a>>16)
#define low(a) (a-high(a))
#define bit(a,i) ((a>>(i-1))%2)
using namespace std;

long long map[200001][6250];
int main(){
//	freopen("ss.oo","w",stdout);
//	for(long i=1;i<=200001;i++)
//		ss[0]+=i;
//	cout<<ss[0];
	long long t=2685667368ll;
	for(int i=32;i>=1;i--){
		if(i%4==0)
			cout<<' ';
		cout<<bit(t,i);
		
	}
}
