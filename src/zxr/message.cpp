#include<iostream>
#include<cstdio>
using namespace std;
int n,m;
bool pp[1001][1001];

int main() {
	cin.sync_with_stdio(0);
	freopen("message.in","r",stdin);
	freopen("message.out","w",stdout);
	cin>>n>>m;
	for(int i=1,a,b; i<=m; i++) {
		cin>>a>>b;
		pp[a][b]=true;
	}
	for(int k=1; k<=n; k++)
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				pp[i][j]=pp[i][j]||(pp[i][k]&&pp[k][j]);
	for(int i=1; i<=n; i++)
		if(pp[i][i])cout<<"T\n";
		else cout<<"F\n";
	return 0;

}



