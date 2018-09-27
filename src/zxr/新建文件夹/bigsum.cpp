#include<iostream>
#include<string>
#include<cstring>
using namespace std;
void in(string a,int b[],int l){
	int j=0;
	for(int i=l-1;i>=0;i--){
		b[j]=a[i]-'0';
		j++;
	}
}
int main(){
	string sa,sb;
	cin>>sa;
	cin>>sb;
	int la=sa.length(),lb=sb.length(),max=0;
	if(la>lb)
		max=la;
	else
		max=lb;
	int a[max+1],b[max+1];
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	in(sa,a,la);
	in(sb,b,lb);
	int c[max+1];
	memset(c,0,sizeof(c));
	for(int i=0;i<max+1;i++){
		c[i]=a[i]+b[i];
		if(c[i]>=10){
			int t=c[i]/10;
			a[i+1]+=t;
			c[i]=c[i]-t*10;
		}
	}
	if(c[max]!=0)
		cout<<c[max];
	for(int i=max-1;i>=0;i--){
			cout<<c[i];
	}
	return 0;
}
