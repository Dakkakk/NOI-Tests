#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;
const long long size=100000;
//�޸�size����ֵ�Ըı���������Ĵ�С
long long zhishu[size/2];
int nn[10][10][10][10][10];
void work() {
	zhishu[1]=2;
	long long k=2;
	for(long long i=3; i<=size; i++) {
		//ö��ÿ����
		bool ok=1;
		for(long long j=1; j<k; j++) {
//ö���Ѿ��õ�������
			if(i%zhishu[j]==0) {
				ok=!ok;
				break;
			}
		}
		if(ok) {
			zhishu[k]=i;
//			cout<<"count"<<k<<' '<<i<<endl;
			cout<<i<<endl;
			k++;
		}
	}
}
int main() {
	freopen("zhishu.out","w",stdout);
//	cout<<"count1 2"<<endl;

	work();
	cout<<'\n';
	return 0;
}
bool isPrime(unsigned long n) {
	if (n <= 3) {
		return n > 1;
	} else if (n % 2 == 0 || n % 3 == 0) {
		return false;
	} else {
		for (unsigned short i = 5; i * i <= n; i += 6) {
			if (n % i == 0 || n % (i + 2) == 0) {
				return false;
			}
		}
		return true;
	}
}
