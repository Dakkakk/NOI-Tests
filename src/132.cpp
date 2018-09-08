#include<iostream>
#include<cstdio>
#include<cstdlib>
//#include<cmath>
//#include<bits/stdc++.h>

using namespace std;

int n,fa,mo;
float DD,Dd,dd;

int main()
{
	printf("			模拟分离定律实验\n");
	printf("请输入实验的组数(限定一千万以内)：") ; 
	scanf("%d",&n);
	printf("\n");
	int cnt=0;
	for (int i=1;i<=n;++i)
	{
		cnt=0;
		fa=rand()%2;
		mo=rand()%2;
		if (fa==1)	cnt++;
		if (mo==1)	cnt++;
		if (cnt==0)	dd++;
		if (cnt==1)	Dd++;
		if (cnt==2)	DD++;
	}
	printf("DD：Dd：dd=");
	printf("%.2f:%.2f:%.2f",DD/n,Dd/n,dd/n);
	return 0;
}


