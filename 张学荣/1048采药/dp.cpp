#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
struct MMM{
	int value,time;
}medics[100];
int t[1001];
int totalTime,n;
int main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	cin>>totalTime>>n;
	memset(t,0,sizeof(t));
	for(int i=0;i<n;i++)
		cin>>medics[i].time>>medics[i].value;
	for(int i=0;i<n;i++){//medic
		for(int j=totalTime;j>=0;j--){//time
			if(j>=medics[i].time)
				t[j]=max(t[j-medics[i].time]+medics[i].value,t[j]);
		}
	}
	cout<<t[totalTime];
	return 0;
}

