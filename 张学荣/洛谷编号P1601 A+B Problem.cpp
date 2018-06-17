#include<iostream>
#include<string>
#include<cstring>
using namespace std;

//倒着读
 
void in(string a,int b[],int l){
	for(int i=0;i<l;i++){
		b[i+1]=a[i]-'0';
	}
}

int main(){
	string sa,sb;
	cin>>sa;
	cin>>sb;
	int la=sa.length();
	int lb=sb.length();
	int a[la+1],b[lb+1];
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	in(sa,a,la);
	in(sb,b,lb);
	int max=0;
	if(la>lb)
		max=la;
	else
		max=lb;
	int c[max];
	memset(c,0,sizeof(c));
	for(int i=max-1;i>0;i--){
		c[i]=a[i]+b[i];
		if(c[i]>=10){
			a[i]++;
			c[i]=c[i]-c[i]/10;
		}
		cout<<i<<'='<<a[i]<<' '<<b[i]<<' '<<c[i]<<endl;
	}
	cout<<endl;
	for(int i=0;i<max;i++){
		cout<<c[i];
	}
	return 0;
}
