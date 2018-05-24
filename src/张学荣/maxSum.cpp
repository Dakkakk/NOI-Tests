#include<cstdio>
#include<cstring>
#define endl printf("\n")
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a>b)?b:a)
using namespace std;
struct bnum{
	int num[100];
	#define l (this->num[0])
	inline bnum(){
		memset(num,0,sizeof num);
	}
	inline bnum(char *c){
		bnum();
		l=strlen(c);
		int i=1,j=l-1;
		while(j>=0){
			num[i]=c[j]-'0';
			j--;
			i++;
		}
	}
	inline bnum(long long integer){
		bnum();
		long long tmp=integer;
		l=0;
		while(tmp>0){
			l++;
			num[l]=tmp%10;
			tmp/=10;
		}
		l=l;
	}
	
	inline void print(){
		for(int i=l;i>=1;i--){
			printf("%d",num[i]);
		}
	}
	#undef l
};
#define l c.num[0]
inline bnum sum(bnum a,bnum b){
	bnum c;
	int maxL=max(a.num[0],b.num[0]);
	int x=0;
	l=1;
	while(l<=maxL){
		c.num[l]=a.num[l]+b.num[l]+x;
		x=c.num[l]/10;
		c.num[l]%=10;
		l++;
	}
	l--;
	return c;
}
inline bnum multiply(bnum a,bnum b){
	
}
#undef l
int n;
int k;
int num[41];
long long getNumOf(int s,int e){
	long long result=0;
	for(int i=e;i<=s;i--){
//		result+=num[i]*
	}
}
int dp[41][7];
int main(){
//	{
//		freopen("in.txt","r",stdin);
//		scanf("%d%d",&n,&k);
//		char c[41];
//		scanf("%s",c);
//		bnum b=c;
//		for(int i=1;i<=n;i++){
//			num[i]=c[i-1]-'0';
//		}
//	}
//	for(int i=1;i<=k;i++){
//		for(int j=1;j<=n;j++){
//			
//		}
//	}
	bnum b=123456789;
	b.print();
	char c[]="159357";
	endl;
	bnum a=c;
	a.print();
	endl;
	bnum t=sum(a,b);
	t.print();
	return 0;
}
