#include<algorithm>
#include<cstdio>
#define max(x,y) ((x>y)?x:y)
using namespace std;
int stages[1001][1001];
int n;
int main(){
	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			scanf("%d",&stages[i][j]);
		}
	}
	for(int i=2;i<=n;i++){
		for(int j=1;j<=i;j++){
			stages[i][j]=stages[i][j]+max(stages[i-1][j-1],stages[i-1][j]);
		}
	}
	int max=stages[n][1];
	for(int i=2;i<=n;i++)
		max=max(stages[n][i],max);
	printf("%d",max);
	return 0;
}
