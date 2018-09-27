#include<cstdio>
#include<cstring>
using namespace std;
int main(){
		char s[100],c[100];
		int n;
		scanf("%d",&n);
		sprintf(s,"%d",n);
		int l=strlen(s);
		for(int i=0;i<=l-1;i++)
			c[l-i-1]=s[i];
		if (n<0)
		printf("-");
		sscanf(c,"%d",&n);
		printf("%d",n);
		return 0;
}
