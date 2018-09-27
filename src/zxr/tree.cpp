#include<iostream>
#include<cstdio>
#include<cstring>
#include <string>
#include <sstream>
#define max(a,b) (a>b?a:b)
using namespace std;

int map[101][101];
int wd[101];
int n;
int cc[101];
void inner() {
	char c=getchar();
	int tmp=0,index=1,i=0;
	while(c!=EOF) {
		if('0'<=c&&c<='9')
			tmp=tmp*10+c-'0';
		else if(c==' ')
			cc[i++]=tmp,tmp=0;
		else {
			cc[i++]=tmp,tmp=0;
			wd[index]=cc[0];
			for(int j=1; j<i; j++)
				map[index][cc[j]]=1;
			index++,i=0;
		}
		c=getchar();
	}
}

int ans[101][101];
int main() {
//	cin.sync_with_stdio(0);
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d",&n);
//	getchar();
//	inner();
//	cout<<'\n';
	string line;
	stringstream ss;
	for (long i=1; i<n+1; i++) {
		cin >> wd[i];
		getline(cin,line);
		ss.clear();
		ss << line;
		long v = 0;
		while (ss >> v)
			map[i][v] = 1;
	}
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			if(i==j)
				ans[i][j]=0;
			else if(map[i][j])
				ans[i][j]=wd[j];
			else ans[i][j]=-0xffffff;
	for(int k=1; k<=n; k++) {
		for(int i=1; i<=n; i++) {
			if(i!=k)
				for(int j=1; j<=n; j++) {
					if(i!=j&&k!=j)
						ans[i][j]=max(ans[i][j],ans[i][k]+ans[k][j]);
				}
		}
	}
	int mx=0;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			mx=max(ans[i][j]+wd[i],mx);
	cout<<mx;
	return 0;

}



