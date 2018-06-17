#include<iostream>
#include<string>
using namespace std;
void tokey(string s,int m[]){
	for(int i=0;i<s.length();i++){
		int a=s[i];
		char b=s[i];
		m[i]=(s[i]<'a')?s[i]-'A':s[i]-'a';
	}
}
//x,密文，y，密钥 
//返回 明文 
char cc(int x,int y){
	int t=x-y;
	if((t<65&&x<'Z')||(t<97&&x>='a'))
		return t+26;
	return t;
}
int main(){
	freopen("vigenere.in","r",stdin);
	freopen("vigenere.out","w",stdout);
	string k,C;
	cin>>k>>C;
	int key[k.length()];
	tokey(k,key);
	for(int j=0,i=0;i<C.length();i++,j++){
		if(j==k.length())
			j=0;
		cout<<cc(C[i],key[j]);
	}
	return 0;
}
