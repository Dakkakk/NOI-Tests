#include<iostream>
#include<string>
using namespace std;
int main(){
	int n=0;
	string s;
	cin>>n;
	cin>>s;
	for(int i=0;i<s.length();i++){
		for(int j=0;j<n;j++){
			s[i]+=1;
			if(s[i]>'z')
				s[i]='a';
		}
	}
	cout<<s;
	return 0;
}
