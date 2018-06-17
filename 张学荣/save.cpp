#include<iostream>
using namespace std;
int main(){
	freopen("save.in","r",stdin);   
	freopen("save.out","w",stdout);
	int left=0;
	double saved=0;
	for(int i=0;i<12;i++){
		int out;
		cin>>out;
		left+=300;
		left-=out;
		if(left<0){
			cout<<'-'<<i+1;
			return 0;
		}
		if(left>=100){
			int t0=left/100;
			int save=t0*100;
			left-=save;
			saved+=save;
		}
	}
	saved=saved*1.2+left;
	cout<<saved;
	return 0;
}
