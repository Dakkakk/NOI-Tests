#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;
struct water {
	double l,r;
} a[15005];
double right;
/*   当前最右边 当前遍历到i  此时最大右边界所在的a[i]*/
void inline quall(int n,int l,int W) {
	int ans=0;
	double lst=-1e300,now=0;
	for(int i=1; i<=n; ++i) {
		printf("i=%d %.4f %.4f\n",i,a[i].l,a[i].r);
		if(a[i].l<=lst&&a[i].r>now) now=a[i].r;
		else if(a[i].l<=now&&a[i].r>now) lst=now,now=a[i].r,ans++;
		if(now>=l) break;
	}
	cout<<(now<l?-1:ans)<<endl;
}
bool cmp(water a,water b) {
	return a.l<b.l;
}

int main() {
	cin.sync_with_stdio(0);
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int as;
	cin>>as;
	while(as--) {
		int n,L,W,tot=0;
		cin>>n>>L>>W;
		W/=2.0;
		for(int i=1; i<=n; ++i) {
			double x,r;
			cin>>x>>r;
			if(r<=W) continue;
			double s=sqrt(r*r-W*W);
			a[++tot].l=x-s;
			a[tot].r=x+s;
		}
		sort(a+1,a+1+tot,cmp);
				cout<<"tot="<<tot<<endl;

		cout<<"work"<<as<<endl;
		for(int i=1;i<=tot;i++)
				printf("i=%d %.4f %.4f\n",i,a[i].l,a[i].r);
		//quall(tot,L,W);
	}
	return 0;

}


