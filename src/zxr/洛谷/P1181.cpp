#include<iostream>
using namespace std;
int main(){
	long N,M,tM;
	cin>>N>>M;
	long divide=0;
	tM=M;
	for(int i=0;i<N;i++){
		int d;
		cin>>d;
		tM-=d;
		if(tM=0){
			tM=M;
			divide++;
		}else if(tM<0){
			divide++;
			tM=M-d;
		}
	}
	cout<<divide;
	return 0;
}
