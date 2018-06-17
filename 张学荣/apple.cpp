#include<iostream>
using namespace std;

int main(){
	freopen("apple.in","r",stdin);    
	freopen("apple.out","w",stdout); 
	int apples[10];
	int length,a=0;
	for(int i=0;i<10;i++){
		cin>>apples[i];
	}
	cin>>length;
	for(int i=0;i<10;i++)
		if(apples[i]<=length+30)
			a++;
	cout<<a;
	return 0;
} 
