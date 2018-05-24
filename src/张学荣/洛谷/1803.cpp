#include<iostream>
#include<algorithm>
using namespace std;

struct TimeTable{
	int start;
	int end;
	int during;
};

bool camp(TimeTable a,TimeTable b){
	return a.start<b.start;
}

int main(){
	freopen("in.txt","r",stdin);
	int n;
	cin>>n;
	TimeTable times[n];
	for(int i=0;i<n;i++){
		cin>>times[i].start>>times[i].end;
		times[i].during=times[i].end-times[i].start;
	}
	//***************
	sort(times,times+n,&camp);
	int i=1;
	TimeTable table=times[0];
	int t=0;
	while(i<n){
		TimeTable tmp=times[i];
		if(table.start==tmp.start){
			if(table.end>tmp.end)
				table=tmp;
		}else if(table.end<=tmp.start){
			t++;
			table=tmp;
		}
		i++;
	}
	cout<<t;
    return 0;
}
