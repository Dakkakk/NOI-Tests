#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
int n,b[100][100]={0},t;
string a[100];
char s[7]={'y','i','z','h','o','n','g'};
int judge(char x){
	for(int i=0;i<7;++i)
		if(x==s[i])
			return 1;
	return 0;
}
void up(int x,int y){
	t=x;int k=1;
	if(a[x][y]==s[0]) for(int i=1;i<=6;++i){
		if(a[t--][y]!=s[i]){
			k=0;break;
		}
	}t=x;
	if(a[x][y]==s[6]) for(int i=5;i>=0;--i){
		if(a[t--][y]!=s[i]){
			k=0;break;
		}
	}
	if(k) for(int i=x+1;i>=x-5;--i) b[i][y]=1;
	return;
}
void left(int x,int y){
	t=y;int k=1;
	if(a[x][y]==s[0]) for(int i=1;i<=6;++i){
		if(a[x][t--]!=s[i]){
			k=0;break;
		}
	}t=y;
	if(a[x][y]==s[6]) for(int i=5;i>=0;--i){
		if(a[x][t--]!=s[i]){
			k=0;break;
		}
	}
	if(k) for(int i=y+1;i>=y-5;--i) b[x][i]=1;
	return;
}
void right(int x,int y){
	t=y;int k=1;
	if(a[x][y]==s[0]) for(int i=1;i<=6;++i){
		if(a[x][t++]!=s[i]){
			k=0;break;
		}
	}t=y;
	if(a[x][y]==s[6]) for(int i=5;i>=0;--i){
		if(a[x][t++]!=s[i]){
			k=0;break;
		}
	}
	if (k) for(int i=y-1;i<=y+5;++i) b[x][i]=1;
	return;
}
void down(int x,int y){
    t=x;int k=1;
	if(a[x][y]==s[0]) for(int i=1;i<=6;++i){
		if(a[t++][y]!=s[i]){
			k=0;break;
		}
	}t=x;
	if(a[x][y]==s[6]) for(int i=5;i>=0;--i){
		if(a[t++][y]!=s[i]){
			k=0;break;
		}
	}
	if(k) for(int i=x-1;i<=x+5;++i) b[i][y]=1;
	return;
}
int main(){
	freopen("as.in","r",stdin);
	freopen("as.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	cin>>a[i];
	for(int i=0;i<n;++i) for(int j=0;j<n;++j) if(!judge(a[i][j])){
	b[i][j]=1;
	a[i][j]='*';}
	for(int i=0;i<n;++i)
	for(int j=0;j<n;++j){
		if(a[i][j]==s[0]||a[i][j]==s[6]){
			if(j>=6) left(i,j-1);
			if(n-1-j>=6) right(i,j+1);
			if(i>=6) up(i-1,j);
			if(n-1-i>=6) down(i+1,j);
		}
	}
	for(int i=0;i<n;++i) for(int j=0;j<n;++j) if(!b[i][i]) a[i][j]='*';
	for(int i=0;i<n;++i) {
	cout<<a[i];
	if(i==n-1) cout<<"\n";
    }
	return 0;
}
